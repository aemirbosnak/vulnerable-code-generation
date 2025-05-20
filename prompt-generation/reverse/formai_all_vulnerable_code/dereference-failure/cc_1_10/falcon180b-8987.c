//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
    int linenumber;
} File;

void initFile(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    file->linenumber = 0;
}

int getNextLine(File *file, char *buffer, int maxlen) {
    char ch;
    int len = 0;

    while ((ch = fgetc(file->fp))!= EOF && len < maxlen - 1) {
        if (ch == '\n') {
            ++file->linenumber;
        }

        buffer[len++] = tolower(ch);
    }

    buffer[len] = '\0';

    if (len == 0) {
        return 0;
    }

    return 1;
}

void closeFile(File *file) {
    fclose(file->fp);
    free(file->filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char buffer[MAX_LINE_LENGTH];
    File file;

    initFile(&file, filename);

    while (getNextLine(&file, buffer, sizeof(buffer))) {
        printf("%4d: %s\n", file.linenumber, buffer);
    }

    closeFile(&file);

    return 0;
}