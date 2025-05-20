//Falcon-180B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char* filename;
    FILE* file;
    int line_count;
} FileHandler;

void init_file_handler(FileHandler* fh, char* filename) {
    fh->filename = strdup(filename);
    fh->file = fopen(filename, "r");
    if (fh->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fh->line_count = 0;
}

void close_file_handler(FileHandler* fh) {
    fclose(fh->file);
    free(fh->filename);
    free(fh);
}

char* read_line(FileHandler* fh) {
    char* line = malloc(MAX_LINE_SIZE);
    if (fgets(line, MAX_LINE_SIZE, fh->file) == NULL) {
        printf("Error reading line from file\n");
        exit(1);
    }
    fh->line_count++;
    return line;
}

int main() {
    char* filename = "example.txt";
    FileHandler fh;
    init_file_handler(&fh, filename);

    printf("Reading lines from file:\n");
    char* line = read_line(&fh);
    while (line!= NULL) {
        printf("%s", line);
        free(line);
        line = read_line(&fh);
    }

    close_file_handler(&fh);
    return 0;
}