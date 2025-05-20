//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

// Function to get the file size
long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Function to copy the file
int copy_file(const char *src, const char *dst) {
    int src_fd, dst_fd;
    char buf[BUF_SIZE];
    int nread, nwritten;

    // Open the source file
    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("open");
        return -1;
    }

    // Open the destination file
    dst_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) {
        perror("open");
        return -1;
    }

    // Copy the file
    while ((nread = read(src_fd, buf, BUF_SIZE)) > 0) {
        nwritten = write(dst_fd, buf, nread);
        if (nwritten != nread) {
            perror("write");
            return -1;
        }
    }

    // Close the files
    close(src_fd);
    close(dst_fd);

    return 0;
}

// Function to compare the files
int compare_files(const char *file1, const char *file2) {
    int fd1, fd2;
    char buf1[BUF_SIZE], buf2[BUF_SIZE];
    int nread1, nread2;

    // Open the files
    fd1 = open(file1, O_RDONLY);
    if (fd1 < 0) {
        perror("open");
        return -1;
    }

    fd2 = open(file2, O_RDONLY);
    if (fd2 < 0) {
        perror("open");
        return -1;
    }

    // Compare the files
    while ((nread1 = read(fd1, buf1, BUF_SIZE)) > 0) {
        nread2 = read(fd2, buf2, BUF_SIZE);
        if (nread2 != nread1) {
            return -1;
        }

        if (memcmp(buf1, buf2, nread1) != 0) {
            return -1;
        }
    }

    // Close the files
    close(fd1);
    close(fd2);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check the arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <src> <dst> <mode>\n", argv[0]);
        return -1;
    }

    // Get the mode
    int mode = atoi(argv[3]);

    // Synchronize the files
    switch (mode) {
    case 1:
        // Copy the file from src to dst
        if (copy_file(argv[1], argv[2]) != 0) {
            return -1;
        }
        break;
    case 2:
        // Compare the files and copy the newer one to the other
        if (get_file_size(argv[1]) > get_file_size(argv[2])) {
            if (copy_file(argv[1], argv[2]) != 0) {
                return -1;
            }
        } else {
            if (copy_file(argv[2], argv[1]) != 0) {
                return -1;
            }
        }
        break;
    case 3:
        // Compare the files and delete the older one
        if (get_file_size(argv[1]) < get_file_size(argv[2])) {
            if (remove(argv[1]) != 0) {
                perror("remove");
                return -1;
            }
        } else {
            if (remove(argv[2]) != 0) {
                perror("remove");
                return -1;
            }
        }
        break;
    default:
        fprintf(stderr, "Invalid mode: %d\n", mode);
        return -1;
    }

    return 0;
}