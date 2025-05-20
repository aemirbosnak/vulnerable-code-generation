//FormAI DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 512

void sync_files(char *src_dir, char *dest_dir) {
    DIR *dir;
    struct dirent *dir_entry;
    char src_path[BUF_SIZE];
    char dest_path[BUF_SIZE];
    struct stat src_file_stat, dest_file_stat;
    char buf[BUF_SIZE];
    int src_fd, dest_fd;
    int num_bytes;

    dir = opendir(src_dir);
    if (dir == NULL) {
        fprintf(stderr, "Error: Failed to open directory %s\n", src_dir);
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        // Ignore . and ..
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        // Create the source and destination paths
        snprintf(src_path, BUF_SIZE, "%s/%s", src_dir, dir_entry->d_name);
        snprintf(dest_path, BUF_SIZE, "%s/%s", dest_dir, dir_entry->d_name);

        // Get stat information for the source and destination files
        if (stat(src_path, &src_file_stat) < 0) {
            fprintf(stderr, "Error: Failed to get stat information for file %s: %s\n", src_path, strerror(errno));
            continue;
        }

        if (stat(dest_path, &dest_file_stat) < 0) {
            if (errno == ENOENT) {
                // The file doesn't exist in the destination directory, so we need to copy it over
                src_fd = open(src_path, O_RDONLY);
                if (src_fd < 0) {
                    fprintf(stderr, "Error: Failed to open file %s: %s\n", src_path, strerror(errno));
                    continue;
                }

                dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, src_file_stat.st_mode);
                if (dest_fd < 0) {
                    fprintf(stderr, "Error: Failed to create file %s: %s\n", dest_path, strerror(errno));
                    close(src_fd);
                    continue;
                }

                while ((num_bytes = read(src_fd, buf, BUF_SIZE)) > 0) {
                    if (write(dest_fd, buf, num_bytes) < 0) {
                        fprintf(stderr, "Error: Failed to write to file %s: %s\n", dest_path, strerror(errno));
                        close(src_fd);
                        close(dest_fd);
                        remove(dest_path);
                        continue;
                    }
                }

                close(src_fd);
                close(dest_fd);

            } else {
                fprintf(stderr, "Error: Failed to get stat information for file %s: %s\n", dest_path, strerror(errno));
                continue;
            }

        } else {
            if (S_ISREG(src_file_stat.st_mode)) {
                // If the source and destination files are regular files, we can compare their inode numbers to see if they are the same file
                if (src_file_stat.st_ino == dest_file_stat.st_ino) {
                    continue;
                }
            }

            // If the destination file is different than the source, overwrite the destination with the source
            src_fd = open(src_path, O_RDONLY);
            if (src_fd < 0) {
                fprintf(stderr, "Error: Failed to open file %s: %s\n", src_path, strerror(errno));
                continue;
            }

            dest_fd = open(dest_path, O_WRONLY | O_TRUNC);
            if (dest_fd < 0) {
                fprintf(stderr, "Error: Failed to open file %s: %s\n", dest_path, strerror(errno));
                close(src_fd);
                continue;
            }

            while ((num_bytes = read(src_fd, buf, BUF_SIZE)) > 0) {
                if (write(dest_fd, buf, num_bytes) < 0) {
                    fprintf(stderr, "Error: Failed to write to file %s: %s\n", dest_path, strerror(errno));
                    close(src_fd);
                    close(dest_fd);
                    remove(dest_path);
                    continue;
                }
            }

            close(src_fd);
            close(dest_fd);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    char *src_dir;
    char *dest_dir;

    if (argc < 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 0;
    }

    src_dir = argv[1];
    dest_dir = argv[2];

    printf("Synchronizing files from %s to %s...\n", src_dir, dest_dir);

    sync_files(src_dir, dest_dir);

    printf("Done.\n");

    return 0;
}