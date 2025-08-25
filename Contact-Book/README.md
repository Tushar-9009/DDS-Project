# 📒 Contact Book (C++)

# 📌 Overview

The Contact Book is a C++ program that allows users to store, search, update, and delete contacts.
Each contact contains a name, phone number, and email address. The program uses a Linked List to manage contacts in memory and keeps them sorted alphabetically by name.

Contacts are also stored in a file (contacts.txt) so that the data is not lost when the program exits.

This project demonstrates the use of self-referential structures, dynamic memory, linked lists, and file handling.

# 🚀 Features

➕ Add Contact → Add a new contact (name, phone, email)

📄 Display Contacts → View all stored contacts in alphabetical order

🔍 Search Contact → Search by name and display details

✏ Update Contact → Edit phone/email of an existing contact

❌ Delete Contact → Remove a contact by name

💾 Save & Load → Automatically saves to contacts.txt and loads at startup

# 🏗 Data Structures Used

Struct (Contact) → Stores details (name, phone, email)

# ▶ How to Run

1. Clone the repository

git clone https://github.com/Tushar-9009/Contact-Book.git

cd Contact-Book/src

2. Compile the program

g++ contact_book.cpp -o contact_book

3. Run the program
   
./contact_book

Singly Linked List (Self-referential) → Each contact points to the next

Dynamic Memory Allocation (new / delete) → For adding/removing contacts

File Handling (fstream) → To persist contacts across program runs

Sorted Insertion → Contacts are inserted in alphabetical order by name
