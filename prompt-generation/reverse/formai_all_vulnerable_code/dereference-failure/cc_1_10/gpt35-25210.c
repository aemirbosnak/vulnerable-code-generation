//FormAI DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 4096 

void async_data_recovery(const char *data_file, const char *output_file) {
    int fd_data, fd_out, flags_data, flags_out;
    mode_t mode;

    // Open the data file in read-only non-blocking mode
    flags_data = O_RDONLY | O_NONBLOCK;
    fd_data = open(data_file, flags_data);
    if (fd_data == -1) {
        // Error opening the data file
        fprintf(stderr, "Error opening data file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Open the output file in write-only non-blocking mode
    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    flags_out = O_WRONLY | O_CREAT | O_TRUNC | O_NONBLOCK;
    fd_out = open(output_file, flags_out, mode);
    if (fd_out == -1) {
        // Error opening the output file
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Allocate buffer for reading the data
    char *buf = malloc(BUF_SIZE * sizeof(char));
    if (buf == NULL) {
        // Error allocating buffer
        fprintf(stderr, "Error allocating buffer: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Read data from the data file and write to the output file
    ssize_t num_read, num_written;
    do {
        // Read data from the data file
        num_read = read(fd_data, buf, BUF_SIZE);
        if (num_read == -1) {
            // Error reading data file
            fprintf(stderr, "Error reading data file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Write data to the output file
        num_written = write(fd_out, buf, num_read);
        if (num_written == -1) {
            // Error writing to output file
            fprintf(stderr, "Error writing to output file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Check if all data has been written to the output file
        if (num_written != num_read) {
            fprintf(stderr, "Error writing all data to output file\n");
            exit(EXIT_FAILURE);
        }

        // Sleep for 1 second to give other processes a chance to access the file
        sleep(1);

    } while (num_read > 0);

    // Free buffer
    free(buf);

    // Close both files
    if (close(fd_data) == -1) {
        // Error closing data file
        fprintf(stderr, "Error closing data file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (close(fd_out) == -1) {
        // Error closing output file
        fprintf(stderr, "Error closing output file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Data recovery complete
    printf("Data recovery complete.\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        // Incorrect number of arguments
        fprintf(stderr, "Usage: %s [data_file] [output_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    async_data_recovery(argv[1], argv[2]);

    return EXIT_SUCCESS;
}