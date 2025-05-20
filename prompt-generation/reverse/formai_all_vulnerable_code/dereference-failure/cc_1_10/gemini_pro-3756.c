//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE 4096

void print_usage(char *progname) {
    printf("Usage: %s <source_dir> <dest_dir>\n", progname);
    printf("Synchronizes files between two directories.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *source_dir = argv[1];
    char *dest_dir = argv[2];

    // Check if both directories exist.
    struct stat source_stat;
    if (stat(source_dir, &source_stat) != 0) {
        fprintf(stderr, "Error: Source directory '%s' does not exist.\n", source_dir);
        return 1;
    }
    struct stat dest_stat;
    if (stat(dest_dir, &dest_stat) != 0) {
        fprintf(stderr, "Error: Destination directory '%s' does not exist.\n", dest_dir);
        return 1;
    }

    // Check if both directories are directories.
    if (!S_ISDIR(source_stat.st_mode)) {
        fprintf(stderr, "Error: Source path '%s' is not a directory.\n", source_dir);
        return 1;
    }
    if (!S_ISDIR(dest_stat.st_mode)) {
        fprintf(stderr, "Error: Destination path '%s' is not a directory.\n", dest_dir);
        return 1;
    }

    // Open both directories.
    DIR *source_dirp = opendir(source_dir);
    if (source_dirp == NULL) {
        fprintf(stderr, "Error: Unable to open source directory '%s'.\n", source_dir);
        return 1;
    }
    DIR *dest_dirp = opendir(dest_dir);
    if (dest_dirp == NULL) {
        fprintf(stderr, "Error: Unable to open destination directory '%s'.\n", dest_dir);
        return 1;
    }

    // Loop through all the files in the source directory.
    struct dirent *source_dirent;
    while ((source_dirent = readdir(source_dirp)) != NULL) {
        // Skip hidden files.
        if (source_dirent->d_name[0] == '.') {
            continue;
        }

        // Construct the full path to the file in the source directory.
        char *source_path = malloc(strlen(source_dir) + strlen(source_dirent->d_name) + 2);
        strcpy(source_path, source_dir);
        strcat(source_path, "/");
        strcat(source_path, source_dirent->d_name);

        // Check if the file exists in the destination directory.
        struct stat dest_stat;
        if (stat(source_path, &dest_stat) != 0) {
            // File does not exist in the destination directory. Copy it over.
            int source_fd = open(source_path, O_RDONLY);
            if (source_fd == -1) {
                fprintf(stderr, "Error: Unable to open source file '%s'.\n", source_path);
                free(source_path);
                continue;
            }
            int dest_fd = open(source_path, O_WRONLY | O_CREAT | O_TRUNC, source_stat.st_mode);
            if (dest_fd == -1) {
                fprintf(stderr, "Error: Unable to open destination file '%s'.\n", source_path);
                free(source_path);
                close(source_fd);
                continue;
            }
            char buf[BUF_SIZE];
            ssize_t bytes_read;
            while ((bytes_read = read(source_fd, buf, BUF_SIZE)) > 0) {
                write(dest_fd, buf, bytes_read);
            }
            close(source_fd);
            close(dest_fd);
        } else {
            // File exists in both directories. Check if it has changed.
            if (source_stat.st_mtime > dest_stat.st_mtime) {
                // Source file is newer. Copy it over.
                int source_fd = open(source_path, O_RDONLY);
                if (source_fd == -1) {
                    fprintf(stderr, "Error: Unable to open source file '%s'.\n", source_path);
                    free(source_path);
                    continue;
                }
                int dest_fd = open(source_path, O_WRONLY | O_TRUNC, source_stat.st_mode);
                if (dest_fd == -1) {
                    fprintf(stderr, "Error: Unable to open destination file '%s'.\n", source_path);
                    free(source_path);
                    close(source_fd);
                    continue;
                }
                char buf[BUF_SIZE];
                ssize_t bytes_read;
                while ((bytes_read = read(source_fd, buf, BUF_SIZE)) > 0) {
                    write(dest_fd, buf, bytes_read);
                }
                close(source_fd);
                close(dest_fd);
            }
        }

        // Free the allocated memory for the source path.
        free(source_path);
    }

    // Close both directories.
    closedir(source_dirp);
    closedir(dest_dirp);

    return 0;
}