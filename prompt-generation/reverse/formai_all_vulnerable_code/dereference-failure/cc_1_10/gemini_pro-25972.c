//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This function encrypts a string using a Caesar cipher.
 *
 * @param plaintext The plaintext string to be encrypted.
 * @param key The Caesar cipher key.
 * @return The encrypted ciphertext string.
 */
char *caesar_encrypt(const char *plaintext, int key) {
    /* Allocate memory for the ciphertext string. */
    char *ciphertext = malloc(strlen(plaintext) + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    /* Encrypt the plaintext string using the Caesar cipher key. */
    for (size_t i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] + key;
    }

    /* Terminate the ciphertext string with a null character. */
    ciphertext[strlen(plaintext)] = '\0';

    /* Return the encrypted ciphertext string. */
    return ciphertext;
}

/*
 * This function decrypts a string using a Caesar cipher.
 *
 * @param ciphertext The ciphertext string to be decrypted.
 * @param key The Caesar cipher key.
 * @return The decrypted plaintext string.
 */
char *caesar_decrypt(const char *ciphertext, int key) {
    /* Allocate memory for the plaintext string. */
    char *plaintext = malloc(strlen(ciphertext) + 1);
    if (plaintext == NULL) {
        return NULL;
    }

    /* Decrypt the ciphertext string using the Caesar cipher key. */
    for (size_t i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] - key;
    }

    /* Terminate the plaintext string with a null character. */
    plaintext[strlen(ciphertext)] = '\0';

    /* Return the decrypted plaintext string. */
    return plaintext;
}

/*
 * This function prints the usage information for the program.
 */
void print_usage() {
    printf("Usage: %s <plaintext> <key>\n", "caesar-cipher");
    printf("\n");
    printf("Encrypts or decrypts a string using a Caesar cipher.\n");
    printf("\n");
    printf("Positional arguments:\n");
    printf("  plaintext  The plaintext string to be encrypted or decrypted.\n");
    printf("  key         The Caesar cipher key (a positive or negative integer).\n");
}

/*
 * This function is the main entry point for the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return The exit code for the program.
 */
int main(int argc, char **argv) {
    /* Check the number of command-line arguments. */
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    /* Parse the command-line arguments. */
    const char *plaintext = argv[1];
    int key = atoi(argv[2]);

    /* Encrypt or decrypt the plaintext string. */
    char *ciphertext = caesar_encrypt(plaintext, key);
    char *decrypted = caesar_decrypt(ciphertext, key);

    /* Print the ciphertext and decrypted plaintext strings. */
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    /* Free the allocated memory. */
    free(ciphertext);
    free(decrypted);

    /* Return the exit code for the program. */
    return EXIT_SUCCESS;
}