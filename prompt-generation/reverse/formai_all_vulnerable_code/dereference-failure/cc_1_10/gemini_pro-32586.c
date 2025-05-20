//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

#define MAX_PATH_LENGTH 256

// Recursively copies the contents of one directory to another
void copy_dir(char *src, char *dest) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH_LENGTH];
    struct stat st;

    // Open the source directory
    if ((dir = opendir(src)) == NULL) {
        fprintf(stderr, "Error opening directory %s\n", src);
        return;
    }

    // Create the destination directory if it doesn't exist
    if (stat(dest, &st) == -1) {
        if (mkdir(dest, 0755) == -1) {
            fprintf(stderr, "Error creating directory %s\n", dest);
            closedir(dir);
            return;
        }
    }

    // Read the directory entries
    while ((ent = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (ent->d_name[0] == '.') {
            continue;
        }

        // Get the full path to the source file
        snprintf(path, MAX_PATH_LENGTH, "%s/%s", src, ent->d_name);

        // Copy the file to the destination directory
        if (lstat(path, &st) == -1) {
            fprintf(stderr, "Error getting file status for %s\n", path);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            // Copy the directory
            char new_path[MAX_PATH_LENGTH];
            snprintf(new_path, MAX_PATH_LENGTH, "%s/%s", dest, ent->d_name);
            copy_dir(path, new_path);
        } else if (S_ISREG(st.st_mode)) {
            // Copy the file
            char new_path[MAX_PATH_LENGTH];
            snprintf(new_path, MAX_PATH_LENGTH, "%s/%s", dest, ent->d_name);
            if (copy_file(path, new_path) == -1) {
                fprintf(stderr, "Error copying file %s\n", path);
            }
        }
    }

    // Close the directory
    closedir(dir);
}

// Copies a file from one location to another
int copy_file(char *src, char *dest) {
    int fd_src, fd_dest;
    char buf[4096];
    int nread;

    // Open the source file
    if ((fd_src = open(src, O_RDONLY)) == -1) {
        fprintf(stderr, "Error opening file %s\n", src);
        return -1;
    }

    // Open the destination file
    if ((fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        fprintf(stderr, "Error opening file %s\n", dest);
        close(fd_src);
        return -1;
    }

    // Copy the file
    while ((nread = read(fd_src, buf, sizeof(buf))) > 0) {
        if (write(fd_dest, buf, nread) != nread) {
            fprintf(stderr, "Error writing to file %s\n", dest);
            close(fd_src);
            close(fd_dest);
            return -1;
        }
    }

    // Close the files
    close(fd_src);
    close(fd_dest);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Copy the source directory to the destination directory
    copy_dir(argv[1], argv[2]);

    return 0;
}