//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define BACKUP_DIR "/backup"

void error_handling(char *message);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char file_path[256];
    strcpy(file_path, argv[1]);

    // Create backup directory if it doesn't exist
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        if (mkdir(BACKUP_DIR, 0777) == -1) {
            error_handling("Failed to create backup directory");
        }
    }

    char backup_path[256];
    sprintf(backup_path, "%s/%s", BACKUP_DIR, basename(file_path));

    // Backup file to backup directory
    int backup_fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (backup_fd == -1) {
        error_handling("Failed to open backup file");
    }

    int file_fd = open(file_path, O_RDONLY);
    if (file_fd == -1) {
        error_handling("Failed to open file");
    }

    char buffer[BUFFER_SIZE];
    while ((read(file_fd, buffer, BUFFER_SIZE)) > 0) {
        write(backup_fd, buffer, strlen(buffer));
    }

    close(file_fd);
    close(backup_fd);

    printf("Backup completed successfully\n");

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}