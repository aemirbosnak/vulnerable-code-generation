//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to recover data from a file
int recover_data(char *filename) {
    // Open the file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    // Get the file size
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return -1;
    }

    // Allocate a buffer to store the file data
    char *data = malloc(st.st_size);
    if (data == NULL) {
        perror("malloc");
        close(fd);
        return -1;
    }

    // Read the file data into the buffer
    if (read(fd, data, st.st_size) != st.st_size) {
        perror("read");
        free(data);
        close(fd);
        return -1;
    }

    // Close the file
    close(fd);

    // Search for the signature of the deleted file
    char *signature = "DELETED";
    char *found = strstr(data, signature);
    if (found == NULL) {
        // The file was not found
        free(data);
        return -1;
    }

    // Get the start and end of the deleted file
    char *start = found + strlen(signature);
    char *end = strchr(start, '\n');
    if (end == NULL) {
        // The file is not valid
        free(data);
        return -1;
    }

    // Write the deleted file to a new file
    char *new_filename = "recovered_file";
    int new_fd = open(new_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (new_fd == -1) {
        perror("open");
        free(data);
        return -1;
    }

    if (write(new_fd, start, end - start) != end - start) {
        perror("write");
        close(new_fd);
        free(data);
        return -1;
    }

    // Close the new file
    close(new_fd);

    // Free the buffer
    free(data);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Recover the data from the file
    if (recover_data(argv[1]) == -1) {
        return -1;
    }

    return 0;
}