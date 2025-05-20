//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
struct Book {
    char title[50];
    char author[50];
    int year;
    float price;
};

// Database
struct Database {
    int size;
    struct Book *books;
};

// Initialization function
void initialize(struct Database *db) {
    db->size = 0;
    db->books = NULL;
}

// Add book function
void add_book(struct Database *db, struct Book book) {
    // Increase size
    db->size++;

    // Reallocate memory for books
    db->books = (struct Book*)realloc(db->books, db->size * sizeof(struct Book));

    // Add book to database
    db->books[db->size-1] = book;
}

// List books function
void list_books(struct Database db) {
    printf("\nList of Books:\n");
    printf("--------------------\n");
    for(int i=0; i<db.size; i++) {
        printf("Title: %s\n", db.books[i].title);
        printf("Author: %s\n", db.books[i].author);
        printf("Year: %d\n", db.books[i].year);
        printf("Price: $%.2f\n", db.books[i].price);
        printf("--------------------\n");
    }
    printf("Total books: %d\n", db.size);
}

// Search book function
void search_book(struct Database db) {
    char search_title[50];
    printf("\nEnter title to search: ");
    scanf("%s", search_title);

    int found = 0;
    for(int i=0; i<db.size; i++) {
        if(strcmp(db.books[i].title, search_title) == 0) {
            printf("\nBook Found!\n");
            printf("Title: %s\n", db.books[i].title);
            printf("Author: %s\n", db.books[i].author);
            printf("Year: %d\n", db.books[i].year);
            printf("Price: $%.2f\n", db.books[i].price);
            printf("--------------------\n");

            found = 1;
        }
    }

    if(!found) {
        printf("\nBook not found!\n");
    }
}

int main() {
    struct Database bookstore;
    initialize(&bookstore);

    // Add books
    struct Book book1 = {"The Hunger Games", "Suzanne Collins", 2008, 12.99};
    add_book(&bookstore, book1);
    struct Book book2 = {"To Kill a Mockingbird", "Harper Lee", 1960, 9.99};
    add_book(&bookstore, book2);
    struct Book book3 = {"1984", "George Orwell", 1949, 7.99};
    add_book(&bookstore, book3);

    // List books
    list_books(bookstore);

    // Search book
    search_book(bookstore);

    return 0;
}