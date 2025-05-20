//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mystical scroll containing the secrets of modern encryption
#define MAX_MSG_LEN 256
#define KEY_LEN 16

// Enchanted function to obtain the key from the wise sage
void obtainKey(char *key) {
    printf("O enlightened one, please bestow upon us a sacred key of length %d: ", KEY_LEN);
    fgets(key, KEY_LEN + 1, stdin);
    // Remove newline character
    key[strcspn(key, "\n")] = 0;
}

// An ancient spell to encrypt the message
void encrypt(char *message, char *key, char *encrypted) {
    size_t msgLen = strlen(message);
    size_t keyLen = strlen(key);

    for (size_t i = 0; i < msgLen; ++i) {
        encrypted[i] = message[i] ^ key[i % keyLen]; // XOR encryption
    }
    encrypted[msgLen] = '\0'; // Null terminate the enchanted message
}

// A powerful incantation to decrypt the message
void decrypt(char *encrypted, char *key, char *decrypted) {
    size_t msgLen = strlen(encrypted);
    size_t keyLen = strlen(key);

    for (size_t i = 0; i < msgLen; ++i) {
        decrypted[i] = encrypted[i] ^ key[i % keyLen]; // XOR decryption
    }
    decrypted[msgLen] = '\0'; // Null terminate the restored message
}

int main() {
    char message[MAX_MSG_LEN];
    char key[KEY_LEN + 1];
    char encrypted[MAX_MSG_LEN];
    char decrypted[MAX_MSG_LEN];

    // The herald of the kingdom proclaims the entrance of the message
    printf("Hark! Enter the message that you wish to safeguard: ");
    fgets(message, MAX_MSG_LEN, stdin);
    
    // Remove newline character
    message[strcspn(message, "\n")] = 0;

    // Seek the key from the wise sage
    obtainKey(key);

    // Invoke the enchantment of the encryption
    encrypt(message, key, encrypted);
    printf("Behold! The encrypted message: %s\n", encrypted);

    // Unravel the enchantment and restore the message
    decrypt(encrypted, key, decrypted);
    printf("Rejoice! The decrypted message: %s\n", decrypted);

    // Validate the restoration of the message
    if (strcmp(message, decrypted) == 0) {
        printf("Verily, the message hath been restored successfully!\n");
    } else {
        printf("Alas, the restoration hath failed!\n");
    }

    return 0;
}