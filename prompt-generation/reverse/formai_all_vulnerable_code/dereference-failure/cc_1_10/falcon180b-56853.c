//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define SIZE 26
#define KEY_SIZE 16

int main() {
    int i, j, k, n;
    char plaintext[100], ciphertext[100], key[KEY_SIZE];
    char *keyptr;
    int *keystream;
    int keystream_size = SIZE * KEY_SIZE;

    // Generate a random key
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % SIZE + 'a';
    }

    // Convert the key to uppercase
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = toupper(key[i]);
    }

    // Generate a keystream
    keystream = malloc(keystream_size * sizeof(int));
    for (i = 0; i < keystream_size; i++) {
        keystream[i] = rand() % SIZE;
    }

    // Print the key and keystream
    printf("Key: ");
    for (i = 0; i < KEY_SIZE; i++) {
        printf("%c ", key[i]);
    }
    printf("\n");
    printf("Keystream: ");
    for (i = 0; i < keystream_size; i++) {
        printf("%d ", keystream[i]);
    }
    printf("\n");

    // Get the plaintext from the user
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    n = strlen(plaintext);
    keyptr = key;
    ciphertext[0] = plaintext[0];
    for (i = 1; i < n; i++) {
        ciphertext[i] = (keyptr[i % KEY_SIZE] + plaintext[i]) % SIZE + 'a';
    }
    ciphertext[n] = '\0';

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Free the memory
    free(keystream);

    return 0;
}