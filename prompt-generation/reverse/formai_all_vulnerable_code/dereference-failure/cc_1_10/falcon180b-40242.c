//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int file_size;
} EBook;

EBook *read_ebook(FILE *file) {
    EBook *ebook = malloc(sizeof(EBook));
    ebook->lines = NULL;
    ebook->num_lines = 0;
    ebook->file_size = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        Line *new_line = malloc(sizeof(Line));
        new_line->text = strdup(line);
        new_line->length = length;
        ebook->lines = realloc(ebook->lines, sizeof(Line) * ++ebook->num_lines);
        ebook->lines[ebook->num_lines - 1] = *new_line;
        ebook->file_size += length + 1;
    }

    return ebook;
}

void print_ebook(EBook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s", ebook->lines[i].text);
    }
}

void free_ebook(EBook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    free(ebook);
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    EBook *ebook = read_ebook(file);
    print_ebook(ebook);

    free_ebook(ebook);
    fclose(file);

    return 0;
}