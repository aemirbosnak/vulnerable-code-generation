//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int line_number;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
} file_t;

file_t *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    file_t *file = malloc(sizeof(file_t));
    if (file == NULL) {
        perror("Error allocating memory for file");
        fclose(fp);
        return NULL;
    }

    file->lines = NULL;
    file->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        line_t *line_struct = malloc(sizeof(line_t));
        if (line_struct == NULL) {
            perror("Error allocating memory for line");
            fclose(fp);
            free(file);
            return NULL;
        }

        line_struct->line = strdup(line);
        if (line_struct->line == NULL) {
            perror("Error duplicating line");
            fclose(fp);
            free(file);
            free(line_struct);
            return NULL;
        }

        line_struct->line_number = file->num_lines + 1;

        file->lines = realloc(file->lines, (file->num_lines + 1) * sizeof(line_t));
        if (file->lines == NULL) {
            perror("Error reallocating memory for lines");
            fclose(fp);
            free(file);
            free(line_struct);
            return NULL;
        }

        file->lines[file->num_lines] = *line_struct;
        file->num_lines++;
    }

    fclose(fp);
    return file;
}

void free_file(file_t *file) {
    for (int i = 0; i < file->num_lines; i++) {
        free(file->lines[i].line);
    }
    free(file->lines);
    free(file);
}

void print_file(file_t *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%d %s", file->lines[i].line_number, file->lines[i].line);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file_t *file = read_file(argv[1]);
    if (file == NULL) {
        return EXIT_FAILURE;
    }

    print_file(file);

    free_file(file);

    return EXIT_SUCCESS;
}