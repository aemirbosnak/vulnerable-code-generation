//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 100
#define BACKUP_DIR "backups/"

typedef struct File {
    char name[FILE_NAME_LENGTH];
    char backup[FILE_NAME_LENGTH];
    FILE *fp;
    struct File *next;
} File;

File *head = NULL;

void createBackup(char *fileName) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, fileName);

    strcat(newFile->backup, BACKUP_DIR);
    strcat(newFile->backup, newFile->name);
    strcat(newFile->backup, ".bak");

    newFile->fp = fopen(newFile->backup, "w");

    if (head == NULL) {
        head = newFile;
        newFile->next = NULL;
    } else {
        File *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFile;
        newFile->next = NULL;
    }

    fseek(newFile->fp, 0, SEEK_SET);
    fwrite(fileName, strlen(fileName), 1, newFile->fp);

    printf("Backup created for file: %s\n", fileName);
}

void backupFiles() {
    File *current = head;

    while (current != NULL) {
        printf("Backing up file: %s to %s...\n", current->name, current->backup);

        if (current->fp != NULL) {
            size_t fileSize;
            char buffer[1024];

            fseek(current->fp, 0, SEEK_END);
            fileSize = ftell(current->fp);
            rewind(current->fp);

            while (fread(buffer, sizeof(char), 1024, current->fp) != 0) {
                fwrite(buffer, sizeof(char), 1024, current->fp);
            }

            fclose(current->fp);
            current->fp = NULL;
        }

        current = current->next;
    }

    printf("Backup completed successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    createBackup(argv[1]);
    backupFiles();

    return 0;
}