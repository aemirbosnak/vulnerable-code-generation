//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int modified;
} File;

void read_files(char *directory, int num_files, File *files) {
    char filename[MAX_FILE_NAME_LENGTH];
    for (int i = 0; i < num_files; i++) {
        sprintf(filename, "%s/file_%d.txt", directory, i);
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error: File not found\n");
            exit(1);
        }
        fseek(file, 0, SEEK_END);
        int length = ftell(file);
        rewind(file);
        char *buffer = malloc(length + 1);
        fread(buffer, 1, length, file);
        buffer[length] = '\0';
        strcpy(files[i].name, filename);
        strcpy(files[i].name, filename);
        files[i].modified = 0;
        fclose(file);
    }
}

void synchronize_files(int num_files, File *files) {
    for (int i = 0; i < num_files; i++) {
        if (files[i].modified) {
            char filename[MAX_FILE_NAME_LENGTH];
            strcpy(filename, files[i].name);
            char *extension = strrchr(filename, '.');
            if (extension == NULL) {
                printf("Error: Invalid file extension\n");
                exit(1);
            }
            strcpy(extension, "bak");
            rename(filename, filename);
            rename(filename, filename);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s directory num_files\n", argv[0]);
        exit(1);
    }
    char directory[MAX_FILE_NAME_LENGTH];
    strcpy(directory, argv[1]);
    int num_files = atoi(argv[2]);
    File files[num_files];
    read_files(directory, num_files, files);
    printf("Synchronizing files...\n");
    synchronize_files(num_files, files);
    printf("Done.\n");
    return 0;
}