//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100
#define KEY_LENGTH 32

void generate_key(unsigned char *key);
void encrypt_message(unsigned char *message, unsigned char *key);
void decrypt_message(unsigned char *message, unsigned char *key);
void print_cyberpunk_banner();
void handle_user_input(unsigned char *message, unsigned char *key, int encrypt);

int main() {
    unsigned char message[MAX_MESSAGE_LENGTH];
    unsigned char key[KEY_LENGTH];
    int encrypt = 1;

    print_cyberpunk_banner();

    handle_user_input(message, key, encrypt);

    if (encrypt) {
        generate_key(key);
        encrypt_message(message, key);
        printf("Encrypted message: ");
        for (int i = 0; i < MAX_MESSAGE_LENGTH; i++) {
            if (i != 0) printf(" %02x", message[i]);
            else printf("%02x", message[i]);
        }
        printf("\n");
    } else {
        printf("Enter key: ");
        scanf("%s", key);
        decrypt_message(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}

void print_cyberpunk_banner() {
    printf("\n*************************************************\n");
    printf("*                                               *\n");
    printf("*  _____ _             ____ _____ _____ _____ _* \n");
    printf("* |_____| |           / ____|_  |_  | ____|  |*\n");
    printf("* |  ___  | ______ ____| (___  | | | |  ____| |\n");
    printf("* | |_  | |______|______  ___| |_| | |______| |\n");
    printf("* |_|  |_|___________|_____|_____|_|___________|\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
}

void handle_user_input(unsigned char *message, unsigned char *key, int encrypt) {
    printf("Enter a message to %s (up to %d characters): ", encrypt ? "encrypt" : "decrypt", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strlen(message) - 1] = '\0'; // remove newline character

    if (strlen(message) > MAX_MESSAGE_LENGTH) {
        printf("Error: message too long.\n");
        exit(1);
    }

    if (encrypt) {
        generate_key(key);
    } else {
        printf("Enter key (32 hexadecimal characters): ");
        scanf("%s", key);
    }
}

void generate_key(unsigned char *key) {
    srand(time(NULL));

    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = (unsigned char)(rand() % 0xFF);
    }
}

void encrypt_message(unsigned char *message, unsigned char *key) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] ^= key[i % KEY_LENGTH];
    }
}

void decrypt_message(unsigned char *message, unsigned char *key) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] ^= key[i % KEY_LENGTH];
    }
}