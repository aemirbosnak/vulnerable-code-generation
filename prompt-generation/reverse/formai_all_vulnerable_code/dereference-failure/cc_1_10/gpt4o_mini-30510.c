//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 4096
#define MAX_BACKUPS 100

void create_backup(const char *source, const char *backup_dir) {
    char backup_file[512];
    snprintf(backup_file, sizeof(backup_file), "%s/%s.bak", backup_dir, strrchr(source, '/') + 1);

    FILE *source_file = fopen(source, "rb");
    if (!source_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *backup_file_ptr = fopen(backup_file, "wb");
    if (!backup_file_ptr) {
        perror("Failed to create backup file");
        fclose(source_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file_ptr);
    }

    printf("Backup of '%s' created at '%s'\n", source, backup_file);

    fclose(source_file);
    fclose(backup_file_ptr);
}

void list_backups(const char *backup_dir) {
    DIR *dir = opendir(backup_dir);
    if (!dir) {
        perror("Failed to open backup directory");
        return;
    }

    struct dirent *entry;
    printf("Backup files in '%s':\n", backup_dir);
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".bak") != NULL) {
            printf(" - %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

void delete_backup(const char *backup_dir, const char *backup_name) {
    char backup_file[512];
    snprintf(backup_file, sizeof(backup_file), "%s/%s", backup_dir, backup_name);

    if (remove(backup_file) == 0) {
        printf("Deleted backup file '%s'\n", backup_file);
    } else {
        perror("Failed to delete backup file");
    }
}

void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
        printf("Backup directory '%s' created\n", backup_dir);
    }
}

int main() {
    char source_file[256];
    char backup_directory[256];
    char command[256];

    printf("Enter the path of the file to backup: ");
    fgets(source_file, sizeof(source_file), stdin);
    source_file[strcspn(source_file, "\n")] = 0; // Remove newline

    printf("Enter the backup directory: ");
    fgets(backup_directory, sizeof(backup_directory), stdin);
    backup_directory[strcspn(backup_directory, "\n")] = 0; // Remove newline

    create_backup_directory(backup_directory);

    int choice;
    while (1) {
        printf("\nBackup Management System\n");
        printf("1. Create Backup\n");
        printf("2. List Backups\n");
        printf("3. Delete Backup\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        fgets(command, sizeof(command), stdin);
        choice = atoi(command);

        switch (choice) {
            case 1:
                create_backup(source_file, backup_directory);
                break;
            case 2:
                list_backups(backup_directory);
                break;
            case 3: {
                char backup_name[256];
                printf("Enter the backup file name to delete (without .bak): ");
                fgets(backup_name, sizeof(backup_name), stdin);
                backup_name[strcspn(backup_name, "\n")] = 0; // Remove newline
                char full_backup_name[256];
                snprintf(full_backup_name, sizeof(full_backup_name), "%s.bak", backup_name);
                delete_backup(backup_directory, full_backup_name);
                break;
            }
            case 4:
                printf("Exiting Backup Management System...\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}