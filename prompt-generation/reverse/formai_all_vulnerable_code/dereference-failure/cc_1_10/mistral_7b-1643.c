//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BACKUP_DIR "backup"
#define FILE_EXT ".bak"
#define BUF_SIZE 4096
#define MAX_PATH 256

int main(int argc, char **argv) {
    int fd_src, fd_dst, i, ret;
    char src_path[MAX_PATH], dst_path[MAX_PATH], buf[BUF_SIZE];
    struct stat st_src;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    strcpy(src_path, argv[1]);
    strcat(src_path, FILE_EXT);

    // Create backup directory if not exists
    mkdir(BACKUP_DIR, 0755);

    // Open source file for reading
    fd_src = open(src_path, O_RDONLY);
    if (fd_src < 0) {
        perror("Error opening source file");
        return 1;
    }

    // Get file size and seek to the end of the file
    fstat(fd_src, &st_src);
    lseek(fd_src, st_src.st_size, SEEK_SET);

    // Generate destination file name
    snprintf(dst_path, MAX_PATH, "%s/%s%s", BACKUP_DIR, src_path, FILE_EXT);

    // Open backup file for writing
    fd_dst = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_dst < 0) {
        perror("Error opening backup file");
        close(fd_src);
        return 1;
    }

    // Read and write data from source to backup file
    while ((ret = read(fd_src, buf, BUF_SIZE)) > 0) {
        write(fd_dst, buf, ret);
    }

    // Close files and check for errors
    close(fd_src);
    close(fd_dst);

    printf("File '%s' backed up to '%s'\n", src_path, dst_path);

    return 0;
}