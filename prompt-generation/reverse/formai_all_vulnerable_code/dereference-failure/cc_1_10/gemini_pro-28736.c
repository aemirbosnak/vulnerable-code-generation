//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
char *encrypt(char *msg, int key);
char *decrypt(char *msg, int key);

int main() {
    // Let's get excited about encryption! 
    
    // Declare variables
    char message[100];
    int key;
    
    // Get the message from the user. Let's make it something secret!
    printf("Enter your top-secret message: ");
    scanf("%s", message);
    
    // Now, let's choose a key. It's like the secret ingredient to our encryption potion!
    printf("Choose a magic key between 1 and 26: ");
    scanf("%d", &key);
    
    // Time to encrypt the message! Abracadabra, let's make it unreadable!
    char *encryptedMsg = encrypt(message, key);
    
    // Show the user their secret-encoded message. They'll be amazed!
    printf("Your encrypted message: %s\n", encryptedMsg);
    
    // Now, let's decrypt the message. It's like a treasure hunt, but with words!
    char *decryptedMsg = decrypt(encryptedMsg, key);
    
    // Reveal the decrypted message, like a magic trick!
    printf("Your decrypted message: %s\n", decryptedMsg);
    
    // Cleanup time! We don't want any traces of our encryption adventure.
    free(encryptedMsg);
    free(decryptedMsg);
    
    // Mission accomplished! We've kept our secrets safe and sound. Encryption rules!
    return 0;
}

// The heart of our encryption adventure! Let's shift those characters!
char *encrypt(char *msg, int key) {
    // Allocate memory for the encrypted message. It's like a treasure chest for our secret code!
    char *encryptedMsg = malloc(strlen(msg) + 1);
    
    // Loop through each character and shift it using our magic key. It's a dance of letters!
    for (int i = 0; i < strlen(msg); i++) {
        // Check if it's an alphabet. We don't want to mess with non-alphabetic characters!
        if (isalpha(msg[i])) {
            // Uppercase or lowercase? Let's handle them separately.
            if (isupper(msg[i])) {
                encryptedMsg[i] = ((msg[i] - 'A' + key) % 26) + 'A';
            } else {
                encryptedMsg[i] = ((msg[i] - 'a' + key) % 26) + 'a';
            }
        } else {
            // Non-alphabetic characters stay as they are. No need to disturb them!
            encryptedMsg[i] = msg[i];
        }
    }
    
    // Add the null terminator to the end of the encrypted message. It's like a secret handshake!
    encryptedMsg[strlen(msg)] = '\0';
    
    // Return the encrypted message, our precious treasure!
    return encryptedMsg;
}

// Time to undo the magic! Let's bring back the original message.
char *decrypt(char *msg, int key) {
    // Allocate memory for the decrypted message. It's like opening a secret box!
    char *decryptedMsg = malloc(strlen(msg) + 1);
    
    // Let's retrace our steps and unshift those characters.
    for (int i = 0; i < strlen(msg); i++) {
        // Check if it's an alphabet. We only need to decipher alphabets!
        if (isalpha(msg[i])) {
            // Uppercase or lowercase? Let's handle them separately.
            if (isupper(msg[i])) {
                // We've got an uppercase letter. Let's unscramble it!
                decryptedMsg[i] = ((msg[i] - 'A' - key + 26) % 26) + 'A';
            } else {
                // Lowercase letter? No problem! Let's decipher it!
                decryptedMsg[i] = ((msg[i] - 'a' - key + 26) % 26) + 'a';
            }
        } else {
            // Non-alphabetic characters stay as they are. They're not part of our secret code!
            decryptedMsg[i] = msg[i];
        }
    }
    
    // Add the null terminator to the end of the decrypted message. It's the final touch!
    decryptedMsg[strlen(msg)] = '\0';
    
    // Return the decrypted message, the unveiled secret!
    return decryptedMsg;
}