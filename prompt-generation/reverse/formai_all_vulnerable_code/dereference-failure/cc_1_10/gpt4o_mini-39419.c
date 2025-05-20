//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define BACKUP_DIR "backup"

// Function to create a backup directory if it doesn't exist
void create_backup_directory() {
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
        printf("Created backup directory: %s\n", BACKUP_DIR);
    } else {
        printf("Backup directory already exists: %s\n", BACKUP_DIR);
    }
}

// Function to copy a file to the backup directory
void copy_file_to_backup(const char *file_path) {
    FILE *source_file = fopen(file_path, "rb"); // Open the source file
    if (!source_file) {
        printf("Failed to open file: %s\n", file_path);
        return;
    }

    char backup_file_path[MAX_FILENAME_LENGTH];
    snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s", BACKUP_DIR, file_path);

    FILE *backup_file = fopen(backup_file_path, "wb"); // Create the backup file
    if (!backup_file) {
        printf("Failed to create backup for: %s\n", file_path);
        fclose(source_file);
        return;
    }

    // Copy contents
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes, backup_file);
    }

    printf("Backup of %s created as %s\n", file_path, backup_file_path);

    fclose(source_file);
    fclose(backup_file);
}

// Function to list all the files in the given directory and backup them
void backup_files_in_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        printf("Failed to open directory: %s\n", dir_path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only process regular files
            char file_path[MAX_FILENAME_LENGTH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            copy_file_to_backup(file_path);
        }
    }

    closedir(dir);
}

// Function to display a friendly message
void display_welcome_message() {
    printf("========================================\n");
    printf("   Welcome to the Peaceful Backup System  \n");
    printf("   Your files deserve a little care.    \n");
    printf("   Let's create some backups for you!   \n");
    printf("========================================\n");
}

// Main function
int main() {
    display_welcome_message();

    create_backup_directory(); // Ensure the backup directory is ready

    char dir_to_backup[MAX_FILENAME_LENGTH];
    printf("Enter the directory you want to backup (absolute path): ");
    fgets(dir_to_backup, sizeof(dir_to_backup), stdin);

    // Remove the newline character from the input
    dir_to_backup[strcspn(dir_to_backup, "\n")] = 0;

    backup_files_in_directory(dir_to_backup);

    printf("Backup process completed. Your files are safe!\n");

    return 0;
}