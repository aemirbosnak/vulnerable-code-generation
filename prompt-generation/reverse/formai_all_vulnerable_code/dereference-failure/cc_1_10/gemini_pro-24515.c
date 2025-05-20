//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZ 1024

// Generate a unique file name based on current time.
char *generate_unique_filename(void) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *filename = malloc(256);
    snprintf(filename, 256, "backup-%04d%02d%02d-%02d%02d%02d.txt",
             tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
             tm->tm_hour, tm->tm_min, tm->tm_sec);
    return filename;
}

// Encrypt the file using a simple XOR cipher.
void encrypt_file(const char *filename) {
    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char *output_filename = generate_unique_filename();
    FILE *output = fopen(output_filename, "wb");
    if (output == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFSIZ];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFSIZ, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= 0x42;  // XOR with a random byte.
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);

    free(output_filename);

    printf("Encrypted file: %s\n", filename);
}

// Decrypt the file using the same XOR cipher.
void decrypt_file(const char *filename) {
    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char *output_filename = generate_unique_filename();
    FILE *output = fopen(output_filename, "wb");
    if (output == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFSIZ];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFSIZ, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= 0x42;  // XOR with the same random byte.
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);

    free(output_filename);

    printf("Decrypted file: %s\n", filename);
}

// Delete the file securely by overwriting it with random data.
void delete_file(const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Overwrite the file with random data.
    unsigned char buffer[BUFSIZ];
    for (int i = 0; i < 100; i++) {
        for (size_t j = 0; j < BUFSIZ; j++) {
            buffer[j] = rand() % 256;
        }
        fwrite(buffer, 1, BUFSIZ, f);
    }

    fclose(f);

    // Delete the file.
    if (remove(filename) != 0) {
        perror("remove");
        exit(EXIT_FAILURE);
    }

    printf("Deleted file: %s\n", filename);
}

int main(int argc, char **argv) {
    // Check the arguments.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Backup the file.
    char *filename = argv[1];
    encrypt_file(filename);

    // Delete the original file.
    delete_file(filename);

    return EXIT_SUCCESS;
}