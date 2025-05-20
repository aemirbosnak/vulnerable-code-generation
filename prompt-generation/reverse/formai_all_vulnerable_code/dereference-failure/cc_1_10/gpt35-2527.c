//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>

/* This program demonstrates a unique example of data mining in C language using file input/output and string operations. */

int main() {
    // Declare necessary variables
    FILE *file;
    char line[100];
    char *token;
    char *keywords[50];
    int i = 0;

    // Open the input file
    file = fopen("input.txt", "r");

    // If file could not be opened
    if (file == NULL) {
        printf("Error: Could not open input file!\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, 100, file)) {

        // Extract keywords from current line
        token = strtok(line, " ");

        // While there are still keywords in the line
        while (token != NULL) {

            // Check if keyword already exists in array
            int exists = 0;
            for (int j=0; j<i; j++) {
                if (strcmp(token, keywords[j]) == 0) {
                    exists = 1;
                    break;
                }
            }

            // If keyword does not exist, add it to array
            if (!exists) {
                keywords[i] = strdup(token);
                i++;
            }

            // Get next keyword in line
            token = strtok(NULL, " ");
        }
    }

    // Close input file
    fclose(file);

    // Open output file
    file = fopen("output.txt", "w");

    // If file could not be opened
    if (file == NULL) {
        printf("Error: Could not open output file!\n");
        return 1;
    }

    // Write keywords to output file
    for (int j=0; j<i; j++) {
        fprintf(file, "%s\n", keywords[j]);
    }

    // Close output file
    fclose(file);

    // Print success message
    printf("Data mining complete!\n");

    return 0;
}