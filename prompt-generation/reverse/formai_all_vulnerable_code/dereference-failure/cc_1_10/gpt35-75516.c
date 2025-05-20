//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to perform XOR encryption */
void xor_encrypt(char *key, char *data){
    int keylen = strlen(key);
    int datalen = strlen(data);
    int i;
    for (i=0; i<datalen; i++){
        data[i] = data[i] ^ key[i % keylen];
    }
}

/* Function to perform Caesar cipher encryption */
void caesar_encrypt(char *data, int shift){
    int len = strlen(data);
    int i;
    for (i=0; i<len; i++){
        // Only apply cipher to alphabetic characters
        if ((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <= 'z')){
            // Move character by shift amount
            data[i] = (data[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

/* Function to generate a random key */
void generate_key(char *key, int keylen){
    int i;
    for (i=0; i<keylen; i++){
        key[i] = rand() % 256;
    }
}

int main(){
    // Initialize random seed
    srand(time(NULL));
    
    // Generate a random key
    char key[16];
    generate_key(key, 16);
    
    // Get user input for data
    char data[256];
    printf("Enter data to encrypt: ");
    fgets(data, 256, stdin);
    data[strcspn(data, "\n")] = 0; // Remove newline character from input
    
    // Perform XOR encryption
    xor_encrypt(key, data);
    
    // Perform Caesar cipher encryption
    caesar_encrypt(data, 5);
    
    // Print encrypted data and key
    printf("Encrypted data: %s\n", data);
    printf("Key: ");
    int i;
    for (i=0; i<16; i++){
        printf("%d ", key[i]);
    }
    
    return 0;
}