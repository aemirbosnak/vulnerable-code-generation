//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    FILE *file;
    int encrypting;
} Encryptor;

Encryptor *encryptor_create(const char *key, const char *file_name) {
    Encryptor *encryptor = malloc(sizeof(Encryptor));
    strncpy(encryptor->key, key, MAX_KEY_LENGTH);
    encryptor->key[MAX_KEY_LENGTH - 1] = '\0';
    encryptor->file = fopen(file_name, "rb");
    if (encryptor->file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
    encryptor->encrypting = 1;
    return encryptor;
}

void encryptor_destroy(Encryptor *encryptor) {
    if (encryptor->file!= NULL) {
        fclose(encryptor->file);
    }
    free(encryptor);
}

int encryptor_write(Encryptor *encryptor, const char *data, int data_len) {
    char buffer[data_len + 1];
    int i, j, k;
    for (i = 0, j = 0; i < data_len; i++) {
        if (isalpha(data[i])) {
            buffer[j++] = data[i] + 'A' - 'a';
        } else {
            buffer[j++] = data[i];
        }
    }
    buffer[j] = '\0';
    for (i = 0, k = 0; i < strlen(encryptor->key); i++) {
        char key_char = tolower(encryptor->key[i]);
        if (isalpha(key_char)) {
            key_char = 'A' + (key_char - 'a');
        }
        k += key_char % 26;
    }
    for (i = 0; i < strlen(buffer); i++) {
        char c = tolower(buffer[i]);
        if (isalpha(c)) {
            c = 'A' + ((c - 'a' + k) % 26);
        }
        fputc(c, encryptor->file);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <key> <file_name> [encrypt|decrypt]\n", argv[0]);
        return 1;
    }
    char *key = argv[1];
    char *file_name = argv[2];
    char *mode = argv[3];
    Encryptor *encryptor = encryptor_create(key, file_name);
    encryptor->encrypting = (strcmp(mode, "encrypt") == 0);
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), encryptor->file)) > 0) {
        if (encryptor->encrypting) {
            encryptor_write(encryptor, buffer, bytes_read);
        } else {
            fwrite(buffer, 1, bytes_read, stdout);
        }
    }
    encryptor_destroy(encryptor);
    return 0;
}