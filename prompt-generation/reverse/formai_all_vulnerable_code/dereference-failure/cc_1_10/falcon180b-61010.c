//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FILE_LEN 10240

typedef struct {
    char *filename;
    FILE *file;
    char *buffer;
    int len;
} Ebook;

Ebook *ebook_open(const char *filename) {
    Ebook *ebook = (Ebook *) malloc(sizeof(Ebook));
    ebook->filename = strdup(filename);
    ebook->file = fopen(filename, "r");
    if (ebook->file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    ebook->buffer = (char *) malloc(MAX_FILE_LEN);
    ebook->len = 0;
    return ebook;
}

void ebook_close(Ebook *ebook) {
    if (ebook->file!= NULL) {
        fclose(ebook->file);
    }
    free(ebook->filename);
    free(ebook->buffer);
    free(ebook);
}

char *ebook_readline(Ebook *ebook) {
    char *line = NULL;
    if (ebook->len == 0) {
        line = fgets(ebook->buffer, MAX_FILE_LEN, ebook->file);
        if (line == NULL) {
            return NULL;
        }
        ebook->len = strlen(line);
    } else {
        line = strndup(ebook->buffer, ebook->len);
        ebook->len = 0;
    }
    return line;
}

int main() {
    Ebook *ebook = ebook_open("book.txt");
    char *line;
    int line_num = 0;
    while ((line = ebook_readline(ebook))!= NULL) {
        printf("%d: %s", line_num++, line);
    }
    ebook_close(ebook);
    return 0;
}