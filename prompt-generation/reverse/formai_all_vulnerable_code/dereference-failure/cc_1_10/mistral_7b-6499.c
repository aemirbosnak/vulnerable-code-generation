//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_FILE_SIZE 1024 * 1024 * 5
#define BUFFER_SIZE 1024

typedef struct {
    char fileName[100];
    char fileData[MAX_FILE_SIZE];
    time_t lastBackupTime;
} FileData;

void backupFile(const char *fileName) {
    FILE *srcFile = fopen(fileName, "rb");
    FILE *destFile = fopen("backup.bin", "ab");

    if (srcFile == NULL || destFile == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(destFile, sizeof(FileData) + ftell(destFile), SEEK_SET);

    size_t fileSize = 0;
    char buffer[BUFFER_SIZE];

    while ((fileSize = fread(buffer, sizeof(char), BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, sizeof(char), fileSize, destFile);
    }

    FileData fileInfo;
    strcpy(fileInfo.fileName, fileName);
    fileInfo.lastBackupTime = time(NULL);

    fwrite(&fileInfo, sizeof(FileData), 1, destFile);

    fclose(srcFile);
    fclose(destFile);
}

int main() {
    char *filePaths[] = {
        "file1.txt",
        "file2.csv",
        "file3.docx",
        "file4.pdf",
        "file5.mp3"
    };

    for (int i = 0; i < 5; i++) {
        backupFile(filePaths[i]);
        printf("Backed up %s\n", filePaths[i]);
    }

    return 0;
}