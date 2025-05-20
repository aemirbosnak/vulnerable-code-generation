//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024*1024

int main(int argc, char *argv[]) {
    struct stat file_stat;
    int fd, fd_bak;
    char filename[1024];
    char filename_bak[1024];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    if (stat(argv[1], &file_stat) < 0) {
        perror("Error reading file status");
        return 1;
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("File too large to backup\n");
        return 1;
    }

    fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    strcpy(filename_bak, argv[1]);
    strcat(filename_bak, ".bak");

    fd_bak = open(filename_bak, O_WRONLY | O_CREAT | O_TRUNC, file_stat.st_mode);
    if (fd_bak < 0) {
        perror("Error creating backup file");
        close(fd);
        return 1;
    }

    if (fstat(fd, &file_stat) < 0) {
        perror("Error getting file status for backup");
        close(fd);
        close(fd_bak);
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, MAX_FILE_SIZE)) > 0) {
        if (write(fd_bak, buffer, bytes_read) < 0) {
            perror("Error writing to backup file");
            close(fd);
            close(fd_bak);
            return 1;
        }
    }

    close(fd);
    close(fd_bak);

    printf("File %s backed up to %s\n", argv[1], filename_bak);

    return 0;
}