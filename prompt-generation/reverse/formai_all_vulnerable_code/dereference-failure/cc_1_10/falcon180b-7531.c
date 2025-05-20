//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* filename;
    FILE* fp;
    char* line;
    size_t line_size;
} EbookReader;

EbookReader* ebook_reader_create(const char* filename) {
    EbookReader* reader = malloc(sizeof(EbookReader));
    reader->filename = filename;
    reader->fp = fopen(filename, "r");
    if (reader->fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    reader->line = malloc(MAX_LINE_LENGTH);
    reader->line_size = 0;
    return reader;
}

void ebook_reader_destroy(EbookReader* reader) {
    if (reader->fp!= NULL) {
        fclose(reader->fp);
    }
    free(reader->line);
    free(reader);
}

char* ebook_reader_read_line(EbookReader* reader) {
    char* result = NULL;
    if (reader->line_size > 0) {
        result = reader->line;
        reader->line_size = 0;
    } else {
        if (fgets(reader->line, MAX_LINE_LENGTH, reader->fp) == NULL) {
            result = NULL;
        } else {
            result = reader->line;
            while (result[strlen(result) - 1] == '\n') {
                result[strlen(result) - 1] = '\0';
            }
            reader->line_size = strlen(result);
        }
    }
    return result;
}

int main() {
    EbookReader* reader = ebook_reader_create("example.txt");
    char* line;
    while ((line = ebook_reader_read_line(reader))!= NULL) {
        printf("%s", line);
    }
    ebook_reader_destroy(reader);
    return 0;
}