//Falcon-180B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *filename;
    FILE *fp;
    char *line;
    int line_len;
} FileHandler;

FileHandler *file_handler_create(const char *filename) {
    FileHandler *fh = malloc(sizeof(FileHandler));
    if (fh == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    fh->filename = strdup(filename);
    fh->fp = fopen(filename, "r");
    if (fh->fp == NULL) {
        printf("Error: Cannot open file '%s'.\n", filename);
        exit(1);
    }

    fh->line = malloc(MAX_LINE_LEN);
    if (fh->line == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    fh->line_len = 0;

    return fh;
}

void file_handler_destroy(FileHandler *fh) {
    if (fh == NULL) {
        return;
    }

    fclose(fh->fp);
    free(fh->filename);
    free(fh->line);
    free(fh);
}

char *file_handler_read_line(FileHandler *fh) {
    if (fh == NULL) {
        return NULL;
    }

    char *line = fgets(fh->line, MAX_LINE_LEN, fh->fp);
    if (line == NULL) {
        if (ferror(fh->fp)) {
            printf("Error: Reading file '%s' failed.\n", fh->filename);
            exit(1);
        } else {
            return NULL;
        }
    }

    return line;
}

int main() {
    FileHandler *fh = file_handler_create("test.txt");
    if (fh == NULL) {
        return 1;
    }

    char *line = file_handler_read_line(fh);
    while (line!= NULL) {
        printf("%s", line);
        line = file_handler_read_line(fh);
    }

    file_handler_destroy(fh);

    return 0;
}