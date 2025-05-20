//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void displayMenu() {
    printf("Welcome to the Simple C Ebook Reader!\n");
    printf("Commands:\n");
    printf("  - next: Read the next line\n");
    printf("  - prev: Read the previous line\n");
    printf("  - jump <line_number>: Jump to a specific line\n");
    printf("  - search <keyword>: Search for a keyword\n");
    printf("  - exit: Exit the ebook reader\n");
    printf("Please enter your command: ");
}

void readLine(FILE *file, char *buffer) {
    if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL) {
        strcpy(buffer, ""); // Set buffer to an empty string if EOF is reached
    }
}

int main() {
    FILE *file;
    char filename[100];
    char command[100];
    char line[MAX_LINE_LENGTH];
    int currentLine = 0;
    char *lines[1000]; // Array to store lines
    int totalLines = 0;

    // User inputs filename
    printf("Enter the filename of the ebook: ");
    scanf("%s", filename);
    
    // Opening the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    // Read lines into memory
    while (fgets(line, sizeof(line), file)) {
        lines[totalLines] = malloc(strlen(line) + 1);
        strcpy(lines[totalLines], line);
        totalLines++;
    }
    fclose(file);

    printf("Loaded %d lines from %s!\n", totalLines, filename);

    // Start displaying the menu
    displayMenu();

    while (1) {
        scanf("%s", command);
        
        if (strcmp(command, "next") == 0) {
            if (currentLine < totalLines) {
                printf("%s", lines[currentLine]);
                currentLine++;
            } else {
                printf("You have reached the end of the ebook.\n");
            }
        } else if (strcmp(command, "prev") == 0) {
            if (currentLine > 0) {
                currentLine--;
                printf("%s", lines[currentLine]);
            } else {
                printf("You are at the beginning of the ebook.\n");
            }
        } else if (strncmp(command, "jump", 4) == 0) {
            int lineNumber;
            sscanf(command + 5, "%d", &lineNumber);
            if (lineNumber > 0 && lineNumber <= totalLines) {
                currentLine = lineNumber - 1;
                printf("%s", lines[currentLine]);
            } else {
                printf("Line number is out of bounds.\n");
            }
        } else if (strncmp(command, "search", 6) == 0) {
            char keyword[50];
            sscanf(command + 7, "%s", keyword);
            printf("Searching for: %s\n", keyword);
            for (int i = 0; i < totalLines; i++) {
                if (strstr(lines[i], keyword) != NULL) {
                    printf("Found in line %d: %s", i + 1, lines[i]);
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    // Clean up
    for (int i = 0; i < totalLines; i++) {
        free(lines[i]);
    }

    printf("Thank you for using the Simple C Ebook Reader! Goodbye!\n");
    return 0;
}