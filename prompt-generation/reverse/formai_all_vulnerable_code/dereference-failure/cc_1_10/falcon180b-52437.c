//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define BACKUP_DIR_NAME "backups"

typedef struct {
    char* file_name;
    char* backup_file_name;
} FileInfo;

void create_backup_dir() {
    char backup_dir[MAX_FILE_NAME_LENGTH];
    strcpy(backup_dir, "./");
    strcat(backup_dir, BACKUP_DIR_NAME);
    mkdir(backup_dir);
}

FileInfo* get_file_info(char* file_name) {
    char* backup_file_name = malloc(MAX_FILE_NAME_LENGTH);
    strcpy(backup_file_name, BACKUP_DIR_NAME);
    strcat(backup_file_name, "/");
    strcat(backup_file_name, file_name);
    FileInfo* file_info = malloc(sizeof(FileInfo));
    file_info->file_name = file_name;
    file_info->backup_file_name = backup_file_name;
    return file_info;
}

void backup_file(FileInfo* file_info) {
    FILE* file = fopen(file_info->file_name, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return;
    }
    FILE* backup_file = fopen(file_info->backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file.\n");
        return;
    }
    char buffer[MAX_FILE_NAME_LENGTH];
    while (fgets(buffer, MAX_FILE_NAME_LENGTH, file)!= NULL) {
        fputs(buffer, backup_file);
    }
    fclose(file);
    fclose(backup_file);
    printf("Backup created successfully.\n");
}

int main() {
    create_backup_dir();
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);
    FileInfo* file_info = get_file_info(file_name);
    backup_file(file_info);
    free(file_info->file_name);
    free(file_info->backup_file_name);
    free(file_info);
    return 0;
}