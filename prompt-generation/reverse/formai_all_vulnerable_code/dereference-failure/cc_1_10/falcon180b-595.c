//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define FILE_NAME_LENGTH 256
#define DATA_FILE_EXTENSION ".dat"

struct file_header {
    char magic_number[4];
    int file_size;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *data_file_name = malloc(FILE_NAME_LENGTH);
    strcpy(data_file_name, file_name);
    strcat(data_file_name, DATA_FILE_EXTENSION);

    int data_file_fd = open(data_file_name, O_RDONLY);
    if (data_file_fd == -1) {
        printf("Error opening data file: %s\n", strerror(errno));
        return 1;
    }

    struct file_header header;
    int bytes_read = read(data_file_fd, &header, sizeof(header));
    if (bytes_read!= sizeof(header)) {
        printf("Error reading header from data file\n");
        return 1;
    }

    if (strcmp(header.magic_number, "DATA")!= 0) {
        printf("Invalid data file\n");
        return 1;
    }

    int file_size = header.file_size;
    char *data = malloc(file_size);

    int bytes_written = 0;
    while (bytes_written < file_size) {
        int bytes_to_read = BUFFER_SIZE;
        if (bytes_to_read > file_size - bytes_written) {
            bytes_to_read = file_size - bytes_written;
        }

        int bytes_read_this_time = read(data_file_fd, data + bytes_written, bytes_to_read);
        if (bytes_read_this_time == -1) {
            printf("Error reading data from data file\n");
            return 1;
        }
        bytes_written += bytes_read_this_time;
    }

    close(data_file_fd);

    printf("Recovered file:\n");
    printf("%s", data);

    return 0;
}