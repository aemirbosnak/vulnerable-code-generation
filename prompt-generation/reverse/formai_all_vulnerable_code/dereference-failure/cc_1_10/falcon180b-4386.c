//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1000000

char *encrypt(char *message, int key) {
    int i, j;
    char *result = malloc(strlen(message) + 1);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = (((message[i] - 'A' + key) % 26) + 'A');
            } else {
                result[j] = (((message[i] - 'a' + key) % 26) + 'a');
            }
        } else {
            result[j] = message[i];
        }
        j++;
    }

    result[j] = '\0';

    return result;
}

char *decrypt(char *message, int key) {
    int i, j;
    char *result = malloc(strlen(message) + 1);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = (((message[i] - 'A' - key + 26) % 26) + 'A');
            } else {
                result[j] = (((message[i] - 'a' - key + 26) % 26) + 'a');
            }
        } else {
            result[j] = message[i];
        }
        j++;
    }

    result[j] = '\0';

    return result;
}

int main() {
    char message[MAX_SIZE];
    char *encrypted_message, *decrypted_message;
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}