//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 256
#define MAX_KEY_LENGTH 256
#define ASCII_MIN 32
#define ASCII_MAX 126

void print_usage() {
    printf("Usage: ./caesar_cipher <message> <key>\n");
}

bool is_valid_key(int key) {
    return key >= ASCII_MIN && key <= ASCII_MAX;
}

void encrypt_message(char *message, int key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char ascii_value = tolower(message[i]) + key;
            if (islower(message[i]) && ascii_value > 'z') {
                ascii_value -= 26;
            } else if (isupper(message[i]) && ascii_value > 'Z') {
                ascii_value -= 26;
            }
            message[i] = ascii_value;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return -1;
    }

    char *message = argv[1];
    int key;

    if (sscanf(argv[2], "%d", &key) != 1 || !is_valid_key(key)) {
        print_usage();
        return -1;
    }

    int message_length = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];

    encrypt_message(message, key);

    printf("Encrypted message: ");
    for (int i = 0; i < message_length; i++) {
        printf("%c", message[i]);
    }
    printf("\n");

    return 0;
}