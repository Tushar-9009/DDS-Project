# 💰 Personal Finance Tracker (C++)

# 📌 Overview

The Personal Finance Tracker is a simple C++ project that helps users keep track of their income and expenses.
It allows adding, viewing, searching, filtering, and sorting financial transactions.
Data is stored persistently using file handling, so records are saved between program runs.

This project demonstrates the use of core Data Structures concepts in a real-world scenario, making it ideal for learning and interviews.

# 🚀 Features

➕ Add income or expense transactions

📄 Display all transactions in a table format

🔍 Filter expenses above a given amount

🔀 Sort transactions by amount

💾 Save transactions to file (transactions.txt)

📂 Load saved transactions at program startup

# 🏗 Data Structures Used

Struct (Transaction) → To store transaction details (type, category, amount, date)

Vector (STL) → Dynamic storage of multiple transactions

Sorting (STL sort) → To arrange transactions by amount

File I/O (fstream) → Persistent storage of transactions in a text file

# ▶ How to Run

1) git clone https://github.com/Tushar-9009/Personal-Finance-Tracker.git

cd Personal-Finance-Tracker/src

2) Compile the code

g++ finance_tracker.cpp -o finance_tracker

3) Run the program

 ./finance_tracker
