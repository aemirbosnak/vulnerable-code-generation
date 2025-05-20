//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

struct File {
    char *name;
    char *extension;
    char *content;
};

typedef struct File File;

File *create_file(char *name, char *extension, char *content) {
    File *file = (File *) malloc(sizeof(File));
    file->name = (char *) malloc(strlen(name) + 1);
    strcpy(file->name, name);
    file->extension = (char *) malloc(strlen(extension) + 1);
    strcpy(file->extension, extension);
    file->content = (char *) malloc(strlen(content) + 1);
    strcpy(file->content, content);
    return file;
}

void print_file(File *file) {
    printf("File name: %s.%s\nContent: %s\n", file->name, file->extension, file->content);
}

File **recover_files(char *disk) {
    // Simulating the process of file recovery
    File *file1 = create_file("file1", "txt", "This is file1");
    File *file2 = create_file("file2", "jpg", "This is file2");
    File *file3 = create_file("file3", "doc", "This is file3");
    File **recovered_files = (File **) malloc(3 * sizeof(File *));
    recovered_files[0] = file1;
    recovered_files[1] = file2;
    recovered_files[2] = file3;
    return recovered_files;
}

int main() {
    char disk[MAX_FILE_SIZE] = "Some broken disk data...";
    printf("Scanning disk for recoverable files...\n");
    File **recovered_files = recover_files(disk);
    printf("Recovered files:\n");
    for (int i = 0; i < 3; i++) {
        print_file(recovered_files[i]);
    }
    free(recovered_files);
    return 0;
}