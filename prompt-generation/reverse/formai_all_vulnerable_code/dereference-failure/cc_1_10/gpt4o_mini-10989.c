//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024
#define MAX_BACKUP_DIRS 10

void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
    }
}

void copy_file(const char *src, const char *dst) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dst, "wb");

    if (source == NULL || destination == NULL) {
        perror("File copy failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

void backup_files(const char *src_dir, const char *backup_dir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(src_dir)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_REG) { // Regular file
                char src_path[MAX_PATH_LEN];
                char dst_path[MAX_PATH_LEN];
                snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
                snprintf(dst_path, sizeof(dst_path), "%s/%s", backup_dir, entry->d_name);
                copy_file(src_path, dst_path);
                printf("Backed up: %s to %s\n", src_path, dst_path);
            }
        }
        closedir(dir);
    } else {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }
}

void display_menu() {
    printf("=== File Backup System ===\n");
    printf("1. Create Backup\n");
    printf("2. Exit\n");
}

int main() {
    char src_dir[MAX_PATH_LEN];
    char backup_dir[MAX_PATH_LEN];
    int option;

    printf("Enter source directory to backup: ");
    scanf("%s", src_dir);
    snprintf(backup_dir, sizeof(backup_dir), "%s_backup", src_dir);
    
    create_backup_directory(backup_dir);

    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                backup_files(src_dir, backup_dir);
                printf("Backup completed successfully!\n");
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 2);

    return 0;
}