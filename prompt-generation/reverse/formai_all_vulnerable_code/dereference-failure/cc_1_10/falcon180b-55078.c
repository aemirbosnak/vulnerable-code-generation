//Falcon-180B DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_STRING_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} File;

void create_file(File *file) {
    file->lines = (Line *) malloc(MAX_NUM_LINES * sizeof(Line));
    file->num_lines = 0;
}

void destroy_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        free(file->lines[i].line);
    }
    free(file->lines);
}

void read_file(File *file, const char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        Line new_line = {.line = strdup(line),.length = strlen(line) };
        if (line_count >= MAX_NUM_LINES) {
            printf("Error: Maximum number of lines exceeded.\n");
            return;
        }
        file->lines[line_count++] = new_line;
    }

    file->num_lines = line_count;
    fclose(fp);
}

void write_file(File *file, const char *filename) {
    FILE *fp = fopen(filename, "w");

    for (int i = 0; i < file->num_lines; i++) {
        fprintf(fp, "%s", file->lines[i].line);
    }

    fclose(fp);
}

void print_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%s\n", file->lines[i].line);
    }
}

int main() {
    File file;
    create_file(&file);

    char input[MAX_LINE_LENGTH];
    printf("Enter filename to read: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    read_file(&file, input);

    char output[MAX_LINE_LENGTH];
    printf("Enter filename to write: ");
    fgets(output, MAX_LINE_LENGTH, stdin);
    output[strcspn(output, "\n")] = '\0';

    write_file(&file, output);

    printf("File contents:\n");
    print_file(&file);

    destroy_file(&file);

    return 0;
}