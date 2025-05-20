//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define INITIAL_CAPACITY 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

typedef struct {
    Book *books;
    int size;
    int capacity;
} Library;

Library* create_library() {
    Library* library = (Library*)malloc(sizeof(Library));
    library->size = 0;
    library->capacity = INITIAL_CAPACITY;
    library->books = (Book*)malloc(library->capacity * sizeof(Book));
    return library;
}

void free_library(Library* library) {
    free(library->books);
    free(library);
}

void add_book(Library* library, const char* title, const char* author) {
    if (library->size >= library->capacity) {
        library->capacity *= 2; 
        library->books = (Book*)realloc(library->books, library->capacity * sizeof(Book));
    }
    strncpy(library->books[library->size].title, title, MAX_TITLE_LENGTH - 1);
    strncpy(library->books[library->size].author, author, MAX_AUTHOR_LENGTH - 1);
    library->books[library->size].title[MAX_TITLE_LENGTH - 1] = '\0'; // Null-terminate
    library->books[library->size].author[MAX_AUTHOR_LENGTH - 1] = '\0'; // Null-terminate
    library->size++;
}

void delete_book(Library* library, int index) {
    if (index < 0 || index >= library->size) {
        printf("Invalid index. Unable to delete book.\n");
        return;
    }
    for (int i = index; i < library->size - 1; i++) {
        library->books[i] = library->books[i + 1];
    }
    library->size--;
}

void display_books(const Library* library) {
    if (library->size == 0) {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < library->size; i++) {
        printf("Book %d: \"%s\" by %s\n", i + 1, library->books[i].title, library->books[i].author);
    }
}

int main() {
    Library* library = create_library();
    int choice;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int index;

    while (1) {
        printf("\nLibrary System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
        case 1:
            printf("Enter book title: ");
            fgets(title, MAX_TITLE_LENGTH, stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline
            printf("Enter author name: ");
            fgets(author, MAX_AUTHOR_LENGTH, stdin);
            author[strcspn(author, "\n")] = 0; // Remove newline
            add_book(library, title, author);
            break;
        case 2:
            printf("Enter book index to delete (1 to %d): ", library->size);
            scanf("%d", &index);
            delete_book(library, index - 1); // Convert to 0-based index
            break;
        case 3:
            display_books(library);
            break;
        case 4:
            free_library(library);
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}