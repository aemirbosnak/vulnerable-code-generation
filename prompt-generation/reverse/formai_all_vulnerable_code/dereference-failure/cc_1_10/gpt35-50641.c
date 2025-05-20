//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void sync_files(char *source_dir, char *dest_dir) {
    DIR *source_dp = opendir(source_dir);
    struct dirent *source_file;
    char source_path[4096];

    DIR *dest_dp = opendir(dest_dir);
    struct dirent *dest_file;
    char dest_path[4096];

    struct stat source_stat, dest_stat;

    while ((source_file = readdir(source_dp)) != NULL) {
        if (source_file->d_type == DT_DIR) {
            if (strcmp(source_file->d_name, ".") != 0 && strcmp(source_file->d_name, "..") != 0) {
                strcpy(source_path, source_dir);
                strcat(source_path, "/");
                strcat(source_path, source_file->d_name);

                strcpy(dest_path, dest_dir);
                strcat(dest_path, "/");
                strcat(dest_path, source_file->d_name);

                // recursively sync subdirectories
                sync_files(source_path, dest_path);
            }
        } else {
            strcpy(source_path, source_dir);
            strcat(source_path, "/");
            strcat(source_path, source_file->d_name);

            strcpy(dest_path, dest_dir);
            strcat(dest_path, "/");
            strcat(dest_path, source_file->d_name);

            if (lstat(source_path, &source_stat) == 0) {
                // check if file exists in destination directory
                if (lstat(dest_path, &dest_stat) == 0) {
                    // check if source is newer than dest, copy if necessary
                    if (difftime(source_stat.st_mtime, dest_stat.st_mtime) > 0) {
                        int source_fd = open(source_path, O_RDONLY);
                        int dest_fd = open(dest_path, O_WRONLY | O_TRUNC);

                        if (source_fd != -1 && dest_fd != -1) {
                            char buffer[4096];
                            ssize_t read_bytes, write_bytes;

                            while ((read_bytes = read(source_fd, buffer, sizeof(buffer))) > 0) {
                                write_bytes = write(dest_fd, buffer, (ssize_t) read_bytes);
                                if (write_bytes != read_bytes) {
                                    fprintf(stderr, "Error writing to destination file: %s: %s\n", dest_path, strerror(errno));
                                    break;
                                }
                            }

                            if (read_bytes == -1) {
                                fprintf(stderr, "Error reading from source file: %s: %s\n", source_path, strerror(errno));
                            }

                            close(source_fd);
                            close(dest_fd);
                        } else {
                            fprintf(stderr, "Error opening files: %s: %s, %s: %s\n", source_path, strerror(errno), dest_path, strerror(errno));
                        }
                    }
                } else {
                    // file does not exist in dest, copy over
                    int source_fd = open(source_path, O_RDONLY);
                    int dest_fd = open(dest_path, O_WRONLY | O_CREAT, source_stat.st_mode);

                    if (source_fd != -1 && dest_fd != -1) {
                        char buffer[4096];
                        ssize_t read_bytes, write_bytes;

                        while ((read_bytes = read(source_fd, buffer, sizeof(buffer))) > 0) {
                            write_bytes = write(dest_fd, buffer, (ssize_t) read_bytes);
                            if (write_bytes != read_bytes) {
                                fprintf(stderr, "Error writing to destination file: %s: %s\n", dest_path, strerror(errno));
                                break;
                            }
                        }

                        if (read_bytes == -1) {
                            fprintf(stderr, "Error reading from source file: %s: %s\n", source_path, strerror(errno));
                        }

                        close(source_fd);
                        close(dest_fd);
                    } else {
                        fprintf(stderr, "Error opening files: %s: %s, %s: %s\n", source_path, strerror(errno), dest_path, strerror(errno));
                    }
                }
            } else {
                fprintf(stderr, "Error getting file information: %s: %s\n", source_path, strerror(errno));
            }
        }
    }

    closedir(source_dp);
    closedir(dest_dp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: sync_files <source directory> <destination directory>\n");
        exit(EXIT_FAILURE);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}