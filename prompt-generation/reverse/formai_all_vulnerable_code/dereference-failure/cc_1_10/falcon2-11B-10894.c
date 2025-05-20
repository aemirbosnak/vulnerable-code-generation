//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_struct {
    char filename[100];
    int size;
    int ref_count;
} file_t;

int main() {
    file_t *files = malloc(sizeof(file_t));
    strcpy(files->filename, "file1");
    files->size = 1024;
    files->ref_count = 1;

    file_t *file2 = malloc(sizeof(file_t));
    strcpy(file2->filename, "file2");
    file2->size = 2048;
    file2->ref_count = 1;

    printf("Created files: file1 and file2\n");

    file_t *new_file = malloc(sizeof(file_t));
    strcpy(new_file->filename, "file3");
    new_file->size = 4096;
    new_file->ref_count = 1;

    printf("Created new file: file3\n");

    printf("Printing file sizes:\n");
    for (int i = 0; i < 3; i++) {
        printf("File %d: %d bytes\n", i + 1, files[i].size);
    }

    printf("Opening file1 for reading:\n");
    FILE *fp1 = fopen("file1", "r");
    if (fp1 == NULL) {
        printf("Failed to open file1 for reading\n");
        return 1;
    }

    printf("Reading file1:\n");
    fread(files, sizeof(file_t), 1, fp1);
    fclose(fp1);

    printf("Printing file sizes after reading:\n");
    for (int i = 0; i < 3; i++) {
        printf("File %d: %d bytes\n", i + 1, files[i].size);
    }

    printf("Deleting file1:\n");
    free(files);
    free(file2);
    free(new_file);

    return 0;
}