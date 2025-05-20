//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// introspect() examines the code of the program and prints a detailed summary.
void introspect() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int n = 0;
    int num_vars = 0;
    int num_funcs = 0;
    int num_comments = 0;
    int num_lines = 0;

    // Open the source file for reading.
    fp = fopen("log_analysis.c", "r");
    if (fp == NULL) {
        perror("fopen() failed");
        return;
    }

    // Read each line of the source file.
    while ((read = getline(&line, &len, fp)) != -1) {
        num_lines++;

        // Check if the line is a variable declaration.
        if (strstr(line, "int") || strstr(line, "float") || strstr(line, "char")) {
            num_vars++;
        }

        // Check if the line is a function declaration.
        if (strstr(line, "void") || strstr(line, "int") || strstr(line, "float") || strstr(line, "char")) {
            num_funcs++;
        }

        // Check if the line is a comment.
        if (strstr(line, "//")) {
            num_comments++;
        }
    }

    // Close the source file.
    fclose(fp);

    // Print the summary of the code.
    printf("Number of lines: %d\n", num_lines);
    printf("Number of variables: %d\n", num_vars);
    printf("Number of functions: %d\n", num_funcs);
    printf("Number of comments: %d\n", num_comments);

    // Free the allocated memory.
    free(line);
}

int main() {
    // Call the introspect() function to examine the code.
    introspect();

    return 0;
}