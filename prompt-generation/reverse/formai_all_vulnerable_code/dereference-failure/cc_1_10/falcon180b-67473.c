//Falcon-180B DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
} FileHandle;

void open_file(FileHandle *fh, const char *filename) {
    fh->filename = strdup(filename);
    fh->file = fopen(filename, "r");
    if (fh->file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
}

void close_file(FileHandle *fh) {
    if (fh->file!= NULL) {
        fclose(fh->file);
        free(fh->filename);
    }
}

int read_line(char *buffer, int max_size, FILE *file) {
    char c;
    int count = 0;
    while ((c = fgetc(file))!= EOF) {
        if (count >= max_size - 1) {
            buffer[count] = '\0';
            break;
        }
        buffer[count++] = c;
    }
    buffer[count] = '\0';
    return count;
}

int main() {
    FileHandle fh;
    char buffer[MAX_LINE_SIZE];
    int line_count = 0;

    open_file(&fh, "example.txt");

    while (read_line(buffer, MAX_LINE_SIZE, fh.file) > 0) {
        printf("%d: %s\n", ++line_count, buffer);
    }

    close_file(&fh);

    return 0;
}