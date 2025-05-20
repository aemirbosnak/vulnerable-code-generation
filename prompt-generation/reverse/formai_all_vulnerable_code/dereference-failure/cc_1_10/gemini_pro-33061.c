//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Define some constants
#define BUF_SIZE 4096
#define MAX_PATH_LEN 256

// Function to recursively traverse a directory and copy files
void backup_dir(char *src_dir, char *dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH_LEN];
    char dest_path[MAX_PATH_LEN];

    // Open the source directory
    dir = opendir(src_dir);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    // Iterate over the entries in the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Construct the source and destination paths
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        // Check if the source entry is a file
        struct stat statbuf;
        if (stat(src_path, &statbuf) == 0 && S_ISREG(statbuf.st_mode)) {
            // Copy the file
            FILE *src_file, *dest_file;
            char buf[BUF_SIZE];
            size_t bytes_read, bytes_written;

            // Open the source file for reading
            src_file = fopen(src_path, "rb");
            if (src_file == NULL) {
                perror("fopen");
                exit(1);
            }

            // Open the destination file for writing
            dest_file = fopen(dest_path, "wb");
            if (dest_file == NULL) {
                perror("fopen");
                exit(1);
            }

            // Copy the file data
            while ((bytes_read = fread(buf, 1, BUF_SIZE, src_file)) > 0) {
                bytes_written = fwrite(buf, 1, bytes_read, dest_file);
                if (bytes_written != bytes_read) {
                    perror("fwrite");
                    exit(1);
                }
            }

            // Close the source and destination files
            fclose(src_file);
            fclose(dest_file);
        } else if (S_ISDIR(statbuf.st_mode)) {
            // Recursively backup the directory
            backup_dir(src_path, dest_path);
        }
    }

    // Close the source directory
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    // Backup the source directory to the destination directory
    backup_dir(argv[1], argv[2]);

    return 0;
}