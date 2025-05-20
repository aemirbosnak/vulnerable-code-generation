//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

struct File {
    char filename[MAX_FILENAME_LENGTH];
    int version;
};

void displayFiles(struct File *files, int num_files) {
    printf("Stored backups:\n");
    printf("Filename\tVersion\n");
    printf("--------------------------\n");
    for(int i=0; i<num_files; i++) {
        printf("%s\t\t%d\n", files[i].filename, files[i].version);
    }
    printf("\n");
}

int searchFile(struct File *files, int num_files, char *filename) {
    for(int i=0; i<num_files; i++) {
        if(strcmp(files[i].filename, filename) == 0) {
            return i;
        }
    }
    return -1;
}

void backupFile(struct File **files, int *num_files, char *filename) {
    int file_index = searchFile(*files, *num_files, filename);
    if(file_index == -1) {
        printf("Creating new file backup for %s\n", filename);
        *num_files += 1;
        *files = (struct File *) realloc(*files, (*num_files) * sizeof(struct File));
        strcpy((*files)[*num_files-1].filename, filename);
        (*files)[*num_files-1].version = 1;
    } else {
        printf("Updating existing file backup for %s\n", filename);
        (*files)[file_index].version += 1;
    }
}

int main() {
    struct File *files = NULL;
    int num_files = 0;
    
    printf("File Backup System\n");
    printf("-------------------\n\n");
    
    while(1) {
        printf("Enter file name to backup (or 'q' to quit):\n");
        char filename[MAX_FILENAME_LENGTH];
        scanf("%s", filename);
        if(strcmp(filename, "q") == 0) {
            break;
        }
        backupFile(&files, &num_files, filename);
        displayFiles(files, num_files);
    }
    
    free(files);
    return 0;
}