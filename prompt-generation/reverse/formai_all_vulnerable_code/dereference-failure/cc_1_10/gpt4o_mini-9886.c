//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book *books;
    size_t count;
} BookCollection;

void initializeCollection(BookCollection *collection) {
    collection->books = NULL;
    collection->count = 0;
}

void addBook(BookCollection *collection, const char *title, const char *author, int year) {
    collection->books = realloc(collection->books, (collection->count + 1) * sizeof(Book));
    if (collection->books == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
    strncpy(collection->books[collection->count].title, title, MAX_TITLE_LENGTH - 1);
    collection->books[collection->count].title[MAX_TITLE_LENGTH - 1] = '\0'; // Ensure null termination.
    strncpy(collection->books[collection->count].author, author, MAX_AUTHOR_LENGTH - 1);
    collection->books[collection->count].author[MAX_AUTHOR_LENGTH - 1] = '\0'; // Ensure null termination.
    collection->books[collection->count].year = year;
    collection->count++;
}

void printCollection(const BookCollection *collection) {
    printf("Book Collection: \n");
    for (size_t i = 0; i < collection->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", collection->books[i].title, collection->books[i].author, collection->books[i].year);
    }
}

void freeCollection(BookCollection *collection) {
    free(collection->books);
    collection->books = NULL;
    collection->count = 0;
}

int main() {
    BookCollection myCollection;
    initializeCollection(&myCollection);

    addBook(&myCollection, "1984", "George Orwell", 1949);
    addBook(&myCollection, "Brave New World", "Aldous Huxley", 1932);
    addBook(&myCollection, "Fahrenheit 451", "Ray Bradbury", 1953);
  
    printCollection(&myCollection);

    // Free the allocated memory
    freeCollection(&myCollection);
  
    return 0;
}