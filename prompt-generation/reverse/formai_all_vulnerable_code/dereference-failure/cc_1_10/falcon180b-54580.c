//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} TextLine;

typedef struct {
    TextLine *lines;
    int num_lines;
} TextBlock;

void add_line(TextBlock *block, char *line) {
    if (block->num_lines >= MAX_LINE_LENGTH) {
        printf("Error: Too many lines.\n");
        exit(1);
    }
    block->lines[block->num_lines] = (TextLine){.text = line,.length = strlen(line)};
    block->num_lines++;
}

void print_block(TextBlock *block) {
    for (int i = 0; i < block->num_lines; i++) {
        printf("%s\n", block->lines[i].text);
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    TextBlock block = {0};

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&block, line);
    }

    fclose(file);

    print_block(&block);

    return 0;
}