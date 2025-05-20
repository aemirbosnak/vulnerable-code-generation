//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void print_error(const char* message, int err) {
    printf("Error: %s (errno: %d)\n", message, err);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <device-name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* device_name = argv[1];
    int fd = open(device_name, O_RDWR);
    if (fd < 0) {
        print_error("Failed to open device", errno);
        exit(EXIT_FAILURE);
    }

    char buffer[512];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        print_error("Failed to read device", errno);
        exit(EXIT_FAILURE);
    }

    char* filename = strtok(buffer, "\n");
    while (filename) {
        int file_size = strtol(filename, NULL, 10);
        if (file_size > 0) {
            char* new_filename = malloc(sizeof(char) * (file_size + 1));
            strncpy(new_filename, filename, file_size);
            new_filename[file_size] = '\0';
            int new_fd = open(new_filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (new_fd < 0) {
                print_error("Failed to create new file", errno);
                exit(EXIT_FAILURE);
            }
            int bytes_written = write(new_fd, buffer + strlen(filename), bytes_read - strlen(filename));
            if (bytes_written < 0) {
                print_error("Failed to write to new file", errno);
                exit(EXIT_FAILURE);
            }
            printf("Recovered file: %s\n", new_filename);
            free(new_filename);
        }
        filename = strtok(NULL, "\n");
    }

    close(fd);
    return EXIT_SUCCESS;
}