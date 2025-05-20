//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    FILE *file;
} File;

void init_file(File *file, char *file_name) {
    strncpy(file->file_name, file_name, MAX_FILE_NAME_LEN);
    file->file = fopen(file_name, "r");
    if (file->file == NULL) {
        printf("Error: could not open file %s\n", file_name);
        exit(1);
    }
}

int compare_lines(const void *a, const void *b) {
    char *line_a = *(char **)a;
    char *line_b = *(char **)b;
    return strcmp(line_a, line_b);
}

void synchronize_files(int num_files, File *files) {
    char **lines = malloc(num_files * sizeof(char *));
    for (int i = 0; i < num_files; i++) {
        lines[i] = malloc(MAX_LINE_LEN);
        fgets(lines[i], MAX_LINE_LEN, files[i].file);
    }
    qsort(lines, num_files, sizeof(char *), compare_lines);

    for (int i = 0; i < num_files; i++) {
        fprintf(stdout, "%s:\n%s", files[i].file_name, lines[i]);
        free(lines[i]);
    }
    free(lines);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s file1 file2...\n", argv[0]);
        return 1;
    }

    int num_files = argc - 1;
    File files[num_files];

    for (int i = 0; i < num_files; i++) {
        init_file(&files[i], argv[i + 1]);
    }

    synchronize_files(num_files, files);

    for (int i = 0; i < num_files; i++) {
        fclose(files[i].file);
    }

    return 0;
}