// test_book.cpp - Simple unit tests for the Book class (ICT0008 A2)
// Compile: g++ -std=c++11 test_book.cpp Book.cpp -o test_book
#include <cassert>
#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    Book b;
    b.setBookDetails("Test Book", "Test Author", "111", true, "2024-01-01");

    // borrowBook(): succeeds only when the book is available
    assert(b.isAvailable() == true);
    assert(b.borrowBook() == true);     // first borrow works
    assert(b.isAvailable() == false);
    assert(b.borrowBook() == false);    // second borrow must fail

    // returnBook(): succeeds only when the book is borrowed
    assert(b.returnBook() == true);     // return works
    assert(b.isAvailable() == true);
    assert(b.returnBook() == false);    // returning an available book fails

    // sortBookData(): sorts by ISBN ascending
    Book arr[3];
    arr[0].setBookDetails("C", "X", "300", true, "2024-01-01");
    arr[1].setBookDetails("A", "X", "100", true, "2024-01-01");
    arr[2].setBookDetails("B", "X", "200", true, "2024-01-01");
    Book::sortBookData(arr, 3);
    assert(arr[0].getISBN() == "100");
    assert(arr[1].getISBN() == "200");
    assert(arr[2].getISBN() == "300");

    cout << "All Book class tests passed." << endl;
    return 0;
}
