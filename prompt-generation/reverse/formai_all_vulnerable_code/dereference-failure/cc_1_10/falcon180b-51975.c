//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 512

void print_usage(char *progname) {
    printf("Usage: %s <device_name> <output_file>\n", progname);
}

int main(int argc, char *argv[]) {
    char *device_name = argv[1];
    char *output_file = argv[2];
    int fd, bytes_read;
    char buffer[BUFFER_SIZE];

    // Check if the device exists
    struct stat st;
    if (stat(device_name, &st) == -1) {
        printf("Error: Device %s does not exist.\n", device_name);
        return 1;
    }

    // Open the device in read-only mode
    fd = open(device_name, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open device %s.\n", device_name);
        return 1;
    }

    // Create the output file
    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: Could not create output file %s.\n", output_file);
        return 1;
    }

    // Read from the device and write to the output file
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytes_read, output_fp);
    }

    // Close the device and output file
    close(fd);
    fclose(output_fp);

    printf("Data recovery successful! Check output file %s.\n", output_file);

    return 0;
}