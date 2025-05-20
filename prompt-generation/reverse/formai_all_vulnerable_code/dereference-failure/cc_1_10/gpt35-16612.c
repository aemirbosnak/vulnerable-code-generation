//FormAI DATASET v1.0 Category: modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100

typedef struct {
    char *key;
    int key_size;
} EncryptionKey;


char* encrypt(EncryptionKey key, char* original_string) {

    // Calculate the length of the original string
    int original_string_size = strlen(original_string);

    // Allocate memory for the new string
    char* new_string = (char*) malloc((original_string_size+1) * sizeof(char));

    // Copy the original string to the new string
    strcpy(new_string, original_string);

    // Encrypt the string using the key
    for(int i = 0; i < original_string_size; i++) {
        new_string[i] ^= key.key[i % key.key_size];
    }

    // Add null terminator to the end of the string
    new_string[original_string_size] = '\0';

    return new_string;
}


int main() {

    EncryptionKey key;
    char original_string[MAX_STRING_SIZE];
    char *encrypted_string;

    // Ask the user to enter a key
    printf("Enter encryption key (max size %d): ", MAX_STRING_SIZE-1);
    fgets(original_string, MAX_STRING_SIZE, stdin);
    original_string[strcspn(original_string, "\n")] = 0;

    // Save the key into the key struct
    key.key = original_string;
    key.key_size = strlen(original_string);

    // Ask the user to enter a string to encrypt
    printf("Enter a string to encrypt (max size %d): ", MAX_STRING_SIZE-1);
    fgets(original_string, MAX_STRING_SIZE, stdin);
    original_string[strcspn(original_string, "\n")] = 0;
    
    // Encrypt the string using the key
    encrypted_string = encrypt(key, original_string);

    // Display the encrypted string
    printf("\n\nThe encrypted string is: %s\n", encrypted_string);

    free(encrypted_string);
    return 0;
}