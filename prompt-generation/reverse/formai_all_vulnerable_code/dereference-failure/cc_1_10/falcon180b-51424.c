//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <device> <filename>\n", argv[0]);
        return 1;
    }

    char device[50] = {0};
    strcat(device, "/dev/");
    strcat(device, argv[1]);

    int fd = open(device, O_RDWR);
    if (fd == -1) {
        printf("Error opening device %s\n", device);
        return 1;
    }

    char filename[50] = {0};
    strcat(filename, argv[2]);

    char buffer[BUFFER_SIZE] = {0};
    int file_size = 0;
    int bytes_read = 0;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        file_size += bytes_read;
    }

    if (file_size == 0) {
        printf("No data found on device %s\n", device);
        close(fd);
        return 1;
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error creating file %s\n", filename);
        close(fd);
        return 1;
    }

    rewind(fp);
    fwrite(buffer, file_size, 1, fp);
    fclose(fp);

    printf("Data recovery successful!\n");
    close(fd);
    return 0;
}