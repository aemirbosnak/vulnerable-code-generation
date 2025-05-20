//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <string.h>

// function to encrypt using xor operation
void encrypt(char* message, char key, int size) {
    // convert message into byte array
    unsigned char *byte_message = (unsigned char*)malloc(size);
    memset(byte_message, 0, size); // clear byte array

    int i;
    for (i = 0; i < size; i++) {
        byte_message[i] = (unsigned char)message[i]; // copy each character into byte array
    }

    // perform xor operation on each byte of message and key
    for (i = 0; i < size; i++) {
        byte_message[i] ^= key; // perform xor operation
    }

    // convert back to string
    char* encrypted_message = (char*)malloc(size);
    memset(encrypted_message, 0, size); // clear string

    for (i = 0; i < size; i++) {
        encrypted_message[i] = (char)byte_message[i]; // copy each byte into string
    }

    // free memory
    free(byte_message);
    free(encrypted_message);
}

// main function
int main() {
    char message[100];
    char key[100];
    int size;

    printf("Enter message:\n");
    fgets(message, 100, stdin);

    // check for invalid input
    if (message[0] == '\0') {
        printf("Invalid input!\n");
        return 0;
    }

    printf("Enter key:\n");
    fgets(key, 100, stdin);

    // check for invalid input
    if (key[0] == '\0') {
        printf("Invalid input!\n");
        return 0;
    }

    printf("Enter message size:\n");
    fgets(size, 10, stdin);

    // check for invalid input
    if (size <= 0 || size > 100) {
        printf("Invalid input!\n");
        return 0;
    }

    encrypt(message, key, size);

    printf("Encrypted message:\n%s\n", message);

    return 0;
}