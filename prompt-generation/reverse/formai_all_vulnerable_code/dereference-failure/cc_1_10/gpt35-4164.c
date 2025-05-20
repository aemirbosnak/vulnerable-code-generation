//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char message[1000], key[1000], new_key[1000];
    printf("Enter message: ");
    fgets(message, 1000, stdin);
    printf("Enter key: ");
    fgets(key, 1000, stdin);
    
    // Remove \n character from input strings
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Convert key to all uppercase
    for(int i = 0; i < strlen(key); i++) {
        new_key[i] = toupper(key[i]);
    }
    new_key[strlen(key)] = '\0';
    
    // Generate keystream by repeating key until it is the same length as message
    char keystream[strlen(message)];
    int key_pos = 0;
    for(int i = 0; i < strlen(message); i++) {
        keystream[i] = new_key[key_pos];
        key_pos++;
        if(key_pos == strlen(new_key)) {
            key_pos = 0;
        }
    }
    keystream[strlen(message)] = '\0';
    
    // XOR message with keystream to obtain ciphertext
    char ciphertext[strlen(message)];
    for(int i = 0; i < strlen(message); i++) {
        ciphertext[i] = message[i] ^ keystream[i];
    }
    ciphertext[strlen(message)] = '\0';
    
    printf("Ciphertext: %s\n", ciphertext);
    
    // Decrypting ciphertext
    char decrypted_message[strlen(ciphertext)];
    for(int i = 0; i < strlen(ciphertext); i++) {
        decrypted_message[i] = ciphertext[i] ^ keystream[i];
    }
    decrypted_message[strlen(ciphertext)] = '\0';
    
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}