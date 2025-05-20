//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the ebook file
void read_ebook(char* filename, char** lines) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the lines from the file
    char line[256];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Add the line to the list of lines
        lines[strlen(lines) + 1] = strdup(line);
    }

    // Close the file
    fclose(fp);
}

// Function to print the ebook
void print_ebook(char** lines, int num_lines) {
    // Print each line
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: ebook <filename>\n");
        exit(1);
    }

    // Read the ebook file
    char** lines = (char**)malloc(sizeof(char*) * 100);
    read_ebook(argv[1], lines);

    // Print the ebook
    print_ebook(lines, strlen(lines) - 1);

    // Free the memory
    for (int i = 0; i < strlen(lines) - 1; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}