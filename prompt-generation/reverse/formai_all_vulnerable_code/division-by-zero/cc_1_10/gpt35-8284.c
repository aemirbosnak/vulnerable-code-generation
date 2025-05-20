//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHARS 500

void encrypt(char* message, char* key);
void decrypt(char* message, char* key);
int random_key();

int main() {
    char message[MAX_CHARS], key[MAX_CHARS];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_CHARS, stdin);

    int key_num = random_key();
    sprintf(key, "%d", key_num);

    encrypt(message, key);

    printf("\nEncrypted message: %s\n", message);
    printf("Key: %s\n", key);

    decrypt(message, key);

    printf("\nDecrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, char* key) {
    int len_m = strlen(message);
    int len_k = strlen(key);
    for(int i=0; i<len_m; i++) {
        message[i] = (message[i] + key[i%len_k]) % 127;
    }
}

void decrypt(char* message, char* key) {
    int len_m = strlen(message);
    int len_k = strlen(key);
    for(int i=0; i<len_m; i++) {
        message[i] = (message[i] - key[i%len_k] + 127) % 127;
    }
}

int random_key() {
    srand(time(NULL));
    return (rand() % 9000) + 1000;
}