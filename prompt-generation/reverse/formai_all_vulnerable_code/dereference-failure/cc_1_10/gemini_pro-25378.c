//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: futuristic
// **Neon Cipher Cypher**

// Mission: Conceal sensitive data from prying eyes with Neon, an advanced file encryption utility.

// **Command Center:**

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// **[TRANSMISSION INITIATED]**

// **Encryption Protocol**:

typedef struct _NeonCipher {
    char *key;
    size_t keyLen;
    uint32_t rounds;
} NeonCipher;

NeonCipher *neon_init(const char *key, size_t keyLen, uint32_t rounds) {
    NeonCipher *cipher = malloc(sizeof(NeonCipher));
    cipher->key = malloc(keyLen + 1);
    memcpy(cipher->key, key, keyLen);
    cipher->key[keyLen] = '\0';
    cipher->keyLen = keyLen;
    cipher->rounds = rounds;
    return cipher;
}

void neon_free(NeonCipher *cipher) {
    free(cipher->key);
    free(cipher);
}

uint32_t neon_encrypt(NeonCipher *cipher, const char *in, char *out, size_t len) {
    uint32_t k = 0, r = 0;
    for (size_t i = 0; i < len; i++) {
        out[i] = in[i] ^ cipher->key[k];
        k = (k + 1) % cipher->keyLen;
        r = (r + 1) % cipher->rounds;
        if (r == 0) {
            k = (k + 1) % cipher->keyLen;
        }
    }
    return len;
}

uint32_t neon_decrypt(NeonCipher *cipher, const char *in, char *out, size_t len) {
    return neon_encrypt(cipher, in, out, len);
}

// **Orbital Launch:**

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <secret key> <input file> <output file> <rounds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // **Key Derivation**

    const char *key = argv[1];
    size_t keyLen = strlen(key);
    uint32_t rounds = atoi(argv[4]);

    // **Cipher Initialization**

    NeonCipher *cipher = neon_init(key, keyLen, rounds);

    // **File I/O**

    FILE *in = fopen(argv[2], "rb");
    if (in == NULL) {
        perror("fopen(input file)");
        neon_free(cipher);
        return EXIT_FAILURE;
    }

    FILE *out = fopen(argv[3], "wb");
    if (out == NULL) {
        perror("fopen(output file)");
        neon_free(cipher);
        fclose(in);
        return EXIT_FAILURE;
    }

    // **Encryption and Transmission**

    fseek(in, 0, SEEK_END);
    size_t len = ftell(in);
    rewind(in);

    char *buf = malloc(len);
    fread(buf, 1, len, in);

    uint32_t encLen = neon_encrypt(cipher, buf, buf, len);
    fwrite(buf, 1, encLen, out);

    // **Mission Accomplished**

    printf("File encrypted successfully!\n");

    // **Resource Decommission**

    neon_free(cipher);
    free(buf);
    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}

// **[TRANSMISSION TERMINATED]**