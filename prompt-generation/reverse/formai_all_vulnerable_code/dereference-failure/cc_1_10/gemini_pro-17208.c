//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define MAX_KEY_LEN 128

typedef struct {
    char *key;
    size_t key_len;
    char *iv;
    size_t iv_len;
} cipher_params;

cipher_params *cipher_params_new(const char *key, size_t key_len,
                                const char *iv, size_t iv_len)
{
    cipher_params *params = malloc(sizeof(cipher_params));
    if (!params)
        return NULL;

    params->key = malloc(key_len);
    if (!params->key) {
        free(params);
        return NULL;
    }
    memcpy(params->key, key, key_len);
    params->key_len = key_len;

    params->iv = malloc(iv_len);
    if (!params->iv) {
        free(params->key);
        free(params);
        return NULL;
    }
    memcpy(params->iv, iv, iv_len);
    params->iv_len = iv_len;

    return params;
}

void cipher_params_free(cipher_params *params)
{
    if (!params)
        return;

    free(params->key);
    free(params->iv);
    free(params);
}

int encrypt_file(const char *input_file, const char *output_file,
                 cipher_params *params)
{
    int fd_in, fd_out;
    struct stat st;
    char *data;
    int ret;

    fd_in = open(input_file, O_RDONLY);
    if (fd_in < 0)
        return -1;

    fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd_out < 0) {
        close(fd_in);
        return -1;
    }

    if (fstat(fd_in, &st) < 0) {
        close(fd_in);
        close(fd_out);
        return -1;
    }

    data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd_in, 0);
    if (data == MAP_FAILED) {
        close(fd_in);
        close(fd_out);
        return -1;
    }

    // Encrypt the data here
    // ...

    ret = write(fd_out, data, st.st_size);
    if (ret < 0) {
        munmap(data, st.st_size);
        close(fd_in);
        close(fd_out);
        return -1;
    }

    munmap(data, st.st_size);
    close(fd_in);
    close(fd_out);

    return 0;
}

int decrypt_file(const char *input_file, const char *output_file,
                 cipher_params *params)
{
    int fd_in, fd_out;
    struct stat st;
    char *data;
    int ret;

    fd_in = open(input_file, O_RDONLY);
    if (fd_in < 0)
        return -1;

    fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd_out < 0) {
        close(fd_in);
        return -1;
    }

    if (fstat(fd_in, &st) < 0) {
        close(fd_in);
        close(fd_out);
        return -1;
    }

    data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd_in, 0);
    if (data == MAP_FAILED) {
        close(fd_in);
        close(fd_out);
        return -1;
    }

    // Decrypt the data here
    // ...

    ret = write(fd_out, data, st.st_size);
    if (ret < 0) {
        munmap(data, st.st_size);
        close(fd_in);
        close(fd_out);
        return -1;
    }

    munmap(data, st.st_size);
    close(fd_in);
    close(fd_out);

    return 0;
}

int main(int argc, char **argv)
{
    int ret;
    cipher_params *params;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key> <iv>\n",
                argv[0]);
        return 1;
    }

    params = cipher_params_new(argv[3], strlen(argv[3]), argv[4], strlen(argv[4]));
    if (!params) {
        fprintf(stderr, "Error: Failed to create cipher parameters\n");
        return 1;
    }

    ret = encrypt_file(argv[1], argv[2], params);
    if (ret < 0) {
        fprintf(stderr, "Error: Failed to encrypt file\n");
        cipher_params_free(params);
        return 1;
    }

    ret = decrypt_file(argv[2], "decrypted.txt", params);
    if (ret < 0) {
        fprintf(stderr, "Error: Failed to decrypt file\n");
        cipher_params_free(params);
        return 1;
    }

    cipher_params_free(params);

    return 0;
}