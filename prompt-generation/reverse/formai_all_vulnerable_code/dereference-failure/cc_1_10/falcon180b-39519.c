//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char backup_filename[MAX_FILE_NAME_LENGTH];
    char backup_path[MAX_FILE_NAME_LENGTH];
    char *file_data;
    int file_size;
    int backup_size;
} FileBackup;

void backup_file(FileBackup *backup) {
    FILE *backup_file = fopen(backup->backup_path, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file.\n");
        exit(1);
    }
    fwrite(backup->file_data, backup->file_size, 1, backup_file);
    fclose(backup_file);
    printf("Backup created: %s\n", backup->backup_filename);
}

void restore_file(FileBackup *backup) {
    FILE *backup_file = fopen(backup->backup_path, "r");
    if (backup_file == NULL) {
        printf("Error opening backup file.\n");
        exit(1);
    }
    fseek(backup_file, 0L, SEEK_END);
    backup->backup_size = ftell(backup_file);
    rewind(backup_file);
    backup->file_data = malloc(backup->backup_size);
    fread(backup->file_data, backup->backup_size, 1, backup_file);
    fclose(backup_file);
    printf("File restored: %s\n", backup->filename);
}

int main() {
    FileBackup backup;
    strcpy(backup.filename, "test.txt");
    strcpy(backup.backup_filename, "backup_test.txt");
    strcpy(backup.backup_path, "backups/");
    backup.file_data = malloc(MAX_FILE_SIZE);
    backup.file_size = 0;
    backup.backup_size = 0;

    FILE *file = fopen(backup.filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char c;
    while ((c = fgetc(file))!= EOF) {
        backup.file_data[backup.file_size++] = c;
    }
    fclose(file);

    backup_file(&backup);

    return 0;
}