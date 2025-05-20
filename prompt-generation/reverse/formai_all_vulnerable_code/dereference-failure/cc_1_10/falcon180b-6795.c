//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINE_COUNT 10000

// Struct to hold line information
typedef struct {
    char* text;
    int length;
} Line;

// Function to read a line from the file
Line read_line(FILE* file) {
    char buffer[MAX_LINE_LENGTH];
    Line line = {0};

    fgets(buffer, MAX_LINE_LENGTH, file);
    line.text = strdup(buffer);
    line.length = strlen(line.text);

    return line;
}

// Function to free a line
void free_line(Line* line) {
    free(line->text);
    line->text = 0;
    line->length = 0;
}

// Function to print a line
void print_line(Line line) {
    printf("%s\n", line.text);
}

// Function to read all lines from the file
int read_lines(FILE* file, Line* lines, int max_lines) {
    int count = 0;

    while (count < max_lines && fgetc(file)!= EOF) {
        Line line = read_line(file);
        lines[count++] = line;
    }

    return count;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    Line lines[MAX_LINE_COUNT];
    int line_count = read_lines(file, lines, MAX_LINE_COUNT);

    for (int i = 0; i < line_count; i++) {
        print_line(lines[i]);
        free_line(&lines[i]);
    }

    fclose(file);
    return 0;
}