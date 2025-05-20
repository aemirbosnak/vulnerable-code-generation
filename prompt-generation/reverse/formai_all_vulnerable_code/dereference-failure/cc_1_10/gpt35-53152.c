//FormAI DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define a struct for holding our C syntax data
typedef struct {
    int num_lines;
    char** lines;
} C_Syntax;

// Function to parse a given file containing C code
C_Syntax parse_c_file(char* filename) {

    // Open the file
    FILE* file = fopen(filename, "r");

    // Make sure the file was successfully opened
    if (file == NULL) {
        printf("Error opening file %s!\n", filename);
        exit(1);
    }

    // Create a C_Syntax struct to hold the parsed data
    C_Syntax syntax;
    syntax.num_lines = 0;
    syntax.lines = malloc(sizeof(char*));

    // Parse each line of code in the file
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file)) {

        // Add the line to our C_Syntax struct
        syntax.num_lines++;
        syntax.lines = realloc(syntax.lines, syntax.num_lines * sizeof(char*));
        syntax.lines[syntax.num_lines - 1] = malloc(strlen(buffer) + 1);
        strcpy(syntax.lines[syntax.num_lines - 1], buffer);

    }

    // Close the file
    fclose(file);

    // Return the parsed C syntax
    return syntax;

}

int main() {

    // Parse a sample C file
    C_Syntax syntax = parse_c_file("sample.c");

    // Print out the parsed code
    printf("Parsed C syntax:\n");
    for (int i = 0; i < syntax.num_lines; i++) {
        printf("%s", syntax.lines[i]);
    }

    // Free memory used by the syntax data
    for (int i = 0; i < syntax.num_lines; i++) {
        free(syntax.lines[i]);
    }
    free(syntax.lines);

    return 0;
}