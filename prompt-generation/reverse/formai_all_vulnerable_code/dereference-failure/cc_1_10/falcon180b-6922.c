//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    FILE *backup_file;
    size_t file_size;
} File;

void backup_file(File *file) {
    char *backup_file_path = malloc(strlen(file->backup_file_name) + 1);
    strcpy(backup_file_path, file->backup_file_name);
    strcat(backup_file_path, ".bak");

    file->backup_file = fopen(backup_file_path, "w");
    if (file->backup_file == NULL) {
        printf("Error: Failed to open backup file '%s'\n", backup_file_path);
        exit(1);
    }

    fseek(file->file, 0, SEEK_SET);
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = 0;

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file->file)) > 0) {
        fwrite(buffer, 1, bytes_read, file->backup_file);
    }

    fclose(file->backup_file);
    printf("Backup of '%s' created as '%s'\n", file->file_name, backup_file_path);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name, argv[1]);

    File file;
    strcpy(file.file_name, file_name);
    strcpy(file.backup_file_name, file_name);
    strcat(file.backup_file_name, ".bak");

    file.file = fopen(file_name, "r+");
    if (file.file == NULL) {
        printf("Error: Failed to open file '%s'\n", file_name);
        exit(1);
    }

    file.file_size = fseek(file.file, 0, SEEK_END);
    if (file.file_size == -1) {
        printf("Error: Failed to get file size of '%s'\n", file_name);
        exit(1);
    }

    backup_file(&file);

    fclose(file.file);
    fclose(file.backup_file);

    return 0;
}