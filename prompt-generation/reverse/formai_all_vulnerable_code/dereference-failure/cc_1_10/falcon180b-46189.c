//Falcon-180B DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 100

typedef struct {
    char* filename;
    FILE* file;
} File;

void init_file(File* file, const char* filename) {
    file->filename = (char*)malloc(MAX_FILE_NAME_SIZE);
    strncpy(file->filename, filename, MAX_FILE_NAME_SIZE);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
}

void close_file(File* file) {
    fclose(file->file);
    free(file->filename);
}

char* read_line(File* file) {
    char* line = (char*)malloc(MAX_LINE_SIZE);
    fgets(line, MAX_LINE_SIZE, file->file);
    return line;
}

int main() {
    File file1, file2;
    char* line1, *line2;
    int count = 0;

    init_file(&file1, "file1.txt");
    init_file(&file2, "file2.txt");

    while (1) {
        line1 = read_line(&file1);
        line2 = read_line(&file2);

        if (line1 == NULL) {
            printf("End of file 1\n");
            break;
        } else if (line2 == NULL) {
            printf("End of file 2\n");
            break;
        }

        if (strcmp(line1, line2) == 0) {
            printf("Line %d: %s\n", ++count, line1);
        } else {
            printf("Line %d: %s\n", ++count, line1);
            printf("Line %d: %s\n", ++count, line2);
        }
    }

    close_file(&file1);
    close_file(&file2);

    return 0;
}