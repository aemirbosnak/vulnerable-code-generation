//FormAI DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void synchronize(char *root_dir, char *dest_dir) {
    DIR *dir = opendir(root_dir);  // Open root directory
    struct dirent *dir_entry;

    // Loop through all files and directories in root directory
    while ((dir_entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        // Construct path to current file or directory
        char src_path[BUF_SIZE];
        char dest_path[BUF_SIZE];
        snprintf(src_path, BUF_SIZE, "%s/%s", root_dir, dir_entry->d_name);
        snprintf(dest_path, BUF_SIZE, "%s/%s", dest_dir, dir_entry->d_name);

        // Get status of current file or directory
        struct stat src_stat;
        lstat(src_path, &src_stat);

        // If current entry is a directory, recursively synchronize it
        if (S_ISDIR(src_stat.st_mode)) {
            // Create corresponding directory in destination
            mkdir(dest_path, src_stat.st_mode);

            // Synchronize contents of current directory
            synchronize(src_path, dest_path);
        } else { // Otherwise, synchronize current file
            int src_file = open(src_path, O_RDONLY);  // Open source file
            int dest_file = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);  // Open or create destination file

            // Copy contents of source file to destination file
            char buf[BUF_SIZE];
            ssize_t bytes_read;
            while ((bytes_read = read(src_file, &buf, BUF_SIZE)) > 0) {
                write(dest_file, &buf, bytes_read);
            }

            // Close files
            close(src_file);
            close(dest_file);

            // Set file modification time of destination to match source
            struct timeval times[2];
            times[0].tv_sec = src_stat.st_atime;
            times[0].tv_usec = 0;
            times[1].tv_sec = src_stat.st_mtime;
            times[1].tv_usec = 0;
            utimes(dest_path, times);
        }
    }

    // Close directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check if both root directory and destination directory were provided
    if (argc < 3) {
        printf("Usage: %s <root_dir> <dest_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Synchronize root directory with destination directory
    synchronize(argv[1], argv[2]);

    return 0;
}