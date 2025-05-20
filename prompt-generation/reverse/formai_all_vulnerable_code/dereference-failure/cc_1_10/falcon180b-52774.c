//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* Function to synchronize files */
void synchronize_files(char* source_file, char* destination_file) {
    int source_fd, destination_fd;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (destination_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        exit(1);
    }

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write(destination_fd, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        printf("Error reading from source file: %s\n", strerror(errno));
        close(source_fd);
        close(destination_fd);
        exit(1);
    }

    close(source_fd);
    close(destination_fd);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}