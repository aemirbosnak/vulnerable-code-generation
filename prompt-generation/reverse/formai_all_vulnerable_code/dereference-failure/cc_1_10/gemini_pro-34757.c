//GEMINI-pro DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// Open a file with O_CREAT|O_EXCL flags, and fail if the file already exists

int create_unique_file(const char *filename) {
    int fd = open(filename, O_CREAT|O_EXCL|O_WRONLY, 0644);
    if (fd == -1) {
        if (errno == EEXIST) {
            fprintf(stderr, "File %s already exists\n", filename);
        } else {
            perror("open");
        }
        return -1;
    }
    return fd;
}

// Write a string to a file, and close the file

int write_string_to_file(int fd, const char *str) {
    int len = strlen(str);
    if (write(fd, str, len) == -1) {
        perror("write");
        return -1;
    }
    if (close(fd) == -1) {
        perror("close");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file with O_CREAT|O_EXCL flags, and fail if the file already exists

    int fd = create_unique_file(argv[1]);
    if (fd == -1) {
        return EXIT_FAILURE;
    }

    // Write a string to the file, and close the file

    if (write_string_to_file(fd, "Hello world!\n") == -1) {
        return EXIT_FAILURE;
    }

    printf("File %s created successfully\n", argv[1]);

    return EXIT_SUCCESS;
}