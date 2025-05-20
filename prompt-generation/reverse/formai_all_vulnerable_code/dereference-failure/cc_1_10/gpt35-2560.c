//FormAI DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#define BUFFER_SIZE 1024

void encrypt(char *filename);
void decrypt(char *filename);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <option> <filename>\n", argv[0]);
        printf("Option:\n");
        printf("  e: encrypt file\n");
        printf("  d: decrypt file\n");
        exit(1);
    }

    if (strcmp(argv[1], "e") == 0) {
        encrypt(argv[2]);
    } else if (strcmp(argv[1], "d") == 0) {
        decrypt(argv[2]);
    } else {
        printf("Invalid option!\n");
        exit(1);
    }

    return 0;
}

void encrypt(char *filename) {
    int fd, out_fd, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    struct stat stat_buf;

    // Get file size
    if (stat(filename, &stat_buf) == -1) {
        perror("stat");
        exit(1);
    }
    off_t filesize = stat_buf.st_size;

    // Generate key
    char key[8];
    int i;
    srand(12345);
    for (i = 0; i < 8; i++) {
        key[i] = rand() % 255;
    }

    // Write key to encrypted file
    out_fd = open(strcat(filename, ".enc"), O_WRONLY|O_CREAT|O_TRUNC, 0666);
    if (out_fd == -1) {
        perror("open");
        exit(1);
    }
    bytes_written = write(out_fd, key, 8);
    if (bytes_written == -1) {
        perror("write");
        exit(1);
    }

    // Encrypt file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ key[i%8];
        }
        bytes_written = write(out_fd, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("write");
            exit(1);
        }
    }
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }

    printf("File %s encrypted and saved as %s.\n", filename, strcat(filename, ".enc"));

    // Cleanup
    close(fd);
    close(out_fd);

    // Remove original file
    if (unlink(filename) == -1) {
        perror("unlink");
        exit(1);
    }
}

void decrypt(char *filename) {
    int fd, out_fd, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    struct stat stat_buf;

    // Get file size
    if (stat(filename, &stat_buf) == -1) {
        perror("stat");
        exit(1);
    }
    off_t filesize = stat_buf.st_size;

    // Read key from encrypted file
    char key[8];
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    bytes_read = read(fd, key, 8);
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }
    if (bytes_read != 8) {
        printf("Invalid file format!\n");
        exit(1);
    }

    // Decrypt file
    out_fd = open(strtok(filename, ".enc"), O_WRONLY|O_CREAT|O_TRUNC, 0666);
    if (out_fd == -1) {
        perror("open");
        exit(1);
    }
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ key[i%8];
        }
        bytes_written = write(out_fd, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("write");
            exit(1);
        }
    }
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }

    printf("File %s decrypted and saved as %s.\n", filename, strtok(filename, ".enc"));

    // Cleanup
    close(fd);
    close(out_fd);

    // Remove original file
    if (unlink(filename) == -1) {
        perror("unlink");
        exit(1);
    }
}