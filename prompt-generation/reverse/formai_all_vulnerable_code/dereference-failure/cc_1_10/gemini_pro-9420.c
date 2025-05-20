//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A linked list node to store a line of the book
struct Node {
    char *line;
    struct Node *next;
};

// The main book data structure
struct Book {
    struct Node *head;
};

// Creates a new book
struct Book *new_book() {
    struct Book *book = malloc(sizeof(struct Book));
    book->head = NULL;
    return book;
}

// Adds a line to the book
void add_line(struct Book *book, char *line) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->line = strdup(line);
    new_node->next = book->head;
    book->head = new_node;
}

// Prints the book
void print_book(struct Book *book) {
    struct Node *current = book->head;
    while (current != NULL) {
        printf("%s\n", current->line);
        current = current->next;
    }
}

// Frees the memory allocated for the book
void free_book(struct Book *book) {
    struct Node *current = book->head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current->line);
        free(current);
        current = next;
    }
    free(book);
}

// Loads a book from a file
struct Book *load_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    struct Book *book = new_book();
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        add_line(book, line);
    }

    fclose(file);
    return book;
}

// Saves a book to a file
void save_book(struct Book *book, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    struct Node *current = book->head;
    while (current != NULL) {
        fprintf(file, "%s", current->line);
        current = current->next;
    }

    fclose(file);
}

// Main function
int main() {
    // Load the book from a file
    struct Book *book = load_book("book.txt");
    if (book == NULL) {
        printf("Error: Could not load book.\n");
        return 1;
    }

    // Print the book
    printf("Book:\n");
    print_book(book);

    // Save the book to a file
    save_book(book, "new_book.txt");

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}