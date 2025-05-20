//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

char* generate_key(int key_size);
void encrypt_block(char* input_block, char* key, char* output_block);
void decrypt_block(char* input_block, char* key, char* output_block);

int main() {
    char* key = generate_key(KEY_SIZE);
    char input_block[BLOCK_SIZE];
    char output_block[BLOCK_SIZE];

    printf("Enter the message to encrypt: ");
    scanf("%s", input_block);

    encrypt_block(input_block, key, output_block);

    printf("Encrypted message: %s\n", output_block);

    decrypt_block(output_block, key, input_block);

    printf("Decrypted message: %s\n", input_block);

    return 0;
}

char* generate_key(int key_size) {
    char* key = malloc(key_size * sizeof(char));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

void encrypt_block(char* input_block, char* key, char* output_block) {
    int i = 0;
    int j = 0;
    while (i < strlen(input_block)) {
        char c = input_block[i];
        char k = key[j];
        output_block[i] = c ^ k;
        i++;
        j++;
        if (j == strlen(key)) {
            j = 0;
        }
    }
}

void decrypt_block(char* input_block, char* key, char* output_block) {
    int i = 0;
    int j = 0;
    while (i < strlen(input_block)) {
        char c = input_block[i];
        char k = key[j];
        output_block[i] = c ^ k;
        i++;
        j++;
        if (j == strlen(key)) {
            j = 0;
        }
    }
}