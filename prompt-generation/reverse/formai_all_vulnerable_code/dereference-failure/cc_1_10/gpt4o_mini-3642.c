//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define NAME_LENGTH 50

typedef struct Book {
    char title[NAME_LENGTH];
    int is_borrowed;
} Book;

typedef struct Library {
    Book *books[MAX_BOOKS];
    int book_count;
} Library;

Library *create_library() {
    Library *library = (Library *)malloc(sizeof(Library));
    library->book_count = 0;
    for (int i = 0; i < MAX_BOOKS; i++) {
        library->books[i] = NULL;
    }
    return library;
}

void free_library(Library *library) {
    for (int i = 0; i < library->book_count; i++) {
        free(library->books[i]);
    }
    free(library);
}

void add_book(Library *library, const char *title) {
    if (library->book_count < MAX_BOOKS) {
        Book *new_book = (Book *)malloc(sizeof(Book));
        strncpy(new_book->title, title, NAME_LENGTH);
        new_book->is_borrowed = 0;
        library->books[library->book_count] = new_book;
        library->book_count++;
        printf("Book '%s' added to the library.\n", title);
    } else {
        printf("Library is full, cannot add more books.\n");
    }
}

void borrow_book(Library *library, const char *title) {
    for (int i = 0; i < library->book_count; i++) {
        if (library->books[i] != NULL && strcmp(library->books[i]->title, title) == 0) {
            if (library->books[i]->is_borrowed) {
                printf("Sorry, the book '%s' is currently borrowed.\n", title);
            } else {
                library->books[i]->is_borrowed = 1;
                printf("You have successfully borrowed the book '%s'.\n", title);
            }
            return;
        }
    }
    printf("The book '%s' is not available in the library.\n", title);
}

void return_book(Library *library, const char *title) {
    for (int i = 0; i < library->book_count; i++) {
        if (library->books[i] != NULL && strcmp(library->books[i]->title, title) == 0) {
            if (library->books[i]->is_borrowed) {
                library->books[i]->is_borrowed = 0;
                printf("You have successfully returned the book '%s'.\n", title);
            } else {
                printf("You haven't borrowed the book '%s'.\n", title);
            }
            return;
        }
    }
    printf("The book '%s' is not available in the library.\n", title);
}

void list_books(Library *library) {
    printf("Books in the library:\n");
    for (int i = 0; i < library->book_count; i++) {
        if (library->books[i] != NULL) {
            printf(" - %s [%s]\n", library->books[i]->title, library->books[i]->is_borrowed ? "Borrowed" : "Available");
        }
    }
}

int main() {
    Library *library = create_library();
    int choice;
    char title[NAME_LENGTH];

    do {
        printf("\n----- Library Menu -----\n");
        printf("1. Add Book\n");
        printf("2. Borrow Book\n");
        printf("3. Return Book\n");
        printf("4. List Books\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, NAME_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                add_book(library, title);
                break;

            case 2:
                printf("Enter book title to borrow: ");
                fgets(title, NAME_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                borrow_book(library, title);
                break;

            case 3:
                printf("Enter book title to return: ");
                fgets(title, NAME_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                return_book(library, title);
                break;

            case 4:
                list_books(library);
                break;

            case 5:
                printf("Exiting the library system.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    free_library(library); // Clean up
    return 0;
}