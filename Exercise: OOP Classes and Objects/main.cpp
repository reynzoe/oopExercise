#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    string getTitle() {
        return title;
    }

    void displayBookDetails() {
        cout << "Title: " << "Author:   "  << "Year:    " << endl;
        cout <<  title << "     " << author << "    " << year << "  " << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, int year) {
        Book newBook(title, author, year);
        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }

    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
        } else {
            for (size_t i = 0; i < books.size(); i++) {
                cout << "\nBook " << i + 1 << " details:" << endl;
                books[i].displayBookDetails();
            }
        }
    }

    void searchBookByTitle(string title) {
        bool found = false;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                cout << "Book found!" << endl;
                books[i].displayBookDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    do {
        cout << "\nLibrary Management System:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter publication year: ";
                cin >> year;
                library.addBook(title, author, year);
                break;

            case 2:
                library.displayAllBooks();
                break;

            case 3:
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
                break;

            case 4:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
