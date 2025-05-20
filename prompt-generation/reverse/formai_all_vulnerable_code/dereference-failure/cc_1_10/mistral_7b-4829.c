//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define FILENAME_MAX 256

void sync_files(char *source_path, char *destination_path) {
    struct stat source_stat, destination_stat;
    int source_fd, destination_fd;
    char buffer[BUFFER_SIZE];
    char source_file[FILENAME_MAX];
    char destination_file[FILENAME_MAX];

    strcpy(source_file, source_path);
    strcpy(destination_file, destination_path);

    if (stat(source_file, &source_stat) < 0) {
        perror("Error reading source file stats.");
        return;
    }

    if (stat(destination_file, &destination_stat) < 0) {
        perror("Error reading destination file stats.");
        return;
    }

    if (S_ISDIR(source_stat.st_mode) || S_ISDIR(destination_stat.st_mode)) {
        printf("Cannot synchronize directories.\n");
        return;
    }

    if (source_stat.st_size != destination_stat.st_size) {
        printf("Files %s and %s are not synchronized.\n", source_file, destination_file);

        source_fd = open(source_file, O_RDONLY);
        if (source_fd < 0) {
            perror("Error opening source file.");
            return;
        }

        destination_fd = open(destination_file, O_WRONLY | O_TRUNC | O_CREAT, source_stat.st_mode);
        if (destination_fd < 0) {
            perror("Error opening destination file.");
            close(source_fd);
            return;
        }

        ssize_t bytes_read;
        while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
            if (write(destination_fd, buffer, bytes_read) != bytes_read) {
                perror("Error writing to destination file.");
                close(source_fd);
                close(destination_fd);
                return;
            }
        }

        close(source_fd);
        close(destination_fd);

        printf("Files %s and %s are now synchronized.\n", source_file, destination_file);
    } else {
        printf("Files %s and %s are already synchronized.\n", source_file, destination_file);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source_path> <destination_path>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}

// End of File