//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define MAX_BOOK_TITLE 100

typedef struct {
    char title[MAX_BOOK_TITLE];
    FILE *file;
} Ebook;

void clearScreen() {
    printf("\033[H\033[J");
}

void displayHeader(const char *title) {
    clearScreen();
    printf("###############################\n");
    printf("#        %s        \n", title);
    printf("###############################\n");
}

Ebook* loadEbook(const char *filename) {
    Ebook *book = malloc(sizeof(Ebook));
    if (!book) {
        fprintf(stderr, "Allocation Error: Unable to allocate memory for Ebook.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(book->title, filename);
    book->file = fopen(filename, "r");
    if (book->file == NULL) {
        fprintf(stderr, "File Error: Unable to open file %s.\n", filename);
        free(book);
        exit(EXIT_FAILURE);
    }

    return book;
}

void displayContent(Ebook *book) {
    char line[MAX_LINE_LENGTH];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), book->file)) {
        printf("%03d: %s", lineNumber++, line);
    }
    fclose(book->file);
}

void searchWord(Ebook *book, const char *word) {
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int found = 0;

    book->file = fopen(book->title, "r"); // Open file again for search
    if (!book->file) {
        fprintf(stderr, "File Error: Unable to open file %s.\n", book->title);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), book->file)) {
        lineNumber++;
        if (strstr(line, word) != NULL) {
            printf("Found '%s' at line %d: %s", word, lineNumber, line);
            found = 1;
        }
    }

    if (!found) {
        printf("Surprise! The word '%s' was not found in this book.\n", word);
    }
    
    fclose(book->file);
}

void freeEbook(Ebook *book) {
    free(book);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Ebook *book = loadEbook(argv[1]);
    displayHeader(book->title);

    printf("Are you ready to dive into this book? (yes/no): ");
    char choice[4];
    scanf("%3s", choice);

    if (strcmp(choice, "yes") == 0) {
        displayContent(book);
    } else {
        printf("Oh no! You've chosen not to read... %s\n", book->title);
    }

    printf("Want to search for a word in this book? (yes/no): ");
    scanf("%3s", choice);

    if (strcmp(choice, "yes") == 0) {
        char word[50];
        printf("Enter the word you want to search for: ");
        scanf("%49s", word);
        searchWord(book, word);
    } else {
        printf("Surprise! No searching today... \n");
    }

    freeEbook(book);
    printf("Thank you for using this awesome Ebook Reader!\n");
    return EXIT_SUCCESS;
}