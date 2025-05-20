//GEMINI-pro DATASET v1.0 Category: System administration ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

// Macros to make error handling a bit less verbose
#define CHECK(expr) do { if (!(expr)) { perror(#expr); exit(EXIT_FAILURE); } } while (0)

// A mind-bending function that takes a file descriptor and magically reverses the contents of the file
void reverse_file(int fd) {
    // Get the file size
    struct stat st;
    CHECK(fstat(fd, &st) == 0);
    size_t size = st.st_size;

    // Allocate a buffer to hold the file contents
    char *buf = malloc(size);
    CHECK(buf != NULL);

    // Read the file into the buffer
    CHECK(read(fd, buf, size) == size);

    // Reverse the buffer contents
    for (size_t i = 0; i < size / 2; i++) {
        char tmp = buf[i];
        buf[i] = buf[size - 1 - i];
        buf[size - 1 - i] = tmp;
    }

    // Write the reversed buffer back to the file
    CHECK(lseek(fd, 0, SEEK_SET) == 0);
    CHECK(write(fd, buf, size) == size);

    // Free the buffer
    free(buf);
}

int main(int argc, char **argv) {
    // Check if the user provided a filename
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file
    int fd = open(argv[1], O_RDWR);
    CHECK(fd >= 0);

    // Reverse the file contents
    reverse_file(fd);

    // Close the file
    CHECK(close(fd) == 0);

    return EXIT_SUCCESS;
}