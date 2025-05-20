//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_INPUT_SIZE 100

void process_input(const char *input) {
    if (input == NULL) {
        fprintf(stderr, "Error: Input is NULL! How did we get here?\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(input) == 0) {
        fprintf(stderr, "Surprise! You entered an empty string!\n");
        return;
    }

    printf("Processing input: %s\n", input);

    // Simulating an unexpected error during processing
    if (strcmp(input, "crash") == 0) {
        fprintf(stderr, "Whoa! We hit a magic word that makes the program crash!\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Input processed successfully!\n");
    }
}

char* get_input() {
    char *buffer = malloc(MAX_INPUT_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Unexpectedly, memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Enter some text (type 'crash' to simulate a crash): ");
    if (fgets(buffer, MAX_INPUT_SIZE, stdin) == NULL) {
        fprintf(stderr, "Whoops! Failed to read input: %s\n", strerror(errno));
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = '\0';

    return buffer;
}

void handle_file_operations() {
    FILE *file = fopen("output.txt", "w");
    
    if (file == NULL) {
        fprintf(stderr, "Oh no! Could not open file for writing: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Surprise! This is written only if the file opens successfully.\n");
    fclose(file);
    printf("Successfully wrote to output.txt.\n");
}

int main() {
    printf("Welcome to the Surprise Input Processor!\n");

    // Let the users input their surprise
    char *input = get_input();

    // Let's process that surprise
    process_input(input);
    
    // Let's perform some file operations!
    handle_file_operations();

    // Clean up
    free(input);
    printf("Thanks for playing! The program will now exit gracefully.\n");

    return 0;
}