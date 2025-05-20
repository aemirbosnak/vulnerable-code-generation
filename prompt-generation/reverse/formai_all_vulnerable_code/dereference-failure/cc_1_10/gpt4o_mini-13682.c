//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOK_SIZE 1000
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char lines[MAX_BOOK_SIZE][MAX_LINE_LENGTH];
    int line_count;
} eBook;

void loadBook(char *filename, eBook *book);
void displayBook(const eBook *book);
void searchWord(const eBook *book, const char *word);
void navigateToLine(const eBook *book, int line_number);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    eBook myBook;
    loadBook(argv[1], &myBook);

    int choice, line_num;
    char searchTerm[MAX_LINE_LENGTH];

    do {
        printf("\n--- eBook Reader ---\n");
        printf("1. Display eBook\n");
        printf("2. Search for a word\n");
        printf("3. Jump to a line\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBook(&myBook);
                break;
            case 2:
                printf("Enter word to search: ");
                scanf("%s", searchTerm);
                searchWord(&myBook, searchTerm);
                break;
            case 3:
                printf("Enter line number to jump to: ");
                scanf("%d", &line_num);
                navigateToLine(&myBook, line_num);
                break;
            case 4:
                printf("Exiting the eBook Reader. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return EXIT_SUCCESS;
}

void loadBook(char *filename, eBook *book) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    strncpy(book->title, filename, MAX_TITLE_LENGTH);
    book->line_count = 0;

    while (fgets(book->lines[book->line_count], MAX_LINE_LENGTH, file) && 
           book->line_count < MAX_BOOK_SIZE) {
        book->line_count++;
    }

    fclose(file);
}

void displayBook(const eBook *book) {
    printf("\n--- %s ---\n", book->title);
    for (int i = 0; i < book->line_count; i++) {
        printf("%d: %s", i + 1, book->lines[i]);
    }
}

void searchWord(const eBook *book, const char *word) {
    int found = 0;
    printf("Searching for '%s'...\n", word);
    
    for (int i = 0; i < book->line_count; i++) {
        if (strstr(book->lines[i], word) != NULL) {
            printf("Found on line %d: %s", i + 1, book->lines[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("'%s' not found in the book.\n", word);
    }
}

void navigateToLine(const eBook *book, int line_number) {
    if (line_number < 1 || line_number > book->line_count) {
        printf("Error: Line number %d is out of range (1-%d).\n", line_number, book->line_count);
        return;
    }

    printf("Jumping to line %d: %s", line_number, book->lines[line_number - 1]);
}