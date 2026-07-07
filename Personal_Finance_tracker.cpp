#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Transaction {
    string type;        // Income or Expense
    string date;
    string category;
    float amount;
    string note;
};

const int MAX =100;
Transaction expense[MAX];
int total =0;

// function declarations
void addIncome();
void addExpense();
void viewTransactions();
void showTotalIncome();
void showTotalExpense();
void showBalance();
void searchByCategory();
void deleteTransaction();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    // load old data from file if present
    loadFromFile();

    do {
        cout << "========== Expense Tracker =========="<<endl;
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. View All Transactions\n";
        cout << "4. Show Total Income\n";
        cout << "5. Show Total Expense\n";
        cout << "6. Show Balance\n";
        cout << "7. Search by Category\n";
        cout << "8. Delete Transaction\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addIncome();
                break;

            case 2:
                addExpense();
                break;

            case 3:
                viewTransactions();
                break;

            case 4:
                showTotalIncome();
                break;

            case 5:
                showTotalExpense();
                break;

            case 6:
                showBalance();
                break;

            case 7:
                searchByCategory();
                break;

            case 8:
                deleteTransaction();
                break;

            case 9:
                saveToFile();
                cout <<"Data saved. Exiting...\n";
                break;

            default:
                cout <<"Invalid choice"<<endl;
        }

    } while (choice != 9);

    return 0;
}

//function to add income
void addIncome() {
    if (total>=MAX) {
        cout <<"Transaction limit reached\n";
        return;
    }

    expense[total].type="Income";

    cout <<"Enter amount: ";
    cin >> expense[total].amount;
    cin.ignore();

    cout <<"Enter date (DD-MM-YYYY): ";
    getline(cin, expense[total].date);

    cout <<"Enter category: ";
    getline(cin, expense[total].category);

    cout <<"Enter note: ";
    getline(cin, expense[total].note);

    total++;
    saveToFile();

    cout <<"Income added successfully\n";
}

// function to add expense
void addExpense() {
    if (total>= MAX) {
        cout<<"Transaction limit reached\n";
        return;
    }

    expense[total].type = "Expense";

    cout<<"Enter amount: ";
    cin>>expense[total].amount;
    cin.ignore();

    cout<<"Enter date (DD-MM-YYYY): ";
    getline(cin, expense[total].date);

    cout<<"Enter category: ";
    getline(cin, expense[total].category);

    cout<<"Enter note: ";
    getline(cin, expense[total].note);

    total++;
    saveToFile();

    cout<<"Expense added successfully\n";
}

// function to display all transactions in table format
void viewTransactions() {
    if (total== 0) {
        cout<<"No transactions found\n";
        return;
    }

    cout << "============================ All Transactions ================================="<<endl;
    cout << left << setw(5) << "No"
         << setw(12) << "Type"
         << setw(12) << "Amount"
         << setw(15) << "Date"
         << setw(20) << "Category"
         << "Note" << endl;

    cout << "---------------------------------------------------------------------------------"<<endl;

    for (int i = 0; i < total; i++) {
        cout <<left<<setw(5)<<i+1
             <<setw(12)<<expense[i].type
             <<setw(12)<<expense[i].amount
             <<setw(15)<<expense[i].date
             <<setw(20)<<expense[i].category
             <<expense[i].note<< endl;
    }
}

// function to calculate total income
void showTotalIncome() {
    float totalIncome = 0;
    for(int i=0;i<total;i++) {
        if (expense[i].type == "Income") {
            totalIncome+=expense[i].amount;
        }
    }

    cout <<"Total Income: "<<totalIncome<<endl;
}

// function to calculate total expense
void showTotalExpense() {
    float totalExpense = 0;

    for (int i=0;i<total;i++) {
        if (expense[i].type=="Expense") {
            totalExpense+=expense[i].amount;
        }
    }

    cout <<"Total Expense: "<<totalExpense<<endl;
}

// function to show current balance
void showBalance() {
    float totalIncome = 0, totalExpense = 0;

    for (int i = 0; i < total; i++) {
        if (expense[i].type == "Income") {
            totalIncome += expense[i].amount;
        } 
        else if (expense[i].type == "Expense") {
            totalExpense += expense[i].amount;
        }
    }

    float balance = totalIncome - totalExpense;
    cout << "Current Balance: " << balance << endl;
}

// function to search transaction by category
void searchByCategory() {
    string searchCategory;
    bool found = false;

    cout << "Enter category to search: ";
    getline(cin, searchCategory);

    cout << "============================ Search Result ====================================="<<endl;

    for (int i = 0; i < total; i++) {
        if (expense[i].category == searchCategory) {
            cout<< "Transaction " << i + 1 << endl;
            cout<< "Type     : " << expense[i].type << endl;
            cout<< "Amount   : " << expense[i].amount << endl;
            cout<< "Date     : " << expense[i].date << endl;
            cout<< "Category : " << expense[i].category << endl;
            cout<< "Note     : " << expense[i].note << endl;
            cout<< "--------------------------------------------------------------------------------\n";
            found=true;
        }
    }

    if (!found) {
        cout<<"No transaction found in this category\n";
    }
}

// function to delete a transaction
void deleteTransaction() {
    if (total == 0) {
        cout << "No transactions to delete\n";
        return;
    }

    int deleteIndex;
    cout << "Enter transaction number to delete: ";
    cin >> deleteIndex;
    cin.ignore();

    if (deleteIndex < 1 || deleteIndex > total) {
        cout << "Invalid transaction number\n";
        return;
    }

    for (int i = deleteIndex - 1; i < total - 1; i++) {
        expense[i] = expense[i + 1];
    }

    total--;
    saveToFile();

    cout << "Transaction deleted successfully\n";
}

// function to save all transactions to file
void saveToFile() {
    ofstream file("expenses.txt");

    if (!file) {
        cout << "Error opening file\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        file << expense[i].type << endl;
        file << expense[i].amount << endl;
        file << expense[i].date << endl;
        file << expense[i].category << endl;
        file << expense[i].note << endl;
    }

    file.close();
}

// function to load transactions from file
void loadFromFile() {
    ifstream file("expenses.txt");

    if (!file) {
        return;
    }

    total = 0;

    while (total < MAX && getline(file, expense[total].type)) {
        file >> expense[total].amount;
        file.ignore();

        getline(file, expense[total].date);
        getline(file, expense[total].category);
        getline(file, expense[total].note);

        total++;
    }

    file.close();
}