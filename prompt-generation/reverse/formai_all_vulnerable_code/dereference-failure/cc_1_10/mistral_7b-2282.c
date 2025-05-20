//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int fd_in, fd_out, i;
    char filename[100], buffer[BUFFER_SIZE], key;
    int length;

    // Check for valid arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <key>\n", argv[0]);
        return 1;
    }

    // Initialize file names and key
    strcpy(filename, argv[1]);
    key = atoi(argv[2]);

    // Open input file for reading
    fd_in = open(filename, O_RDONLY);
    if (fd_in == -1) {
        perror("Error opening input file");
        return 1;
    }

    // Create output file with the same name as input file
    // with .enc extension
    strcat(filename, ".enc");
    fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_out == -1) {
        perror("Error opening output file");
        close(fd_in);
        return 1;
    }

    // Read file content in chunks
    while ((length = read(fd_in, buffer, BUFFER_SIZE)) > 0) {
        for (i = 0; i < length; i++) {
            // Apply Caesar Cipher encryption
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = ((buffer[i] - 'A' + key) % 26) + 'A';
            } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = ((buffer[i] - 'a' + key) % 26) + 'a';
            }
        }

        // Write encrypted data to output file
        write(fd_out, buffer, length);
    }

    // Close input and output files
    close(fd_in);
    close(fd_out);

    printf("File encrypted successfully.\n");
    return 0;
}