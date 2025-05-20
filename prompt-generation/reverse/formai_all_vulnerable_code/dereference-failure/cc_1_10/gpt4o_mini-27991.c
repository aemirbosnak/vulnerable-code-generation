//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 100
#define CRYPT_KEY 137  // Simple encryption key (XOR)

void encrypt(char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= CRYPT_KEY;  // XOR encryption
    }
}

void decrypt(char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= CRYPT_KEY;  // XOR decryption
    }
}

void backup_file(const char *source, const char *destination) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    if ((src_fd = open(source, O_RDONLY)) < 0) {
        perror("Source file open failed");
        return;
    }

    if ((dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        perror("Destination file open failed");
        close(src_fd);
        return;
    }

    while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        encrypt(buffer, bytesRead);  // Encrypt data before writing
        write(dest_fd, buffer, bytesRead);
    }

    close(src_fd);
    close(dest_fd);
}

void restore_file(const char *source, const char *destination) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    if ((src_fd = open(source, O_RDONLY)) < 0) {
        perror("Source file open failed");
        return;
    }

    if ((dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        perror("Destination file open failed");
        close(src_fd);
        return;
    }

    while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        decrypt(buffer, bytesRead);  // Decrypt data before writing
        write(dest_fd, buffer, bytesRead);
    }

    close(src_fd);
    close(dest_fd);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <backup|restore> <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "backup") == 0) {
        backup_file(argv[2], argv[3]);
        printf("Backup completed: %s -> %s\n", argv[2], argv[3]);
    } else if (strcmp(argv[1], "restore") == 0) {
        restore_file(argv[2], argv[3]);
        printf("Restore completed: %s -> %s\n", argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid action. Use 'backup' or 'restore'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}