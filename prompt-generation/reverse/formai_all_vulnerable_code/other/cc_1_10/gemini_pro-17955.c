//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char **lines;
    int num_lines;
    int max_num_lines;
} ebook_t;

ebook_t *ebook_new() {
    ebook_t *ebook = malloc(sizeof(ebook_t));
    assert(ebook != NULL);
    ebook->lines = malloc(sizeof(char *) * MAX_LINES);
    assert(ebook->lines != NULL);
    ebook->num_lines = 0;
    ebook->max_num_lines = MAX_LINES;
    return ebook;
}

void ebook_free(ebook_t *ebook) {
    assert(ebook != NULL);
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i]);
    }
    free(ebook->lines);
    free(ebook);
}

bool ebook_load_from_file(ebook_t *ebook, const char *filename) {
    assert(ebook != NULL);
    assert(filename != NULL);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return false;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (ebook->num_lines >= ebook->max_num_lines) {
            ebook->lines = realloc(ebook->lines, sizeof(char *) * ebook->max_num_lines * 2);
            assert(ebook->lines != NULL);
            ebook->max_num_lines *= 2;
        }
        ebook->lines[ebook->num_lines] = malloc(strlen(line) + 1);
        assert(ebook->lines[ebook->num_lines] != NULL);
        strcpy(ebook->lines[ebook->num_lines], line);
        ebook->num_lines++;
    }
    fclose(fp);
    return true;
}

void ebook_print(const ebook_t *ebook) {
    assert(ebook != NULL);
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s", ebook->lines[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    ebook_t *ebook = ebook_new();
    if (!ebook_load_from_file(ebook, argv[1])) {
        fprintf(stderr, "Error loading ebook from file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    ebook_print(ebook);
    ebook_free(ebook);
    return EXIT_SUCCESS;
}