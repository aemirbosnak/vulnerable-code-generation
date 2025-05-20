//FormAI DATASET v1.0 Category: Modern Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 100
#define MAX_KEY_LEN 100

char* encryptMsg(char* message, char* key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);

    char* encrypted_msg = (char*)malloc(sizeof(char) * msg_len);
    for(int i=0; i<msg_len; i++) {
        encrypted_msg[i] = message[i] ^ key[i % key_len];
    }

    return encrypted_msg;
}

char* decryptMsg(char* encrypted_msg, char* key) {
    int msg_len = strlen(encrypted_msg);
    int key_len = strlen(key);

    char* decrypted_msg = (char*)malloc(sizeof(char) * msg_len);
    for(int i=0; i<msg_len; i++) {
        decrypted_msg[i] = encrypted_msg[i] ^ key[i % key_len];
    }

    return decrypted_msg;
}

int main() {
    char message[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];

    printf("Enter message (max length = %d): ", MAX_MSG_LEN);
    fgets(message, MAX_MSG_LEN, stdin);

    printf("Enter encryption key (max length = %d): ", MAX_KEY_LEN);
    fgets(key, MAX_KEY_LEN, stdin);

    // Remove trailing newline characters from user inputs
    message[strcspn(message, "\r\n")] = '\0';
    key[strcspn(key, "\r\n")] = '\0';

    char* encrypted_msg = encryptMsg(message, key);
    printf("Encrypted message: %s\n", encrypted_msg);

    char* decrypted_msg = decryptMsg(encrypted_msg, key);
    printf("Decrypted message: %s\n", decrypted_msg);

    free(encrypted_msg);
    free(decrypted_msg);

    return 0;
}