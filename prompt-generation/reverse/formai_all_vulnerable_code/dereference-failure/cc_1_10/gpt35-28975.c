//FormAI DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 128

// Function to copy contents of one file to another
int copyFile(const char *src, const char *dst) {
    int fd_src, fd_dst, read_count, write_count;
    char buffer[BUFFSIZE];

    // Open source file for reading
    fd_src = open(src, O_RDONLY);
    if (fd_src == -1) {
        return -1;
    }

    // Open destination file for writing
    fd_dst = open(dst, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_dst == -1) {
        close(fd_src);
        return -1;
    }

    // Copy contents of source file to destination file
    while ((read_count = read(fd_src, buffer, BUFFSIZE)) > 0) {
        write_count = write(fd_dst, buffer, read_count);
        if (write_count != read_count) {
            close(fd_src);
            close(fd_dst);
            return -1;
        }
    }

    // Clean up and return
    close(fd_src);
    close(fd_dst);
    return 0;
}

// Function to synchronize source and destination directories
void synchronize(const char *src_dir, const char *dst_dir) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char src_path[256], dst_path[256];

    // Open source directory for scanning
    dir = opendir(src_dir);
    if (!dir) {
        fprintf(stderr, "Unable to open directory %s\n", src_dir);
        return;
    }

    // Scan source directory
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build source and destination file paths
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        // Check if source file exists
        if (lstat(src_path, &statbuf) == -1) {
            fprintf(stderr, "Unable to get file info for %s\n", src_path);
            continue;
        }

        // Check if source file is a directory
        if (S_ISDIR(statbuf.st_mode)) {
            // Directory synchronization
            if (access(dst_path, F_OK) == -1) {
                // Create new destination directory if it doesn't exist
                mkdir(dst_path, S_IRUSR | S_IWUSR | S_IXUSR);
            }
            synchronize(src_path, dst_path);    // Recursively synchronize directories
        } else {
            // File synchronization
            if (access(dst_path, F_OK) == -1) {
                // Copy source file to destination if it doesn't exist
                if (copyFile(src_path, dst_path) == -1) {
                    fprintf(stderr, "Unable to copy file %s to %s\n", src_path, dst_path);
                }
            } else {
                // Update destination file if source file is newer
                if (stat(dst_path, &statbuf) == -1) {
                    fprintf(stderr, "Unable to get file info for %s\n", dst_path);
                    continue;
                }
                if (statbuf.st_mtime < statbuf.st_mtime) {
                    if (copyFile(src_path, dst_path) == -1) {
                        fprintf(stderr, "Unable to copy file %s to %s\n", src_path, dst_path);
                    }
                }
            }
        }
    }

    // Clean up
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_dir destination_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronize(argv[1], argv[2]);    // Synchronize directories
    printf("Synchronization complete!\n");

    return 0;
}