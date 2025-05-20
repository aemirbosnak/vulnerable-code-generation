//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char name[50];  // Book name
    int author[5];  // Author's name
    int publisher[5];  // Publisher's name
    int year[4];  // Year of publication
    int pages[3];  // Number of pages
    int avail[2];  // Availability (0 = not available, 1 = available)
} book_t;

// Define database
book_t books[10];

// Function to add a book to the database
void add_book(char *name, int author, int publisher, int year, int pages) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(books[i].name, name) == 0) {
            printf("Error: Book already exists in the database.\n");
            return;
        }
    }
    strcpy(books[i].name, name);
    books[i].author[0] = author;
    books[i].publisher[0] = publisher;
    books[i].year[0] = year;
    books[i].pages[0] = pages;
    books[i].avail[0] = 1;
}

// Function to borrow a book
void borrow_book(int borrower_id, int book_id) {
    book_t *book = &books[book_id];
    if (book->avail[0] == 0) {
        printf("Error: Book is not available for borrowing.\n");
        return;
    }
    book->avail[0] = 0;
    printf("User %d has borrowed book %d successfully.\n", borrower_id, book_id);
}

// Function to return a book
void return_book(int borrower_id, int book_id) {
    book_t *book = &books[book_id];
    if (book->avail[0] == 1) {
        printf("Error: Book is already returned by another user.\n");
        return;
    }
    book->avail[0] = 1;
    printf("User %d has returned book %d successfully.\n", borrower_id, book_id);
}

// Function to view the database
void view_database() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d. %s (%d, %d, %d, %d, %d)\n", i + 1, books[i].name, books[i].author[0], books[i].publisher[0], books[i].year[0], books[i].pages[0], books[i].avail[0]);
    }
}

int main() {
    // Add some books to the database
    add_book("Harry Potter", 1, "J.K. Rowling", 2001, 784);
    add_book("The Great Gatsby", 2, "F. Scott Fitzgerald", 1925, 410);
    add_book("To Kill a Mockingbird", 3, "Harper Lee", 1960, 474);

    // Borrow and return some books
    borrow_book(1, 1);  // Borrow Harry Potter
    return_book(1, 1);  // Return Harry Potter
    borrow_book(2, 2);  // Borrow The Great Gatsby
    return_book(2, 2);  // Return The Great Gatsby

    // View the database
    view_database();

    return 0;
}