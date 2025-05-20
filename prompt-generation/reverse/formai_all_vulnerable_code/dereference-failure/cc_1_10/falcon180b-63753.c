//Falcon-180B DATASET v1.0 Category: Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32

int encrypt(char *key, char *message) {
    int i, j, k;
    int keylen = strlen(key);
    int msg_len = strlen(message);
    char *result = (char*)malloc(msg_len + 1);
    char *key_index = (char*)malloc(MAX_KEY_LENGTH * sizeof(char));
    int key_index_len = 0;
    char *key_index_ptr = key_index;

    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key_index_ptr[i] = i;
    }

    for (i = 0; i < keylen; i++) {
        key_index_ptr = strchr(key_index, key[i]);
        key_index_len = key_index_ptr - key_index;
    }

    for (i = 0; i < msg_len; i++) {
        result[i] = message[i] ^ key_index[i % keylen];
    }

    result[msg_len] = '\0';

    strcpy(message, result);

    free(result);
    free(key_index);

    return 0;
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[100];

    printf("Enter the key (max %d characters): ", MAX_KEY_LENGTH - 1);
    scanf("%s", key);

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    encrypt(key, message);

    printf("Encrypted message: %s\n", message);

    return 0;
}