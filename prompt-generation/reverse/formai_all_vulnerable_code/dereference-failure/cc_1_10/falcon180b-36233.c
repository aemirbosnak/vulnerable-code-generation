//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10000

typedef struct {
    char *line;
    int indent;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int indent;
} Block;

void indent(Block *block) {
    block->indent += 4;
}

void unindent(Block *block) {
    block->indent -= 4;
}

void add_line(Block *block, char *line) {
    Line *new_line = malloc(sizeof(Line));
    new_line->line = strdup(line);
    new_line->indent = block->indent;
    block->lines = realloc(block->lines, sizeof(Line) * (block->num_lines + 1));
    block->lines[block->num_lines] = *new_line;
    block->num_lines++;
}

void print_block(Block *block) {
    for (int i = 0; i < block->num_lines; i++) {
        for (int j = 0; j < block->lines[i].indent; j++) {
            printf(" ");
        }
        printf("%s", block->lines[i].line);
        printf("\n");
    }
}

void print_html(char *html) {
    Block block = {0};
    char *line = strtok(html, "\n");
    while (line!= NULL) {
        if (strlen(line) > MAX_LINE_LENGTH) {
            printf("Error: Line length exceeds maximum limit.\n");
            exit(1);
        }
        add_line(&block, line);
        line = strtok(NULL, "\n");
    }
    print_block(&block);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    char *html = NULL;
    size_t size = 0;
    while ((getline(&html, &size, file))!= -1) {
        html[strcspn(html, "\r")] = '\0';
        print_html(html);
    }
    free(html);
    return 0;
}