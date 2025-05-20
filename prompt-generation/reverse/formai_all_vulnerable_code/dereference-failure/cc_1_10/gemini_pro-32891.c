//GEMINI-pro DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd, ret;
    char buf[1024];
    struct stat st;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check if the file exists and is readable
    if (stat(argv[1], &st) == -1) {
        fprintf(stderr, "Error: %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (!S_ISREG(st.st_mode) || !(st.st_mode & S_IRUSR)) {
        fprintf(stderr, "Error: %s is not a regular file or is not readable\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Open the file for reading
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Read the file contents
    while ((ret = read(fd, buf, sizeof(buf))) > 0) {
        // Write the file contents to stdout
        write(STDOUT_FILENO, buf, ret);
    }

    if (ret == -1) {
        fprintf(stderr, "Error: %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    return EXIT_SUCCESS;
}