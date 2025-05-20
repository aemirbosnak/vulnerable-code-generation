//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOKS 10

typedef struct {
    char title[100];
    char *content;
    size_t size; // Size of the content in bytes
} Book;

void loadBook(Book *book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    // Store book title
    strncpy(book->title, filename, sizeof(book->title) - 1);
    book->title[sizeof(book->title) - 1] = '\0';

    // Load content
    fseek(file, 0, SEEK_END);
    book->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    book->content = (char *)malloc(book->size + 1);
    if (!book->content) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(book->content, 1, book->size, file);
    book->content[book->size] = '\0'; // Null-terminate the string
    fclose(file);
}

void displayBook(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Content:\n\n");
    printf("%s\n", book->content);
}

void searchInBook(const Book *book, const char *word) {
    char *found = strstr(book->content, word);
    if (found) {
        printf("The word \"%s\" was found in the book \"%s\".\n", word, book->title);
    } else {
        printf("The word \"%s\" was not found in the book \"%s\".\n", word, book->title);
    }
}

void freeBook(Book *book) {
    free(book->content);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <book1.txt> [<book2.txt> ... <bookN.txt>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    Book books[MAX_BOOKS];
    int bookCount = 0;

    // Load books
    for (int i = 1; i < argc && bookCount < MAX_BOOKS; i++, bookCount++) {
        loadBook(&books[bookCount], argv[i]);
    }

    // Interactive reading session
    char command[100];
    while (1) {
        printf("Commands: display, search <word>, exit\n");
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove the newline

        if (strncmp(command, "display", 7) == 0) {
            for (int i = 0; i < bookCount; i++) {
                displayBook(&books[i]);
            }
        } else if (strncmp(command, "search", 6) == 0) {
            char *word = command + 7; // Get the word after 'search '
            if (*word) {
                for (int i = 0; i < bookCount; i++) {
                    searchInBook(&books[i], word);
                }
            } else {
                printf("Please provide a word to search for.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }

    // Free allocated memory
    for (int i = 0; i < bookCount; i++) {
        freeBook(&books[i]);
    }

    return EXIT_SUCCESS;
}