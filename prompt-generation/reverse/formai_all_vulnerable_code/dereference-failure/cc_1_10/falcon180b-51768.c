//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_path> <output_file>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    char *output_file = argv[2];

    int fd_in = open(file_path, O_RDONLY);
    if (fd_in == -1) {
        printf("Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    struct stat stat_buf;
    if (fstat(fd_in, &stat_buf) == -1) {
        printf("Error getting file size: %s\n", strerror(errno));
        return 1;
    }

    int file_size = stat_buf.st_size;
    printf("File size: %d bytes\n", file_size);

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int fd_out = open(output_file, O_CREAT | O_WRONLY, 0644);
    if (fd_out == -1) {
        printf("Error opening output file: %s\n", strerror(errno));
        return 1;
    }

    int bytes_read = 0;
    while ((bytes_read = read(fd_in, buffer, BUFFER_SIZE))!= 0) {
        if (bytes_read == -1) {
            printf("Error reading input file: %s\n", strerror(errno));
            return 1;
        }

        int bytes_written = write(fd_out, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to output file: %s\n", strerror(errno));
            return 1;
        }

        bytes_read = 0;
    }

    free(buffer);
    close(fd_in);
    close(fd_out);

    printf("File recovery completed successfully.\n");

    return 0;
}