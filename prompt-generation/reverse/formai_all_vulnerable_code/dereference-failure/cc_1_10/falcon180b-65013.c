//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <output_file>\n", argv[0]);
        return 1;
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    struct stat input_stat;
    if (fstat(input_fd, &input_stat) == -1) {
        printf("Error getting file status: %s\n", strerror(errno));
        return 1;
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        printf("Error creating output file: %s\n", strerror(errno));
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(output_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error writing to output file: %s\n", strerror(errno));
            return 1;
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from input file: %s\n", strerror(errno));
        return 1;
    }

    close(input_fd);
    close(output_fd);

    printf("Recovery complete! Output file created.\n");

    return 0;
}