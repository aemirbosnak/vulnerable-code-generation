//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 1024 // 1GB
#define BUFFER_SIZE 1024
#define BACKUP_EXTENSION ".bkp"

void backup_file(const char *file_path) {
    int file_fd, backup_fd;
    char buffer[BUFFER_SIZE];
    struct stat file_stat;
    char *backup_path;

    if (stat(file_path, &file_stat) < 0) {
        perror("Error getting file stats");
        return;
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("File is too large to backup: %s (%llu bytes)\n", file_path, file_stat.st_size);
        return;
    }

    backup_path = malloc(strlen(file_path) + strlen(BACKUP_EXTENSION) + 1);
    strcpy(backup_path, file_path);
    strcat(backup_path, BACKUP_EXTENSION);

    if ((file_fd = open(file_path, O_RDONLY)) < 0) {
        perror("Error opening file for reading");
        free(backup_path);
        return;
    }

    if ((backup_fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error opening backup file for writing");
        close(file_fd);
        free(backup_path);
        return;
    }

    while (read(file_fd, buffer, BUFFER_SIZE) > 0) {
        write(backup_fd, buffer, strlen(buffer));
    }

    close(file_fd);
    close(backup_fd);

    printf("Backup created: %s\n", backup_path);
    free(backup_path);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}