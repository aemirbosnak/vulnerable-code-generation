//FormAI DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <string.h>

void encrypt(char* plain_text, char* key, char* result) {
    int i = 0;
    int key_length = strlen(key);
    int text_length = strlen(plain_text);

    for (i = 0; i < text_length; ++i)
    {
        char c = plain_text[i];
        char k = key[i % key_length];
        result[i] = ((c + k) % 26) + 'A';
    }

    result[text_length] = '\0';
}

void decrypt(char* cipher_text, char* key, char* result) {
    int i = 0;
    int key_length = strlen(key);
    int text_length = strlen(cipher_text);

    for (i = 0; i < text_length; ++i)
    {
        char c = cipher_text[i];
        char k = key[i % key_length];
        result[i] = ((c - k + 26) % 26) + 'A';
    }

    result[text_length] = '\0';
}

int main()
{
    char plain_text[1000];
    char key[100];
    char encrypt_result[1000];
    char decrypt_result[1000];

    printf("Please enter the message to encrypt: ");
    fgets(plain_text, sizeof(plain_text), stdin);

    printf("Please enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove new line character from input
    plain_text[strcspn(plain_text, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(plain_text, key, encrypt_result);
    decrypt(encrypt_result, key, decrypt_result);

    printf("PlainText : %s\n", plain_text);
    printf("Key       : %s\n", key);
    printf("Encrypt   : %s\n", encrypt_result);
    printf("Decrypt   : %s\n", decrypt_result);

    return 0;
}