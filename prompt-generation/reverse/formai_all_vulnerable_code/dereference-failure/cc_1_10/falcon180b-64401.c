//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    char *buffer;
    int buffer_size;
    int current_line;
} Ebook;

void ebook_init(Ebook *ebook, const char *filename) {
    ebook->filename = strdup(filename);
    ebook->file = fopen(filename, "r");
    if (ebook->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    ebook->buffer = malloc(MAX_LINE_LENGTH);
    ebook->buffer_size = MAX_LINE_LENGTH;
    ebook->current_line = 0;
}

void ebook_free(Ebook *ebook) {
    fclose(ebook->file);
    free(ebook->filename);
    free(ebook->buffer);
    free(ebook);
}

char *ebook_get_line(Ebook *ebook) {
    if (ebook->current_line >= ebook->buffer_size) {
        ebook->buffer_size += MAX_LINE_LENGTH;
        ebook->buffer = realloc(ebook->buffer, ebook->buffer_size);
    }
    fseek(ebook->file, 0, SEEK_SET);
    fgets(ebook->buffer + ebook->current_line, MAX_LINE_LENGTH - ebook->current_line, ebook->file);
    ebook->current_line += strlen(ebook->buffer + ebook->current_line);
    return ebook->buffer;
}

int main(int argc, char *argv[]) {
    Ebook ebook;
    ebook_init(&ebook, argv[1]);

    while (ebook_get_line(&ebook)!= NULL) {
        printf("%s", ebook.buffer);
    }

    ebook_free(&ebook);
    return 0;
}