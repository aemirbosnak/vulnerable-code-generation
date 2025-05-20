//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    char ch;

    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading line\n");
        exit(1);
    }

    ch = line[strlen(line) - 1];
    if (ch == '\n') {
        line[strlen(line) - 1] = '\0';
    }

    return line;
}

// Function to recursively read the contents of the file
void read_file(FILE* file, int depth) {
    char* line = read_line(file);

    while (line!= NULL) {
        printf("%*s%s\n", depth * 4, "", line);
        free(line);
        line = read_line(file);
    }
}

int main(int argc, char** argv) {
    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Reading file...\n");
    read_file(file, 0);

    printf("\nDone.\n");
    fclose(file);

    return 0;
}