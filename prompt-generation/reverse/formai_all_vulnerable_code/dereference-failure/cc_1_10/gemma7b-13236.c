//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the structure of a book
typedef struct Book {
    char title[256];
    char author[256];
    int year;
    struct Book* next;
} Book;

// Define the hashing function
int hash(char* str) {
    int hash_val = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_val = hash_val * 33 + str[i];
    }
    return hash_val;
}

// Define the index structure
typedef struct Index {
    int key;
    struct Index* next;
} Index;

// Create a book node
Book* createBook(char* title, char* author, int year) {
    Book* book = (Book*)malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->year = year;
    book->next = NULL;
    return book;
}

// Insert a book into the index
void insertBook(Index** head, Book* book) {
    Index* index = (Index*)malloc(sizeof(Index));
    index->key = hash(book->title);
    index->next = NULL;

    if (*head == NULL) {
        *head = index;
    } else {
        Index* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = index;
    }
}

// Search for a book in the index
Book* searchBook(Index* head, char* title) {
    Index* current = head;
    while (current) {
        if (hash(title) == current->key) {
            Book* book = (Book*)malloc(sizeof(Book));
            book = current->next;
            return book;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Book* head = NULL;
    insertBook(&head, createBook("The Lord of the Flies", "William Golding", 1954));
    insertBook(&head, createBook("To Kill a Mockingbird", "Harper Lee", 1960));
    insertBook(&head, createBook("The Great Gatsby", "F. Scott Fitzgerald", 1925));

    Book* book = searchBook(head, "The Lord of the Flies");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Year: %d\n", book->year);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}