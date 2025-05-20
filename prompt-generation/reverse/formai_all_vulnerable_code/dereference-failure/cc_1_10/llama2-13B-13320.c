//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to read a file line by line and store in an array
void readFile(char *filename, char **lines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        lines[i] = line;
        i++;
    }

    fclose(file);
}

// Function to write a file line by line
void writeFile(char *filename, char **lines) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int i = 0;
    for (; i < sizeof(lines) / sizeof(lines[0]); i++) {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);
}

int main() {
    char filename[] = "example.txt";
    char *lines[10];

    // Read file line by line
    readFile(filename, lines);

    // Print the lines
    for (int i = 0; i < sizeof(lines) / sizeof(lines[0]); i++) {
        printf("%d: %s\n", i, lines[i]);
    }

    // Write the lines to a new file
    char newFilename[] = "new_example.txt";
    writeFile(newFilename, lines);

    return 0;
}