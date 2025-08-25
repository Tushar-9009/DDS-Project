#include <iostream>
#include <string>
using namespace std;

struct Car {
    string license;
    string owner;
    string entryTime;
    Car* next;
};

Car* head = nullptr;
int capacity = 5;
int count = 0;

void parkCar() {
    if (count >= capacity) {
        cout << "Parking Lot Full! Cannot add more cars.\n";
        return;
    }

    Car* newCar = new Car;
    cout << "Enter License Number: ";
    cin >> newCar->license;
    cout << "Enter Owner Name: ";
    cin >> newCar->owner;
    cout << "Enter Entry Time (HH:MM): ";
    cin >> newCar->entryTime;

    newCar->next = nullptr;

    if (head == nullptr) {
        head = newCar;
    } else {
        Car* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newCar;
    }

    count++;
    cout << "Car parked successfully!\n";
}

void exitCar() {
    if (head == nullptr) {
        cout << "No cars in the parking lot.\n";
        return;
    }

    string license;
    cout << "Enter License Number to remove: ";
    cin >> license;

    Car* temp = head;
    Car* prev = nullptr;

    while (temp != nullptr && temp->license != license) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Car with license " << license << " not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    count--;
    cout << "Car with license " << license << " has exited.\n";
}

void displayCars() {
    if (head == nullptr) {
        cout << "No cars currently parked.\n";
        return;
    }

    cout << "\n--- Parked Cars (" << count << "/" << capacity << ") ---\n";
    Car* temp = head;
    while (temp != nullptr) {
        cout << "License: " << temp->license
             << " | Owner: " << temp->owner
             << " | Entry Time: " << temp->entryTime << "\n";
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Smart Parking Lot Management =====\n";
        cout << "1. Park a Car\n";
        cout << "2. Exit a Car\n";
        cout << "3. Display Parked Cars\n";
        cout << "4. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: parkCar(); break;
        case 2: exitCar(); break;
        case 3: displayCars(); break;
        case 4: cout << "Exiting system...\n"; return 0;
        default: cout << "Invalid choice!\n";
        }
    }
}
