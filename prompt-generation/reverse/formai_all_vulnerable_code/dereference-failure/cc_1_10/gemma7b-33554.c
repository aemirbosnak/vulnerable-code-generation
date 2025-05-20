//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[256];
    char author[256];
    int pages;
    struct Book* next;
} Book;

typedef struct Library {
    Book* head;
    Book* tail;
} Library;

Library* createLibrary() {
    Library* library = (Library*)malloc(sizeof(Library));
    library->head = NULL;
    library->tail = NULL;
    return library;
}

void addBookToLibrary(Library* library, char* title, char* author, int pages) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->pages = pages;
    newBook->next = NULL;

    if (library->head == NULL) {
        library->head = newBook;
        library->tail = newBook;
    } else {
        library->tail->next = newBook;
        library->tail = newBook;
    }
}

void printBooksInLibrary(Library* library) {
    Book* currentBook = library->head;
    while (currentBook) {
        printf("%s by %s, %d pages\n", currentBook->title, currentBook->author, currentBook->pages);
        currentBook = currentBook->next;
    }
}

int main() {
    Library* library = createLibrary();

    addBookToLibrary(library, "The Lord of the Flies", "William Golding", 200);
    addBookToLibrary(library, "The Great Gatsby", "F. Scott Fitzgerald", 180);
    addBookToLibrary(library, "To Kill a Mockingbird", "Harper Lee", 220);

    printBooksInLibrary(library);

    return 0;
}