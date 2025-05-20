//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char** lines;
    int num_lines;
    int current_line;
} Ebook;

Ebook* create_ebook(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    Ebook* ebook = malloc(sizeof(Ebook));
    ebook->lines = NULL;
    ebook->num_lines = 0;
    ebook->current_line = 0;
    char line[1000];
    while (fgets(line, 1000, file)!= NULL) {
        ebook->lines = realloc(ebook->lines, sizeof(char*) * (ebook->num_lines + 1));
        ebook->lines[ebook->num_lines] = malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(ebook->lines[ebook->num_lines], line);
        ebook->num_lines++;
    }
    fclose(file);
    return ebook;
}

void destroy_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i]);
    }
    free(ebook->lines);
    free(ebook);
}

void print_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i]);
    }
}

void next_line(Ebook* ebook) {
    ebook->current_line++;
    if (ebook->current_line >= ebook->num_lines) {
        ebook->current_line = 0;
    }
}

void prev_line(Ebook* ebook) {
    ebook->current_line--;
    if (ebook->current_line < 0) {
        ebook->current_line = ebook->num_lines - 1;
    }
}

int main() {
    char* filename = "example.txt";
    Ebook* ebook = create_ebook(filename);
    print_ebook(ebook);
    next_line(ebook);
    next_line(ebook);
    prev_line(ebook);
    prev_line(ebook);
    destroy_ebook(ebook);
    return 0;
}