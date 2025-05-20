//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BACKUP_DIR "Futuristic_Backups"

void create_directory(const char *path) {
    if (mkdir(path, 0755) == -1) {
        perror("Error creating backup directory");
        exit(EXIT_FAILURE);
    }
}

void generate_backup_name(char *backup_name, const char *file_name) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(backup_name, MAX_PATH, "%Y%m%d_%H%M%S", tm_info);
    strcat(backup_name, "_");
    strcat(backup_name, file_name);
}

void backup_file(const char *file_name) {
    char backup_name[MAX_PATH];
    generate_backup_name(backup_name, file_name);
    
    char source_file[MAX_PATH];
    char destination_file[MAX_PATH];
    
    snprintf(source_file, sizeof(source_file), "%s", file_name);
    snprintf(destination_file, sizeof(destination_file), "%s/%s.bak", BACKUP_DIR, backup_name);

    FILE *source = fopen(source_file, "rb");
    if (!source) {
        perror("Error opening source file for backup");
        return;
    }

    FILE *dest = fopen(destination_file, "wb");
    if (!dest) {
        perror("Error opening destination file for backup");
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
    printf("Backup created: %s\n", destination_file);
}

void scan_and_backup_files(const char *directory) {
    DIR *dir = opendir(directory);
    if (!dir) {
        perror("Error opening directory for scanning");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);
            backup_file(file_path);
        }
    }
    closedir(dir);
}

void display_menu() {
    printf("====== Futuristic File Backup System ======\n");
    printf("1. Backup files from the current directory\n");
    printf("2. Backup specific file\n");
    printf("3. Exit\n");
    printf("===========================================\n");
}

int main() {
    char option;
    // Ensure the backup directory exists
    create_directory(BACKUP_DIR);

    while (1) {
        display_menu();
        printf("Choose an option (1-3): ");
        option = getchar();
        getchar(); // Consume the newline character

        switch (option) {
            case '1':
                printf("Backing up files from the current directory...\n");
                scan_and_backup_files(".");
                break;
            case '2': {
                char file_name[MAX_PATH];
                printf("Enter the name of the file to backup: ");
                fgets(file_name, sizeof(file_name), stdin);
                file_name[strcspn(file_name, "\n")] = 0; // Remove trailing newline
                backup_file(file_name);
                break;
            }
            case '3':
                printf("Exiting the backup system. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}