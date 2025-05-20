//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <string.h>

int main(){

    // declare variables for key and message
    char key[100];
    char message[100];

    // get user input for key and message
    printf("Enter a key: ");
    fgets(key, 100, stdin);

    printf("Enter a message: ");
    fgets(message, 100, stdin);

    // remove trailing newline character from user input
    key[strcspn(key, "\n")] = 0;
    message[strcspn(message, "\n")] = 0;

    // get length of key and message
    int key_len = strlen(key);
    int message_len = strlen(message);

    // create array to hold encrypted message
    char encrypted[message_len+1];

    // loop through each character in the message
    for(int i = 0; i < message_len; i++){
        // XOR message character with corresponding key character
        encrypted[i] = message[i] ^ key[i % key_len];
    }

    // add null terminator to encrypted message
    encrypted[message_len] = 0;

    // print out encrypted message
    printf("\nEncrypted message: %s\n", encrypted);

    // create array to hold decrypted message
    char decrypted[message_len+1];

    // loop through each character in the encrypted message
    for(int i = 0; i < message_len; i++){
        // XOR encrypted character with corresponding key character
        decrypted[i] = encrypted[i] ^ key[i % key_len];
    }

    // add null terminator to decrypted message
    decrypted[message_len] = 0;

    // print out decrypted message
    printf("Decrypted message: %s\n", decrypted);

    // exit program
    return 0;
}