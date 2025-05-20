//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *text;
    int length;
} TextLine;

TextLine *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    TextLine *lines = NULL;
    TextLine line = {0};
    char *buffer = malloc(MAX_LINE_SIZE);

    while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
        line.text = realloc(line.text, line.length + strlen(buffer) + 1);
        strcat(line.text, buffer);
        line.length += strlen(buffer);
    }

    lines = malloc(sizeof(TextLine));
    lines[0] = line;
    free(line.text);

    fclose(file);
    free(buffer);

    return lines;
}

void print_lines(TextLine *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].text);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    TextLine *lines = read_file(argv[1]);
    int num_lines = 1; // The number of lines in the file

    print_lines(lines, num_lines);

    free(lines);
    return 0;
}