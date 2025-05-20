//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define ENCRYPTION_KEY "SuperSecret"

typedef struct {
    char *filename;
    char *encrypted_filename;
    int file_size;
    unsigned char *file_data;
    unsigned char *encrypted_file_data;
} file_info;

int encrypt_file(file_info *file) {
    int i;
    unsigned char *key = (unsigned char *)ENCRYPTION_KEY;
    int key_len = strlen(ENCRYPTION_KEY);

    // Allocate memory for encrypted data.
    file->encrypted_file_data = malloc(file->file_size);
    if (file->encrypted_file_data == NULL) {
        return -1;
    }

    // Encrypt file data.
    for (i = 0; i < file->file_size; i++) {
        file->encrypted_file_data[i] = file->file_data[i] ^ key[i % key_len];
    }

    return 0;
}

int write_encrypted_file(file_info *file) {
    int fd;

    // Open encrypted file for writing.
    fd = open(file->encrypted_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        return -1;
    }

    // Write encrypted data to file.
    if (write(fd, file->encrypted_file_data, file->file_size) != file->file_size) {
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}

int main(int argc, char *argv[]) {
    int i;
    file_info *files;

    // Check command line arguments.
    if (argc < 3) {
        printf("Usage: %s <input files> <output directory>\n", argv[0]);
        return 1;
    }

    // Allocate memory for file info.
    files = malloc(sizeof(file_info) * (argc - 2));
    if (files == NULL) {
        return -1;
    }

    // Parse command line arguments.
    for (i = 1; i < argc - 1; i++) {
        files[i - 1].filename = argv[i];
        files[i - 1].encrypted_filename = malloc(strlen(argv[argc - 1]) + strlen(argv[i]) + 1);
        if (files[i - 1].encrypted_filename == NULL) {
            free(files);
            return -1;
        }
        sprintf(files[i - 1].encrypted_filename, "%s/%s", argv[argc - 1], argv[i]);
    }

    // Encrypt files.
    for (i = 0; i < argc - 2; i++) {
        // Open input file for reading.
        files[i].file_data = malloc(files[i].file_size);
        if (files[i].file_data == NULL) {
            free(files);
            return -1;
        }
        int fd = open(files[i].filename, O_RDONLY);
        if (fd == -1) {
            free(files);
            return -1;
        }
        files[i].file_size = read(fd, files[i].file_data, files[i].file_size);
        close(fd);

        // Encrypt file data.
        if (encrypt_file(&files[i]) != 0) {
            free(files);
            return -1;
        }

        // Write encrypted file data to file.
        if (write_encrypted_file(&files[i]) != 0) {
            free(files);
            return -1;
        }
    }

    // Free allocated memory.
    for (i = 0; i < argc - 2; i++) {
        free(files[i].encrypted_filename);
        free(files[i].file_data);
        free(files[i].encrypted_file_data);
    }
    free(files);

    return 0;
}