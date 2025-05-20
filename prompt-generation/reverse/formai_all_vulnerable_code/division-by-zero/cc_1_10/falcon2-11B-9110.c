//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1024
#define MAX_MESSAGE_LENGTH 256

void generateKeys(int *publicKey, int *privateKey) {
    int e = 3, n = 0, p = 0, q = 0, d = 0;

    srand(time(NULL));

    do {
        p = rand() % 1000;
        q = rand() % 1000;
        n = p * q;
    } while (n <= 1);

    e = (p-1) * (q-1);

    for (int i = 2; i <= e; i++) {
        if (gcd(e, i)!= 1) {
            e = i;
            break;
        }
    }

    d = mod_inverse(e, (p-1)*(q-1));

    *publicKey = e;
    *privateKey = d;
}

int main() {
    int publicKey, privateKey;
    char message[MAX_MESSAGE_LENGTH];
    char encryptedMessage[MAX_MESSAGE_LENGTH];

    printf("Enter the message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    generateKeys(&publicKey, &privateKey);

    int messageLength = strlen(message);

    int encryptedMessageLength = (messageLength / publicKey) + 1;

    for (int i = 0; i < encryptedMessageLength; i++) {
        encryptedMessage[i] = (char)((int)message[i] ^ publicKey);
    }

    encryptedMessage[encryptedMessageLength] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);

    int decryptedMessageLength = strlen(encryptedMessage);

    for (int i = 0; i < decryptedMessageLength; i++) {
        encryptedMessage[i] = (char)((int)encryptedMessage[i] ^ privateKey);
    }

    decryptedMessageLength = strlen(encryptedMessage);

    if (decryptedMessageLength!= messageLength) {
        printf("Decryption failed.\n");
    } else {
        printf("Decrypted message: %s\n", encryptedMessage);
    }

    return 0;
}

int mod_inverse(int a, int m) {
    int b;
    for (b = 1; b <= m; b++) {
        if (a * b % m == 1) {
            return b;
        }
    }
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}