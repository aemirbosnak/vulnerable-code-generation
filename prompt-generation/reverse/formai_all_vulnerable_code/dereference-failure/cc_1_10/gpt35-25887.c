//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void generate_key(char *key){
    int i;
    srand(time(NULL));
    for(i = 0; i < KEY_LENGTH; i++){
        key[i] = rand() % 256;
    }
}

void encrypt(char *input, char *key, char *output, int size){
    int i, j;
    int round = size / BLOCK_SIZE;
    char *prev = (char *)malloc(BLOCK_SIZE * sizeof(char));
    memcpy(prev, key, BLOCK_SIZE); //initial vector is the key
    for(i = 0; i < round; i++){
        for(j = 0; j < BLOCK_SIZE; j++){
            output[i * BLOCK_SIZE + j] = input[i * BLOCK_SIZE + j] ^ prev[j]; // XOR
        }
        memcpy(prev, output + (i * BLOCK_SIZE), BLOCK_SIZE); //set previous encrypted block as the new initialization vector
    }
    free(prev);
}

void decrypt(char *input, char *key, char *output, int size){
    int i, j;
    int round = size / BLOCK_SIZE;
    char *prev = (char *)malloc(BLOCK_SIZE * sizeof(char));
    memcpy(prev, key, BLOCK_SIZE); //initial vector is the key
    for(i = 0; i < round; i++){
        for(j = 0; j < BLOCK_SIZE; j++){
            output[i * BLOCK_SIZE + j] = input[i * BLOCK_SIZE + j] ^ prev[j]; // XOR
        }
        memcpy(prev, input + (i * BLOCK_SIZE), BLOCK_SIZE); //set previous encrypted block as the new initialization vector
    }
    free(prev);
}

int main(){
    char key[KEY_LENGTH];
    char message[] = "This is a secret message!";
    int size = strlen(message);
    int block = size % BLOCK_SIZE == 0 ? size : size + BLOCK_SIZE - size % BLOCK_SIZE;
    char *input = (char *)malloc(block * sizeof(char));
    char *output = (char *)malloc(block * sizeof(char));
    char *decrypt_output = (char *)malloc(block * sizeof(char));

    //fill the input message with the original message and padding with zeroes
    memcpy(input, message, size);
    memset(input + size, '\0', block - size);

    //generate the random key
    generate_key(key);

    //encrypt the message
    encrypt(input, key, output, block);
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    int i;
    for(i = 0; i < block; i++){
        printf("%02X ", output[i]); //print hexadecimal representation of each byte
    }
    printf("\n");

    //decrypt the message
    decrypt(output, key, decrypt_output, block);
    printf("Decrypted message: %s\n", decrypt_output);

    free(input);
    free(output);
    free(decrypt_output);

    return 0;
}