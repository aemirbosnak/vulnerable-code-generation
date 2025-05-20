//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// Function to read data from a file
void read_data(int fd, char *buffer, int size) {
    int bytes_read = 0;
    while (bytes_read < size) {
        int ret = read(fd, buffer + bytes_read, size - bytes_read);
        if (ret <= 0) {
            printf("Error reading file\n");
            exit(1);
        }
        bytes_read += ret;
    }
}

// Function to write data to a file
void write_data(int fd, char *buffer, int size) {
    int bytes_written = 0;
    while (bytes_written < size) {
        int ret = write(fd, buffer + bytes_written, size - bytes_written);
        if (ret <= 0) {
            printf("Error writing file\n");
            exit(1);
        }
        bytes_written += ret;
    }
}

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == -1) {
        return 0;
    }
    return 1;
}

// Function to recover deleted data from a file
void recover_data(int fd, int size) {
    char buffer[size];
    read_data(fd, buffer, size);

    // Search for deleted data
    int i = 0;
    while (i < size) {
        if (buffer[i] == 0) {
            // Deleted data found
            printf("Deleted data found at offset %d\n", i);

            // Recover deleted data
            int j = i + 1;
            while (buffer[j] == 0) {
                j++;
            }
            int deleted_size = j - i - 1;
            printf("Deleted data size: %d\n", deleted_size);

            char deleted_buffer[deleted_size];
            memset(deleted_buffer, 0, deleted_size);
            read_data(fd, deleted_buffer, deleted_size);

            printf("Recovered deleted data:\n");
            for (int k = 0; k < deleted_size; k++) {
                printf("%c", deleted_buffer[k]);
            }
            printf("\n");

            // Overwrite deleted data with recovered data
            i += deleted_size;
            j += deleted_size;
            while (j < size) {
                buffer[i] = buffer[j];
                i++;
                j++;
            }
        } else {
            i++;
        }
    }

    // Write recovered data to file
    write_data(fd, buffer, size);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <size>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    int size = atoi(argv[2]);
    if (size <= 0) {
        printf("Invalid file size\n");
        exit(1);
    }

    if (!file_exists(argv[1])) {
        printf("File does not exist\n");
        exit(1);
    }

    recover_data(fd, size);

    close(fd);
    return 0;
}