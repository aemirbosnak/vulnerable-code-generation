//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[50];
    int size;
    char data[MAX_FILE_SIZE];
} File;

File files[MAX_FILES];
int numFiles = 0;

void addFile(char *name, int size, char *data) {
    if (numFiles == MAX_FILES) {
        printf("Error: cannot add more files.\n");
        return;
    }

    strcpy(files[numFiles].name, name);
    files[numFiles].size = size;
    memcpy(files[numFiles].data, data, size);
    numFiles++;
}

void backupFiles() {
    time_t now = time(NULL);
    char backupFileName[50];
    strftime(backupFileName, sizeof(backupFileName), "backup-%Y%m%d%H%M%S.zip", localtime(&now));

    FILE *backupFile = fopen(backupFileName, "wb");
    if (backupFile == NULL) {
        printf("Error: cannot open backup file.\n");
        return;
    }

    for (int i = 0; i < numFiles; i++) {
        fwrite(&files[i], sizeof(File), 1, backupFile);
    }

    fclose(backupFile);
}

void restoreFiles(char *backupFileName) {
    FILE *backupFile = fopen(backupFileName, "rb");
    if (backupFile == NULL) {
        printf("Error: cannot open backup file.\n");
        return;
    }

    numFiles = 0;
    while (fread(&files[numFiles], sizeof(File), 1, backupFile) == 1) {
        numFiles++;
    }

    fclose(backupFile);
}

int main() {
    addFile("file1.txt", 5, "Hello");
    addFile("file2.txt", 10, "World");
    addFile("file3.txt", 15, "This is a file backup system.");

    backupFiles();

    restoreFiles("backup-20230228143234.zip");

    for (int i = 0; i < numFiles; i++) {
        printf("%s (%d bytes): %s\n", files[i].name, files[i].size, files[i].data);
    }

    return 0;
}