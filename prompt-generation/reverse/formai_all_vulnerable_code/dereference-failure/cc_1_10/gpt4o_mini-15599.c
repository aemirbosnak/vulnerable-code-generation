//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_FILES 100
#define BUFFER_SIZE 1024

void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
        printf("Backup directory '%s' created.\n", backup_dir);
    } else {
        printf("Backup directory '%s' already exists.\n", backup_dir);
    }
}

void copy_file(const char *src, const char *dest) {
    char buffer[BUFFER_SIZE];
    FILE *source_file = fopen(src, "rb");
    FILE *dest_file = fopen(dest, "wb");

    if (!source_file || !dest_file) {
        fprintf(stderr, "Error opening files for copying: %s to %s\n", src, dest);
        return;
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
    printf("File '%s' backed up to '%s'.\n", src, dest);
}

void backup_files(const char *src_dir, const char *backup_dir) {
    DIR *directory;
    struct dirent *dir_entry;

    if ((directory = opendir(src_dir)) == NULL) {
        perror("Error opening source directory");
        return;
    }
    
    while ((dir_entry = readdir(directory)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            char src_path[MAX_PATH];
            char dest_path[MAX_PATH];

            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, dir_entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_dir, dir_entry->d_name);

            struct stat file_stat;
            if (stat(src_path, &file_stat) == -1) {
                perror("Error retrieving file info");
                continue;
            }

            if (S_ISREG(file_stat.st_mode)) {
                copy_file(src_path, dest_path);
            } else if (S_ISDIR(file_stat.st_mode)) {
                char new_backup_dir[MAX_PATH];
                snprintf(new_backup_dir, sizeof(new_backup_dir), "%s/%s", backup_dir, dir_entry->d_name);
                create_backup_directory(new_backup_dir);
                backup_files(src_path, new_backup_dir);
            }
        }
    }
    
    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *backup_dir = argv[2];

    create_backup_directory(backup_dir);
    backup_files(src_dir, backup_dir);

    printf("Backup process completed.\n");
    return EXIT_SUCCESS;
}