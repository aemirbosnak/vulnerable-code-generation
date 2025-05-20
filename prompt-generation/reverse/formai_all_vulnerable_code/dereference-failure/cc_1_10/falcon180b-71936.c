//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

void print_pattern(Line *lines, int num_lines) {
    printf("Pattern:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%s", lines[i].line);
        for (int j = 0; j < MAX_LINE_LENGTH - strlen(lines[i].line); j++) {
            printf(" ");
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    Line *lines = malloc(MAX_NUM_LINES * sizeof(Line));
    int num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: Reached maximum number of lines (%d)\n", MAX_NUM_LINES);
            break;
        }
        lines[num_lines].line = strdup(line);
        lines[num_lines].length = strlen(line);
        num_lines++;
    }

    fclose(file);

    if (num_lines == 0) {
        printf("Error: File is empty\n");
        return 1;
    }

    print_pattern(lines, num_lines);

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);

    return 0;
}