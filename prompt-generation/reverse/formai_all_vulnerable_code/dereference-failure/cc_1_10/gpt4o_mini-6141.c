//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

void toUpperCase(char *line) {
    for (int i = 0; line[i]; i++) {
        line[i] = toupper(line[i]);
    }
}

void toLowerCase(char *line) {
    for (int i = 0; line[i]; i++) {
        line[i] = tolower(line[i]);
    }
}

void countVowels(const char *line, int *vowelCount) {
    *vowelCount = 0;
    for (int i = 0; line[i]; i++) {
        char ch = tolower(line[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            (*vowelCount)++;
        }
    }
}

void reverseString(char *line) {
    int len = strlen(line);
    for (int i = 0; i < len / 2; i++) {
        char temp = line[i];
        line[i] = line[len - i - 1];
        line[len - i - 1] = temp;
    }
}

void printMenu() {
    printf("~~~~~~~~~~~ Text Processing Menu ~~~~~~~~~~~\n");
    printf("1. Convert to Upper Case\n");
    printf("2. Convert to Lower Case\n");
    printf("3. Count Vowels\n");
    printf("4. Reverse Text\n");
    printf("5. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int main() {
    char *lines[MAX_LINES];
    int lineCounter = 0;

    printf("Welcome to the Ultimate Text Processing Program!\n");
    printf("You can input up to %d lines of text. Now, let's get started!\n\n", MAX_LINES);
    
    // Collect text from the user
    while (lineCounter < MAX_LINES) {
        lines[lineCounter] = (char *)malloc(MAX_LENGTH * sizeof(char));
        printf("Enter line %d (or type 'exit' to quit): ", lineCounter + 1);
        fgets(lines[lineCounter], MAX_LENGTH, stdin);

        // Check for exit condition
        if (strncmp(lines[lineCounter], "exit", 4) == 0) {
            free(lines[lineCounter]);
            break;
        }

        // Remove newline character
        lines[lineCounter][strcspn(lines[lineCounter], "\n")] = 0;
        lineCounter++;
    }

    int choice;
    do {
        printMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
        case 1: {
            // Convert to Upper Case
            for (int i = 0; i < lineCounter; i++) {
                toUpperCase(lines[i]);
                printf("Upper case line %d: %s\n", i + 1, lines[i]);
            }
            break;
        }
        case 2: {
            // Convert to Lower Case
            for (int i = 0; i < lineCounter; i++) {
                toLowerCase(lines[i]);
                printf("Lower case line %d: %s\n", i + 1, lines[i]);
            }
            break;
        }
        case 3: {
            // Count Vowels
            for (int i = 0; i < lineCounter; i++) {
                int vowelCount = 0;
                countVowels(lines[i], &vowelCount);
                printf("Line %d contains %d vowels.\n", i + 1, vowelCount);
            }
            break;
        }
        case 4: {
            // Reverse Text
            for (int i = 0; i < lineCounter; i++) {
                char original[MAX_LENGTH];
                strcpy(original, lines[i]);
                reverseString(lines[i]);
                printf("Original line %d: %s\n", i + 1, original);
                printf("Reversed line %d: %s\n", i + 1, lines[i]);
            }
            break;
        }
        case 5:
            printf("Exiting the program. Thank you for using the Ultimate Text Processing Program!\n");
            break;
        default:
            printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    for (int i = 0; i < lineCounter; i++) {
        free(lines[i]);
    }

    return 0;
}