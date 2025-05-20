//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Mind-bending Encryption Function
char *encrypt(char *plaintext, int key) {
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] + key;
        if (ciphertext[i] > 'z') {
            ciphertext[i] -= 26;
        } else if (ciphertext[i] < 'a') {
            ciphertext[i] += 26;
        }
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// A Mind-bending Decryption Function
char *decrypt(char *ciphertext, int key) {
    int len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] - key;
        if (plaintext[i] > 'z') {
            plaintext[i] -= 26;
        } else if (plaintext[i] < 'a') {
            plaintext[i] += 26;
        }
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    // An Array of Mind-bending Quotes
    char *quotes[] = {
        "Reality is merely an illusion, albeit a very persistent one.",
        "The universe is a vast and wondrous place, and we are but tiny specks within it.",
        "The most important thing is not to stop questioning.",
        "Imagination is more important than knowledge.",
        "The only true wisdom is in knowing you know nothing."
    };

    // Choose a Random Quote
    int idx = rand() % 5;
    char *quote = quotes[idx];

    // Encrypt the Quote with a Random Key
    int key = rand() % 26;
    char *ciphertext = encrypt(quote, key);

    // Decrypt the Ciphertext with the Same Key
    char *plaintext = decrypt(ciphertext, key);

    // Print the Encrypted and Decrypted Quotes
    printf("Encrypted Quote: %s\n", ciphertext);
    printf("Decrypted Quote: %s\n", plaintext);

    return 0;
}