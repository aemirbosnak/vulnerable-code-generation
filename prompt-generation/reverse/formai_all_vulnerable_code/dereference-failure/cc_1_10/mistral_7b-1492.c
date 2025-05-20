//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Book {
    char title[50];
    struct Book *next;
} Book;

Book *library = NULL;

void addBook(char *title) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    newBook->next = library;
    library = newBook;
    printf("Book added successfully!\n");
}

bool searchBook(char *title) {
    Book *current = library;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return true;
        }
        current = current->next;
    }
    printf("Book not found!\n");
    return false;
}

void removeBook(char *title) {
    if (library == NULL) {
        printf("Library is empty!\n");
        return;
    }

    if (strcmp(library->title, title) == 0) {
        Book *temp = library;
        library = library->next;
        free(temp);
        printf("Book removed successfully!\n");
        return;
    }

    Book *current = library;
    while (current->next != NULL && strcmp(current->next->title, title) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Book not found!\n");
        return;
    }

    Book *temp = current->next;
    current->next = current->next->next;
    free(temp);
    printf("Book removed successfully!\n");
}

int main() {
    char command[20], title[50];
    bool quit = false;

    while (!quit) {
        printf("\nLibrary Management System\n");
        printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Remove a book\n");
        printf("4. Quit\n");
        printf("Enter your command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter the title of the book: ");
                scanf("%s", title);
                addBook(title);
                break;
            case '2':
                printf("Enter the title of the book to search: ");
                scanf("%s", title);
                if (searchBook(title)) {
                    printf("Book found!\n");
                }
                break;
            case '3':
                printf("Enter the title of the book to remove: ");
                scanf("%s", title);
                removeBook(title);
                break;
            case '4':
                quit = true;
                break;
            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}