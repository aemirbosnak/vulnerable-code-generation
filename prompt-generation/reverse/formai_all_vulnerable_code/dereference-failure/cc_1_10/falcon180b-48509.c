//Falcon-180B DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Define the message to be encrypted
    char message[100] = "Hello, World!";

    // Define the encryption key
    char key[100] = "secret";

    // Define the encrypted message buffer
    char encrypted_message[100];

    // Initialize the encrypted message buffer to empty
    strcpy(encrypted_message, "");

    // Define the output buffer
    char output_buffer[100];

    // Initialize the output buffer to empty
    strcpy(output_buffer, "");

    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {

        // Get the ASCII value of the current character
        int ascii_value = message[i];

        // Get the ASCII value of the corresponding key character
        int key_ascii_value = key[i % strlen(key)];

        // Calculate the encrypted ASCII value
        int encrypted_ascii_value = (ascii_value + key_ascii_value) % 256;

        // Convert the encrypted ASCII value to a character
        char encrypted_character = encrypted_ascii_value;

        // Add the encrypted character to the encrypted message buffer
        strcat(encrypted_message, &encrypted_character);
    }

    // Loop through each character in the encrypted message buffer
    for (int i = 0; i < strlen(encrypted_message); i++) {

        // Get the ASCII value of the current character
        int ascii_value = encrypted_message[i];

        // Convert the ASCII value to a character
        char decrypted_character = ascii_value;

        // Add the decrypted character to the output buffer
        strcat(output_buffer, &decrypted_character);
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", output_buffer);

    return 0;
}