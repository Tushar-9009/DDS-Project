#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Transaction {
    string type;
    string category;
    float amount;
    string date;
};

vector<Transaction> transactions;

void addTransaction() {
    Transaction t;
    cout << "What type of transaction is it (Income/Expense)? ";
    cin >> t.type;
    cout << "What category does it belong to? ";
    cin >> t.category;
    cout << "How much is the amount? ";
    cin >> t.amount;
    cout << "When did this happen? (DD/MM/YYYY): ";
    cin >> t.date;

    transactions.push_back(t);
    cout << "✅ Transaction added successfully!\n";
}

void displayTransactions() {
    cout << "\n--- All Transactions ---\n";
    cout << left << setw(10) << "Type" 
         << setw(15) << "Category" 
         << setw(10) << "Amount" 
         << setw(12) << "Date" << "\n";
    cout << "-----------------------------------------\n";

    for (const auto &t : transactions) {
        cout << left << setw(10) << t.type
             << setw(15) << t.category
             << setw(10) << t.amount
             << setw(12) << t.date << "\n";
    }
}

void saveToFile() {
    ofstream file("transactions.txt");
    if (!file) {
        cout << "⚠ Oops! There was an error opening the file for writing.\n";
        return;
    }

    for (const auto &t : transactions) {
        file << t.type << " " 
             << t.category << " " 
             << t.amount << " " 
             << t.date << "\n";
    }

    file.close();
    cout << "💾 Your data has been saved to transactions.txt!\n";
}

void loadFromFile() {
    ifstream file("transactions.txt");
    if (!file) {
        cout << "⚠ No previous data found. Starting fresh.\n";
        return;
    }

    transactions.clear();
    Transaction t;
    while (file >> t.type >> t.category >> t.amount >> t.date) {
        transactions.push_back(t);
    }

    file.close();
    cout << "📂 Data loaded from transactions.txt!\n";
}

void filterExpenses() {
    float limit;
    cout << "Enter the amount to filter expenses: ";
    cin >> limit;

    cout << "\n--- Expenses above " << limit << " ---\n";
    for (const auto &t : transactions) {
        if (t.type == "Expense" && t.amount > limit) {
            cout << t.type << " | " 
                 << t.category << " | " 
                 << t.amount << " | " 
                 << t.date << "\n";
        }
    }
}

void sortByAmount() {
    sort(transactions.begin(), transactions.end(), 
         [](const Transaction &a, const Transaction &b) {
             return a.amount < b.amount;
         });

    cout << "🔀 Transactions sorted by amount!\n";
}

int main() {
    int choice;
    loadFromFile();

    while (true) {
        cout << "\n===== Personal Finance Tracker =====\n";
        cout << "1. Add Transaction\n";
        cout << "2. View All Transactions\n";
        cout << "3. Filter Expenses > Amount\n";
        cout << "4. Sort by Amount\n";
        cout << "5. Save & Exit\n";
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1: addTransaction(); break;
        case 2: displayTransactions(); break;
        case 3: filterExpenses(); break;
        case 4: sortByAmount(); break;
        case 5: saveToFile(); 
                cout << " Thank you for using the program! Exiting...\n"; 
                return 0;
        default: cout << " That's not a valid choice! Please try again.\n";
        }
    }
}
