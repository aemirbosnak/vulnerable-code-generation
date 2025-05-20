//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 32

static unsigned char key[KEY_LEN];

static void init_key(const char *password) {
    unsigned int i, j;
    for (i = 0, j = 0; i < KEY_LEN; i++, j = (j + 1) % strlen(password)) {
        key[i] = password[j];
    }
}

static void encrypt(unsigned char *data, size_t len) {
    unsigned int i;
    for (i = 0; i < len; i++) {
        data[i] ^= key[i % KEY_LEN];
    }
}

static void decrypt(unsigned char *data, size_t len) {
    unsigned int i;
    for (i = 0; i < len; i++) {
        data[i] ^= key[i % KEY_LEN];
    }
}

int main(int argc, char *argv[]) {
    unsigned char *data;
    size_t len;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s password data\n", argv[0]);
        return EXIT_FAILURE;
    }

    init_key(argv[1]);

    len = strlen(argv[2]);
    data = malloc(len);
    if (!data) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    memcpy(data, argv[2], len);

    encrypt(data, len);

    printf("Encrypted data: %s\n", data);

    decrypt(data, len);

    printf("Decrypted data: %s\n", data);

    free(data);

    return EXIT_SUCCESS;
}