# Library-Management-System-using-Data-Structures

## Overview
Library Management System is a simple console application implemented in **C++** using linked lists. The system allows users to perform basic library operations such as issuing books, returning issued books, and displaying records of issued books along with user details.

## Features
- Each book in the library has a unique identification number (Book ID).
- Users can issue books by entering the Book ID and their personal details.
- Each user can issue only one book at a time.
- When a user returns a book, the book becomes available for issuing again.
- View records of all issued books with corresponding user details.

## How It Works
- The library maintains a linked list of books currently available.
- When a book is issued, it is removed from the available books list and added to the issued books linked list with user details.
- Upon returning, the book is removed from the issued list and added back to the available books list.
- The system provides a menu-driven interface for ease of use.

## Usage
1. Compile the program using a C++ compiler (e.g., g++).
2. Run the executable in a console/terminal.
3. Follow on-screen instructions to issue or return books, and view issued book records.

## Data Structures Used
