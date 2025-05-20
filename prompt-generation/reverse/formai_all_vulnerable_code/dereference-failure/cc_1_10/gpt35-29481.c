//FormAI DATASET v1.0 Category: Data recovery tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 255
#define MAX_DATA_SIZE 1024

typedef struct Data {
    char filename[MAX_FILE_NAME_SIZE];
    char* content;
    int size;
} Data;

int searchFile(char* fileName, FILE* disk) {
    char buffer[MAX_FILE_NAME_SIZE];
    int found = 0;
    while (!feof(disk)) {
        fread(buffer, sizeof(char), MAX_FILE_NAME_SIZE, disk);
        if (strcmp(buffer, fileName) == 0) {
            found = 1;
            break;
        }
        fseek(disk, MAX_DATA_SIZE - MAX_FILE_NAME_SIZE, SEEK_CUR);
    }
    return found;
}

Data* recoverFile(char* fileName, FILE* disk) {
    Data* file;
    if (searchFile(fileName, disk)) {
        file = (Data*) malloc(sizeof(Data));
        strcpy(file->filename, fileName);
        file->content = (char*) malloc(MAX_DATA_SIZE - MAX_FILE_NAME_SIZE);
        fread(file->content, sizeof(char), MAX_DATA_SIZE - MAX_FILE_NAME_SIZE, disk);
        file->size = MAX_DATA_SIZE - MAX_FILE_NAME_SIZE;
        return file;
    }
    return NULL;
}

int main() {
    FILE* disk = fopen("disk.img", "r");
    if (disk == NULL) {
        printf("Error: could not open disk image.\n");
        return 1;
    }

    Data* file = recoverFile("example.txt", disk);
    if (file != NULL) {
        printf("File found:\n\tName: %s\n\tSize: %d\n\tContent: %s\n", file->filename, file->size, file->content);
        free(file->content);
        free(file);
    } else {
        printf("File not found.\n");
    }

    fclose(disk);
    return 0;
}