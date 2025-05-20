//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BACKUP_MAGIC "obituary"
#define BACKUP_EXTENSION ".obit"
#define BUF_SIZE 1024

struct backup_header {
    char magic[8];
    int file_size;
    int backup_version;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *backup_file_name = malloc(strlen(file_name) + strlen(BACKUP_EXTENSION) + 1);
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_EXTENSION);

    int fd_in = open(file_name, O_RDONLY);
    if (fd_in < 0) {
        perror("Error opening input file");
        free(backup_file_name);
        return 1;
    }

    int fd_out = open(backup_file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_out < 0) {
        perror("Error opening output file");
        close(fd_in);
        free(backup_file_name);
        return 1;
    }

    struct stat file_stat;
    if (fstat(fd_in, &file_stat) < 0) {
        perror("Error getting file size");
        close(fd_in);
        close(fd_out);
        free(backup_file_name);
        return 1;
    }

    struct backup_header header;
    header.file_size = file_stat.st_size;
    header.backup_version = 1;
    strcpy(header.magic, BACKUP_MAGIC);

    write(fd_out, &header, sizeof(header));
    char buffer[BUF_SIZE];
    int bytes_read;
    while ((bytes_read = read(fd_in, buffer, BUF_SIZE)) > 0) {
        write(fd_out, buffer, bytes_read);
    }

    close(fd_in);
    close(fd_out);
    free(backup_file_name);

    printf("File '%s' backed up to '%s'\n", file_name, backup_file_name);

    return 0;
}