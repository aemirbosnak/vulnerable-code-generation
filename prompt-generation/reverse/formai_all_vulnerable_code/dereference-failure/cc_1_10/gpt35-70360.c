//FormAI DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_LENGTH 256

int backup_file(char *file_path, char *dest_dir);
int backup_dir(char *dir_path, char *dest_dir);

int main(int argc, char **argv) {
    char *src_path = argv[1];
    char *dest_path = argv[2];
    struct stat file_stat;

    // Check if the source path is valid
    if (stat(src_path, &file_stat) != 0) {
        printf("Invalid source path: %s\n", src_path);
        return 1;
    }

    // Check if the destination directory exists
    DIR *dest_dir = opendir(dest_path);
    if (!dest_dir) {
        printf("Destination directory does not exist: %s\n", dest_path);
        return 1;
    }
    closedir(dest_dir);

    // Check if the source path is a file or directory and backup accordingly
    if (S_ISDIR(file_stat.st_mode)) {
        printf("Backing up directory %s to %s\n", src_path, dest_path);
        backup_dir(src_path, dest_path);
    } else if (S_ISREG(file_stat.st_mode)) {
        printf("Backing up file %s to %s\n", src_path, dest_path);
        backup_file(src_path, dest_path);
    } else {
        printf("Unknown file type: %s\n", src_path);
        return 1;
    }

    return 0;
}

int backup_file(char *file_path, char *dest_dir) {
    char command[MAX_LENGTH];
    snprintf(command, MAX_LENGTH, "cp %s %s", file_path, dest_dir);
    return system(command);
}

int backup_dir(char *dir_path, char *dest_dir) {
    struct dirent *de;
    DIR *dir = opendir(dir_path);
    char src_file[MAX_LENGTH];
    char dest_file[MAX_LENGTH];
    while ((de = readdir(dir)) != NULL) {
        // Skip '.' and '..'
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_file, MAX_LENGTH, "%s/%s", dir_path, de->d_name);
        snprintf(dest_file, MAX_LENGTH, "%s/%s", dest_dir, de->d_name);

        struct stat file_stat;
        if (stat(src_file, &file_stat) != 0) {
            printf("Failed to get file info for %s, skipping file\n", src_file);
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // Recursive backup for directory
            backup_dir(src_file, dest_file);
        } else if (S_ISREG(file_stat.st_mode)) {
            // Backup file
            printf("Backing up file %s to %s\n", src_file, dest_file);
            backup_file(src_file, dest_dir);
        } else {
            printf("Unknown file type: %s\n", src_file);
            continue;
        }
    }
    closedir(dir);
    return 0;
}