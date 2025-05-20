//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File {
    char name[50];
    int size;
    char* data;
} File;

void createFile(File* file, const char* filename, int size) {
    file->size = size;
    file->data = (char*)malloc(size);
    if (!file->data) {
        printf("Error: Failed to allocate memory for file data.\n");
        return;
    }
    strcpy(file->name, filename);
}

void readFile(File* file, FILE* output) {
    fwrite(file->data, sizeof(char), file->size, output);
}

void writeFile(File* file, FILE* output) {
    fwrite(file->data, sizeof(char), file->size, output);
}

void printFile(File* file) {
    printf("Name: %s\nSize: %d bytes\nData:\n", file->name, file->size);
    for (int i = 0; i < file->size; i++) {
        printf("%c", file->data[i]);
    }
    printf("\n");
}

int main() {
    File* file = (File*)malloc(sizeof(File));
    createFile(file, "test.txt", 100);
    FILE* fp = fopen("test.txt", "r");
    readFile(file, fp);
    fclose(fp);
    fp = fopen("test.txt", "w");
    writeFile(file, fp);
    fclose(fp);
    fp = fopen("test.txt", "r");
    printFile(file);
    fclose(fp);
    free(file);
    return 0;
}