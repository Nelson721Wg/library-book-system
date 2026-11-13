// main.cpp - Main application for the Community Library system
#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

using namespace std;

const int NUM_BOOKS = 5;

void displayAllBooks(const Book books[], int size) {
    cout << "\n" << left << setw(32) << "Title" << setw(22) << "Author"
         << setw(16) << "ISBN" << setw(12) << "Status" << "Date Added" << endl;
    cout << string(94, '-') << endl;
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
    }
    cout << endl;
}

int main() {
    Book library[NUM_BOOKS];

    // Initialise the array with 5 books (stored unsorted on purpose)
    library[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", true,  "2024-02-10");
    library[1].setBookDetails("1984", "George Orwell", "9780451524935", true,  "2024-03-05");
    library[2].setBookDetails("To Kill a Mockingbird", "Harper Lee", "9780061120084", false, "2024-01-20");
    library[3].setBookDetails("Pride and Prejudice", "Jane Austen", "9780141439518", true,  "2024-04-18");
    library[4].setBookDetails("The Hobbit", "J.R.R. Tolkien", "9780547928227", true,  "2024-05-02");

    // Sort the book data by ISBN, then show the collection
    Book::sortBookData(library, NUM_BOOKS);
    cout << "=== Community Library Book Management System ===" << endl;
    displayAllBooks(library, NUM_BOOKS);

    string inputISBN;
    while (true) {
        cout << "Enter the ISBN of the book you wish to borrow (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Thank you for using the library system. Goodbye!" << endl;
            break;
        }

        bool found = false;
        for (int i = 0; i < NUM_BOOKS; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                if (library[i].borrowBook()) {
                    cout << "Success: the book has been borrowed." << endl;
                    library[i].displayBookDetails();
                } else {
                    cout << "Error: this book is currently unavailable (already borrowed)." << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "Error: no book found with ISBN " << inputISBN << "." << endl;
        }
    }
    return 0;
}
