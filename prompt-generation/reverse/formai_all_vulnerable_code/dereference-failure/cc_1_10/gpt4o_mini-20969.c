//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TITLE 100

typedef struct {
    char title[MAX_TITLE];
    char **contents;
    int totalLines;
} EBook;

void loadEBook(const char *filename, EBook *book) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    strncpy(book->title, filename, MAX_TITLE - 1);
    book->title[MAX_TITLE - 1] = '\0';

    char buffer[MAX_BUFFER];
    int lineCount = 0;
    
    // Initial allocation for lines
    book->contents = malloc(sizeof(char *) * MAX_BUFFER);
    if (!book->contents) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        book->contents[lineCount] = malloc(strlen(buffer) + 1);
        if (!book->contents[lineCount]) {
            perror("Memory allocation for line failed");
            exit(EXIT_FAILURE);
        }
        strcpy(book->contents[lineCount], buffer);
        lineCount++;
    }

    book->totalLines = lineCount;
    fclose(file);
}

void freeEBook(EBook *book) {
    for (int i = 0; i < book->totalLines; i++) {
        free(book->contents[i]);
    }
    free(book->contents);
}

void displayPage(const EBook *book, int startLine) {
    system("clear"); // Clear the screen
    printf("=== %s ===\n", book->title);
    for (int i = startLine; i < startLine + 20 && i < book->totalLines; i++) {
        printf("%s", book->contents[i]);
    }
    printf("\nCommands: (n)ext, (p)revious, (q)uit\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    EBook book;
    loadEBook(argv[1], &book);
    
    int currentPage = 0;
    char command; 

    while (1) {
        displayPage(&book, currentPage);
        
        command = getchar();
        getchar(); // Consume newline character
        if (command == 'n') {
            if (currentPage + 20 < book.totalLines) {
                currentPage += 20;
            } else {
                printf("You are at the last page!\n");
            }
        } else if (command == 'p') {
            if (currentPage - 20 >= 0) {
                currentPage -= 20;
            } else {
                printf("You are at the first page!\n");
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("Unknown command. Please use (n), (p), or (q).\n");
        }

        while (getchar() != '\n'); // Clear the input buffer
    }

    freeEBook(&book);
    return EXIT_SUCCESS;
}