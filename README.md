# Expense Tracker in C++

A simple **console-based Expense Tracker** made using **C++**.
This project helps users store and manage their **income and expense transactions**. It supports adding records, viewing all transactions, calculating totals, checking balance, searching by category, deleting transactions, and saving data in a file.

## Features

* Add **Income**
* Add **Expense**
* View all transactions
* Show **Total Income**
* Show **Total Expense**
* Show **Current Balance**
* Search transactions by category
* Delete a transaction
* Save data to file
* Load previous data from file when program starts

## Technologies Used

* **C++**
* **File Handling**
* **Structures**
* **Functions**
* **Arrays**

## Project Structure

Each transaction stores:

* **Type** → Income / Expense
* **Amount**
* **Date**
* **Category**
* **Note**

## How It Works

The program shows a menu with different options.
Users can choose to add income or expense records, view all stored transactions, calculate totals, and manage records.

The project also uses **file handling**, so the data is stored in a file named `expenses.txt`.
When the program is run again, the old transaction data is loaded automatically.

## Menu Options

1. Add Income
2. Add Expense
3. View All Transactions
4. Show Total Income
5. Show Total Expense
6. Show Balance
7. Search by Category
8. Delete Transaction
9. Exit

## File Handling

The project stores transaction data in a text file:

`expenses.txt`

This file is used to:

* save all transactions
* load previous transactions when the program starts

## Concepts Used in This Project

This project helped in practicing:

* structures in C++
* arrays of structures
* function-based programming
* loops and conditional statements
* file handling using `ifstream` and `ofstream`


