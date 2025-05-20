//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Custom encryption function using XOR cipher
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int keylen = strlen(key);
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % keylen];
    }
}

// Custom decryption function using XOR cipher
void decrypt(char *ciphertext, char *key, char *plaintext) {
    encrypt(ciphertext, key, plaintext);
}

// Custom function to generate a random string of a given length
char *generate_random_string(int length) {
    char *random_string = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        random_string[i] = (rand() % 26) + 'a';
    }
    random_string[length] = '\0';
    return random_string;
}

int main() {
    char plaintext[] = "This is a secret message";
    char key[] = "mysecretkey";

    // Encrypt the plaintext using the XOR cipher
    char ciphertext[strlen(plaintext)];
    encrypt(plaintext, key, ciphertext);

    // Print the encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR cipher
    char decrypted_plaintext[strlen(ciphertext)];
    decrypt(ciphertext, key, decrypted_plaintext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Generate a random string using the custom function
    int string_length = 10;
    char *random_string = generate_random_string(string_length);

    // Print the generated random string
    printf("Random string: %s\n", random_string);

    // Calculate the SHA256 hash of the random string
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, random_string, string_length);
    SHA256_Final(hash, &sha256);

    // Print the SHA256 hash
    int i;
    printf("SHA256 hash: ");
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    free(random_string);

    return 0;
}