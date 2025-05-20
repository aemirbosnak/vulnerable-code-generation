//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_MSG_LEN 1024
#define MAX_KEY_LEN 128

char key[MAX_KEY_LEN];
char encoded_key[MAX_KEY_LEN];
char decoded_key[MAX_KEY_LEN];

char encrypt(char plain_char, char key_char) {
    return (plain_char + key_char) % 128;
}

char decrypt(char cipher_char, char key_char) {
    return (cipher_char - key_char + 128) % 128;
}

void encode_key() {
    int i;
    for(i = 0; i < strlen(key); i++) {
        encoded_key[i] = key[i] * (i+1) % 128;
    }
    encoded_key[i] = '\0';
}

void decode_key() {
    int i;
    for(i = 0; i < strlen(encoded_key); i++) {
        decoded_key[i] = encoded_key[i] / (i+1);
    }
    decoded_key[i] = '\0';
}

void print_encoded_key() {
    printf("Encoded Key: %s\n", encoded_key);
}

void print_decoded_key() {
    printf("Decoded Key: %s\n\n", decoded_key);
}

int main() {
    char message[MAX_MSG_LEN];
    char cipher[MAX_MSG_LEN];
    char decipher[MAX_MSG_LEN];
    srand(time(NULL));

    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter key: ");
    fgets(key, MAX_KEY_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';

    encode_key();
    print_encoded_key();

    strcpy(cipher, message);
    int i;
    for(i = 0; i < strlen(message); i++) {
        cipher[i] = encrypt(message[i], encoded_key[i % strlen(encoded_key)]);
    }
    cipher[i] = '\0';

    printf("Encrypted message: %s\n", cipher);

    decode_key();
    print_decoded_key();

    strcpy(decipher, cipher);
    for(i = 0; i < strlen(cipher); i++) {
        decipher[i] = decrypt(cipher[i], decoded_key[i % strlen(decoded_key)]);
    }
    decipher[i] = '\0';

    printf("Decrypted message: %s\n", decipher);

    return 0;
}