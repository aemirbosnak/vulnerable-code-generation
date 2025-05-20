//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare file pointer and variables
    FILE *fp;
    char filename[] = "data.txt";
    int num_lines = 0;
    int i;

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Count number of lines in file
    while (!feof(fp)) {
        if (fgetc(fp) == '\n') {
            num_lines++;
        }
    }
    rewind(fp);  // Reset file pointer to beginning of file

    // Allocate memory for array of strings
    char **lines = (char **)malloc(num_lines * sizeof(char *));
    for (i = 0; i < num_lines; i++) {
        lines[i] = (char *)malloc(256 * sizeof(char));
    }

    // Read lines from file into array of strings
    i = 0;
    while (fgets(lines[i], 256, fp)) {
        i++;
    }

    // Close file
    fclose(fp);

    // Print out lines in array
    for (i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
    }

    // Free memory used by array of strings
    for (i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}