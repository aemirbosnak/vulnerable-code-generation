//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: asynchronous
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BLOCK_SIZE 16
#define BUF_SIZE 1024

typedef struct {
    unsigned char *key;
    unsigned char *iv;
} cipher_params_t;

void print_hex(const unsigned char *s, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", s[i]);
    }
    printf("\n");
}

int init_params(cipher_params_t *params) {
    params->key = (unsigned char *) malloc(BLOCK_SIZE);
    RAND_bytes(params->key, BLOCK_SIZE);

    params->iv = (unsigned char *) malloc(BLOCK_SIZE);
    RAND_bytes(params->iv, BLOCK_SIZE);

    return 0;
}

int encrypt(int in_fd, int out_fd, cipher_params_t *params) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        perror("Failed to create EVP_CIPHER_CTX");
        return -1;
    }

    if (!EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, params->key, params->iv)) {
        perror("Failed to initialize cipher");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    int out_len;
    unsigned char in_buf[BUF_SIZE];
    unsigned char out_buf[BUF_SIZE + BLOCK_SIZE];

    while (1) {
        // Read data from input file descriptor
        ssize_t bytes_read = read(in_fd, in_buf, BUF_SIZE);
        if (bytes_read == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Failed to read data from input file descriptor");
                EVP_CIPHER_CTX_free(ctx);
                return -1;
            }
        } else if (bytes_read == 0) {
            break;
        }

        // Encrypt the read data
        if (!EVP_EncryptUpdate(ctx, out_buf, &out_len, in_buf, bytes_read)) {
            perror("Failed to encrypt data");
            EVP_CIPHER_CTX_free(ctx);
            return -1;
        }

        // Write the encrypted data to output file descriptor
        ssize_t bytes_written = write(out_fd, out_buf, out_len);
        if (bytes_written == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Failed to write data to output file descriptor");
                EVP_CIPHER_CTX_free(ctx);
                return -1;
            }
        }
    }

    // Finalize the encryption process
    if (!EVP_EncryptFinal_ex(ctx, out_buf, &out_len)) {
        perror("Failed to finalize encryption process");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Write the final encrypted data to output file descriptor
    ssize_t bytes_written = write(out_fd, out_buf, out_len);
    if (bytes_written == -1) {
        if (errno == EINTR) {
            bytes_written = write(out_fd, out_buf, out_len);
        } else {
            perror("Failed to write final encrypted data to output file descriptor");
            EVP_CIPHER_CTX_free(ctx);
            return -1;
        }
    }

    EVP_CIPHER_CTX_free(ctx);
    return 0;
}

int decrypt(int in_fd, int out_fd, cipher_params_t *params) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        perror("Failed to create EVP_CIPHER_CTX");
        return -1;
    }

    if (!EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, params->key, params->iv)) {
        perror("Failed to initialize cipher");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    int out_len;
    unsigned char in_buf[BUF_SIZE + BLOCK_SIZE];
    unsigned char out_buf[BUF_SIZE];

    while (1) {
        // Read data from input file descriptor
        ssize_t bytes_read = read(in_fd, in_buf, BUF_SIZE + BLOCK_SIZE);
        if (bytes_read == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Failed to read data from input file descriptor");
                EVP_CIPHER_CTX_free(ctx);
                return -1;
            }
        } else if (bytes_read == 0) {
            break;
        }

        // Decrypt the read data
        if (!EVP_DecryptUpdate(ctx, out_buf, &out_len, in_buf, bytes_read)) {
            perror("Failed to decrypt data");
            EVP_CIPHER_CTX_free(ctx);
            return -1;
        }

        // Write the decrypted data to output file descriptor
        ssize_t bytes_written = write(out_fd, out_buf, out_len);
        if (bytes_written == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Failed to write data to output file descriptor");
                EVP_CIPHER_CTX_free(ctx);
                return -1;
            }
        }
    }

    // Finalize the decryption process
    if (!EVP_DecryptFinal_ex(ctx, out_buf, &out_len)) {
        perror("Failed to finalize decryption process");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Write the final decrypted data to output file descriptor
    ssize_t bytes_written = write(out_fd, out_buf, out_len);
    if (bytes_written == -1) {
        if (errno == EINTR) {
            bytes_written = write(out_fd, out_buf, out_len);
        } else {
            perror("Failed to write final decrypted data to output file descriptor");
            EVP_CIPHER_CTX_free(ctx);
            return -1;
        }
    }

    EVP_CIPHER_CTX_free(ctx);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s [enc|dec] input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    int in_fd = open(argv[2], O_RDONLY);
    if (in_fd == -1) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    int out_fd = open(argv[3], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if (out_fd == -1) {
        perror("Failed to open output file");
        close(in_fd);
        return EXIT_FAILURE;
    }

    // Generate random encryption parameters
    cipher_params_t params;
    init_params(&params);

    if (strcmp(argv[1], "enc") == 0) {
        // Write iv to output file
        if (write(out_fd, params.iv, BLOCK_SIZE) != BLOCK_SIZE) {
            perror("Failed to write initialization vector to output file");
            close(in_fd);
            close(out_fd);
            return EXIT_FAILURE;
        }

        if (encrypt(in_fd, out_fd, &params) != 0) {
            close(in_fd);
            close(out_fd);
            return EXIT_FAILURE;
        }

        printf("Encryption key: ");
        print_hex(params.key, BLOCK_SIZE);
    } else if (strcmp(argv[1], "dec") == 0) {
        // Read iv from input file
        if (read(in_fd, params.iv, BLOCK_SIZE) != BLOCK_SIZE) {
            perror("Failed to read initialization vector from input file");
            close(in_fd);
            close(out_fd);
            return EXIT_FAILURE;
        }

        if (decrypt(in_fd, out_fd, &params) != 0) {
            close(in_fd);
            close(out_fd);
            return EXIT_FAILURE;
        }

        printf("Decryption key: ");
        print_hex(params.key, BLOCK_SIZE);
    } else {
        fprintf(stderr, "Usage: %s [enc|dec] input_file output_file\n", argv[0]);
        close(in_fd);
        close(out_fd);
        return EXIT_FAILURE;
    }

    close(in_fd);
    close(out_fd);
    return EXIT_SUCCESS;
}