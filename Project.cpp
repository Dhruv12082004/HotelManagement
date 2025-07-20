#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Class to represent a time slot booking
class Booking {
public:
    string host;
    string startTime;
    string endTime;
    string from;
    string to;

    Booking(string h, string st, string et, string f, string t)
        : host(h), startTime(st), endTime(et), from(f), to(t) {}

    // Check for time conflict with another booking
    bool conflictsWith(const Booking& other) const {
        return (startTime < other.endTime && endTime > other.startTime);
    }
};

// Hotel class managing a fixed set of room numbers
class Hotel {
private:
    vector<string> allowedRooms = {"101", "102", "103", "104", "105", "106", "107", "108", "109", "110"};
    unordered_map<string, vector<Booking>> bookings; // key = roomNumber, value = all bookings

public:
    // Checks if the room number is in the allowed list
    bool isValidRoom(const string& roomNumber) const {
        return find(allowedRooms.begin(), allowedRooms.end(), roomNumber) != allowedRooms.end();
    }

    void bookRoom() {
        string roomNumber, host, startTime, endTime, from, to;
        cout << "Enter Room Number (101 to 110): ";
        cin >> roomNumber;

        if (!isValidRoom(roomNumber)) {
            cout << "Invalid room number. Only rooms 101–110 can be booked.\n";
            return;
        }

        cout << "Enter Host Name: ";
        cin >> host;
        cout << "Start Time (e.g., 10:00): ";
        cin >> startTime;
        cout << "End Time (e.g., 11:00): ";
        cin >> endTime;
        cout << "From: ";
        cin >> from;
        cout << "To: ";
        cin >> to;

        Booking newBooking(host, startTime, endTime, from, to);

        for (const Booking& existing : bookings[roomNumber]) {
            if (existing.conflictsWith(newBooking)) {
                cout << "Time conflict with existing booking in Room " << roomNumber << ".\n";
                return;
            }
        }

        bookings[roomNumber].push_back(newBooking);
        cout << "Room " << roomNumber << " booked successfully!\n";
    }

    void showRoomDetails() const {
        string roomNumber;
        cout << "Enter Room Number to show bookings: ";
        cin >> roomNumber;

        if (!isValidRoom(roomNumber)) {
            cout << "Invalid room number.\n";
            return;
        }

        auto it = bookings.find(roomNumber);
        if (it == bookings.end() || it->second.empty()) {
            cout << "No bookings found for Room " << roomNumber << ".\n";
            return;
        }

        cout << "\nBookings for Room " << roomNumber << ":\n";
        cout << left << setw(15) << "Host" << setw(10) << "Start" << setw(10) << "End" << setw(10) << "From" << setw(10) << "To" << "\n";
        for (const Booking& b : it->second) {
            cout << left << setw(15) << b.host << setw(10) << b.startTime << setw(10) << b.endTime
                 << setw(10) << b.from << setw(10) << b.to << "\n";
        }
    }

  void listAllRooms() const {
    cout << "\n========== Room Summary ==========\n";
    cout << left << setw(10) << "Room No"
         << setw(15) << "Bookings"
         << setw(15) << "Status"
         << "Time Slots\n";
    cout << "--------------------------------------------------------------\n";

    for (const string& room : allowedRooms) {
        int count = bookings.count(room) ? bookings.at(room).size() : 0;
        string status = (count == 0) ? "Available" : "Occupied";

        cout << left << setw(10) << room
             << setw(15) << count
             << setw(15) << status;

        // Display all time slots if any
        if (count == 0) {
            cout << " -\n";
        } else {
            for (const auto& entry : bookings.at(room)) {
                cout << "[" << entry.startTime << " - " << entry.endTime << "] ";
            }
            cout << "\n";
        }
    }
}


};

// Main driver
int main() {
    Hotel hotel;
    int choice;
    do {
        cout << "\n===== Hotel Room Booking System =====\n";
        cout << "1. Book a Room\n";
        cout << "2. Show Room Details\n";
        cout << "3. List All Rooms\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: hotel.bookRoom(); break;
            case 2: hotel.showRoomDetails(); break;
            case 3: hotel.listAllRooms(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 4);

    return 0;
}
