//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_LENGTH];
    FILE *file_in;
    FILE *file_out;
} Encryptor;

void encrypt_file(Encryptor *encryptor) {
    char buffer[MAX_FILE_SIZE];
    int buffer_len = 0;
    int key_len = strlen(encryptor->key);

    // Read in the file and encrypt it
    while ((buffer_len = fread(buffer, 1, MAX_FILE_SIZE, encryptor->file_in)) > 0) {
        for (int i = 0; i < buffer_len; i++) {
            buffer[i] ^= encryptor->key[i % key_len];
        }
        fwrite(buffer, 1, buffer_len, encryptor->file_out);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    Encryptor encryptor;
    encryptor.key[0] = '\0';
    strncat(encryptor.key, argv[3], MAX_KEY_LENGTH - 1);

    encryptor.file_in = fopen(argv[1], "rb");
    if (encryptor.file_in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    encryptor.file_out = fopen(argv[2], "wb");
    if (encryptor.file_out == NULL) {
        printf("Error opening output file.\n");
        fclose(encryptor.file_in);
        return 1;
    }

    encrypt_file(&encryptor);

    fclose(encryptor.file_in);
    fclose(encryptor.file_out);

    return 0;
}