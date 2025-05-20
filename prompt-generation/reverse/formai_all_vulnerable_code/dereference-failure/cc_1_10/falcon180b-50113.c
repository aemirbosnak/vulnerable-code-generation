//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100000

struct line {
    char *text;
    int length;
};

struct line *lines = NULL;
int num_lines = 0;

void add_line(char *text) {
    if (num_lines >= MAX_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    struct line *new_line = malloc(sizeof(struct line));
    if (new_line == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    new_line->text = strdup(text);
    new_line->length = strlen(text);

    lines = realloc(lines, sizeof(struct line) * ++num_lines);
    lines[num_lines - 1] = *new_line;
}

void print_lines() {
    if (num_lines == 0) {
        printf("No lines found.\n");
        return;
    }

    printf("Total lines: %d\n", num_lines);
    for (int i = 0; i < num_lines; i++) {
        printf("Line %d: %s\n", i + 1, lines[i].text);
    }
}

void free_lines() {
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);
    lines = NULL;
    num_lines = 0;
}

int main() {
    char buffer[1024];
    FILE *file = fopen("logfile.txt", "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        add_line(buffer);
    }

    fclose(file);

    print_lines();

    free_lines();

    return 0;
}