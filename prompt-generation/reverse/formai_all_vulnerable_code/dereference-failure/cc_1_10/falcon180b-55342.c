//Falcon-180B DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_NUM_LINES 1000

struct Line {
    char *text;
    int length;
};

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    struct Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    int longest_line_length = 0;
    int i;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Allocate memory for line text
        lines[num_lines].text = malloc(strlen(line) + 1);
        if (lines[num_lines].text == NULL) {
            printf("Error: Could not allocate memory.\n");
            return 1;
        }

        // Copy line text into allocated memory
        strcpy(lines[num_lines].text, line);

        // Update length of longest line
        if (lines[num_lines].length > longest_line_length) {
            longest_line_length = lines[num_lines].length;
        }

        // Increment number of lines
        num_lines++;
    }

    // Close file
    fclose(file);

    // Print longest line
    printf("Longest line: ");
    for (i = 0; i < longest_line_length; i++) {
        printf("*");
    }
    printf("\n");

    // Print number of lines
    printf("Number of lines: %d\n", num_lines);

    // Free memory allocated for line text
    for (i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }

    return 0;
}