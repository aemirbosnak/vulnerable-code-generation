//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    char encoded_message[MAX_SIZE];
    char decoded_message[MAX_SIZE];
    int i, j, n;

    printf("Enter the message: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter the key: ");
    fgets(key, MAX_SIZE, stdin);

    n = strlen(message);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            j = (j + message[i] - 'a' + key[i % strlen(key)] - 'a') % 26 + 'a';
            encoded_message[i] = j;
        } else {
            encoded_message[i] = message[i];
        }
    }

    printf("Encoded message: %s\n", encoded_message);

    n = strlen(encoded_message);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(encoded_message[i])) {
            if (isupper(encoded_message[i])) {
                encoded_message[i] = tolower(encoded_message[i]);
            }
            j = (j - encoded_message[i] + 26 - key[i % strlen(key)] + 'a') % 26 + 'a';
            decoded_message[i] = j;
        } else {
            decoded_message[i] = encoded_message[i];
        }
    }

    printf("Decoded message: %s\n", decoded_message);

    return 0;
}