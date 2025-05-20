//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecret"

typedef struct {
    char *plaintext;
    size_t plaintext_len;
    char *ciphertext;
    size_t ciphertext_len;
} File;

File *file_new(const char *filename) {
    File *file = malloc(sizeof(File));
    if (!file) {
        return NULL;
    }
    file->plaintext = NULL;
    file->plaintext_len = 0;
    file->ciphertext = NULL;
    file->ciphertext_len = 0;

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        free(file);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    file->plaintext_len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->plaintext = malloc(file->plaintext_len + 1);
    if (!file->plaintext) {
        fclose(fp);
        free(file);
        return NULL;
    }
    fread(file->plaintext, 1, file->plaintext_len, fp);
    file->plaintext[file->plaintext_len] = '\0';

    fclose(fp);

    return file;
}

void file_free(File *file) {
    if (!file) {
        return;
    }
    free(file->plaintext);
    free(file->ciphertext);
    free(file);
}

void encrypt(File *file) {
    size_t i;
    size_t key_len = strlen(KEY);
    size_t key_index = 0;
    file->ciphertext_len = file->plaintext_len;
    file->ciphertext = malloc(file->ciphertext_len + 1);
    if (!file->ciphertext) {
        return;
    }

    for (i = 0; i < file->ciphertext_len; i++) {
        file->ciphertext[i] = file->plaintext[i] ^ KEY[key_index];
        key_index = (key_index + 1) % key_len;
    }

    file->ciphertext[file->ciphertext_len] = '\0';
}

void decrypt(File *file) {
    size_t i;
    size_t key_len = strlen(KEY);
    size_t key_index = 0;

    for (i = 0; i < file->ciphertext_len; i++) {
        file->plaintext[i] = file->ciphertext[i] ^ KEY[key_index];
        key_index = (key_index + 1) % key_len;
    }
}

void save_file(const char *filename, const char *data, size_t len) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }
    fwrite(data, 1, len, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    File *file = file_new(argv[1]);
    if (!file) {
        printf("Could not read input file.\n");
        return EXIT_FAILURE;
    }

    encrypt(file);

    save_file(argv[2], file->ciphertext, file->ciphertext_len);

    file_free(file);

    return EXIT_SUCCESS;
}