//Falcon-180B DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
} File;

typedef struct {
    char *line;
    int line_number;
} Line;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    File file_info = {filename, file};
    Line lines[MAX_LINE_SIZE];
    int num_lines = 0;

    // Read the file and store each line in an array
    while (fgets(file_info.filename, MAX_LINE_SIZE, file)!= NULL) {
        if (num_lines >= MAX_LINE_SIZE) {
            printf("Error: file has too many lines\n");
            return 1;
        }

        lines[num_lines].line = file_info.filename;
        lines[num_lines++].line_number = num_lines;
    }

    // Sort the lines alphabetically
    qsort(lines, num_lines, sizeof(Line), (int (*)(const void *, const void *))strcmp);

    // Print the sorted lines with line numbers
    printf("Sorted lines:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_number, lines[i].line);
    }

    // Close the file
    fclose(file);
    return 0;
}