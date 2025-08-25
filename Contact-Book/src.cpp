#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
    Contact* next;
};

Contact* head = nullptr;

Contact* createContact(string name, string phone, string email) {
    Contact* newContact = new Contact;
    newContact->name = name;
    newContact->phone = phone;
    newContact->email = email;
    newContact->next = nullptr;
    return newContact;
}

void addContact() {
    string name, phone, email;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Phone: ";
    cin >> phone;
    cout << "Enter Email: ";
    cin >> email;

    Contact* newContact = createContact(name, phone, email);

    if (head == nullptr || name < head->name) {
        newContact->next = head;
        head = newContact;
    } else {
        Contact* temp = head;
        while (temp->next != nullptr && temp->next->name < name) {
            temp = temp->next;
        }
        newContact->next = temp->next;
        temp->next = newContact;
    }

    cout << "Contact added successfully!\n";
}

void displayContacts() {
    if (head == nullptr) {
        cout << "No contacts available.\n";
        return;
    }

    cout << "\n--- Contact List ---\n";
    Contact* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name
             << " | Phone: " << temp->phone
             << " | Email: " << temp->email << "\n";
        temp = temp->next;
    }
}

void searchContact() {
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    Contact* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            cout << "Contact Found!\n";
            cout << "Name: " << temp->name
                 << " | Phone: " << temp->phone
                 << " | Email: " << temp->email << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Contact not found.\n";
}

void updateContact() {
    string name;
    cout << "Enter name to update: ";
    cin >> name;

    Contact* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            cout << "Enter new Phone: ";
            cin >> temp->phone;
            cout << "Enter new Email: ";
            cin >> temp->email;
            cout << "Contact updated!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Contact not found.\n";
}

void deleteContact() {
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    Contact* temp = head;
    Contact* prev = nullptr;

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Contact not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Contact deleted!\n";
}

void saveToFile() {
    ofstream file("contacts.txt");
    Contact* temp = head;
    while (temp != nullptr) {
        file << temp->name << " " << temp->phone << " " << temp->email << "\n";
        temp = temp->next;
    }
    file.close();
    cout << "Contacts saved to contacts.txt!\n";
}

void loadFromFile() {
    ifstream file("contacts.txt");
    if (!file) {
        cout << "No saved contacts found.\n";
        return;
    }

    string name, phone, email;
    while (file >> name >> phone >> email) {
        Contact* newContact = createContact(name, phone, email);

        if (head == nullptr || name < head->name) {
            newContact->next = head;
            head = newContact;
        } else {
            Contact* temp = head;
            while (temp->next != nullptr && temp->next->name < name) {
                temp = temp->next;
            }
            newContact->next = temp->next;
            temp->next = newContact;
        }
    }

    file.close();
    cout << "Contacts loaded from contacts.txt!\n";
}

int main() {
    int choice;
    loadFromFile();

    while (true) {
        cout << "\n===== Contact Book =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addContact(); break;
        case 2: displayContacts(); break;
        case 3: searchContact(); break;
        case 4: updateContact(); break;
        case 5: deleteContact(); break;
        case 6: saveToFile(); 
                cout << "Exiting program...\n";
                return 0;
        default: cout << "Invalid choice!\n";
        }
    }
}
