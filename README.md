🏨 Hotel Room Booking System (C++ | LLD)

A console-based Hotel Room Booking System built using C++, applying Object-Oriented Programming (OOP) principles and clean Low-Level Design concepts.

This project simulates booking and managing hotel rooms with time-slot conflict handling.

🚀 Features

✅ Book rooms (101–110)

✅ Prevent time-slot conflicts

✅ View bookings for a specific room

✅ List all rooms with status (Available / Occupied)

✅ Display booked time slots

✅ Clean class-based design

🧠 Design Overview (LLD Concepts)
1️⃣ Booking Class

Represents a single booking.

Attributes:

Host name

Start time

End time

From

To

Key Method:

conflictsWith() → Checks if two bookings overlap

2️⃣ Hotel Class

Responsible for:

Managing valid room numbers

Storing bookings using:

unordered_map<string, vector<Booking>>

Key Functions:

bookRoom() → Adds booking after conflict check

showRoomDetails() → Displays bookings of a room

listAllRooms() → Shows summary of all rooms

isValidRoom() → Ensures room number is valid

🔄 Booking Conflict Logic

Two bookings conflict if:

startTime < other.endTime AND endTime > other.startTime

This ensures:

No overlapping time slots

Proper schedule management

🏗️ System Architecture
User
  ↓
Main Menu
  ↓
Hotel Class
  ↓
Booking Class
  ↓
Time Conflict Validation
💻 How to Run
1️⃣ Compile
g++ hotel.cpp -o hotel
2️⃣ Run
./hotel
📌 Sample Menu
1. Book a Room
2. Show Room Details
3. List All Rooms
4. Exit
🎯 OOP Principles Used

✔ Encapsulation (Booking & Hotel classes)

✔ Abstraction (User interacts only through menu)

✔ Separation of Concerns

✔ Clean modular structure

⚡ Future Improvements

Store data in file (persistent storage)

Add date handling

Improve time validation

Add sorting of bookings

Convert to full hotel management system

📚 Learning Outcome

This project strengthens:

OOP design

STL usage (vector, unordered_map)

Conflict detection logic

Basic Low-Level Design structuring
