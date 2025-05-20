//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100000

typedef struct {
    char *text;
    int length;
} Line;

int main() {
    FILE *file;
    char *filename = "example.txt";
    Line *lines = NULL;
    int num_lines = 0;
    int line_length = 0;
    char line[MAX_LINE_LENGTH];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
            line_length--;
        }

        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines in file %s\n", filename);
            exit(1);
        }

        lines = realloc(lines, sizeof(Line) * (num_lines + 1));
        lines[num_lines].text = malloc(line_length + 1);
        strcpy(lines[num_lines].text, line);
        lines[num_lines].length = line_length;

        num_lines++;
    }

    fclose(file);

    printf("Number of lines in file %s: %d\n", filename, num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i].text);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);

    return 0;
}