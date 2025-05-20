//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to encrypt a message using a substitution cipher
char* encryptMessage(char* message, int key) {
    int len = strlen(message);
    char* ciphertext = (char*)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        ciphertext[i] = message[i] + key;
        if (ciphertext[i] > 'z')
            ciphertext[i] -= 26;
        else if (ciphertext[i] < 'a')
            ciphertext[i] += 26;
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Function to decrypt a message using a substitution cipher
char* decryptMessage(char* ciphertext, int key) {
    int len = strlen(ciphertext);
    char* plaintext = (char*)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] - key;
        if (plaintext[i] > 'z')
            plaintext[i] -= 26;
        else if (plaintext[i] < 'a')
            plaintext[i] += 26;
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    srand(time(NULL));

    int key = randomNumber(0, 25);

    printf("Enter a message: ");
    char message[100];
    fgets(message, sizeof(message), stdin);

    char* ciphertext = encryptMessage(message, key);
    printf("Ciphertext: %s\n", ciphertext);

    char* plaintext = decryptMessage(ciphertext, key);
    printf("Plaintext: %s\n", plaintext);

    free(ciphertext);
    free(plaintext);

    return 0;
}