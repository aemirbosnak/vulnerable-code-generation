//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Library {
    char* name;
    char* address;
    char* phone_number;
    int num_books;
};

struct Book {
    char* title;
    char* author;
    char* ISBN;
    int num_copies;
};

void create_library(struct Library* lib) {
    lib->name = malloc(100);
    lib->address = malloc(100);
    lib->phone_number = malloc(20);
    lib->num_books = 0;
}

void add_book(struct Library* lib, struct Book* book) {
    lib->num_books++;
}

void delete_book(struct Library* lib, int index) {
    lib->num_books--;
}

void display_library(struct Library* lib) {
    printf("Library Name: %s\n", lib->name);
    printf("Address: %s\n", lib->address);
    printf("Phone Number: %s\n", lib->phone_number);
    printf("Number of Books: %d\n", lib->num_books);
}

int main() {
    struct Library* library = malloc(sizeof(struct Library));
    create_library(library);

    struct Book* book1 = malloc(sizeof(struct Book));
    book1->title = "The Great Gatsby";
    book1->author = "F. Scott Fitzgerald";
    book1->ISBN = "978-0-06-093546-1";
    book1->num_copies = 3;
    add_book(library, book1);

    struct Book* book2 = malloc(sizeof(struct Book));
    book2->title = "To Kill a Mockingbird";
    book2->author = "Harper Lee";
    book2->ISBN = "978-0-06-093546-1";
    book2->num_copies = 2;
    add_book(library, book2);

    display_library(library);

    delete_book(library, 1);
    display_library(library);

    free(library->name);
    free(library->address);
    free(library->phone_number);
    free(library);

    return 0;
}