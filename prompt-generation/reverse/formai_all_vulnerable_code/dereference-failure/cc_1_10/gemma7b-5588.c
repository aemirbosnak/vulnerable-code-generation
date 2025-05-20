//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_KEY_LENGTH 256
#define MAX_CIPHER_LENGTH 1024

void encrypt_file(char* key, char* cipher, int key_length, int cipher_length) {

    FILE* file = fopen("mysecret.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char* file_contents = (char*)malloc(cipher_length);
    if (file_contents == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    fread(file_contents, cipher_length, 1, file);
    fclose(file);

    for (int i = 0; i < key_length; i++) {
        for (int j = 0; j < cipher_length; j++) {
            int offset = key[i] ^ file_contents[j];
            file_contents[j] ^= offset;
        }
    }

    FILE* output = fopen("encrypted.txt", "w");
    if (output == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(file_contents, cipher_length, 1, output);
    fclose(output);

    free(file_contents);
}

int main() {

    char key[MAX_KEY_LENGTH];
    printf("Enter the key: ");
    scanf("%s", key);

    char cipher[MAX_CIPHER_LENGTH];
    printf("Enter the cipher: ");
    scanf("%s", cipher);

    encrypt_file(key, cipher, strlen(key), strlen(cipher));

    printf("File encrypted.\n");

    return 0;
}