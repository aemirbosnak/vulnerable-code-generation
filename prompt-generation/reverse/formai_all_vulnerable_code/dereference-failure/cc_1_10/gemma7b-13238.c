//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Book {
    char name[MAX_NAME_LENGTH];
    int year;
    struct Book* next;
} Book;

typedef struct Index {
    char name[MAX_NAME_LENGTH];
    int page;
    struct Index* next;
} Index;

Book* insertBook(Book* head, char* name, int year) {
    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->name, name);
    newBook->year = year;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* currentBook = head;
        while (currentBook->next != NULL) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
    }

    return head;
}

Index* insertIndex(Index* head, char* name, int page) {
    Index* newIndex = malloc(sizeof(Index));
    strcpy(newIndex->name, name);
    newIndex->page = page;
    newIndex->next = NULL;

    if (head == NULL) {
        head = newIndex;
    } else {
        Index* currentIndex = head;
        while (currentIndex->next != NULL) {
            currentIndex = currentIndex->next;
        }
        currentIndex->next = newIndex;
    }

    return head;
}

void searchBook(Book* head, char* name) {
    Book* currentBook = head;
    while (currentBook != NULL) {
        if (strcmp(currentBook->name, name) == 0) {
            printf("Book: %s, Year: %d\n", currentBook->name, currentBook->year);
            break;
        }
        currentBook = currentBook->next;
    }

    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

void searchIndex(Index* head, char* name) {
    Index* currentIndex = head;
    while (currentIndex != NULL) {
        if (strcmp(currentIndex->name, name) == 0) {
            printf("Page: %d\n", currentIndex->page);
            break;
        }
        currentIndex = currentIndex->next;
    }

    if (currentIndex == NULL) {
        printf("Index entry not found.\n");
    }
}

int main() {
    Book* head = NULL;
    Index* indexHead = NULL;

    insertBook(head, "The Lord of the Rings", 1954);
    insertBook(head, "The Hobbit", 1937);
    insertBook(head, "The Harry Potter Series", 1997);

    insertIndex(indexHead, "The Lord of the Rings", 100);
    insertIndex(indexHead, "The Hobbit", 200);
    insertIndex(indexHead, "The Harry Potter Series", 300);

    searchBook(head, "The Lord of the Rings");
    searchIndex(indexHead, "The Lord of the Rings");

    return 0;
}