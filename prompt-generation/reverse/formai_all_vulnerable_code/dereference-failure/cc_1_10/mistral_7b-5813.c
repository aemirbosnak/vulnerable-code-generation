//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10

void backup_file(const char *file_name) {
    int orig_fd, bak_fd;
    off_t orig_size, bak_size;
    char orig_file[MAX_FILE_SIZE];
    char bak_file[MAX_FILE_SIZE];

    // Open the original file for reading
    orig_fd = open(file_name, O_RDONLY);
    if (orig_fd < 0) {
        perror("Error opening original file");
        return;
    }

    // Get the size of the original file
    fstat(orig_fd, &orig_size);

    // Create the backup file name
    strcpy(bak_file, file_name);
    strcat(bak_file, ".bak");

    // Open the backup file for writing
    bak_fd = open(bak_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (bak_fd < 0) {
        perror("Error opening backup file");
        close(orig_fd);
        return;
    }

    // Read the data from the original file and write it to the backup file
    while (read(orig_fd, orig_file, sizeof(orig_file)) > 0) {
        write(bak_fd, orig_file, sizeof(orig_file));
    }

    // Close the file descriptors
    close(orig_fd);
    close(bak_fd);

    printf("File '%s' backed up to '%s'\n", file_name, bak_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}