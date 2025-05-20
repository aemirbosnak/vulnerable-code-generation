//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

//function to encrypt the message using a monoalphabetic substitution cipher
char* encrypt(char* plaintext, char* key) {
    int i;
    char* ciphertext = malloc(sizeof(char) * (strlen(plaintext) + 1));

    //loop through each character of plaintext and substitute with corresponding character from key
    for(i = 0; i < strlen(plaintext); i++) {
        if(plaintext[i] == ' ') {
            ciphertext[i] = ' ';
        }
        else {
            int index = plaintext[i] - 'a';
            ciphertext[i] = key[index];
        }
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

//function to decrypt the message using a monoalphabetic substitution cipher
char* decrypt(char* ciphertext, char* key) {
    int i;
    char* plaintext = malloc(sizeof(char) * (strlen(ciphertext) + 1));

    //loop through each character of ciphertext and substitute with corresponding character from key
    for(i = 0; i < strlen(ciphertext); i++) {
        if(ciphertext[i] == ' ') {
            plaintext[i] = ' ';
        }
        else {
            int index = strchr(key, ciphertext[i]) - key;
            plaintext[i] = index + 'a';
        }
    }
    plaintext[i] = '\0';
    return plaintext;
}

//function to generate a random key for monoalphabetic substitution cipher
char* generateKey() {
    int i;
    char* key = malloc(sizeof(char) * 26);
    for(i = 0; i < 26; i++) {
        key[i] = i + 'a';
    }

    //shuffle the key array to generate a random key
    srand(time(0));
    for(i = 25; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
    key[i] = '\0';
    return key;
}

int main() {
    char plaintext[100];
    char* key;
    char* ciphertext;
    char* decryptedtext;

    printf("\nEnter the plaintext: ");
    fgets(plaintext, 100, stdin);
    printf("\nGenerating key...");
    key = generateKey();
    printf("\nKey generated: %s", key);

    ciphertext = encrypt(plaintext, key);
    printf("\nEncrypted text: %s", ciphertext);

    decryptedtext = decrypt(ciphertext, key);
    printf("\nDecrypted text: %s", decryptedtext);

    return 0;
}