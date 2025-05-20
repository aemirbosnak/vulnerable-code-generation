//Falcon-180B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME_SIZE 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *file_name;
    FILE *fp;
    char **lines;
    int num_lines;
} File;

void init_file(File *file, char *file_name) {
    file->file_name = strdup(file_name);
    file->fp = fopen(file_name, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
    file->lines = NULL;
    file->num_lines = 0;
}

void read_lines(File *file) {
    char line[MAX_LINE_SIZE];
    int line_num = 0;
    while (fgets(line, MAX_LINE_SIZE, file->fp)!= NULL) {
        line_num++;
        file->lines = realloc(file->lines, sizeof(char *) * line_num);
        file->lines[line_num - 1] = strdup(line);
        file->num_lines++;
    }
}

void print_lines(File *file) {
    int i;
    for (i = 0; i < file->num_lines; i++) {
        printf("%d: %s\n", i + 1, file->lines[i]);
    }
}

void free_file(File *file) {
    int i;
    if (file->fp!= NULL) {
        fclose(file->fp);
    }
    if (file->lines!= NULL) {
        for (i = 0; i < file->num_lines; i++) {
            free(file->lines[i]);
        }
        free(file->lines);
    }
    free(file->file_name);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: No file name specified\n");
        exit(1);
    }
    File file;
    init_file(&file, argv[1]);
    read_lines(&file);
    print_lines(&file);
    free_file(&file);
    return 0;
}