//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    char path[MAX_SIZE];
} File;

void read_files(File* files, int* count) {
    char line[MAX_SIZE];
    FILE* input = fopen("files.txt", "r");

    while (fgets(line, MAX_SIZE, input)) {
        strcpy(files[*count].name, line);
        strcpy(files[*count].path, "");
        (*count)++;
    }

    fclose(input);
}

void sync_files(File* files, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(files[i].path, "") == 0) {
            char path[MAX_SIZE];
            printf("Enter path for %s: ", files[i].name);
            scanf("%s", path);
            strcpy(files[i].path, path);
        }
    }
}

void sync_files_system(File* files, int count) {
    for (int i = 0; i < count; i++) {
        char command[MAX_SIZE];
        strcpy(command, "rsync -avz ");
        strcat(command, files[i].name);
        strcat(command, " ");
        strcat(command, files[i].path);
        system(command);
    }
}

int main() {
    File files[MAX_SIZE];
    int count = 0;

    read_files(files, &count);
    sync_files(files, count);
    sync_files_system(files, count);

    return 0;
}