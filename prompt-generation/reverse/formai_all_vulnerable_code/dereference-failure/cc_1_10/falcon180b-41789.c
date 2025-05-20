//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define FILE_BACKUP_EXTENSION ".bak"

typedef struct {
    char *filename;
    char *backup_filename;
    FILE *file;
    FILE *backup_file;
} FileBackup;

int create_backup_filename(const char *filename, char *backup_filename) {
    strncpy(backup_filename, filename, strlen(filename) - strlen(strrchr(filename, '. ')));
    strcat(backup_filename, FILE_BACKUP_EXTENSION);
    return 0;
}

int backup_file(FileBackup *file_backup) {
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file_backup->file)!= NULL) {
        fprintf(file_backup->backup_file, "%s", buffer);
    }
    fclose(file_backup->file);
    fclose(file_backup->backup_file);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <backup_filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_LINE_LENGTH];
    char backup_filename[MAX_LINE_LENGTH];
    strcpy(filename, argv[1]);
    strcpy(backup_filename, argv[2]);

    create_backup_filename(filename, backup_filename);

    FileBackup file_backup = {
       .filename = filename,
       .backup_filename = backup_filename,
       .file = fopen(filename, "r"),
       .backup_file = fopen(backup_filename, "w")
    };

    if (file_backup.file == NULL || file_backup.backup_file == NULL) {
        printf("Error: Could not open file or backup file.\n");
        return 1;
    }

    backup_file(&file_backup);

    printf("File backed up successfully.\n");
    return 0;
}