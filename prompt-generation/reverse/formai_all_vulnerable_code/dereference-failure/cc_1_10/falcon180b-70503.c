//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 100000

typedef struct {
    char *text;
    int length;
} Line;

int main() {
    FILE *ebook_file;
    Line *lines = NULL;
    int num_lines = 0;
    int line_length;
    char line_buffer[MAX_LINE_LENGTH];

    ebook_file = fopen("example_ebook.txt", "r");

    if (ebook_file == NULL) {
        printf("Error: Could not open ebook file.\n");
        exit(1);
    }

    while (fgets(line_buffer, MAX_LINE_LENGTH, ebook_file)!= NULL) {
        line_length = strlen(line_buffer);

        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: Ebook is too large.\n");
            exit(1);
        }

        lines = realloc(lines, sizeof(Line) * (num_lines + 1));

        lines[num_lines].text = malloc(line_length + 1);
        strcpy(lines[num_lines].text, line_buffer);
        lines[num_lines].length = line_length;

        num_lines++;
    }

    fclose(ebook_file);

    printf("Ebook loaded successfully.\n");

    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i, lines[i].text);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }

    free(lines);

    return 0;
}