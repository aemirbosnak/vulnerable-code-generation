//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

typedef struct {
    char *text;
    int length;
} Line;

Line *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    Line *lines = malloc(sizeof(Line));
    int num_lines = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        lines[num_lines].text = strdup(buffer);
        lines[num_lines].length = strlen(lines[num_lines].text);
        num_lines++;

        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: File '%s' has too many lines (max %d).\n", filename, MAX_NUM_LINES);
            exit(1);
        }
    }

    fclose(file);
    return lines;
}

void print_line_numbers(Line *lines, int num_lines) {
    printf("Line numbers:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i].text);
    }
}

int search_line(Line *lines, int num_lines, const char *search_text) {
    for (int i = 0; i < num_lines; i++) {
        if (strstr(lines[i].text, search_text)!= NULL) {
            printf("Found line %d: %s\n", i + 1, lines[i].text);
            return i + 1;
        }
    }

    printf("Line not found.\n");
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <search_text>\n", argv[0]);
        exit(1);
    }

    const char *filename = argv[1];
    const char *search_text = argv[2];

    Line *lines = read_file(filename);
    int num_lines = lines!= NULL? lines->length : 0;

    int search_result = search_line(lines, num_lines, search_text);

    free(lines);
    return 0;
}