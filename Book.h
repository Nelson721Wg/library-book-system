// Book.h - Book class declaration for the Community Library system (ICT0008 A2)
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;      // Title of the book
    std::string author;     // Author of the book
    std::string isbn;       // Unique identifier of the book
    bool available;         // true = available, false = borrowed
    std::string dateAdd;    // Date the library bought the book (YYYY-MM-DD)

public:
    Book();                 // Default constructor

    // Assigns values to the book's attributes
    void setBookDetails(const std::string& t, const std::string& a,
                        const std::string& i, bool avail,
                        const std::string& date);

    // Displays title, author, ISBN, availability and date added
    void displayBookDetails() const;

    // Marks the book as borrowed (only if it is currently available)
    bool borrowBook();

    // Marks the book as available again (only if it is currently borrowed)
    bool returnBook();

    // Sorts an array of books by ISBN (ascending) using insertion sort
    static void sortBookData(Book books[], int size);

    // Getter used by the main application to search by ISBN
    std::string getISBN() const;
    bool isAvailable() const;
};

#endif