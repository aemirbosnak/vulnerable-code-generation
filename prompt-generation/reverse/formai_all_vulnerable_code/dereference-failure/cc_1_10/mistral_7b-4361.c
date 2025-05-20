//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BACKUP_DIR "backup_directory"
#define MAX_FILENAME_LENGTH 100
#define BACKUP_EXTENSION ".bak"

struct file_info {
    char filename[MAX_FILENAME_LENGTH];
    off_t file_size;
};

void create_backup_directory() {
    int dir_fd = open(BACKUP_DIR, O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);

    if (dir_fd < 0) {
        perror("Failed to create backup directory");
        exit(EXIT_FAILURE);
    }

    close(dir_fd);
}

void backup_file(char *filename) {
    int file_fd = open(filename, O_RDONLY);
    int backup_fd = open((strcat(filename, BACKUP_EXTENSION)), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    off_t file_size = lseek(file_fd, 0, SEEK_END);
    char buffer[4096];
    struct file_info file_info;

    strcpy(file_info.filename, filename);
    file_info.file_size = file_size;

    write(backup_fd, &file_info, sizeof(file_info));

    if (file_size > 0) {
        while (file_size > 0) {
            ssize_t bytes_read = read(file_fd, buffer, sizeof(buffer));
            if (bytes_read <= 0) break;

            write(backup_fd, buffer, bytes_read);
            file_size -= bytes_read;
        }
    }

    close(file_fd);
    close(backup_fd);
}

void print_message(char *message) {
    printf("\033[1;31m%s\n", message);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_message("Please provide a file name as an argument.");
        return EXIT_FAILURE;
    }

    create_backup_directory();

    print_message("Backing up file...");
    backup_file(argv[1]);
    print_message("Backup created successfully!");

    return EXIT_SUCCESS;
}