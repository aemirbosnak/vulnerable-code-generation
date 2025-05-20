//FormAI DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

void synchronize(char* src_folder, char* dest_folder) {
    // Open directories
    DIR* src_dir = opendir(src_folder);
    DIR* dest_dir = opendir(dest_folder);

    // Check if directories were opened successfully
    if (src_dir == NULL) {
        printf("Error: could not open %s\n", src_folder);
        exit(1);
    }
    if (dest_dir == NULL) {
        printf("Error: could not open %s\n", dest_folder);
        exit(1);
    }

    // Read files in source directory
    struct dirent* src_entry;
    while ((src_entry = readdir(src_dir)) != NULL) {
        // Skip directories and hidden files
        if (src_entry->d_type == DT_DIR || src_entry->d_name[0] == '.') {
            continue;
        }

        // Generate full path of file in source folder
        char src_path[MAX_FILENAME_LENGTH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_folder, src_entry->d_name);

        // Check if file exists in destination folder
        struct dirent* dest_entry;
        int found = 0;
        while ((dest_entry = readdir(dest_dir)) != NULL) {
            char dest_path[MAX_FILENAME_LENGTH];
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_folder, dest_entry->d_name);

            // Compare file names
            if (strcmp(src_entry->d_name, dest_entry->d_name) == 0) {
                // Check if files have different sizes
                struct stat src_stat, dest_stat;
                stat(src_path, &src_stat);
                stat(dest_path, &dest_stat);

                if (src_stat.st_size != dest_stat.st_size) {
                    // Copy file from source to destination
                    int src_file = open(src_path, O_RDONLY);
                    int dest_file = open(dest_path, O_WRONLY);
                    char buffer[BUFFER_SIZE];
                    int bytes_read;

                    while ((bytes_read = read(src_file, buffer, BUFFER_SIZE)) > 0) {
                        write(dest_file, buffer, bytes_read);
                    }

                    close(src_file);
                    close(dest_file);

                    printf("Copied %s to %s\n", src_path, dest_path);
                }

                found = 1;
                break;
            }
        }

        // File not found in destination folder, copy it over
        if (!found) {
            char dest_path[MAX_FILENAME_LENGTH];
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_folder, src_entry->d_name);

            int src_file = open(src_path, O_RDONLY);
            int dest_file = open(dest_path, O_CREAT | O_WRONLY, 0644);
            char buffer[BUFFER_SIZE];
            int bytes_read;

            while ((bytes_read = read(src_file, buffer, BUFFER_SIZE)) > 0) {
                write(dest_file, buffer, bytes_read);
            }

            close(src_file);
            close(dest_file);

            printf("Copied %s to %s\n", src_path, dest_path);
        }

        rewinddir(dest_dir);
    }

    // Close directories
    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source folder> <destination folder>\n", argv[0]);
        exit(1);
    }

    synchronize(argv[1], argv[2]);

    return 0;
}