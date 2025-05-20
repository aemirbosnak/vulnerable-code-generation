//Falcon-180B DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME_SIZE 256

typedef struct {
    char *filename;
    FILE *file;
} File;

File *open_file(const char *filename) {
    File *f = malloc(sizeof(File));
    if (f == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    f->filename = strdup(filename);
    f->file = fopen(filename, "r");
    if (f->file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    return f;
}

void close_file(File *f) {
    if (f->file!= NULL) {
        fclose(f->file);
    }
    free(f->filename);
    free(f);
}

char *read_line(File *f) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    if (getline(&line, &len, f->file) == -1) {
        if (feof(f->file)) {
            return NULL;
        } else {
            printf("Error: Could not read line from file '%s'\n", f->filename);
            exit(1);
        }
    }
    line[strcspn(line, "\n")] = '\0';
    return line;
}

int main() {
    char input_buffer[MAX_LINE_SIZE];
    char filename[MAX_FILE_NAME_SIZE];
    File *file = NULL;
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    file = open_file(filename);
    if (file == NULL) {
        return 1;
    }
    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        char *line = read_line(file);
        if (line == NULL) {
            break;
        }
        if (strstr(line, input_buffer)!= NULL) {
            printf("%s\n", line);
        }
    }
    close_file(file);
    return 0;
}