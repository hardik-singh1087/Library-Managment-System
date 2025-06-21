#include <iostream>
#include <string>
#include <cstdlib>  // for system
using namespace std;

struct Book {
    string name;
    string author;
    int id;
    Book* next = nullptr;
};

struct Student {
    string name;
    string email;
    string book;
    string author;
    int id;
    Student* next = nullptr;
};

Book* start_lib = nullptr;
Student* start = nullptr;

Book* initialize_lib(Book*);
Student* book_issue(Student*);
Student* book_return(Student*);
void display_students(Student*);
Book* delete_book(int);
Book* add_book(const string&, const string&, int);
void greetings();
void main_menu();

int main() {
    start_lib = initialize_lib(start_lib);
    greetings();
    main_menu();
    return 0;
}

void greetings() {
    cout << "\n\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *     ----------------------------     *\n";
    cout << "\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n";
    cout << "\t\t\t     *     ----------------------------     *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\n\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *       ------------------------       *\n";
    cout << "\t\t\t     *           STUDENT LIBRARY            *\n";
    cout << "\t\t\t     *       ------------------------       *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *       KOTA, Rajasthan, India.        *\n";
    cout << "\t\t\t     *     Email: studentlib@gmail.com      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\n\n\t\t\t             Press Enter to continue: ";
    cin.ignore();
    cin.get();
}

void main_menu() {
    int choice;
    do {
        cout << "\n\n";
        cout << "\n\t\t\t*************************************************\n";
        cout << "\n\t\t\t\t      MAIN MENU: ";
        cout << "\n\t\t\t\t     1. ISSUE OF BOOKS ";
        cout << "\n\t\t\t\t     2. RETURN OF BOOKS ";
        cout << "\n\t\t\t\t     3. DISPLAY STUDENT DETAILS ";
        cout << "\n\t\t\t\t     4. EXIT\n ";
        cout << "\n\t\t\t*************************************************\n";
        cout << "\n\t\t\t\t      Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to consume newline after number input

        switch (choice) {
            case 1:
                start = book_issue(start);
                break;
            case 2:
                start = book_return(start);
                break;
            case 3:
                display_students(start);
                break;
            case 4:
                exit(0);
            default:
                cout << "\n\t\t\t\t      ...Invalid Option!...\n";
                cout << "\n\t\t\t\t      Press Enter to try again: ";
                cin.get();
        }
        system("cls");  // or "clear" if on Linux/macOS
    } while (choice != 4);
}

Book* initialize_lib(Book* start) {
    Book* ptr;
    Book* new_book1 = new Book{"The Kite Runner", "Khaled Hosseini", 101, nullptr};
    start_lib = new_book1;
    ptr = new_book1;

    Book* new_book2 = new Book{"To Kill A Mockingbird", "Harper Lee", 102, nullptr};
    ptr->next = new_book2;
    ptr = new_book2;

    Book* new_book3 = new Book{"The Alchemist", "Paulo Coelho", 103, nullptr};
    ptr->next = new_book3;
    ptr = new_book3;

    Book* new_book4 = new Book{"Pride And Prejudice", "Jane Austen", 104, nullptr};
    ptr->next = new_book4;
    ptr = new_book4;

    Book* new_book5 = new Book{"A Tale Of Two Cities", "Charles Dickens", 105, nullptr};
    ptr->next = new_book5;

    return start_lib;
}

Student* book_issue(Student* start) {
    if (start_lib == nullptr) {
        cout << "\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n";
        return start;
    }

    system("cls");
    Book* ptr = start_lib;
    int i = 1;
    cout << "\n\t*************** Books Available: ****************\n";
    while (ptr != nullptr) {
        cout << "\n\t_________________________________________________\n";
        cout << "\n\t Book " << i++;
        cout << "\n\t Book Title: " << ptr->name;
        cout << "\n\t Name of Author: " << ptr->author;
        cout << "\n\t Book ID: " << ptr->id;
        cout << "\n\t_________________________________________________\n";
        ptr = ptr->next;
    }
    cout << "\n\n\t Enter the Book ID: ";
    int id;
    cin >> id;
    cin.ignore();

    ptr = start_lib;
    bool found = false;
    while (ptr != nullptr) {
        if (ptr->id == id) {
            found = true;
            break;
        }
        ptr = ptr->next;
    }

    if (found) {
        Student* new_student = new Student;
        cout << "\n\t Enter Student Details:\n ";
        cout << "\n\t Enter your Name: ";
        getline(cin, new_student->name);
        cout << "\n\t Enter your Email: ";
        getline(cin, new_student->email);

        // Set book info
        ptr = start_lib;
        while (ptr->id != id) {
            ptr = ptr->next;
        }
        new_student->book = ptr->name;
        new_student->author = ptr->author;
        new_student->id = ptr->id;
        new_student->next = nullptr;

        cout << "\n\t Issue of Book ID " << new_student->id << " done successfully!\n";
        cout << "\n\n\t*************************************************\n";

        if (start == nullptr) {
            start = new_student;
        } else {
            Student* ptr2 = start;
            while (ptr2->next != nullptr) {
                ptr2 = ptr2->next;
            }
            ptr2->next = new_student;
        }
        start_lib = delete_book(new_student->id);
        cout << "\n\n\t Press Enter to go to the main menu: ";
        cin.get();
        system("cls");
    } else {
        cout << "\n\t\t      ...Invalid Option!...\n";
        cout << "\n\t\t      Press Enter to try again: ";
        cin.get();
        system("cls");
    }
    return start;
}

Student* book_return(Student* start) {
    cout << "\n\n\t*************** Books Submission: ****************\n";
    cout << "\n\n\t Enter your Book ID: ";
    int identity;
    cin >> identity;
    cin.ignore();

    Student* ptr = start;
    Student* preptr = nullptr;
    bool found = false;
    while (ptr != nullptr) {
        if (ptr->id == identity) {
            found = true;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }

    if (found) {
        cout << "\n\t_________________________________________________\n";
        cout << "\n\t Student Name: " << ptr->name;
        cout << "\n\t Student Email: " << ptr->email;
        cout << "\n\t Name of Book Issued: " << ptr->book;
        cout << "\n\t Book ID: " << ptr->id;
        cout << "\n\t_________________________________________________\n";

        string bookname = ptr->book;
        string authorname = ptr->author;
        int id = ptr->id;

        if (ptr == start) { // first node
            start = start->next;
        } else {
            preptr->next = ptr->next;
        }
        delete ptr;
        add_book(bookname, authorname, id);

        cout << "\n\n\t Return of Book ID " << identity << " done successfully!\n";
        cout << "\n\t Thank you! \n\t Do visit again! ";
        cout << "\n\n\t Press Enter to go to the main menu: ";
        cin.get();
        system("cls");
    } else {
        cout << "\n\tSorry the book doesn't exist! Please recheck the entered ID";
        cout << "\n\t\t\t\t      Press Enter to try again: ";
        cin.get();
        system("cls");
    }

    return start;
}

void display_students(Student* start) {
    Student* ptr = start;
    while (ptr != nullptr) {
        cout << "\n\t************* Details of Students: **************\n";
        cout << "\n\t_________________________________________________\n";
        cout << "\n\t\t Student Name: " << ptr->name;
        cout << "\n\t\t Student Email: " << ptr->email;
        cout << "\n\t\t Name of Book Issued: " << ptr->book;
        cout << "\n\t\t Book ID: " << ptr->id;
        cout << "\n\t_________________________________________________\n";
        cout << "\n\n\t*************************************************\n";
        ptr = ptr->next;
    }
    cout << "\n\n\t Press Enter to go to the main menu: ";
    cin.get();
    system("cls");
}

Book* delete_book(int id) {
    if (start_lib == nullptr) return nullptr;

    if (start_lib->id == id) {
        Book* temp = start_lib;
        start_lib = start_lib->next;
        delete temp;
        return start_lib;
    }

    Book* ptr = start_lib;
    Book* preptr = nullptr;

    while (ptr != nullptr && ptr->id != id) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr != nullptr) {
        preptr->next = ptr->next;
        delete ptr;
    }
    return start_lib;
}

Book* add_book(const string& bookname, const string& authorname, int id) {
    Book* new_book = new Book{bookname, authorname, id, nullptr};
    if (start_lib == nullptr) {
        start_lib = new_book;
    } else {
        Book* ptr = start_lib;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new_book;
    }
    return start_lib;
}
