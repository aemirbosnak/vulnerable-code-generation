//FormAI DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 100 // maximum file name length
#define MAX_COMMAND_LEN 50 // maximum command length
#define MAX_BACKUP_FILES 10 // maximum number of backup files to keep
#define MAX_BACKUP_PATH_LEN 200 // maximum backup path length

void copyFile(char *src_path, char *dst_path);
void mergeFiles(char *src_path, char *dst_path);

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LEN];
    char backup_path[MAX_BACKUP_PATH_LEN];
    char command[MAX_COMMAND_LEN];
    char backup_files[MAX_BACKUP_FILES][MAX_FILENAME_LEN];
    int num_backup_files = 0;
    time_t current_time;
    struct tm *time_info;
    char time_str[20];
    char backup_filename[MAX_FILENAME_LEN + 10];
    int i;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // get the current time
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%Y%m%d_%H%M%S", time_info);

    // create the backup path and filename
    snprintf(backup_path, MAX_BACKUP_PATH_LEN, "./backups");
    snprintf(backup_filename, MAX_FILENAME_LEN + 10, "./backups/%s_%s", time_str, argv[1]);

    // check if the backup directory exists, create it if it doesn't
    if (system("test -d ./backups") != 0) {
        system("mkdir ./backups");
    }

    // copy the file to the backup directory
    copyFile(argv[1], backup_filename);

    // add the backup file to the list
    num_backup_files++;
    strncpy(backup_files[num_backup_files - 1], backup_filename, sizeof(backup_files[num_backup_files - 1]) - 1);

    // if there are more than MAX_BACKUP_FILES backup files, remove the oldest one
    if (num_backup_files > MAX_BACKUP_FILES) {
        for (i = 0; i < num_backup_files - 1; i++) {
            strcpy(backup_files[i], backup_files[i + 1]);
        }
        num_backup_files--;

        // remove the oldest backup file
        snprintf(command, MAX_COMMAND_LEN, "rm %s", backup_files[0]);
        system(command);
    }

    // merge all backup files into a single file
    if (num_backup_files > 1) {
        mergeFiles(backup_files[0], backup_files[num_backup_files - 1]);

        // remove all except the merged file
        for (i = 0; i < num_backup_files - 1; i++) {
            snprintf(command, MAX_COMMAND_LEN, "rm %s", backup_files[i]);
            system(command);
        }

        // rename the merged file to the filename of the original file
        snprintf(command, MAX_COMMAND_LEN, "mv %s %s", backup_files[num_backup_files - 1], argv[1]);
        system(command);
    }

    printf("Backup successful!\n");

    return 0;
}

// copy a file from src_path to dst_path
void copyFile(char *src_path, char *dst_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dst_file = fopen(dst_path, "wb");
    char buffer[1024];
    size_t num_read;

    if (!src_file) {
        printf("ERROR: Unable to open source file for backup\n");
        exit(1);
    }

    if (!dst_file) {
        printf("ERROR: Unable to open destination file for backup\n");
        exit(1);
    }

    while ((num_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, num_read, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}

// merge two files, src_path and dst_path, and save the result in dst_path
void mergeFiles(char *src_path, char *dst_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dst_file = fopen(dst_path, "ab");
    char buffer[1024];
    size_t num_read;

    if (!dst_file) {
        printf("ERROR: Unable to open destination file for merge\n");
        exit(1);
    }

    if (!src_file) {
        fclose(dst_file);
        return;
    }

    while ((num_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, num_read, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}