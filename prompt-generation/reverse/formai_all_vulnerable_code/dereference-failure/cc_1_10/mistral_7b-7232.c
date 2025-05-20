//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME_LENGTH 100
#define BACKUP_FILE_SUFFIX ".bak"

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *file;
} FileHandle;

void backup_file(FileHandle *file_handle) {
    FILE *backup_file;
    size_t size;
    char buffer[1024];

    backup_file = fopen(strcat(file_handle->name, BACKUP_FILE_SUFFIX), "w");
    if (backup_file == NULL) {
        perror("Error creating backup file");
        return;
    }

    fseek(file_handle->file, 0, SEEK_END);
    size = ftell(file_handle->file);
    rewind(file_handle->file);

    while (fread(buffer, 1, sizeof(buffer), file_handle->file) > 0) {
        fwrite(buffer, 1, sizeof(buffer), backup_file);
    }

    fclose(backup_file);
    printf("File '%s' backed up successfully.\n", file_handle->name);
}

int main(int argc, char *argv[]) {
    FileHandle file_handle;
    int result;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_to_backup>\n", argv[0]);
        exit(1);
    }

    strcpy(file_handle.name, argv[1]);
    file_handle.file = fopen(file_handle.name, "r");

    if (file_handle.file == NULL) {
        perror("Error opening file for backup");
        return 1;
    }

    backup_file(&file_handle);
    fclose(file_handle.file);

    return 0;
}