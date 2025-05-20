//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int main(int argc, char *argv[]) {

    // Check if correct number of arguments are passed
    if (argc != 2) {
        printf("Usage: ./sherlock <file_name>\n");
        exit(1);
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "r");

    // Check if file exists
    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    // We will store all the lines in an array of strings
    char **lines = malloc(MAX_LINES * sizeof(char*));
    int line_count = 0;

    // Read all the lines from the file
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        // Allocate memory for the line and copy it into the array
        lines[line_count] = malloc((strlen(line) + 1) * sizeof(char));
        strcpy(lines[line_count], line);
        line_count++;
    }
    free(line);

    // Close the file
    fclose(file);

    // Search for the keyword "murder" in all the lines
    for (int i = 0; i < line_count; i++) {
        if (strstr(lines[i], "murder") != NULL) {
            printf("Elementary, my dear Watson! Found a murder on line %d.\n", i+1);
        }
    }

    // Free memory allocated for the lines array
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}