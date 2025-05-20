//FormAI DATASET v1.0 Category: File Synchronizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define BUFF_SIZE 1024

int sync_files(const char *dir1, const char *dir2);

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s [Directory 1] [Directory 2]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}

int sync_files(const char *dir1, const char *dir2) {
    DIR *dir1_ptr = opendir(dir1);
    DIR *dir2_ptr = opendir(dir2);
    struct dirent *dir1_entry_ptr;
    char dir1_path[BUFF_SIZE], dir2_path[BUFF_SIZE];

    // Check if directories exist
    if (dir1_ptr == NULL) {
        printf("[ERROR] Directory %s does not exist!\n", dir1);
        return EXIT_FAILURE;
    } else if (dir2_ptr == NULL) {
        printf("[ERROR] Directory %s does not exist!\n", dir2);
        return EXIT_FAILURE;
    }

    // Create the directories if they do not exist
    mkdir(dir1, 0777);
    mkdir(dir2, 0777);

    // Check files in dir1
    while ((dir1_entry_ptr = readdir(dir1_ptr)) != NULL) {
        if (strcmp(dir1_entry_ptr->d_name, ".") != 0
            && strcmp(dir1_entry_ptr->d_name, "..") != 0) {

            // Construct full file paths
            snprintf(dir1_path, BUFF_SIZE, "%s/%s", dir1, dir1_entry_ptr->d_name);
            snprintf(dir2_path, BUFF_SIZE, "%s/%s", dir2, dir1_entry_ptr->d_name);

            // Check if dir1 file is newer than dir2 file
            struct stat dir1_stat_buf, dir2_stat_buf;
            stat(dir1_path, &dir1_stat_buf);
            int dir2_fd = open(dir2_path, O_RDONLY);
            if (dir2_fd == -1) {
                // File does not exist in dir2, copy it over
                int dir1_fd = open(dir1_path, O_RDONLY);
                if (dir1_fd == -1) {
                    printf("[ERROR] File %s could not be opened!\n", dir1_path);
                    return EXIT_FAILURE;
                }

                // Create the file in dir2
                dir2_fd = open(dir2_path, O_RDWR | O_CREAT, 0644);
                if (dir2_fd == -1) {
                    printf("[ERROR] File %s could not be created!\n", dir2_path);
                    return EXIT_FAILURE;
                }

                // Copy the contents of dir1 file to dir2 file
                char buffer[BUFF_SIZE];
                ssize_t read_val;
                while ((read_val = read(dir1_fd, buffer, BUFF_SIZE)) > 0) {
                    ssize_t write_val = write(dir2_fd, buffer, (size_t) read_val);
                    if (write_val != read_val) {
                        printf("[ERROR] Error occurred while copying file %s to %s!\n", dir1_path, dir2_path);
                        return EXIT_FAILURE;
                    }
                }

                // Close the files
                close(dir1_fd);
                close(dir2_fd);

                printf("[INFO] File %s copied to %s\n", dir1_path, dir2_path);
                continue;
            }
            stat(dir2_path, &dir2_stat_buf);

            if (difftime(dir1_stat_buf.st_mtime, dir2_stat_buf.st_mtime) > 0) {
                // dir1 file is newer, copy it over
                int dir1_fd = open(dir1_path, O_RDONLY);
                if (dir1_fd == -1) {
                    printf("[ERROR] File %s could not be opened!\n", dir1_path);
                    return EXIT_FAILURE;
                }

                // Open the dir2 file in write mode
                dir2_fd = open(dir2_path, O_RDWR | O_TRUNC);
                if (dir2_fd == -1) {
                    printf("[ERROR] File %s could not be opened for writing!\n", dir2_path);
                    return EXIT_FAILURE;
                }

                // Copy the contents of dir1 file to dir2 file
                char buffer[BUFF_SIZE];
                ssize_t read_val;
                while ((read_val = read(dir1_fd, buffer, BUFF_SIZE)) > 0) {
                    ssize_t write_val = write(dir2_fd, buffer, (size_t) read_val);
                    if (write_val != read_val) {
                        printf("[ERROR] Error occurred while copying file %s to %s!\n", dir1_path, dir2_path);
                        return EXIT_FAILURE;
                    }
                }

                // Close the files
                close(dir1_fd);
                close(dir2_fd);

                printf("[INFO] File %s copied to %s\n", dir1_path, dir2_path);
            } else if (difftime(dir1_stat_buf.st_mtime, dir2_stat_buf.st_mtime) == 0) {
                // dir1 file is same as dir2 file, do nothing
                printf("[INFO] File %s is already up to date\n", dir2_path);
            }
        }
    }

    closedir(dir1_ptr);
    closedir(dir2_ptr);
    return EXIT_SUCCESS;
}