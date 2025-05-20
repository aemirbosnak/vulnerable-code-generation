//FormAI DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure to hold the input data
typedef struct {
    char* key;
    char* plaintext;
} InputData;

/**
 * Function to apply the cipher operation
 * @param c The character to apply the cipher to
 * @param key The key to use for the cipher operation
 * @return The encrypted/decrypted character
 */
char cipher(char c, char key) {
    return (c ^ key);
}

/**
 * Function to apply the encryption algorithm to a given input
 * @param input The input data containing the key and plaintext
 */
void encrypt(InputData input) {

    //Calculate the length of the plaintext
    int plaintextLength = strlen(input.plaintext);

    //Allocate memory for the encrypted buffer
    char* encrypted = (char*)malloc(sizeof(char) * (plaintextLength + 1));

    //Loop through each character in the plaintext and apply the cipher
    for (int i = 0; i < plaintextLength; i++) {
        encrypted[i] = cipher(input.plaintext[i], input.key[i % strlen(input.key)]);
    }

    //Add null terminator to encrypted buffer
    encrypted[plaintextLength] = '\0';

    //Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    //Free the memory allocated for the encrypted buffer
    free(encrypted);
}

int main() {

    //Get the input data from the user
    InputData input;
    input.key = "futuristic";
    input.plaintext = "Hello World!";

    //Perform the encryption operation
    encrypt(input);

    return 0;
}