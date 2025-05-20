//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MSG_LEN 1000 // maximum length of the message
#define MAX_KEY_LEN 100 // maximum length of the encryption key

void print_encrypt(char msg[], char key[]) {
    srand(time(NULL)); // seed for random number generator
    int key_len = strlen(key); // length of key
    int msg_len = strlen(msg); // length of message
    char encrypt_msg[msg_len]; // encrypted message array
    int i;

    for (i = 0; i < msg_len; i++) { // loop through each character in the message
        int key_index = rand() % key_len; // pick a random key_index
        char encrypted_char = msg[i] ^ key[key_index]; // XOR operation to encrypt the char
        encrypt_msg[i] = encrypted_char; // add encrypted char to encrypted message array
    }
    printf("Encrypted message: %s\n", encrypt_msg);
}

void print_decrypt(char encrypt_msg[], char key[]) {
    int key_len = strlen(key); // length of key
    int msg_len = strlen(encrypt_msg); // length of encrypted message
    char decrypted_msg[msg_len]; // decrypted message array
    int i;

    for (i = 0; i < msg_len; i++) { // loop through each character in the encrypted message
        int key_index = i % key_len; // pick the corresponding key_index
        char decrypted_char = encrypt_msg[i] ^ key[key_index]; // XOR operation to decrypt the char
        decrypted_msg[i] = decrypted_char; // add decrypted char to decrypted message array
    }
    printf("Decrypted message: %s\n", decrypted_msg);
}

int main() {
    char msg[MAX_MSG_LEN]; // message input
    char key[MAX_KEY_LEN]; // encryption key input
    printf("Enter message to encrypt:\n");
    fgets(msg, MAX_MSG_LEN, stdin); // read input from user
    printf("Enter encryption key:\n");
    fgets(key, MAX_KEY_LEN, stdin); // read input from user
    printf("Original message: %s", msg);
    printf("Encryption key: %s", key);
    // remove new line characters from inputs
    msg[strcspn(msg, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    print_encrypt(msg, key); // print encrypted message
    print_decrypt("UnRdLX0fWAQJAwILXFMFL16QZRE=", key); // example decryption with provided encrypted message
    return 0;
}