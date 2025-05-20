//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    time_t backup_time;
} BackupFile;

void backup_file(char *file_name) {
    FILE *fp;
    BackupFile backup_file;

    strcpy(backup_file.file_name, file_name);
    backup_file.backup_time = time(NULL);

    fp = fopen("backup.txt", "a");
    if (fp == NULL) {
        printf("Error: could not open backup file.\n");
        exit(1);
    }

    fprintf(fp, "%s %ld\n", backup_file.file_name, backup_file.backup_time);
    fclose(fp);
}

void restore_file(char *file_name) {
    FILE *fp;
    BackupFile backup_file;
    char line[MAX_FILE_NAME_LEN + 20];

    fp = fopen("backup.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open backup file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %ld", backup_file.file_name, &backup_file.backup_time);

        if (strcmp(backup_file.file_name, file_name) == 0) {
            printf("Restoring %s from backup...\n", file_name);
            rename(file_name, "restore.txt");
            rename("restore.txt", file_name);
            break;
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name> [backup|restore]\n", argv[0]);
        exit(1);
    }

    strcpy(argv[1], argv[1]);

    if (argc == 3) {
        if (strcmp(argv[2], "backup") == 0) {
            backup_file(argv[1]);
            printf("File backed up successfully.\n");
        } else if (strcmp(argv[2], "restore") == 0) {
            restore_file(argv[1]);
        } else {
            printf("Invalid command.\n");
        }
    } else {
        printf("Error: command not specified.\n");
    }

    return 0;
}