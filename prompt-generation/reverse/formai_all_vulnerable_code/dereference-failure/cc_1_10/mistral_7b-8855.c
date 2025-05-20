//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define BLOCK_SIZE 1024

typedef struct FileBlock {
    char data[BLOCK_SIZE];
    struct FileBlock *next;
} FileBlock;

typedef struct FileBackup {
    char fileName[MAX_FILE_NAME_LEN];
    FileBlock *head;
} FileBackup;

FileBackup *createBackup(const char *filePath, const char *backupPath) {
    FILE *file = fopen(filePath, "rb");
    FileBackup *backup = NULL;
    FileBlock *current = NULL;
    char buffer[BLOCK_SIZE];
    size_t bytesRead;

    if (file == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", filePath);
        return NULL;
    }

    backup = (FileBackup *)malloc(sizeof(FileBackup));
    strcpy(backup->fileName, filePath);
    backup->head = NULL;

    while ((bytesRead = fread(buffer, sizeof(char), BLOCK_SIZE, file)) > 0) {
        FileBlock *newBlock = (FileBlock *)malloc(sizeof(FileBlock));
        memcpy(newBlock->data, buffer, bytesRead);
        newBlock->next = current;
        current = newBlock;
        backup->head = current;
    }

    fclose(file);

    char backupFile[MAX_FILE_NAME_LEN];
    snprintf(backupFile, MAX_FILE_NAME_LEN, "%s/%s.bak", backupPath, filePath);

    FILE *backupFilePtr = fopen(backupFile, "wb");

    FileBlock *iterator = backup->head;
    while (iterator != NULL) {
        fwrite(iterator->data, sizeof(char), bytesRead, backupFilePtr);
        bytesRead = bytesRead + sizeof(FileBlock) - sizeof(iterator->data);
        FileBlock *temp = iterator;
        iterator = iterator->next;
        free(temp);
    }

    fclose(backupFilePtr);

    return backup;
}

void deleteBackup(FileBackup *backup) {
    FileBlock *iterator = backup->head;
    FileBlock *temp = NULL;

    while (iterator != NULL) {
        temp = iterator;
        iterator = iterator->next;
        free(temp->data);
        free(temp);
    }

    free(backup);
}

int main() {
    FileBackup *backup = createBackup("input.txt", "backup");
    if (backup != NULL) {
        printf("Backup created successfully.\n");
        deleteBackup(backup);
    }
    return 0;
}