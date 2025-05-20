//Gemma-7B DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct FileData {
    char *data;
    int size;
} FileData;

void file_init(FileData *file, char *filename) {
    file->data = malloc(MAX_SIZE);
    file->size = 0;
    FILE *fp = fopen(filename, "r");
    if (fp) {
        char line[MAX_SIZE];
        while (fgets(line, MAX_SIZE, fp) != NULL) {
            file->data = realloc(file->data, file->size + 1);
            file->data[file->size++] = line;
        }
        fclose(fp);
    }
}

void file_append(FileData *file, char *data) {
    file->data = realloc(file->data, file->size + 1);
    file->data[file->size++] = data;
}

void file_write(FileData *file, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp) {
        for (int i = 0; i < file->size; i++) {
            fprintf(fp, "%s\n", file->data[i]);
        }
        fclose(fp);
    }
}

int main() {
    FileData file1;
    file_init(&file1, "Romeo.txt");
    file_append(&file1, "Juliet is my love.");
    file_append(&file1, "They are a pair.");
    file_write(&file1, "Juliet.txt");

    FileData file2;
    file_init(&file2, "Juliet.txt");
    file_append(&file2, "Romeo is my heart.");
    file_append(&file2, "They are forever.");
    file_write(&file2, "Romeo.txt");

    return 0;
}