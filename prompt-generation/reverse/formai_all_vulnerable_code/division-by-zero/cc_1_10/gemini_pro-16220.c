//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    size_t length;
} EncodedFile;

EncodedFile *encrypt_file(char *filename, char *password) {
    FILE *fp;
    EncodedFile *encoded_file = malloc(sizeof(EncodedFile));

    if ((fp = fopen(filename, "rb")) == NULL) {
        perror("fopen");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    encoded_file->length = ftell(fp);
    rewind(fp);

    encoded_file->data = malloc(encoded_file->length);
    if (encoded_file->data == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(encoded_file->data, sizeof(char), encoded_file->length, fp);
    fclose(fp);

    for (size_t i = 0; i < encoded_file->length; i++) {
        encoded_file->data[i] ^= password[i % strlen(password)];
    }

    return encoded_file;
}

void decrypt_file(EncodedFile *encoded_file, char *password) {
    for (size_t i = 0; i < encoded_file->length; i++) {
        encoded_file->data[i] ^= password[i % strlen(password)];
    }

    FILE *fp;
    if ((fp = fopen("decrypted.txt", "wb")) == NULL) {
        perror("fopen");
        return;
    }

    fwrite(encoded_file->data, sizeof(char), encoded_file->length, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <filename> <password>\n", argv[0]);
        return 1;
    }

    EncodedFile *encoded_file = encrypt_file(argv[1], argv[2]);
    if (encoded_file == NULL) {
        return 1;
    }

    decrypt_file(encoded_file, argv[2]);
    free(encoded_file->data);
    free(encoded_file);

    return 0;
}