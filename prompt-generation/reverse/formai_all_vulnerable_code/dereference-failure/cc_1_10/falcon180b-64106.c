//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to read the ebook file and return the number of lines
int read_ebook(char *filename, char **lines) {
    FILE *f;
    char line[MAX_LINE_SIZE];
    int num_lines = 0;

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, f)!= NULL) {
        lines[num_lines] = malloc(strlen(line) + 1);
        strcpy(lines[num_lines], line);
        num_lines++;
    }

    fclose(f);
    return num_lines;
}

// Function to print the ebook lines
void print_ebook(int num_lines, char **lines) {
    int i;

    for (i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }
}

// Function to read the ebook recursively
void read_ebook_recursive(char *filename) {
    char **lines;
    int num_lines;

    // Read the ebook file
    num_lines = read_ebook(filename, lines);

    // Print the ebook lines
    print_ebook(num_lines, lines);

    // Free the memory used by the ebook lines
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s ebook_file\n", argv[0]);
        exit(1);
    }

    read_ebook_recursive(argv[1]);

    return 0;
}