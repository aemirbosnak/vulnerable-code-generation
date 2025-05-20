//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_LINES 1000
#define MAX_TEXT_LEN 1000

typedef struct {
    char *text;
    int len;
} TextLine;

typedef struct {
    TextLine *lines;
    int num_lines;
} TextBlock;

void add_line(TextBlock *block, const char *line) {
    TextLine *new_line = malloc(sizeof(TextLine));
    new_line->text = strdup(line);
    new_line->len = strlen(line);
    block->lines = realloc(block->lines, sizeof(TextLine) * (block->num_lines + 1));
    block->lines[block->num_lines] = *new_line;
    block->num_lines++;
}

void print_block(const TextBlock *block) {
    for (int i = 0; i < block->num_lines; i++) {
        const TextLine *line = &block->lines[i];
        printf("%s\n", line->text);
    }
}

void free_block(TextBlock *block) {
    for (int i = 0; i < block->num_lines; i++) {
        TextLine *line = &block->lines[i];
        free(line->text);
    }
    free(block->lines);
}

int main() {
    char input_text[MAX_TEXT_LEN];
    fgets(input_text, MAX_TEXT_LEN, stdin);
    input_text[strcspn(input_text, "\n")] = '\0';

    TextBlock block;
    block.lines = NULL;
    block.num_lines = 0;

    char *line = strtok(input_text, "\n");
    while (line!= NULL) {
        add_line(&block, line);
        line = strtok(NULL, "\n");
    }

    int max_width = 0;
    for (int i = 0; i < block.num_lines; i++) {
        TextLine *line = &block.lines[i];
        if (line->len > max_width) {
            max_width = line->len;
        }
    }

    for (int i = 0; i < block.num_lines; i++) {
        TextLine *line = &block.lines[i];
        int padding = (max_width - line->len) / 2;
        printf("%*s%s\n", padding, "", line->text);
    }

    free_block(&block);

    return 0;
}