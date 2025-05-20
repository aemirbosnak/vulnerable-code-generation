//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000    // Maximum file size to read

// function to encrypt the message
char *encrypt(char *msg, char *key) {
    int key_len = strlen(key);
    char *result = (char *) malloc(strlen(msg) + 1);
    int i;

    for (i = 0; i < strlen(msg); i++) {
        result[i] = ((msg[i] + key[i % key_len]) % 26) + 'A';
    }

    result[i] = '\0';

    return result;
}

// function to decrypt the message
char *decrypt(char *msg, char *key) {
    int key_len = strlen(key);
    char *result = (char *) malloc(strlen(msg) + 1);
    int i;

    for (i = 0; i < strlen(msg); i++) {
        result[i] = (((msg[i] - 'A') - key[i % key_len]) + 26) % 26 + 'A';
    }

    result[i] = '\0';

    return result;
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    FILE *file_pointer;

    file_pointer = fopen("message.txt", "r");    // open message.txt file for reading

    if (file_pointer == NULL) {
        printf("Can't open file.\n");
        exit(1);
    }

    fgets(message, MAX_SIZE, file_pointer);      // read message from the file
    fclose(file_pointer);                        // close the file

    file_pointer = fopen("key.txt", "r");        // open key.txt file for reading

    if (file_pointer == NULL) {
        printf("Can't open file.\n");
        exit(1);
    }

    fgets(key, MAX_SIZE, file_pointer);          // read key from the file
    fclose(file_pointer);                        // close the file

    char *encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char *decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}