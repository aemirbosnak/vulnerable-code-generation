//FormAI DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 4096

struct async_data {
    int infile;
    int outfile;
    EVP_CIPHER_CTX *ctx;
};

void* encrypt_file_async(void* arg) {
    struct async_data* data = (struct async_data*) arg;

    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    while ((bytes_read = read(data->infile, buffer, BUFFER_SIZE)) > 0) {
        if (EVP_EncryptUpdate(data->ctx, buffer, &bytes_written, buffer, bytes_read) != 1) {
            perror("Encrypt update failed");
            EVP_CIPHER_CTX_free(data->ctx);
            free(data);
            return NULL;
        }

        if (write(data->outfile, buffer, bytes_written) != bytes_written) {
            perror("Write to output file failed");
            EVP_CIPHER_CTX_free(data->ctx);
            free(data);
            return NULL;
        }
    }

    if (bytes_read < 0) {
        perror("Read from input file failed");
        EVP_CIPHER_CTX_free(data->ctx);
        free(data);
        return NULL;
    }

    if (EVP_EncryptFinal_ex(data->ctx, buffer, &bytes_written) != 1) {
        perror("Encrypt final failed");
        EVP_CIPHER_CTX_free(data->ctx);
        free(data);
        return NULL;
    }

    if (write(data->outfile, buffer, bytes_written) != bytes_written) {
        perror("Write final block to output file failed");
        EVP_CIPHER_CTX_free(data->ctx);
        free(data);
        return NULL;
    }

    EVP_CIPHER_CTX_free(data->ctx);
    free(data);
    return NULL;
}

int encrypt_file_async_wrapper(const char* infile_path, const char* outfile_path, const char* password) {
    int infd, outfd;
    struct stat statbuf;
    pthread_t thread;
    int rc;

    if ((infd = open(infile_path, O_RDONLY)) < 0) {
        perror("Open input file failed");
        return errno;
    }

    if (fstat(infd, &statbuf) < 0) {
        perror("Get input file size failed");
        return errno;
    }

    if ((outfd = open(outfile_path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR)) < 0) {
        perror("Open output file failed");
        return errno;
    }

    // Initialize encryption context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_set_padding(ctx, 0); // Disable padding (output is multiple of 16 bytes)

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char*) password, NULL) != 1) {
        perror("Encrypt init failed");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Create async data structure and thread
    struct async_data* data = (struct async_data*) malloc(sizeof(struct async_data));
    data->infile = infd;
    data->outfile = outfd;
    data->ctx = ctx;

    if ((rc = pthread_create(&thread, NULL, encrypt_file_async, data))) {
        perror("Thread creation failed");
        close(infd);
        close(outfd);
        EVP_CIPHER_CTX_free(ctx);
        free(data);
        return rc;
    }

    pthread_detach(thread);
    return 0;
}

int main() {
    const char* infile_path = "/path/to/file";
    const char* outfile_path = "/path/to/encrypted/file";
    const char* password = "my_password";

    if (encrypt_file_async_wrapper(infile_path, outfile_path, password) != 0) {
        printf("Encryption failed\n");
    } else {
        printf("Encryption successful\n");
    }

    return 0;
}