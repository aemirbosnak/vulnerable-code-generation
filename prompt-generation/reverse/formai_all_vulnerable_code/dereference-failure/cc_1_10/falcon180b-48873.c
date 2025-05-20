//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <device> <output_file>\n", argv[0]);
        return 1;
    }

    int device_fd = open(argv[1], O_RDONLY);
    if (device_fd == -1) {
        printf("Error opening device: %s\n", strerror(errno));
        return 1;
    }

    struct stat device_stat;
    if (fstat(device_fd, &device_stat) == -1) {
        printf("Error getting device information: %s\n", strerror(errno));
        close(device_fd);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", strerror(errno));
        close(device_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = 0;
    int total_bytes_read = 0;
    while ((bytes_read = read(device_fd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, bytes_read, 1, output_file);
        total_bytes_read += bytes_read;
    }

    if (bytes_read == -1) {
        printf("Error reading from device: %s\n", strerror(errno));
        fclose(output_file);
        close(device_fd);
        return 1;
    }

    printf("Successfully recovered %d bytes from device and saved to %s\n", total_bytes_read, argv[2]);

    fclose(output_file);
    close(device_fd);

    return 0;
}