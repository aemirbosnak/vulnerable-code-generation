//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 1024 * 1024
#define BACKUP_DIR "./backup/"
#define BACKUP_EXT ".bkp"

struct FileMetadata {
    char name[100];
    int size;
    time_t last_modified;
};

void create_backup(const char *file_path) {
    int fd, bkfd;
    char bkp_file_path[150];
    struct stat file_stat;
    struct FileMetadata file_metadata;

    if (stat(file_path, &file_stat) < 0) {
        perror("Error getting file stats");
        return;
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("File '%s' is too large to be backed up.\n", file_path);
        return;
    }

    strcpy(file_metadata.name, file_path);
    strcpy(file_metadata.name + strlen(file_metadata.name), BACKUP_EXT);
    file_metadata.size = file_stat.st_size;
    file_metadata.last_modified = file_stat.st_mtime;

    strcpy(bkp_file_path, BACKUP_DIR);
    strcat(bkp_file_path, file_metadata.name);

    mkdir(BACKUP_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        return;
    }

    bkfd = open(bkp_file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (bkfd < 0) {
        perror("Error opening backup file for writing");
        close(fd);
        return;
    }

    ssize_t bytes_read;
    char buffer[1024];

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(bkfd, buffer, bytes_read);
    }

    close(fd);
    close(bkfd);

    printf("File '%s' backed up to '%s'\n", file_path, bkp_file_path);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    create_backup(argv[1]);
    return 0;
}