//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char *filename;
    FILE *file;
    char *line;
    int line_number;
} Ebook;

Ebook *open_ebook(char *filename) {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->filename = filename;
    ebook->file = fopen(filename, "r");
    if (ebook->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    ebook->line = malloc(MAX_LINE_LENGTH);
    ebook->line_number = 1;
    return ebook;
}

void close_ebook(Ebook *ebook) {
    fclose(ebook->file);
    free(ebook->filename);
    free(ebook->line);
    free(ebook);
}

char *read_line(Ebook *ebook) {
    char *line = fgets(ebook->line, MAX_LINE_LENGTH, ebook->file);
    if (line == NULL) {
        printf("Error: End of file reached\n");
        exit(1);
    }
    ebook->line_number++;
    return line;
}

int main() {
    Ebook *ebook = open_ebook("example.txt");
    char *line = read_line(ebook);
    while (line!= NULL) {
        printf("%d: %s", ebook->line_number, line);
        line = read_line(ebook);
    }
    close_ebook(ebook);
    return 0;
}