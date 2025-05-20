//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        exit(1);
    }

    char source_file[100];
    char destination_file[100];

    strcpy(source_file, argv[1]);
    strcpy(destination_file, argv[2]);

    struct stat source_stat;
    struct stat destination_stat;

    stat(source_file, &source_stat);
    stat(destination_file, &destination_stat);

    if (S_ISDIR(source_stat.st_mode) || S_ISDIR(destination_stat.st_mode)) {
        fprintf(stderr, "%s is a directory, cannot backup\n", source_file);
        exit(1);
    }

    if (stat(destination_file, &destination_stat) == -1) {
        if (mkdir(destination_file, 0777) == -1) {
            fprintf(stderr, "Error creating directory: %s\n", destination_file);
            exit(1);
        }
    }

    int source_fd = open(source_file, O_RDONLY);
    int destination_fd = open(destination_file, O_WRONLY | O_CREAT, 0644);

    while (1) {
        ssize_t bytes_read = read(source_fd, NULL, 1);
        if (bytes_read == -1) {
            perror("read");
            break;
        }

        ssize_t bytes_written = write(destination_fd, NULL, bytes_read);
        if (bytes_written == -1) {
            perror("write");
            break;
        }
    }

    close(source_fd);
    close(destination_fd);

    return 0;
}