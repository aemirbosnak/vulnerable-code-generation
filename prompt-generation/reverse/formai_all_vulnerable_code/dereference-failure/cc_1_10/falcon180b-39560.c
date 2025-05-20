//Falcon-180B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024


int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./program <file_path> <operation>\n");
        return 1;
    }

    char *file_path = argv[1];
    char *operation = argv[2];

    int file_desc = open(file_path, O_RDWR);
    if (file_desc == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (strcmp(operation, "write") == 0) {
        char buffer[BUFFER_SIZE];
        printf("Enter data to write: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        size_t bytes_written = write(file_desc, buffer, strlen(buffer));
        if (bytes_written == -1) {
            printf("Error: %s\n", strerror(errno));
        } else {
            printf("Bytes written: %zu\n", bytes_written);
        }
    } else if (strcmp(operation, "read") == 0) {
        char buffer[BUFFER_SIZE];
        size_t bytes_read = read(file_desc, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            printf("Error: %s\n", strerror(errno));
        } else {
            buffer[bytes_read] = '\0';
            printf("Data read: %s\n", buffer);
        }
    } else {
        printf("Invalid operation\n");
    }

    close(file_desc);
    return 0;
}