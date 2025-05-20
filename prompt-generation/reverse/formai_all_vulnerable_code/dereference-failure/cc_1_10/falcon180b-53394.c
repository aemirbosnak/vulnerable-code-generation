//Falcon-180B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
} File;

void init_file(File *file, const char *filename) {
    file->filename = (char *)malloc(strlen(filename) + 1);
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->line_count = 0;
}

void close_file(File *file) {
    fclose(file->file);
    free(file->filename);
}

int read_line(File *file, char *buffer, int max_size) {
    char c;
    int i = 0;
    while ((c = fgetc(file->file))!= EOF) {
        if (i >= max_size - 1) {
            printf("Error: Line too long\n");
            exit(1);
        }
        buffer[i++] = c;
        if (c == '\n') {
            file->line_count++;
            break;
        }
    }
    buffer[i] = '\0';
    return i;
}

int main() {
    File file;
    char buffer[MAX_LINE_SIZE];
    init_file(&file, "example.txt");
    while (read_line(&file, buffer, MAX_LINE_SIZE) > 0) {
        printf("%d: %s", file.line_count, buffer);
    }
    close_file(&file);
    return 0;
}