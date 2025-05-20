//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    int year;
} Book;

typedef struct Library {
    Book *books;
    int size;
    int capacity;
} Library;

Library* createLibrary(int capacity) {
    Library *lib = (Library *)malloc(sizeof(Library));
    lib->capacity = capacity;
    lib->size = 0;
    lib->books = (Book *)malloc(capacity * sizeof(Book));
    return lib;
}

void freeLibrary(Library *lib) {
    free(lib->books);
    free(lib);
}

void resizeLibrary(Library *lib) {
    lib->capacity *= 2;
    lib->books = (Book *)realloc(lib->books, lib->capacity * sizeof(Book));
}

void addBook(Library *lib, const char *title, const char *author, int year) {
    if (lib->size >= lib->capacity) {
        resizeLibrary(lib);
    }
    strcpy(lib->books[lib->size].title, title);
    strcpy(lib->books[lib->size].author, author);
    lib->books[lib->size].year = year;
    lib->size++;
}

void viewBooks(Library *lib) {
    if (lib->size == 0) {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < lib->size; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", lib->books[i].title);
        printf("  Author: %s\n", lib->books[i].author);
        printf("  Year: %d\n", lib->books[i].year);
    }
}

void deleteBook(Library *lib, int index) {
    if (index < 0 || index >= lib->size) {
        printf("Invalid book index.\n");
        return;
    }
    for (int i = index; i < lib->size - 1; i++) {
        lib->books[i] = lib->books[i + 1];
    }
    lib->size--;
    printf("Book removed successfully.\n");
}

int main() {
    Library *library = createLibrary(2);
    int choice;
    char title[100], author[100];
    int year, index;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline

                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove newline

                printf("Enter publication year: ");
                scanf("%d", &year);

                addBook(library, title, author, year);
                printf("Book added successfully.\n");
                break;

            case 2:
                viewBooks(library);
                break;

            case 3:
                printf("Enter book index to delete (starting from 0): ");
                scanf("%d", &index);
                deleteBook(library, index);
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeLibrary(library);
    return 0;
}