//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 1000

void displayLine(char *line, int lineNumber) {
    printf("\n[%d] %s", lineNumber + 1, line);
}

void displayBook(char **bookLines, int totalLines) {
    printf("\nWelcome to the Ultimate eBook Reader!\n");
    printf("Press 'n' to go to the next line, 'p' to go to the previous line, 'q' to quit.\n\n");

    int currentLine = 0;
    char choice[10];

    while (currentLine < totalLines) {
        displayLine(bookLines[currentLine], currentLine);
        
        printf("\nEnter your choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "n") == 0) {
            if (currentLine + 1 < totalLines) {
                currentLine++;
            } else {
                printf("You have reached the end of the book!\n");
            }
        } else if (strcmp(choice, "p") == 0) {
            if (currentLine - 1 >= 0) {
                currentLine--;
            } else {
                printf("You are already at the beginning of the book!\n");
            }
        } else if (strcmp(choice, "q") == 0) {
            printf("\nThank you for using the Ultimate eBook Reader! Bye!\n");
            break;
        } else {
            printf("Invalid input! Please use 'n', 'p', or 'q'.\n");
        }
    }
}

char **loadBookFromFile(const char *filename, int *totalLines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char **lines = malloc(MAX_LINES * sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++) {
        lines[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    *totalLines = 0;
    while (*totalLines < MAX_LINES && fgets(lines[*totalLines], MAX_LINE_LENGTH, file)) {
        // Remove newline character
        lines[*totalLines][strcspn(lines[*totalLines], "\n")] = 0;
        (*totalLines)++;
    }

    fclose(file);
    return lines;
}

void freeBookLines(char **bookLines, int totalLines) {
    for (int i = 0; i < totalLines; i++) {
        free(bookLines[i]);
    }
    free(bookLines);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.txt>\n", argv[0]);
        return 1;
    }

    int totalLines = 0;
    char **bookLines = loadBookFromFile(argv[1], &totalLines);
    
    displayBook(bookLines, totalLines);
    
    freeBookLines(bookLines, totalLines);
    return 0;
}