//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TITLE_LENGTH 100
#define MAX_BOOKS 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char **content; // Pointer to dynamic array of strings
    int num_lines; // Total lines in the book
} Book;

// Function prototypes
Book* loadBook(const char *filename);
void freeBook(Book *book);
void displayContent(Book *book, int start_line, int lines_to_display);
void searchBook(Book *book, const char *keyword);

int main() {
    char *filenames[] = {"book1.txt", "book2.txt"};
    Book *books[MAX_BOOKS];
    int num_books = 2; // Example of 2 books

    // Load books
    for (int i = 0; i < num_books; i++) {
        books[i] = loadBook(filenames[i]);
        if (books[i] == NULL) {
            printf("Failed to load book: %s\n", filenames[i]);
            return 1;
        }
    }

    // Simple command line interface
    char command[20];
    int current_book_idx = 0;
    int current_line = 0;

    while (1) {
        printf("\nCommands: 'next', 'prev', 'search <word>', 'exit'\n");
        printf("Current Book: %s\n", books[current_book_idx]->title);
        displayContent(books[current_book_idx], current_line, 10);

        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "next") == 0) {
            current_line += 10;
            if (current_line >= books[current_book_idx]->num_lines) {
                current_line = books[current_book_idx]->num_lines - 10; // Stay within bounds
            }
        } else if (strcmp(command, "prev") == 0) {
            current_line -= 10;
            if (current_line < 0) {
                current_line = 0; // Stay within bounds
            }
        } else if (strncmp(command, "search", 6) == 0) {
            char *keyword = command + 7; // Get the word after 'search '
            searchBook(books[current_book_idx], keyword);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command!\n");
        }
    }

    // Cleanup
    for (int i = 0; i < num_books; i++) {
        freeBook(books[i]);
    }
    return 0;
}

// Function to load a book from a file
Book* loadBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    Book *book = (Book *)malloc(sizeof(Book));
    strcpy(book->title, filename);
    
    // Allocate memory for content dynamically
    book->content = (char **)malloc(sizeof(char *) * MAX_LINE_LENGTH);
    book->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        book->content[book->num_lines] = strdup(line); // Copy the line
        book->num_lines++;
    }

    fclose(file);
    return book;
}

// Function to free dynamically allocated book memory
void freeBook(Book *book) {
    for (int i = 0; i < book->num_lines; i++) {
        free(book->content[i]); // Free each line
    }
    free(book->content); // Free the content array
    free(book); // Free the book structure
}

// Function to display part of the book content
void displayContent(Book *book, int start_line, int lines_to_display) {
    for (int i = 0; i < lines_to_display && (start_line + i) < book->num_lines; i++) {
        printf("%s", book->content[start_line + i]); // Print the specified lines
    }
}

// Function to search for a word in the book and print occurrences
void searchBook(Book *book, const char *keyword) {
    printf("Searching for '%s'...\n", keyword);
    int found = 0;
    for (int i = 0; i < book->num_lines; i++) {
        if (strstr(book->content[i], keyword)) {
            printf("Found on line %d: %s", i + 1, book->content[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("'%s' not found in the book.\n", keyword);
    }
}