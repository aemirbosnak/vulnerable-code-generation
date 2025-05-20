//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUMBER_OF_LINES 1000

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
    int num_lines;
    char **lines;
} File;

int read_file(File *file) {
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    file->lines = (char **) malloc(MAX_NUMBER_OF_LINES * sizeof(char *));

    while (fgets(line, MAX_LINE_LENGTH, file->file)!= NULL) {
        if (num_lines == MAX_NUMBER_OF_LINES) {
            printf("Error: File too large.\n");
            exit(1);
        }
        file->lines[num_lines] = strdup(line);
        num_lines++;
    }

    file->num_lines = num_lines;

    return num_lines;
}

void print_file(File *file) {
    int i;

    for (i = 0; i < file->num_lines; i++) {
        printf("%s\n", file->lines[i]);
    }
}

void free_file(File *file) {
    int i;

    for (i = 0; i < file->num_lines; i++) {
        free(file->lines[i]);
    }
    free(file->lines);
    fclose(file->file);
}

int main() {
    File file;

    printf("Enter filename: ");
    scanf("%s", file.filename);

    file.file = fopen(file.filename, "r");

    if (file.file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int num_lines = read_file(&file);

    if (num_lines == 0) {
        exit(1);
    }

    printf("File contents:\n");
    print_file(&file);

    free_file(&file);

    return 0;
}