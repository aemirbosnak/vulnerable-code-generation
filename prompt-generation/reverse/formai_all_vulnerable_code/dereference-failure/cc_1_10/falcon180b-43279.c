//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int line_num;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Text;

Text *read_text(FILE *file) {
    Text *text = malloc(sizeof(Text));
    text->lines = NULL;
    text->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Line *new_line = malloc(sizeof(Line));
        new_line->text = strdup(line);
        new_line->line_num = text->num_lines;
        text->lines = realloc(text->lines, sizeof(Line) * ++text->num_lines);
        text->lines[text->num_lines - 1] = *new_line;
    }

    return text;
}

void write_text(FILE *file, Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        fprintf(file, "%s", text->lines[i].text);
    }
}

int main() {
    srand(time(NULL));
    int num_lines = rand() % MAX_NUM_LINES + 1;
    Text *text = read_text(stdin);

    int num_swaps = 0;
    for (int i = 0; i < num_lines; i++) {
        int j = rand() % num_lines;
        if (i!= j) {
            Line temp = text->lines[i];
            text->lines[i] = text->lines[j];
            text->lines[j] = temp;
            num_swaps++;
        }
    }

    printf("Number of swaps: %d\n", num_swaps);
    write_text(stdout, text);

    return 0;
}