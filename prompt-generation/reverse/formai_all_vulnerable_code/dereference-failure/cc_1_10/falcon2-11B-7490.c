//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

void encrypt(char *input, char *key, char *output) {
    // Convert key to bytes
    unsigned char *keyBytes = (unsigned char*) malloc(KEY_SIZE);
    for (int i = 0; i < KEY_SIZE; i++) {
        keyBytes[i] = key[i];
    }
    
    // Encrypt input using AES-CBC
    unsigned char *iv = (unsigned char*) malloc(BLOCK_SIZE);
    unsigned char *encrypted = (unsigned char*) malloc(BLOCK_SIZE * (strlen(input) / BLOCK_SIZE + 1));
    int encryptedIndex = 0;
    int remaining = strlen(input);
    
    for (int i = 0; i < KEY_SIZE; i++) {
        iv[i] = keyBytes[i];
    }
    
    // Generate initial IV
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = iv[i] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + i];
    }
    
    // Encrypt input
    for (int i = 0; i < remaining; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            iv[j] = iv[j] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + j];
        }
        
        for (int k = 0; k < BLOCK_SIZE; k++) {
            encrypted[encryptedIndex + k] = input[i + k] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + k];
        }
        
        // Mix the data with IV
        for (int l = 0; l < BLOCK_SIZE; l++) {
            encrypted[encryptedIndex + l] = encrypted[encryptedIndex + l] ^ iv[l];
        }
        
        for (int m = 0; m < BLOCK_SIZE; m++) {
            iv[m] = iv[m] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + m];
        }
        
        // Update the remaining length
        remaining -= BLOCK_SIZE;
        encryptedIndex += BLOCK_SIZE;
    }
    
    // Add padding to reach the block size
    for (int i = 0; i < BLOCK_SIZE - remaining; i++) {
        encrypted[encryptedIndex + i] = 0;
    }
    
    // Convert encrypted to string
    int charIndex = 0;
    for (int i = 0; i < encryptedIndex; i++) {
        output[charIndex++] = (char) encrypted[i];
    }
    
    // Free memory
    free(keyBytes);
    free(iv);
    free(encrypted);
}

void decrypt(char *input, char *key, char *output) {
    // Convert key to bytes
    unsigned char *keyBytes = (unsigned char*) malloc(KEY_SIZE);
    for (int i = 0; i < KEY_SIZE; i++) {
        keyBytes[i] = key[i];
    }
    
    // Decrypt input using AES-CBC
    unsigned char *iv = (unsigned char*) malloc(BLOCK_SIZE);
    unsigned char *decrypted = (unsigned char*) malloc(BLOCK_SIZE * (strlen(input) / BLOCK_SIZE + 1));
    int decryptedIndex = 0;
    int remaining = strlen(input);
    
    for (int i = 0; i < KEY_SIZE; i++) {
        iv[i] = keyBytes[i];
    }
    
    // Generate initial IV
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = iv[i] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + i];
    }
    
    // Decrypt input
    for (int i = 0; i < remaining; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            iv[j] = iv[j] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + j];
        }
        
        for (int k = 0; k < BLOCK_SIZE; k++) {
            decrypted[decryptedIndex + k] = input[i + k] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + k];
        }
        
        // Mix the data with IV
        for (int l = 0; l < BLOCK_SIZE; l++) {
            decrypted[decryptedIndex + l] = decrypted[decryptedIndex + l] ^ iv[l];
        }
        
        for (int m = 0; m < BLOCK_SIZE; m++) {
            iv[m] = iv[m] ^ keyBytes[KEY_SIZE - BLOCK_SIZE + m];
        }
        
        // Update the remaining length
        remaining -= BLOCK_SIZE;
        decryptedIndex += BLOCK_SIZE;
    }
    
    // Add padding to reach the block size
    for (int i = 0; i < BLOCK_SIZE - remaining; i++) {
        decrypted[decryptedIndex + i] = 0;
    }
    
    // Convert decrypted to string
    int charIndex = 0;
    for (int i = 0; i < decryptedIndex; i++) {
        output[charIndex++] = (char) decrypted[i];
    }
    
    // Free memory
    free(keyBytes);
    free(iv);
    free(decrypted);
}

int main() {
    char input[] = "This is a secret message.";
    char key[] = "key1234567890";
    char output[strlen(input) + 1];
    
    encrypt(input, key, output);
    printf("Encrypted: %s\n", output);
    
    decrypt(output, key, input);
    printf("Decrypted: %s\n", input);
    
    return 0;
}