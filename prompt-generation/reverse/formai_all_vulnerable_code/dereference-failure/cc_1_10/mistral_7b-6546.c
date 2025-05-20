//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BACKUP_EXTENSION ".bak"

void backup_file(char *file_name) {
    char backup_file_name[100];
    int fd_original, fd_backup;
    off_t file_size;

    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_EXTENSION);

    fd_original = open(file_name, O_RDWR);
    if (fd_original < 0) {
        perror("Error opening file for backup");
        return;
    }

    fd_backup = open(backup_file_name, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_backup < 0) {
        perror("Error creating backup file");
        close(fd_original);
        return;
    }

    file_size = lseek(fd_original, 0, SEEK_END);
    if (file_size < 0) {
        perror("Error getting file size");
        close(fd_original);
        close(fd_backup);
        return;
    }

    if (lseek(fd_original, 0, SEEK_SET) < 0) {
        perror("Error setting file position to beginning");
        close(fd_original);
        close(fd_backup);
        return;
    }

    if (write(fd_backup, "\0", file_size) < file_size) {
        perror("Error writing file to backup");
        close(fd_original);
        close(fd_backup);
        return;
    }

    if (lseek(fd_original, 0, SEEK_SET) < 0) {
        perror("Error setting file position to beginning");
        close(fd_original);
        close(fd_backup);
        return;
    }

    if (close(fd_original) < 0) {
        perror("Error closing original file");
        close(fd_backup);
        return;
    }

    if (rename(file_name, backup_file_name) < 0) {
        perror("Error renaming original file to backup");
        close(fd_backup);
        return;
    }

    printf("File '%s' backed up to '%s'\n", file_name, backup_file_name);
    close(fd_backup);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}