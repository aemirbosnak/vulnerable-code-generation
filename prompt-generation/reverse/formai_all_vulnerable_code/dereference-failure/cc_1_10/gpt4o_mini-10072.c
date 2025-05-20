//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PATH_LENGTH 512
#define BACKUP_EXTENSION ".bak"
#define MAX_BACKUPS 5

void create_backup(char *source_file_path) {
    // Extracting file name and directory
    char file_path[MAX_PATH_LENGTH];
    char file_name[MAX_FILENAME_LENGTH];
    char backup_file_path[MAX_PATH_LENGTH];

    strcpy(file_path, source_file_path);
    
    char *last_slash = strrchr(file_path, '/');
    if (last_slash != NULL) {
        strcpy(file_name, last_slash + 1);
        *last_slash = '\0'; // Temporarily terminate the string at the last slash for directory path
    } else {
        strcpy(file_name, file_path);
        *file_path = '\0'; // No directory, empty path
    }
    
    // Creating the backup file name
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s_%04d%02d%02d_%02d%02d%02d%s",
             file_path, file_name,
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec, BACKUP_EXTENSION);
    
    // Perform the backup
    if (access(source_file_path, F_OK) != -1) {
        FILE *src = fopen(source_file_path, "rb");
        FILE *backup = fopen(backup_file_path, "wb");
        
        if (src == NULL || backup == NULL) {
            printf("Error creating backup for %s\n", source_file_path);
            if (src) fclose(src);
            if (backup) fclose(backup);
            return;
        }
        
        char buffer[1024];
        size_t bytes;
        while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
            fwrite(buffer, 1, bytes, backup);
        }

        printf("Backup created: %s\n", backup_file_path);
        fclose(src);
        fclose(backup);
    } else {
        printf("The source file %s does not exist!\n", source_file_path);
    }
}

void list_backups(char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        printf("Could not open directory: %s\n", directory);
        return;
    }

    printf("Backups in %s:\n", directory);
    while ((entry = readdir(dp))) {
        if (strstr(entry->d_name, BACKUP_EXTENSION) != NULL) {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void manage_backups(char *file_path) {
    char folder[MAX_PATH_LENGTH];
    char file_name[MAX_FILENAME_LENGTH];
    
    strcpy(folder, file_path);
    char *last_slash = strrchr(folder, '/');
    if (last_slash != NULL) {
        *last_slash = '\0';
        strcpy(file_name, last_slash + 1);
    } else {
        strcpy(file_name, folder);
        *folder = '\0'; // No directory
    }

    char backups_path[MAX_PATH_LENGTH];
    snprintf(backups_path, sizeof(backups_path), "%s/", folder);

    list_backups(backups_path);
}

int main() {
    char command[100];
    char source_file[MAX_PATH_LENGTH];

    printf("Welcome to the Ephemeral Backup System!\n");
    
    while (1) {
        printf("\nOptions:\n1. Create Backup\n2. List Backups\n3. Manage Backups\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        fgets(command, sizeof(command), stdin);
        int choice = atoi(command);

        switch (choice) {
            case 1:
                printf("Enter the path of the file to back up: ");
                fgets(source_file, sizeof(source_file), stdin);
                source_file[strcspn(source_file, "\n")] = 0; // Remove newline character
                create_backup(source_file);
                break;
            case 2:
                printf("Enter the directory to list backups: ");
                fgets(source_file, sizeof(source_file), stdin);
                source_file[strcspn(source_file, "\n")] = 0; // Remove newline character
                list_backups(source_file);
                break;
            case 3:
                printf("Enter the path of the file for backup management: ");
                fgets(source_file, sizeof(source_file), stdin);
                source_file[strcspn(source_file, "\n")] = 0; // Remove newline character
                manage_backups(source_file);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}