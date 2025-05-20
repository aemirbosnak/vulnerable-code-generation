//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char **lines;
    int total_lines;
} eBook;

// Function prototypes
eBook* load_eBook(const char *filename);
void free_eBook(eBook *book);
void display_eBook(eBook *book);
void navigate_eBook(eBook *book);

int main() {
    const char *filename = "example.txt"; // Specify your .txt file here
    eBook *myBook = load_eBook(filename);

    if (myBook == NULL) {
        fprintf(stderr, "Failed to load the book: %s\n", filename);
        return EXIT_FAILURE;
    }

    display_eBook(myBook);
    navigate_eBook(myBook);
    free_eBook(myBook);

    return EXIT_SUCCESS;
}

// Function to load an eBook from a text file
eBook* load_eBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    eBook *book = malloc(sizeof(eBook));
    book->lines = malloc(MAX_LINES * sizeof(char*));
    book->total_lines = 0;

    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, sizeof(buffer), file) && book->total_lines < MAX_LINES) {
        book->lines[book->total_lines] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(book->lines[book->total_lines], buffer);
        book->total_lines++;
    }

    fclose(file);
    return book;
}

// Function to free the eBook data
void free_eBook(eBook *book) {
    for (int i = 0; i < book->total_lines; i++) {
        free(book->lines[i]);
    }
    free(book->lines);
    free(book);
}

// Function to display the eBook contents
void display_eBook(eBook *book) {
    printf("eBook Contents (%d lines):\n", book->total_lines);
    for (int i = 0; i < book->total_lines; i++) {
        printf("%s", book->lines[i]);
    }
}

// Function to navigate through the eBook
void navigate_eBook(eBook *book) {
    int current_line = 0;
    char command[10];

    while (1) {
        printf("\nCurrent line: %d / %d\n", current_line + 1, book->total_lines);
        printf("Command (next, prev, exit): ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character from command if present
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "next") == 0) {
            if (current_line < book->total_lines - 1) {
                current_line++;
                printf("%s", book->lines[current_line]);
            } else {
                printf("You are at the last line.\n");
            }
        } else if (strcmp(command, "prev") == 0) {
            if (current_line > 0) {
                current_line--;
                printf("%s", book->lines[current_line]);
            } else {
                printf("You are at the first line.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the eBook reader.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}