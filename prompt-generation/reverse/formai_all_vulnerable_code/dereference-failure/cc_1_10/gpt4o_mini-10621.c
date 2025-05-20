//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void display_files(const char *directory) {
    struct dirent *dir_entry;
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("Files in directory '%s':\n", directory);
    while ((dir_entry = readdir(dir)) != NULL) {
        if (dir_entry->d_type == DT_REG) { // Only regular files
            printf("%s\n", dir_entry->d_name);
        }
    }
    closedir(dir);
}

int copy_file(const char *source, const char *destination) {
    FILE *src_file = fopen(source, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        fclose(src_file);
        perror("Error opening destination file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    return 0;
}

void backup_files(const char *source_directory, const char *backup_directory) {
    struct dirent *dir_entry;
    DIR *dir = opendir(source_directory);

    if (dir == NULL) {
        perror("Unable to open source directory");
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        if (dir_entry->d_type == DT_REG) { // Regular files only
            char source_path[512];
            char dest_path[512];

            snprintf(source_path, sizeof(source_path), "%s/%s", source_directory, dir_entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_directory, dir_entry->d_name);

            if (copy_file(source_path, dest_path) == 0) {
                printf("Successfully backed up: %s\n", dir_entry->d_name);
            } else {
                printf("Failed to back up: %s\n", dir_entry->d_name);
            }
        }
    }
    closedir(dir);
}

int main() {
    char source_directory[256];
    char backup_directory[256];

    printf("Enter the source directory to back up files: ");
    scanf("%s", source_directory);

    printf("Enter the backup directory: ");
    scanf("%s", backup_directory);

    struct stat st;
    // Create backup directory if it does not exist
    if (stat(backup_directory, &st) == -1) {
        mkdir(backup_directory, 0700);
    }

    printf("Backing up files from '%s' to '%s'...\n", source_directory, backup_directory);
    backup_files(source_directory, backup_directory);

    printf("Backup process completed.\n");
    return 0;
}