//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define BACKUP_DIR "backup/"
#define MAX_LEN 1024

int create_backup(const char *file_path) {
    int file_fd, backup_fd;
    char backup_file_name[MAX_LEN];
    struct stat file_stat;
    time_t current_time;

    if (stat(file_path, &file_stat) < 0) {
        perror("Error statting file");
        return 1;
    }

    current_time = time(NULL);

    snprintf(backup_file_name, sizeof(backup_file_name), "%s%s_%ld_%s.bak", BACKUP_DIR, basename(file_path), (long)current_time, strrchr(file_path, '.'));

    if ((file_fd = open(file_path, O_RDONLY)) < 0 || (backup_fd = open(backup_file_name, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error opening files");
        close(file_fd);
        return 1;
    }

    ssize_t read_bytes;
    char buffer[4096];

    while ((read_bytes = read(file_fd, buffer, sizeof(buffer))) > 0) {
        if (write(backup_fd, buffer, read_bytes) != read_bytes) {
            perror("Error writing to backup file");
            close(file_fd);
            close(backup_fd);
            unlink(backup_file_name);
            return 1;
        }
    }

    close(file_fd);
    close(backup_fd);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    if (create_backup(argv[1])) {
        perror("Error creating backup");
        return 1;
    }

    printf("Backup created successfully: %s\n", argv[1]);

    return 0;
}