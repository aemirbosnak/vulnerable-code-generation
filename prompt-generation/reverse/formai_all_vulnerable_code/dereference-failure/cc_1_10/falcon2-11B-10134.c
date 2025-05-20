//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char* word;
    struct node* next;
} node;

typedef struct {
    char* name;
    node* first;
    node* last;
    int count;
} book;

void addWord(node** head, char* word) {
    node* newNode = malloc(sizeof(node));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        (*head)->next = NULL;
    } else {
        node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addBook(book* books, char* name, int count) {
    books->name = strdup(name);
    books->first = NULL;
    books->last = NULL;
    books->count = count;
}

void displayBook(book* books, int index) {
    if (index < 0 || index >= books->count) {
        printf("Invalid index! Please enter a number between 0 and %d\n", books->count - 1);
        return;
    }

    node* current = books->first;
    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            printf("No books found!\n");
            return;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("No book found at index %d\n", index);
        return;
    }

    printf("Book %s\n", books->name);
    while (current!= NULL) {
        printf("Word: %s\n", current->word);
        current = current->next;
    }
}

int main() {
    book books[5];
    addBook(books, "Harry Potter", 1);
    addBook(books, "The Lord of the Rings", 2);
    addBook(books, "The Hobbit", 1);
    addBook(books, "A Game of Thrones", 1);
    addBook(books, "A Clash of Kings", 1);
    addBook(books, "A Storm of Swords", 1);

    displayBook(books, 3);
    displayBook(books, 8);

    return 0;
}