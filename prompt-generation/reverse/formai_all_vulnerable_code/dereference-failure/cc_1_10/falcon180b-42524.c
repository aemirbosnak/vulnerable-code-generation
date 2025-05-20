//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_BACKUP_DIR_LENGTH 1000
#define MAX_BACKUP_FILE_NAME_LENGTH 2000

// Function to create a backup directory if it does not exist
void create_backup_directory(char* backup_dir) {
    char command[MAX_FILE_NAME_LENGTH];
    strcpy(command, "mkdir -p ");
    strcat(command, backup_dir);
    system(command);
}

// Function to get the current date and time in the format YYYYMMDDHHMMSS
void get_current_date_time(char* date_time) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(date_time, MAX_FILE_NAME_LENGTH, "%Y%m%d%H%M%S", t);
}

// Function to backup a file
void backup_file(char* source_file, char* backup_dir, char* date_time) {
    char backup_file_name[MAX_BACKUP_FILE_NAME_LENGTH];
    strcpy(backup_file_name, backup_dir);
    strcat(backup_file_name, "/");
    strcat(backup_file_name, date_time);
    strcat(backup_file_name, "_");
    strcat(backup_file_name, source_file);

    char command[MAX_FILE_NAME_LENGTH];
    strcpy(command, "cp ");
    strcat(command, source_file);
    strcat(command, " ");
    strcat(command, backup_file_name);
    system(command);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_file backup_dir file_name\n", argv[0]);
        return 1;
    }

    char* source_file = argv[1];
    char* backup_dir = argv[2];
    char* file_name = argv[3];

    char date_time[MAX_FILE_NAME_LENGTH];
    get_current_date_time(date_time);

    char backup_file_name[MAX_BACKUP_FILE_NAME_LENGTH];
    strcpy(backup_file_name, backup_dir);
    strcat(backup_file_name, "/");
    strcat(backup_file_name, date_time);
    strcat(backup_file_name, "_");
    strcat(backup_file_name, file_name);

    create_backup_directory(backup_dir);
    backup_file(source_file, backup_dir, date_time);

    printf("Backup completed: %s\n", backup_file_name);

    return 0;
}