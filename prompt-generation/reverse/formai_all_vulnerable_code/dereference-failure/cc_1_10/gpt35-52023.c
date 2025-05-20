//FormAI DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1024

// Function to check if the file exists
int check_file_exists(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    fclose(file);
    return 1;
}

// Function to recursively copy files from source directory to destination directory
void copy_files(char *src_path, char *dest_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat src_stat, dest_stat;
    char src_file_path[MAX_FILE_SIZE], dest_file_path[MAX_FILE_SIZE];
    
    // Open the source directory
    if ((dir = opendir(src_path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Create the destination directory if it does not exist
    if (!check_file_exists(dest_path)) {
        mkdir(dest_path, 0777);
    }

    // Traverse the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create the source and destination file paths
        sprintf(src_file_path, "%s/%s", src_path, entry->d_name);
        sprintf(dest_file_path, "%s/%s", dest_path, entry->d_name);

        // Get the source file status
        if (stat(src_file_path, &src_stat) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        // If the source file is a directory, recursively copy its contents
        if (S_ISDIR(src_stat.st_mode)) {
            copy_files(src_file_path, dest_file_path);
        }
        // If the source file is a regular file, copy it to destination
        else if (S_ISREG(src_stat.st_mode)) {
            // If the destination file exists and its last modified time is the same as the source file,
            // then do not copy the file
            if (check_file_exists(dest_file_path)) {
                if (stat(dest_file_path, &dest_stat) == -1) {
                    perror("stat");
                    exit(EXIT_FAILURE);
                }
                if (src_stat.st_mtime <= dest_stat.st_mtime) {
                    continue;
                }
            }

            // If the destination file does not exist or the source and destination are different, copy the file
            int src_fd, dest_fd;
            char buf[MAX_FILE_SIZE];
            ssize_t bytes_read, bytes_written;

            src_fd = open(src_file_path, O_RDONLY);
            if (src_fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            dest_fd = open(dest_file_path, O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);
            if (dest_fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            while ((bytes_read = read(src_fd, buf, sizeof buf)) > 0) {
                bytes_written = write(dest_fd, buf, bytes_read);
                if (bytes_written == -1) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }

                if (bytes_written != bytes_read) {
                    fprintf(stderr, "write error: partial write\n");
                    exit(EXIT_FAILURE);
                }
            }

            if (bytes_read == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            if (close(src_fd) == -1) {
                perror("close");
                exit(EXIT_FAILURE);
            }

            if (close(dest_fd) == -1) {
                perror("close");
                exit(EXIT_FAILURE);
            }
        }
    }

    if (closedir(dir) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copy_files(argv[1], argv[2]);

    printf("Files synchronized successfully!\n");
    exit(EXIT_SUCCESS);
}