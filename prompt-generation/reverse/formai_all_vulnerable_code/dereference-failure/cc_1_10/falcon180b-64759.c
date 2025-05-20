//Falcon-180B DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE + 1)

// Function to encrypt the input string using the key
char* encrypt(char* input, char* key) {
    int input_size = strlen(input);
    int key_size = strlen(key);
    char output[MAX_OUTPUT_SIZE];
    int j = 0;

    // Loop through each character in the input string
    for (int i = 0; i < input_size; i++) {
        char c = tolower(input[i]);

        // Encrypt the character if it is a letter
        if (isalpha(c)) {
            int k = (int)c - 97;

            // Shift the character by the corresponding key character
            k = (k + (int)key[j] - 97) % 26;

            // Convert the encrypted character back to a letter
            c = k + 97;
        }

        // Append the encrypted character to the output string
        output[j++] = c;
    }

    output[j] = '\0';
    return strdup(output);
}

// Function to decrypt the encrypted string using the key
char* decrypt(char* encrypted, char* key) {
    int encrypted_size = strlen(encrypted);
    int key_size = strlen(key);
    char decrypted[MAX_OUTPUT_SIZE];
    int j = 0;

    // Loop through each character in the encrypted string
    for (int i = 0; i < encrypted_size; i++) {
        char c = encrypted[i];

        // Decrypt the character if it is a letter
        if (isalpha(c)) {
            int k = (int)c - 97;

            // Shift the character back by the corresponding key character
            k = (k - (int)key[j] + 26) % 26;

            // Convert the decrypted character back to a letter
            c = k + 97;
        }

        // Append the decrypted character to the output string
        decrypted[j++] = c;
    }

    decrypted[j] = '\0';
    return strdup(decrypted);
}

// Function to read the input and key from the user
void read_input(char* input, char* key) {
    printf("Enter the input string: ");
    scanf("%s", input);

    printf("Enter the encryption key: ");
    scanf("%s", key);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char key[MAX_KEY_SIZE];
    char* encrypted;
    char* decrypted;

    // Read the input and key from the user
    read_input(input, key);

    // Encrypt the input string using the key
    encrypted = encrypt(input, key);

    // Decrypt the encrypted string using the key
    decrypted = decrypt(encrypted, key);

    // Print the original input, encrypted string, and decrypted string
    printf("Original input: %s\n", input);
    printf("Encrypted string: %s\n", encrypted);
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}