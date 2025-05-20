//FormAI DATASET v1.0 Category: modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function to generate a random encryption key of given length
char *generateKey(int keyLen) {
    srand(time(NULL)); //initialize random seed
    char *key = malloc(sizeof(char) * (keyLen + 1)); //allocate memory for key
    for (int i = 0; i < keyLen; i++) {
        key[i] = '!' + rand() % 94; //generate a random printable ascii character
    }
    key[keyLen] = '\0'; //null terminate the key
    return key;
}

//Function to perform encryption using given key
void encrypt(char *message, char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    for (int i = 0; i < messageLen; i++) {
        message[i] ^= key[i % keyLen]; //XOR each character with corresponding character in key
    }
}

//Function to perform decryption using given key
void decrypt(char *message, char *key) {
    encrypt(message, key); //since XORing twice returns original value
}

int main() {
    char message[101];
    char *key;
    int keyLen;
    
    printf("Enter message to be encrypted (max 100 characters):\n");
    fgets(message, 101, stdin);
    //remove newline character at the end of message from fgets
    message[strcspn(message, "\n")] = 0;
    
    printf("Enter length of encryption key (min 8, max 100):\n");
    scanf("%d", &keyLen);
    if (keyLen < 8 || keyLen > 100) { //validate key length
        printf("Invalid key length\n");
        return 1;
    }
    
    key = generateKey(keyLen); //generate encryption key
    printf("Generated key: %s\n", key);
    
    encrypt(message, key); //encrypt message using key
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key); //decrypt message using key
    printf("Decrypted message: %s\n", message);
    
    free(key); //free memory allocated for key
    
    return 0;
}