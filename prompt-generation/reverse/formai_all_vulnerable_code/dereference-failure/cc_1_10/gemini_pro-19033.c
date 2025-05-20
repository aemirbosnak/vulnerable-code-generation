//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PATH 256

// Function to get the current time and date
void get_current_time(char *time_str) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(time_str, 256, "%Y-%m-%d %H:%M:%S", tm);
}

// Function to create a backup file
int create_backup_file(char *src_path, char *dest_path) {
    FILE *src_file, *dest_file;

    // Open the source file for reading
    src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        perror("fopen() error");
        return -1;
    }

    // Open the destination file for writing
    dest_file = fopen(dest_path, "w");
    if (dest_file == NULL) {
        perror("fopen() error");
        fclose(src_file);
        return -1;
    }

    // Copy the contents of the source file to the destination file
    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, src_file) != NULL) {
        fputs(buffer, dest_file);
    }

    // Close the files
    fclose(src_file);
    fclose(dest_file);

    return 0;
}

// Function to backup a directory
int backup_directory(char *src_dir, char *dest_dir) {
    DIR *src_dirp, *dest_dirp;
    struct dirent *src_dirent, *dest_dirent;
    char src_path[MAX_PATH], dest_path[MAX_PATH], time_str[256];

    // Create the destination directory if it doesn't exist
    dest_dirp = opendir(dest_dir);
    if (dest_dirp == NULL) {
        if (mkdir(dest_dir, 0755) == -1) {
            perror("mkdir() error");
            return -1;
        }
    } else {
        closedir(dest_dirp);
    }

    // Open the source directory
    src_dirp = opendir(src_dir);
    if (src_dirp == NULL) {
        perror("opendir() error");
        return -1;
    }

    // Iterate over the files in the source directory
    while ((src_dirent = readdir(src_dirp)) != NULL) {
        // Skip hidden files
        if (src_dirent->d_name[0] == '.') {
            continue;
        }

        // Get the source file path
        snprintf(src_path, MAX_PATH, "%s/%s", src_dir, src_dirent->d_name);

        // Get the destination file path
        snprintf(dest_path, MAX_PATH, "%s/%s", dest_dir, src_dirent->d_name);

        // If the source file is a directory, backup it recursively
        if (src_dirent->d_type == DT_DIR) {
            if (backup_directory(src_path, dest_path) == -1) {
                return -1;
            }
        } else if (src_dirent->d_type == DT_REG) {
            // If the source file is a regular file, create a backup file
            get_current_time(time_str);
            snprintf(dest_path, MAX_PATH, "%s.%s", dest_path, time_str);
            if (create_backup_file(src_path, dest_path) == -1) {
                return -1;
            }
        }
    }

    // Close the directories
    closedir(src_dirp);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        return -1;
    }

    // Backup the source directory to the destination directory
    if (backup_directory(argv[1], argv[2]) == -1) {
        return -1;
    }

    return 0;
}