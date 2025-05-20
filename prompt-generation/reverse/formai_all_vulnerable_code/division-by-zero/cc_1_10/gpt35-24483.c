//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scientific
/* This program demonstrates a unique encryption method that uses scientific principles to generate a secure key.
   The key is randomly generated based on the user's input and a preset seed. The encryption algorithm uses XOR 
   operations and bitwise shifting to scramble the user's input string. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void gen_key(char [], int); // function to generate the encryption key
void encrypt(char [], char [], char []); // function to encrypt the user's input string

int main() {
    char input[100], key[100], encrypted[100];
    int len;

    printf("Enter the string to be encrypted: ");
    fgets(input, 100, stdin);

    len = strlen(input) - 1; // eliminate newline character from input

    gen_key(key, len); // generate encryption key

    encrypt(input, key, encrypted); // encrypt the input string

    printf("Original string: %s", input);
    printf("Encrypted string: %s", encrypted);

    return 0;
}

void gen_key(char key[], int len) {
    char seed[] = "encryption"; // preset seed
    int i;

    srand(time(NULL)); // initialize random number generator

    for (i = 0; i < len; i++) {
        key[i] = ((rand() % 26) + 65) ^ seed[i % strlen(seed)]; // randomly generate key using XOR operations
    }

    key[i] = '\0'; // terminate key with null character
}

void encrypt(char input[], char key[], char encrypted[]) {
    int i;

    for (i = 0; i < strlen(input); i++) {
        encrypted[i] = (input[i] ^ key[i % strlen(key)]) << 1; // perform XOR and bitwise shifting operations
    }

    encrypted[i] = '\0'; // terminate encrypted string with null character
}