//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100

void shout(const char *text) {
    while (*text) {
        putchar(toupper(*text));
        text++;
    }
    putchar('\n');
}

void giggle() {
    printf("Haha! That's funny!\n");
}

int main() {
    char *lines[MAX_NUM_LINES];
    int line_count = 0;

    // The program is now a magical buffer - let's fill it with spells!
    printf("Welcome to the fantastically funny text processing program!\n");
    printf("Enter up to %d lines of text (type 'exit' to finish):\n", MAX_NUM_LINES);

    for (int i = 0; i < MAX_NUM_LINES; i++) {
        lines[i] = (char *)malloc(MAX_LINE_LENGTH);
        if (lines[i] == NULL) {
            fprintf(stderr, "Oops! Memory allocation failed. Oh no!\n");
            return 1;
        }
        fgets(lines[i], MAX_LINE_LENGTH, stdin);

        // Remove newline character if present
        lines[i][strcspn(lines[i], "\n")] = 0;

        if (strcmp(lines[i], "exit") == 0) {
            printf("You wish to escape? Too bad! Let's process your input!\n");
            break;
        }

        line_count++;
        if (strstr(lines[i], "funny") != NULL) {
            giggle();
        }
    }

    printf("\nYou've entered the following lines:\n");
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("\nLet's make your lines LOUDER! Shouting time:\n");
    for (int i = 0; i < line_count; i++) {
        shout(lines[i]);
    }

    printf("\nNow, let's make it absurd! I'll reverse your lines:\n");
    for (int i = 0; i < line_count; i++) {
        char *reversed_line = (char *)malloc(MAX_LINE_LENGTH);
        if (reversed_line == NULL) {
            fprintf(stderr, "Oh no! Memory allocation for reversed line failed.\n");
            return 1;
        }
        size_t length = strlen(lines[i]);
        for (size_t j = 0; j < length; j++) {
            reversed_line[j] = lines[i][length - j - 1];
        }
        reversed_line[length] = '\0'; // Null-terminate the string
        printf("Reverse of '%s' is '%s'. Wow!\n", lines[i], reversed_line);
        free(reversed_line);
    }

    // Free memory for lines
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }

    printf("\nThank you for being a part of our hilarious program! Goodbye!\n");
    return 0;
}