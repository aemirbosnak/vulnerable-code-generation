//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 80

typedef struct {
    char *text;
    int length;
} Line;

Line lines[MAX_LINES];
int num_lines = 0;

void add_line(char *line) {
    if (num_lines >= MAX_LINES) {
        printf("Error: Too many lines!\n");
        exit(1);
    }

    lines[num_lines].text = malloc(strlen(line) + 1);
    if (lines[num_lines].text == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    strcpy(lines[num_lines].text, line);
    lines[num_lines].length = strlen(line);

    num_lines++;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LEN];
    int i;

    file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        add_line(line);
    }

    fclose(file);

    for (i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i].text);
    }

    for (i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }

    return 0;
}