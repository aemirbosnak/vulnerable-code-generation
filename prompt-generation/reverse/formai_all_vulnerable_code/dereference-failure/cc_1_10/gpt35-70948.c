//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[50];
    int size;
    char* data;
};

void syncFiles(struct file f1, struct file f2) {
    // check if files have same name
    if (strcmp(f1.name, f2.name) != 0) {
        printf("Error: Files have different names\n");
        return;
    }

    // check if files have same size
    if (f1.size != f2.size) {
        printf("Error: Files are of different size\n");
        return;
    }

    // check if file data is the same
    if (memcmp(f1.data, f2.data, f1.size) != 0) {
        printf("Error: File data is different\n");
        return;
    }

    // files are synced
    printf("Files are in sync\n");
}

int main() {
    // create two file objects
    struct file file1, file2;

    // set file1 name and data
    strcpy(file1.name, "file1.txt");
    file1.size = 10;
    file1.data = malloc(sizeof(char) * file1.size);
    strcpy(file1.data, "File 1");

    // set file2 name and data
    strcpy(file2.name, "file1.txt");
    file2.size = 10;
    file2.data = malloc(sizeof(char) * file2.size);
    strcpy(file2.data, "File 1");

    // sync the files
    syncFiles(file1, file2);

    // free the file data
    free(file1.data);
    free(file2.data);

    return 0;
}