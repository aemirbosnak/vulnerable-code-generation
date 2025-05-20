//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

struct FileInfo {
    char *path;
    size_t size;
    byte *data;
};

struct CipherContext {
    byte key[16];
    size_t rounds;
};

void initCipher(struct CipherContext *ctx, const char *key, size_t rounds) {
    int i, j, k;
    byte tmp[16];

    // Initialize key schedule
    for (i = 0; i < 16; i++) {
        ctx->key[i] = key[i];
    }

    // Expand key schedule
    for (i = 16; i < 256; i++) {
        j = (i + 1) % 16;
        k = j - 1;
        if (j == 0) {
            // Rotate, substitute, and XOR
            tmp[0] = ctx->key[k];
            tmp[1] = ctx->key[(k + 1) % 16];
            tmp[2] = ctx->key[(k + 2) % 16];
            tmp[3] = ctx->key[(k + 3) % 16];
            ctx->key[k] = (tmp[0] << 3) | (tmp[1] >> 5);
            ctx->key[(k + 1) % 16] = (tmp[1] << 3) | (tmp[2] >> 5);
            ctx->key[(k + 2) % 16] = (tmp[2] << 3) | (tmp[3] >> 5);
            ctx->key[(k + 3) % 16] = (tmp[3] << 3) | (tmp[0] >> 5);
        } else if (j % 4 == 0) {
            // Substitute and XOR
            ctx->key[i] = ctx->key[i - 4] ^ (ctx->key[i - 1] << 1);
        } else {
            // XOR
            ctx->key[i] = ctx->key[i - 1];
        }
    }

    // Set number of rounds
    ctx->rounds = rounds;
}

void encryptFile(struct FileInfo *file, struct CipherContext *ctx) {
    int i, j, k;
    byte keystream[8];

    // Initialize keystream
    for (i = 0; i < 8; i++) {
        keystream[i] = 0;
    }

    // Encrypt file
    for (i = 0; i < file->size; i += 8) {
        // Generate keystream
        for (j = 0; j < 8; j++) {
            keystream[j] = 0;
        }
        for (j = 0; j < ctx->rounds; j++) {
            for (k = 0; k < 16; k++) {
                keystream[k % 8] ^= ctx->key[k];
            }
            // Update key schedule
            for (k = 15; k >= 0; k--) {
                ctx->key[k] = ctx->key[(k + 1) % 16] ^ ctx->key[(k + 2) % 16] ^ ctx->key[(k + 3) % 16] ^ ctx->key[(k + 7) % 16] ^ ctx->key[(k + 14) % 16];
            }
        }

        // XOR file data with keystream
        for (j = 0; j < 8 && i + j < file->size; j++) {
            file->data[i + j] ^= keystream[j];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input file> <key>\n", argv[0]);
        return 1;
    }

    // Read input file
    struct FileInfo file;
    file.path = argv[1];
    FILE *fp = fopen(file.path, "rb");
    if (fp == NULL) {
        perror("fopen()");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    file.size = ftell(fp);
    rewind(fp);
    file.data = malloc(file.size);
    if (file.data == NULL) {
        perror("malloc()");
        fclose(fp);
        return 1;
    }
    fread(file.data, 1, file.size, fp);
    fclose(fp);

    // Initialize cipher context
    struct CipherContext ctx;
    initCipher(&ctx, argv[2], 10);

    // Encrypt file
    encryptFile(&file, &ctx);

    // Write encrypted file
    char *outpath = malloc(file.size + 5);
    if (outpath == NULL) {
        perror("malloc()");
        free(file.data);
        return 1;
    }
    sprintf(outpath, "%s.enc", file.path);
    fp = fopen(outpath, "wb");
    if (fp == NULL) {
        perror("fopen()");
        free(file.data);
        free(outpath);
        return 1;
    }
    fwrite(file.data, 1, file.size, fp);
    fclose(fp);

    // Clean up
    free(file.data);
    free(outpath);

    return 0;
}