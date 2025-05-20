//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    time_t backup_time;
} BackupFile;

void backup_file(char *file_name)
{
    BackupFile *backup_file_ptr;
    FILE *file_ptr;
    char backup_file_name[MAX_FILE_NAME_LEN];

    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");

    file_ptr = fopen(backup_file_name, "wb");
    if (file_ptr == NULL) {
        printf("Error: Could not create backup file %s\n", backup_file_name);
        exit(1);
    }

    backup_file_ptr = (BackupFile *) malloc(sizeof(BackupFile));
    if (backup_file_ptr == NULL) {
        printf("Error: Could not allocate memory for backup file structure\n");
        exit(1);
    }

    strcpy(backup_file_ptr->file_name, file_name);
    backup_file_ptr->backup_time = time(NULL);

    fwrite(backup_file_ptr, sizeof(BackupFile), 1, file_ptr);
    fclose(file_ptr);
}

void restore_file(char *file_name)
{
    BackupFile backup_file;
    char backup_file_name[MAX_FILE_NAME_LEN];

    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");

    FILE *file_ptr = fopen(backup_file_name, "rb");
    if (file_ptr == NULL) {
        printf("Error: Could not open backup file %s\n", backup_file_name);
        exit(1);
    }

    fread(&backup_file, sizeof(BackupFile), 1, file_ptr);
    fclose(file_ptr);

    printf("Restoring file %s from backup file %s\n", backup_file.file_name, backup_file_name);
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <backup|restore> <file_name>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "backup") == 0) {
        backup_file(argv[2]);
    } else if (strcmp(argv[1], "restore") == 0) {
        restore_file(argv[2]);
    } else {
        printf("Error: Invalid command\n");
        exit(1);
    }

    return 0;
}