// Book.cpp - Book class implementation for the Community Library system
#include "Book.h"
#include <iostream>
#include <iomanip>

using namespace std;

Book::Book() : title(""), author(""), isbn(""), available(true), dateAdd("") {}

void Book::setBookDetails(const string& t, const string& a, const string& i,
                          bool avail, const string& date) {
    title = t;
    author = a;
    isbn = i;
    available = avail;
    dateAdd = date;
}

void Book::displayBookDetails() const {
    cout << left << setw(32) << title
         << setw(22) << author
         << setw(16) << isbn
         << setw(12) << (available ? "Available" : "Borrowed")
         << dateAdd << endl;
}

bool Book::borrowBook() {
    if (available) {
        available = false;
        return true;            // Borrow successful
    }
    return false;               // Already borrowed
}

bool Book::returnBook() {
    if (!available) {
        available = true;
        return true;            // Return successful
    }
    return false;               // Book was not borrowed
}

// Insertion sort by ISBN (ascending). Suitable for a small, nearly sorted array.
void Book::sortBookData(Book books[], int size) {
    for (int i = 1; i < size; i++) {
        Book key = books[i];
        int j = i - 1;
        while (j >= 0 && books[j].isbn > key.isbn) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }
