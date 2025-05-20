//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// Define a function to check if a file/directory exists
int file_exists(char *path) {
    struct stat stats;
    return (stat(path, &stats) == 0);
}

// Define a function to create a directory
int create_directory(char *path) {
    if (mkdir(path, 0777) == -1) {
        return 0;
    }
    return 1;
}

// Define a function to copy a file
int copy_file(char *src_path, char *dst_path) {
    FILE *src_file, *dst_file;
    int buf_size = 512; // buffer size in bytes
    char buffer[buf_size];

    src_file = fopen(src_path, "rb");
    if (src_file == NULL) {
        return 0;
    }

    dst_file = fopen(dst_path, "wb");
    if (dst_file == NULL) {
        fclose(src_file);
        return 0;
    }

    while (fread(buffer, sizeof(char), buf_size, src_file) > 0) {
        fwrite(buffer, sizeof(char), buf_size, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    return 1;
}

// Define a function to synchronize two directories
int sync_directories(char *src_dir, char *dst_dir) {
    DIR *src_dp, *dst_dp;
    struct dirent *src_dirent, *dst_dirent;
    char src_path[4096], dst_path[4096];

    // Open the source and destination directories
    src_dp = opendir(src_dir);
    if (src_dp == NULL) {
        printf("Error opening source directory\n");
        return 0;
    }

    dst_dp = opendir(dst_dir);
    if (dst_dp == NULL) {
        printf("Error opening destination directory\n");
        closedir(src_dp);
        return 0;
    }

    // Iterate over the source directory entries
    while ((src_dirent = readdir(src_dp)) != NULL) {
        if (strcmp(src_dirent->d_name, ".") == 0 || strcmp(src_dirent->d_name, "..") == 0) {
            // Skip . and .. directories
            continue;
        }

        sprintf(src_path, "%s/%s", src_dir, src_dirent->d_name);
        sprintf(dst_path, "%s/%s", dst_dir, src_dirent->d_name);

        if (file_exists(dst_path)) {
            // If the file already exists in the destination directory, check if it needs to be updated
            struct stat src_stats, dst_stats;
            stat(src_path, &src_stats);
            stat(dst_path, &dst_stats);

            if (src_stats.st_mtime > dst_stats.st_mtime) {
                // If the source file has been modified more recently than the destination file, copy it over
                copy_file(src_path, dst_path);
            }
        } else {
            // If the file doesn't exist in the destination directory, copy it over
            copy_file(src_path, dst_path);
        }
    }

    // Close the directories and return success
    closedir(src_dp);
    closedir(dst_dp);
    return 1;
}

int main(int argc, char *argv[]) {
    char *src_dir, *dst_dir;

    if (argc < 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    src_dir = argv[1];
    dst_dir = argv[2];

    if (!file_exists(src_dir)) {
        printf("Source directory doesn't exist\n");
        return 1;
    }

    if (!file_exists(dst_dir)) {
        if (!create_directory(dst_dir)) {
            printf("Error creating the destination directory\n");
            return 1;
        }
    }

    if (!sync_directories(src_dir, dst_dir)) {
        printf("Error synchronizing the directories\n");
        return 1;
    }

    printf("Directories synchronized successfully\n");
    return 0;
}