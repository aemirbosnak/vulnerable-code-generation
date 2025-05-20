//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_CONTENT_LENGTH 1024

typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} File;

typedef struct {
    char name[MAX_NAME_LENGTH];
    File* files[2];
} Directory;

int file_exists(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}

void print_file(FILE* fp) {
    fseek(fp, 0, SEEK_SET);
    fread(fp, sizeof(char), MAX_CONTENT_LENGTH, fp);
    fclose(fp);
}

void print_directory(Directory* directory) {
    printf("Directory: %s\n", directory->name);
    for (int i = 0; i < 2; i++) {
        if (directory->files[i]!= NULL) {
            printf("\t%s\n", directory->files[i]->name);
            print_file(directory->files[i]->content);
        }
    }
}

int main() {
    Directory root;
    root.name[0] = '\0';
    root.files[0] = NULL;
    root.files[1] = NULL;

    Directory data;
    data.name[0] = '\0';
    data.files[0] = NULL;
    data.files[1] = NULL;

    Directory logs;
    logs.name[0] = '\0';
    logs.files[0] = NULL;
    logs.files[1] = NULL;

    strcpy(root.name, "root");
    strcpy(data.name, "data");
    strcpy(logs.name, "logs");

    File* file1 = (File*) malloc(sizeof(File));
    strcpy(file1->name, "file1.txt");
    file1->content[0] = '\0';

    File* file2 = (File*) malloc(sizeof(File));
    strcpy(file2->name, "file2.txt");
    file2->content[0] = '\0';

    File* file3 = (File*) malloc(sizeof(File));
    strcpy(file3->name, "file3.txt");
    file3->content[0] = '\0';

    strcpy(file1->content, "This is file 1.");
    strcpy(file2->content, "This is file 2.");
    strcpy(file3->content, "This is file 3.");

    data.files[0] = file1;
    data.files[1] = file2;
    logs.files[0] = file3;

    root.files[0] = &data;
    root.files[1] = &logs;

    print_directory(&root);

    return 0;
}