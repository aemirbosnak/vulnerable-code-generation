//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

// Function to sync files between two directories
void sync_files(char* source_dir, char* dest_dir) {
    DIR* source_dir_ptr = opendir(source_dir);
    DIR* dest_dir_ptr = opendir(dest_dir);

    if (source_dir_ptr == NULL || dest_dir_ptr == NULL) {
        printf("Error: Unable to open one or both directories.\n");
        exit(1);
    }

    struct dirent* source_dirent;
    struct dirent* dest_dirent;

    while ((source_dirent = readdir(source_dir_ptr))!= NULL) {
        char source_file_path[MAX_PATH];
        char dest_file_path[MAX_PATH];

        strcpy(source_file_path, source_dir);
        strcat(source_file_path, "/");
        strcat(source_file_path, source_dirent->d_name);

        strcpy(dest_file_path, dest_dir);
        strcat(dest_file_path, "/");
        strcat(dest_file_path, source_dirent->d_name);

        struct stat source_stat;
        stat(source_file_path, &source_stat);

        if (S_ISDIR(source_stat.st_mode)) {
            // Recursively sync subdirectories
            sync_files(source_file_path, dest_file_path);
        } else {
            // Sync individual files
            int source_fd = open(source_file_path, O_RDONLY);
            int dest_fd = open(dest_file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

            char buffer[BUFFER_SIZE];
            ssize_t bytes_read;

            while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
                write(dest_fd, buffer, bytes_read);
            }

            close(source_fd);
            close(dest_fd);
        }
    }

    closedir(source_dir_ptr);
    closedir(dest_dir_ptr);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}