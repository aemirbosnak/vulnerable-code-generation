//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 256
#define BACKUP_DIR_NAME "backups"
#define BACKUP_EXTENSION ".bak"
#define VERSION_FILE_NAME "version.txt"

typedef struct {
    char original_file_name[MAX_FILE_NAME_LEN];
    time_t backup_time;
} BackupFile;

void create_backup_dir() {
    char backup_dir_path[MAX_FILE_NAME_LEN];
    strcpy(backup_dir_path, "./");
    strcat(backup_dir_path, BACKUP_DIR_NAME);
    mkdir(backup_dir_path);
}

void create_version_file() {
    FILE *version_file;
    version_file = fopen(VERSION_FILE_NAME, "w");
    fprintf(version_file, "1.0");
    fclose(version_file);
}

int read_version() {
    FILE *version_file;
    char version[10];
    version_file = fopen(VERSION_FILE_NAME, "r");
    fscanf(version_file, "%s", version);
    fclose(version_file);
    return atoi(version);
}

void write_backup_file(BackupFile backup_file) {
    FILE *backup_file_ptr;
    char backup_file_name[MAX_FILE_NAME_LEN];
    strcpy(backup_file_name, backup_file.original_file_name);
    strcat(backup_file_name, BACKUP_EXTENSION);
    backup_file_ptr = fopen(backup_file_name, "w");
    fprintf(backup_file_ptr, "Backup created on %s", ctime(&backup_file.backup_time));
    fclose(backup_file_ptr);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char file_name[MAX_FILE_NAME_LEN];
    strcpy(file_name, argv[1]);

    create_backup_dir();
    create_version_file();

    int version = read_version();
    if (version < 1) {
        printf("Version not supported.\n");
        return 1;
    }

    BackupFile backup_file;
    strcpy(backup_file.original_file_name, file_name);
    backup_file.backup_time = time(NULL);
    write_backup_file(backup_file);

    printf("Backup created successfully.\n");
    return 0;
}