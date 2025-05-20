//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters for a single line
#define MAX_LINE_LENGTH 80

// Define the structure for a single line
typedef struct {
    char *text;
    int length;
    struct line_t *next;
} line_t;

// Define the structure for a file
typedef struct {
    line_t *head;
    int num_lines;
} file_t;

// Function to create a new line
line_t *create_line(char *text, int length) {
    line_t *new_line = malloc(sizeof(line_t));
    if (new_line == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_line->text = text;
    new_line->length = length;
    new_line->next = NULL;
    return new_line;
}

// Function to create a new file
file_t *create_file() {
    file_t *new_file = malloc(sizeof(file_t));
    if (new_file == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_file->head = NULL;
    new_file->num_lines = 0;
    return new_file;
}

// Function to add a new line to the file
void add_line(file_t *file, char *text, int length) {
    line_t *new_line = create_line(text, length);
    new_line->next = file->head;
    file->head = new_line;
    file->num_lines++;
}

// Function to print the file
void print_file(file_t *file) {
    printf("File contains %d lines:\n", file->num_lines);
    line_t *current_line = file->head;
    while (current_line!= NULL) {
        printf("%s\n", current_line->text);
        current_line = current_line->next;
    }
}

// Function to free the memory used by the file
void free_file(file_t *file) {
    line_t *current_line = file->head;
    while (current_line!= NULL) {
        free(current_line->text);
        current_line = current_line->next;
    }
    free(file);
}

int main() {
    // Create a new file
    file_t *file = create_file();

    // Read lines from standard input and add them to the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int length = strlen(line);
        add_line(file, line, length);
    }

    // Print the file
    print_file(file);

    // Free the memory used by the file
    free_file(file);

    return 0;
}