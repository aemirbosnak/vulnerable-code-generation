//FormAI DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILENAME_LENGTH 128

int sync_files(char *dir1, char *dir2);
void copy_file(char *src_path, char *dst_path);
int is_dir(char *path);
int check_file_exists(char *path);
void create_dir(char *path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./file_syncer <directory 1> <directory 2>\n");
        return 1;
    }

    char *dir1 = argv[1];
    char *dir2 = argv[2];

    int result = sync_files(dir1, dir2);
    if (result == 0) {
        printf("Files synced successfully!\n");
    } else {
        printf("Failed to sync files.\n");
    }

    return 0;
}

int sync_files(char *dir1, char *dir2) {
    DIR *dir;
    struct dirent *ent;
    char src_path[MAX_PATH_LENGTH], dst_path[MAX_PATH_LENGTH];
    int errors = 0;

    // Open directory 1
    if ((dir = opendir(dir1)) != NULL) {
        // Loop through all files in directory 1
        while ((ent = readdir(dir)) != NULL) {
            // Ignore special directories
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", dir1, ent->d_name);
            snprintf(dst_path, MAX_PATH_LENGTH, "%s/%s", dir2, ent->d_name);

            // Check if the file is a directory
            if (is_dir(src_path)) {
                // If the directory doesn't exist in directory 2, create it
                if (!check_file_exists(dst_path)) {
                    create_dir(dst_path);
                }

                // Recursively sync files in the subdirectory
                sync_files(src_path, dst_path);
            } else {
                // Only copy the file if it doesn't exist in directory 2 or if it has been modified
                if (!check_file_exists(dst_path)) {
                    copy_file(src_path, dst_path);
                }
            }
        }

        closedir(dir);
    } else {
        // Failed to open directory 1
        perror("Could not open directory");
        errors++;
    }

    return errors;
}

void copy_file(char *src_path, char *dst_path) {
    FILE *src, *dst;
    char buffer[1024];
    size_t bytes_read, bytes_written;

    // Open the source file
    if ((src = fopen(src_path, "rb")) == NULL) {
        perror("Could not open source file");
        return;
    }

    // Create the destination file
    if ((dst = fopen(dst_path, "wb")) == NULL) {
        perror("Could not create destination file");
        return;
    }

    // Copy the file contents
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dst);
        if (bytes_written != bytes_read) {
            perror("Could not write to destination file");
            return;
        }
    }

    fclose(src);
    fclose(dst);
}

int is_dir(char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        perror("Could not get file stats");
        return 0;
    }

    return S_ISDIR(path_stat.st_mode);
}

int check_file_exists(char *path) {
    if (access(path, F_OK) != -1) {
        return 1;
    } else {
        return 0;
    }
}

void create_dir(char *path) {
    char command[MAX_PATH_LENGTH];
    snprintf(command, MAX_PATH_LENGTH, "mkdir -p %s", path);
    system(command);
}