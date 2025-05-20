//GEMINI-pro DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line in the file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines to read from the file
#define MAX_LINES 10000

// Define the structure of a single line in the file
typedef struct {
    char *line;
    int length;
} line_t;

// Define the structure of the entire file
typedef struct {
    line_t *lines;
    int num_lines;
} file_t;

// Function to read a file into a file structure
file_t *read_file(const char *filename) {
    // Open the file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create a new file structure
    file_t *file = malloc(sizeof(file_t));
    if (file == NULL) {
        perror("Error allocating memory for file");
        fclose(fp);
        return NULL;
    }

    // Initialize the file structure
    file->lines = NULL;
    file->num_lines = 0;

    // Read the lines from the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Create a new line structure
        line_t *line_struct = malloc(sizeof(line_t));
        if (line_struct == NULL) {
            perror("Error allocating memory for line");
            fclose(fp);
            free(file);
            return NULL;
        }

        // Copy the line into the line structure
        line_struct->line = strdup(line);
        if (line_struct->line == NULL) {
            perror("Error allocating memory for line");
            fclose(fp);
            free(file);
            free(line_struct);
            return NULL;
        }

        // Set the length of the line
        line_struct->length = strlen(line);

        // Add the line to the file structure
        file->lines = realloc(file->lines, (file->num_lines + 1) * sizeof(line_t));
        if (file->lines == NULL) {
            perror("Error allocating memory for lines");
            fclose(fp);
            free(file);
            free(line_struct);
            free(line_struct->line);
            return NULL;
        }
        file->lines[file->num_lines++] = *line_struct;

        // Free the line structure
        free(line_struct);
    }

    // Close the file
    fclose(fp);

    // Return the file structure
    return file;
}

// Function to write a file from a file structure
int write_file(const char *filename, file_t *file) {
    // Open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the lines to the file
    for (int i = 0; i < file->num_lines; i++) {
        fprintf(fp, "%s", file->lines[i].line);
    }

    // Close the file
    fclose(fp);

    // Return 0 on success
    return 0;
}

// Function to free the memory allocated for a file structure
void free_file(file_t *file) {
    // Free the lines
    for (int i = 0; i < file->num_lines; i++) {
        free(file->lines[i].line);
    }
    free(file->lines);

    // Free the file structure
    free(file);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided a filename
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

    // Read the file into a file structure
    file_t *file = read_file(argv[1]);
    if (file == NULL) {
        return -1;
    }

    // Write the file to a new filename
    char new_filename[MAX_LINE_LENGTH];
    sprintf(new_filename, "%s.new", argv[1]);
    if (write_file(new_filename, file) != 0) {
        return -1;
    }

    // Free the memory allocated for the file structure
    free_file(file);

    // Return 0 on success
    return 0;
}