//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 256
#define FILENAME "paranoid_file.txt"

// Function to handle errors
void handle_error(const char *msg) {
    fprintf(stderr, "Error: %s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

// Function to write a paranoid note to the file
void write_paranoid_note(FILE *file, const char *note) {
    if (fprintf(file, "Note: %s\n", note) < 0) {
        handle_error("Failed to write note to file");
    }
    fflush(file); // Ensure it's written immediately
}

// Function to read the notes from the file
void read_paranoid_notes(FILE *file) {
    char line[MAX_LINE_LENGTH];
    rewind(file); // Go to the beginning of the file

    printf("Reading notes from the file:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

// Function to create a file if it doesn't exist
FILE *create_file_if_not_exists(const char *filename) {
    FILE *file = fopen(filename, "a+"); // Open for reading and appending
    if (!file) {
        handle_error("Could not open or create the file");
    }
    return file;
}

// Main function for managing paranoid notes
int main() {
    FILE *file = create_file_if_not_exists(FILENAME);
    
    // Infinite loop to handle user commands
    while (1) {
        char command[MAX_LINE_LENGTH];
        printf("Enter your command (write/read/exit): ");
        if (!fgets(command, sizeof(command), stdin)) {
            handle_error("Failed to read command");
        }

        // Remove newline character if exists
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "write") == 0) {
            char note[MAX_LINE_LENGTH];
            printf("Enter your paranoid note: ");
            if (!fgets(note, sizeof(note), stdin)) {
                handle_error("Failed to read note");
            }

            // Remove newline character from note
            note[strcspn(note, "\n")] = 0;

            write_paranoid_note(file, note);
            printf("Your note has been safely recorded.\n");
        } else if (strcmp(command, "read") == 0) {
            read_paranoid_notes(file);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program. Take care of your notes!\n");
            break;
        } else {
            printf("Unknown command. Please use 'write', 'read', or 'exit'.\n");
        }
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close the file");
    }

    return 0;
}