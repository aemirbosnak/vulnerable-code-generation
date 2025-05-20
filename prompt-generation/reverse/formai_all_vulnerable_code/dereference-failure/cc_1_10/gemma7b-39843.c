//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[256];
    char author[256];
    char genre[256];
    int pages;
    struct Book* nextBook;
} Book;

Book* createBook(char* title, char* author, char* genre, int pages) {
    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    newBook->pages = pages;
    newBook->nextBook = NULL;

    return newBook;
}

void addBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        head->nextBook = newBook;
        head = newBook;
    }
}

int main() {
    Book* library = NULL;
    Book* newBook = createBook("The Lord of the Flies", "William Golding", "Classic", 200);
    addBook(library, newBook);

    newBook = createBook("To Kill a Mockingbird", "Harper Lee", "Classic", 250);
    addBook(library, newBook);

    newBook = createBook("The Great Gatsby", "F. Scott Fitzgerald", "Classic", 220);
    addBook(library, newBook);

    newBook = createBook("The Catcher in the Rye", "J.D. Salinger", "Classic", 200);
    addBook(library, newBook);

    newBook = createBook("The Joy of Living", "William Shakespeare", "Classic", 280);
    addBook(library, newBook);

    // Print the library
    Book* currentBook = library;
    while (currentBook) {
        printf("%s by %s (%d pages)\n", currentBook->title, currentBook->author, currentBook->pages);
        currentBook = currentBook->nextBook;
    }

    return 0;
}