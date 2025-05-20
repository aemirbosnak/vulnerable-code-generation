//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUP_FILES 10
#define BACKUP_FILE_EXTENSION ".bak"

struct backup_file {
    char original_file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
};

void backup_file(const char* original_file_name) {
    struct backup_file backup_files[MAX_BACKUP_FILES];
    int num_backup_files = 0;
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;

    FILE* original_file = fopen(original_file_name, "rb");
    if (original_file == NULL) {
        printf("Error: could not open original file %s\n", original_file_name);
        exit(1);
    }

    backup_time = time(NULL);
    strftime(backup_file_name, MAX_FILE_NAME_LENGTH, "%Y%m%d%H%M%S", localtime(&backup_time));
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    for (int i = 0; i < num_backup_files; i++) {
        if (strcmp(backup_files[i].original_file_name, original_file_name) == 0) {
            printf("Error: backup file for %s already exists\n", original_file_name);
            exit(1);
        }
    }

    strcpy(backup_files[num_backup_files].original_file_name, original_file_name);
    strcpy(backup_files[num_backup_files].backup_file_name, backup_file_name);
    backup_files[num_backup_files].backup_time = backup_time;
    num_backup_files++;

    if (num_backup_files > MAX_BACKUP_FILES) {
        printf("Error: maximum number of backup files reached\n");
        exit(1);
    }

    FILE* backup_file = fopen(backup_file_name, "wb");
    if (backup_file == NULL) {
        printf("Error: could not create backup file %s\n", backup_file_name);
        exit(1);
    }

    char buffer[4096];
    while (fread(buffer, 1, sizeof(buffer), original_file) > 0) {
        fwrite(buffer, 1, sizeof(buffer), backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    backup_file(argv[1]);

    return 0;
}