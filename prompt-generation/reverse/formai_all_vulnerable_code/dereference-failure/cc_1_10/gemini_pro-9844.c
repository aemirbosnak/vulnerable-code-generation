//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-themed text effects
#define CYBER_RED "\x1b[31;1m"
#define CYBER_GREEN "\x1b[32;1m"
#define CYBER_YELLOW "\x1b[33;1m"
#define CYBER_BLUE "\x1b[34;1m"
#define CYBER_MAGENTA "\x1b[35;1m"
#define CYBER_CYAN "\x1b[36;1m"
#define CYBER_WHITE "\x1b[37;1m"
#define CYBER_RESET "\x1b[0m"

// Data structure to store book chapters
typedef struct Chapter {
    char *title;
    char *text;
    struct Chapter *next;
} Chapter;

// Global variables
Chapter *head = NULL; // Head of the linked list of chapters
int current_chapter = 0; // Index of the current chapter

// Function to load a book from a file
void load_book(char *filename) {
    FILE *fp;
    char buffer[1024];
    Chapter *new_chapter;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), fp)) {
        // Check if the line is a chapter title
        if (buffer[0] == '#') {
            // Allocate memory for the new chapter
            new_chapter = malloc(sizeof(Chapter));

            // Set the chapter title
            new_chapter->title = strdup(buffer + 1);

            // Set the chapter text to empty
            new_chapter->text = strdup("");

            // Add the new chapter to the linked list
            if (head == NULL) {
                head = new_chapter;
            } else {
                new_chapter->next = head;
                head = new_chapter;
            }
        } else {
            // Append the line to the current chapter text
            new_chapter->text = realloc(new_chapter->text, strlen(new_chapter->text) + strlen(buffer) + 1);
            strcat(new_chapter->text, buffer);
        }
    }

    // Close the file
    fclose(fp);
}

// Function to display the current chapter
void display_chapter() {
    Chapter *chapter = head;

    // Iterate through the chapters until we find the current chapter
    for (int i = 0; i < current_chapter; i++) {
        chapter = chapter->next;
    }

    // Display the chapter title and text
    printf(CYBER_BLUE "Chapter %d: %s" CYBER_RESET "\n", current_chapter + 1, chapter->title);
    printf(CYBER_YELLOW "%s" CYBER_RESET "\n", chapter->text);
}

// Function to handle user input
void handle_input() {
    char input[1024];

    // Get user input
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Check if the user wants to quit
    if (strcmp(input, "q\n") == 0) {
        exit(0);
    } else if (strcmp(input, "n\n") == 0) {
        // Go to the next chapter
        if (current_chapter < (head->next == NULL ? 1 : head->next->next == NULL ? 2 : 3)) {
            current_chapter++;
            display_chapter();
        } else {
            printf("Reached last chapter\n");
        }
    } else if (strcmp(input, "p\n") == 0) {
        // Go to the previous chapter
        if (current_chapter > 0) {
            current_chapter--;
            display_chapter();
        } else {
            printf("Reached first chapter\n");
        }
    } else {
        // Invalid input
        printf("Invalid input\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a book file was provided
    if (argc < 2) {
        printf("Usage: %s <book_file>\n", argv[0]);
        return 1;
    }

    // Load the book
    load_book(argv[1]);

    // Display the first chapter
    display_chapter();

    // Handle user input
    while (1) {
        handle_input();
    }

    return 0;
}