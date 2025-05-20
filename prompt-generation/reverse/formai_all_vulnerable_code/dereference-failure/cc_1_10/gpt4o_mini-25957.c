//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 256

void display_menu() {
    printf("\n--- C File Backup System ---\n");
    printf("1. Backup Files\n");
    printf("2. Restore Files\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void backup_files(const char *source_dir, const char *backup_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_path[PATH_MAX];
    char backup_path[PATH_MAX];
    FILE *source_file, *backup_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if ((dir = opendir(source_dir)) == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(backup_path, sizeof(backup_path), "%s/%s.bak", backup_dir, entry->d_name);

            source_file = fopen(source_path, "rb");
            if (source_file == NULL) {
                perror("Failed to open source file");
                continue;
            }

            backup_file = fopen(backup_path, "wb");
            if (backup_file == NULL) {
                perror("Failed to open backup file");
                fclose(source_file);
                continue;
            }

            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
                fwrite(buffer, 1, bytes_read, backup_file);
            }

            fclose(source_file);
            fclose(backup_file);
            printf("Backed up: %s to %s\n", source_path, backup_path);
        }
    }

    closedir(dir);
}

void restore_files(const char *backup_dir, const char *restore_dir) {
    DIR *dir;
    struct dirent *entry;
    char backup_path[PATH_MAX];
    char restore_path[PATH_MAX];
    FILE *backup_file, *restore_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if ((dir = opendir(backup_dir)) == NULL) {
        perror("Failed to open backup directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".bak")) { // Backup file
            snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);
            snprintf(restore_path, sizeof(restore_path), "%s/%s", restore_dir, entry->d_name);

            backup_file = fopen(backup_path, "rb");
            if (backup_file == NULL) {
                perror("Failed to open backup file");
                continue;
            }

            restore_file = fopen(restore_path, "wb");
            if (restore_file == NULL) {
                perror("Failed to open restore file");
                fclose(backup_file);
                continue;
            }

            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, backup_file)) > 0) {
                fwrite(buffer, 1, bytes_read, restore_file);
            }

            fclose(backup_file);
            fclose(restore_file);
            printf("Restored: %s to %s\n", backup_path, restore_path);
        }
    }

    closedir(dir);
}

int main() {
    char source_dir[PATH_MAX];
    char backup_dir[PATH_MAX];
    char restore_dir[PATH_MAX];
    int option;

    printf("Enter source directory to backup: ");
    scanf("%s", source_dir);

    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    printf("Enter restore directory: ");
    scanf("%s", restore_dir);

    do {
        display_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                backup_files(source_dir, backup_dir);
                break;
            case 2:
                restore_files(backup_dir, restore_dir);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}