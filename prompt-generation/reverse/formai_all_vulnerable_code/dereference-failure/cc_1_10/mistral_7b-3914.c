//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PATH 1024
#define BACKUP_DIR "backup"
#define FILE_EXT ".bak"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    char orig_file[MAX_PATH], backup_file[MAX_PATH];
    strcpy(orig_file, argv[1]);
    strcpy(backup_file, orig_file);

    // Get the file extension
    int len = strlen(orig_file);
    int ext_len = strlen(FILE_EXT);
    int i = len - 1;

    while (i >= 0 && orig_file[i] != '.') {
        i--;
    }

    if (i < 0) {
        strcat(orig_file, FILE_EXT);
    } else {
        strncpy(backup_file + i, FILE_EXT, ext_len);
    }

    // Create backup directory if not exists
    mkdir(BACKUP_DIR, 0755);

    // Create a new backup file
    int fd = open(backup_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Error creating backup file");
        return 1;
    }

    // Copy the file contents to the backup file
    ssize_t bytes_read;
    int src_fd = open(orig_file, O_RDONLY);

    if (src_fd < 0) {
        perror("Error opening original file");
        close(fd);
        return 1;
    }

    char buffer[4096];

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(fd, buffer, bytes_read);
    }

    close(src_fd);
    close(fd);

    printf("File '%s' backed up to '%s'\n", orig_file, backup_file);

    return 0;
}

void usage(char *argv)
{
    printf("Usage: %s <file_to_backup>\n", argv[0]);
}