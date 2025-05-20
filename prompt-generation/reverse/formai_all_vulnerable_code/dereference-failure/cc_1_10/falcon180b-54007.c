//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 256
#define BASE 16

char *encrypt(char *message, int key);
char *decrypt(char *encrypted_message, int key);

int main() {
    char message[1000];
    int key;
    char *encrypted_message;
    char *decrypted_message;

    printf("Enter message: ");
    fgets(message, 1000, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

char *encrypt(char *message, int key) {
    char *encrypted_message = malloc(strlen(message) + 1);
    int i, j, k;
    char *hex_chars = "0123456789ABCDEF";

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = hex_chars[(int)message[i] + key - 65];
            j++;
        } else if (isdigit(message[i])) {
            encrypted_message[j] = hex_chars[(int)message[i] + key - 48];
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }

    encrypted_message[j] = '\0';

    return encrypted_message;
}

char *decrypt(char *encrypted_message, int key) {
    char *decrypted_message = malloc(strlen(encrypted_message) + 1);
    int i, j, k;
    char *hex_chars = "0123456789ABCDEF";

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isxdigit(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = hex_chars[(int)encrypted_message[i] - 65 - key];
            } else {
                decrypted_message[j] = hex_chars[(int)encrypted_message[i] - 48 - key];
            }
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }

    decrypted_message[j] = '\0';

    return decrypted_message;
}