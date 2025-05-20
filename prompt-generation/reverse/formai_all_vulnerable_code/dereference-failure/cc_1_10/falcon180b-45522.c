//Falcon-180B DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

char **lines = NULL;
int num_lines = 0;

void add_line(char *line) {
    if (num_lines >= MAX_NUM_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    lines = realloc(lines, sizeof(char *) * (num_lines + 1));
    if (lines == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    lines[num_lines] = strdup(line);
    if (lines[num_lines] == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    num_lines++;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i;

    lines = malloc(sizeof(char *) * (num_lines + 1));
    if (lines == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_lines; i++) {
        lines[i] = NULL;
    }

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(line);
    }

    for (i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
    }

    for (i = 0; i < num_lines; i++) {
        token = strtok(lines[i], " ");
        while (token!= NULL) {
            printf("%s ", token);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    for (i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}