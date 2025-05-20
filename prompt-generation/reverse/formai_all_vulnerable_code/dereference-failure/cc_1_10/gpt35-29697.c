//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
char* encrypt(char* plain_text, char* key){
    int plain_text_len = strlen(plain_text);
    int key_len = strlen(key);
    int i, j;
    char* cipher_text = (char*) malloc((plain_text_len + 1) * sizeof(char));

    for (i = 0, j = 0; i < plain_text_len; i++, j++){
        if (j == key_len)
            j = 0;
        cipher_text[i] = (char) (plain_text[i] ^ key[j]);
    }
    cipher_text[plain_text_len] = '\0';
    return cipher_text;
}

// Decryption function (using the same key as encrypt)
char* decrypt(char* cipher_text, char* key){
    int cipher_text_len = strlen(cipher_text);
    int key_len = strlen(key);
    int i, j;
    char* plain_text = (char*) malloc((cipher_text_len + 1) * sizeof(char));

    for (i = 0, j = 0; i < cipher_text_len; i++, j++){
        if (j == key_len)
            j = 0;
        plain_text[i] = (char) (cipher_text[i] ^ key[j]);
    }
    plain_text[cipher_text_len] = '\0';
    return plain_text;
}

int main(){
    char plain_text[100];
    char key[100];
    printf("Enter plain text: ");
    fgets(plain_text, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);

    char* cipher_text = encrypt(plain_text, key);
    printf("Cipher text: %s\n", cipher_text);

    char* decrypted_text = decrypt(cipher_text, key);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}