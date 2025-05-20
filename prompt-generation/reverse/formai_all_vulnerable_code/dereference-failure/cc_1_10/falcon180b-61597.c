//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_SIZE 256
#define BACKUP_FILE_EXTENSION ".bak"

struct file_info {
    char file_name[MAX_FILE_NAME_SIZE];
    time_t last_modified_time;
};

void backup_file(char *file_name) {
    char backup_file_name[MAX_FILE_NAME_SIZE];
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    FILE *backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", backup_file_name);
        exit(1);
    }

    FILE *original_file = fopen(file_name, "r");
    if (original_file == NULL) {
        printf("Error: Could not open original file %s\n", file_name);
        fclose(backup_file);
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    char file_name[MAX_FILE_NAME_SIZE];
    strcpy(file_name, argv[1]);

    struct stat file_stat;
    if (stat(file_name, &file_stat) == -1) {
        printf("Error: File not found\n");
        exit(1);
    }

    time_t last_modified_time = file_stat.st_mtime;
    struct file_info file_info = {
       .file_name = file_name,
       .last_modified_time = last_modified_time
    };

    char backup_folder[MAX_FILE_NAME_SIZE];
    strcpy(backup_folder, file_name);
    strcat(backup_folder, "_backups");

    if (mkdir(backup_folder, 0777) == -1) {
        printf("Error: Could not create backup folder %s\n", backup_folder);
        exit(1);
    }

    char backup_file_name[MAX_FILE_NAME_SIZE];
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, "_");
    strcat(backup_file_name, ctime(&last_modified_time));
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    char backup_file_path[MAX_FILE_NAME_SIZE];
    strcpy(backup_file_path, backup_folder);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, backup_file_name);

    backup_file(backup_file_path);

    printf("Backup created: %s\n", backup_file_path);

    return 0;
}