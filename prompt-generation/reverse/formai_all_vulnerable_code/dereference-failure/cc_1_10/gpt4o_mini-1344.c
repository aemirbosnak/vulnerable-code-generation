//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_SUMMARIZED_LINES 10
#define MAX_LINE_LENGTH 256

void sanitize_input(char *line) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n' || line[i] == '\r') {
            line[i] = '\0';
            break;
        }
    }
}

void paranoid_summary(const char *file_name) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *lines[MAX_SUMMARIZED_LINES];
    int line_count = 0;

    // Opening the file in paranoid mode
    if (!(file = fopen(file_name, "r"))) {
        fprintf(stderr, "Error: Could not open file '%s'. Are you sure it exists?\n", file_name);
        exit(EXIT_FAILURE);
    }

    // Read lines from the file
    while (fgets(buffer, BUFFER_SIZE, file) && line_count < MAX_SUMMARIZED_LINES) {
        // Ensure the buffer is sanitized
        sanitize_input(buffer);

        // Allocate memory for the line
        lines[line_count] = malloc(MAX_LINE_LENGTH);
        if (!lines[line_count]) {
            fprintf(stderr, "Error: Memory allocation failed. Someone is sabotaging this program!\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        
        // Copy buffer into the allocated space
        strcpy(lines[line_count], buffer);
        line_count++;
    }

    // Close the file since we are done reading
    fclose(file);

    // Generate the summary
    printf("***** Paranoid Text Summary *****\n");
    for (int i = 0; i < line_count; i++) {
        // Be wary of what we print out - double-checking sanity
        printf("%d: %s\n", i + 1, lines[i]);
        
        // Free allocated memory cautiously
        free(lines[i]);
        lines[i] = NULL; // Avoid dangling pointers
    }
    printf("Summary completed. But was it too easy? \n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file-to-summarize>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Paranoid check on the file name provided
    printf("Initiating summary process... Check your surroundings!\n");
    paranoid_summary(argv[1]);
    
    // Final paranoia check
    printf("No unexpected behavior has been detected. Proceed with caution!\n");
    return 0;
}