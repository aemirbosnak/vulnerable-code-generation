//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_PATH_LEN 1024
#define BUFFER_SIZE 4096

// function to check if file exists
int file_exists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// function to get size of a file
int get_file_size(char *filename) {
    struct stat buffer;
    stat(filename, &buffer);
    return buffer.st_size;
}

// function to copy file1 to file2
int copy_file(char *file1, char *file2) {
    int fd1, fd2, n, m;
    char buffer[BUFFER_SIZE];

    // open file1
    if ((fd1 = open(file1, O_RDONLY)) == -1) {
        printf("Error opening file %s: %s\n", file1, strerror(errno));
        return 1;
    }

    // open file2
    if ((fd2 = open(file2, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR)) == -1) {
        printf("Error opening file %s: %s\n", file2, strerror(errno));
        return 1;
    }

    // copy file1 to file2
    while ((n = read(fd1, buffer, BUFFER_SIZE)) > 0) {
        if ((m = write(fd2, buffer, n)) != n) {
            printf("Error writing to file %s: %s\n", file2, strerror(errno));
            return 1;
        }
    }

    // check for errors
    if (n == -1) {
        printf("Error reading file %s: %s\n", file1, strerror(errno));
        return 1;
    }

    // close both files
    close(fd1);
    close(fd2);

    return 0;
}

// function to synchronize two directories
int sync_directories(char *dir1, char *dir2) {
    DIR *dp;
    struct dirent *entry;
    char path[MAX_PATH_LEN];
    int file_count = 0;

    // open dir1
    if ((dp = opendir(dir1)) == NULL) {
        printf("Error opening directory %s: %s\n", dir1, strerror(errno));
        return 1;
    }

    // iterate over files in dir1
    while ((entry = readdir(dp)) != NULL) {
        // ignore '.' and '..' directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // construct path for current file in dir1
        snprintf(path, MAX_PATH_LEN, "%s/%s", dir1, entry->d_name);

        // check if path is a file or directory
        if (entry->d_type == DT_DIR) {
            // recursively call sync_directories on subdirectory
            if (sync_directories(path, dir2) != 0) {
                return 1;
            }
        } else if (entry->d_type == DT_REG) {
            // path is a file
            file_count++;

            // construct path for corresponding file in dir2
            snprintf(path, MAX_PATH_LEN, "%s/%s", dir2, entry->d_name);

            // check if file exists in dir2 and get its size
            int file_size = 0;
            if (file_exists(path)) {
                file_size = get_file_size(path);
            }

            // check if file needs to be copied
            if (get_file_size(path) != get_file_size(entry->d_name)) {
                printf("Copying file %s to %s\n", entry->d_name, path);
                if (copy_file(entry->d_name, path) != 0) {
                    printf("Error copying file %s to %s\n", entry->d_name, path);
                    return 1;
                }
            }
        }
    }

    // check for errors
    if (errno != 0) {
        printf("Error reading directory %s: %s\n", dir1, strerror(errno));
        return 1;
    }

    // close dir1
    closedir(dp);

    printf("Synchronized %d file(s)\n", file_count);

    return 0;
}

// main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s dir1 dir2\n", argv[0]);
        return 1;
    }

    if (sync_directories(argv[1], argv[2]) != 0) {
        printf("Error synchronizing directories\n");
        return 1;
    }

    return 0;
}