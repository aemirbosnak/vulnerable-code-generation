//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
// Linus Torvalds Style C File Synchronizer

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

// File comparison function
int compare_files(const char *file1, const char *file2)
{
    // Open the files
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_RDONLY);
    if (fd1 < 0 || fd2 < 0) {
        perror("open");
        return -1;
    }

    // Get the file sizes
    struct stat st1, st2;
    if (fstat(fd1, &st1) < 0 || fstat(fd2, &st2) < 0) {
        perror("fstat");
        return -1;
    }

    // Check if the file sizes are different
    if (st1.st_size != st2.st_size) {
        printf("Files '%s' and '%s' have different sizes\n", file1, file2);
        return -1;
    }

    // Read the files into buffers
    char *buf1 = malloc(st1.st_size);
    char *buf2 = malloc(st2.st_size);
    if (buf1 == NULL || buf2 == NULL) {
        perror("malloc");
        return -1;
    }
    if (read(fd1, buf1, st1.st_size) < 0 || read(fd2, buf2, st2.st_size) < 0) {
        perror("read");
        return -1;
    }

    // Compare the buffers
    int result = memcmp(buf1, buf2, st1.st_size);

    // Clean up
    free(buf1);
    free(buf2);
    close(fd1);
    close(fd2);

    return result;
}

// File copying function
int copy_file(const char *source, const char *destination)
{
    // Open the source file for reading
    int fd1 = open(source, O_RDONLY);
    if (fd1 < 0) {
        perror("open");
        return -1;
    }

    // Open the destination file for writing
    int fd2 = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("open");
        return -1;
    }

    // Copy the data from the source file to the destination file
    char buf[4096];
    ssize_t nread;
    while ((nread = read(fd1, buf, sizeof(buf))) > 0) {
        if (write(fd2, buf, nread) < 0) {
            perror("write");
            return -1;
        }
    }

    // Check for errors
    if (nread < 0) {
        perror("read");
        return -1;
    }

    // Clean up
    close(fd1);
    close(fd2);

    return 0;
}

// Main function
int main(int argc, char **argv)
{
    // Check the arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return -1;
    }

    // Compare the files
    int result = compare_files(argv[1], argv[2]);

    // If the files are different, copy the source file to the destination file
    if (result != 0) {
        printf("Files '%s' and '%s' are different\nCopying '%s' to '%s'\n",
               argv[1], argv[2], argv[1], argv[2]);
        if (copy_file(argv[1], argv[2]) < 0) {
            perror("copy_file");
            return -1;
        }
    } else {
        printf("Files '%s' and '%s' are the same\n", argv[1], argv[2]);
    }

    return 0;
}