//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define BUF_SIZE 1024

void sync_files(char *src_dir, char *dest_dir) {
    DIR *src_dir_ptr = opendir(src_dir);
    DIR *dest_dir_ptr = opendir(dest_dir);

    if (src_dir_ptr == NULL || dest_dir_ptr == NULL) {
        printf("Error: Could not open one of the directories.\n");
        exit(1);
    }

    struct dirent *src_file;
    struct dirent *dest_file;

    while ((src_file = readdir(src_dir_ptr))!= NULL) {
        char src_file_path[256];
        char dest_file_path[256];

        strcpy(src_file_path, src_dir);
        strcat(src_file_path, "/");
        strcat(src_file_path, src_file->d_name);

        strcpy(dest_file_path, dest_dir);
        strcat(dest_file_path, "/");
        strcat(dest_file_path, src_file->d_name);

        if (src_file->d_type == DT_DIR) {
            if (mkdir(dest_file_path, 0755)!= 0) {
                printf("Error: Could not create directory %s.\n", dest_file_path);
                exit(1);
            }
        } else {
            int src_fd = open(src_file_path, O_RDONLY);
            int dest_fd = open(dest_file_path, O_WRONLY | O_CREAT, 0755);

            if (src_fd == -1 || dest_fd == -1) {
                printf("Error: Could not open file %s.\n", src_file_path);
                exit(1);
            }

            char buffer[BUF_SIZE];
            ssize_t bytes_read;

            while ((bytes_read = read(src_fd, buffer, BUF_SIZE)) > 0) {
                ssize_t bytes_written = write(dest_fd, buffer, bytes_read);

                if (bytes_written!= bytes_read) {
                    printf("Error: Could not write all data to file %s.\n", dest_file_path);
                    exit(1);
                }
            }

            close(src_fd);
            close(dest_fd);
        }
    }

    closedir(src_dir_ptr);
    closedir(dest_dir_ptr);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    printf("File synchronization complete.\n");
    return 0;
}