//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructs a fictional magical amulet to guard our secret key.
typedef struct Amulet {
    char *phrase;
    int length;
} Amulet;

// Creates a new magical amulet.
Amulet *amulet_create(char *phrase) {
    Amulet *amulet = malloc(sizeof(Amulet));
    amulet->phrase = strdup(phrase);
    amulet->length = strlen(phrase);
    return amulet;
}

// Destroys the magical amulet, returning its power to the void.
void amulet_destroy(Amulet *amulet) {
    free(amulet->phrase);
    free(amulet);
}

// Enchants a message with the power of our magical amulet.
char *encrypt(char *message, Amulet *amulet) {
    char *encrypted = malloc(strlen(message) + amulet->length + 1);
    int i, j;
    for (i = 0, j = 0; message[i] != '\0'; i++) {
        encrypted[j++] = message[i] ^ amulet->phrase[j % amulet->length];
    }
    encrypted[j] = '\0';
    return encrypted;
}

// Deciphers a message using the wisdom of our magical amulet.
char *decrypt(char *encrypted, Amulet *amulet) {
    char *decrypted = malloc(strlen(encrypted) + 1);
    int i, j;
    for (i = 0, j = 0; encrypted[i] != '\0'; i++) {
        decrypted[j++] = encrypted[i] ^ amulet->phrase[j % amulet->length];
    }
    decrypted[j] = '\0';
    return decrypted;
}

int main() {
    // The secret phrase whispered to our magical amulet.
    Amulet *amulet = amulet_create("abracadabra");

    // The secret message we wish to hide from prying eyes.
    char *message = "Top secret plans for world domination!";

    // We enchant our message with the power of the amulet.
    char *encrypted = encrypt(message, amulet);

    // An evil sorcerer intercepts the encrypted message.
    printf("Behold, the encrypted message: %s\n", encrypted);

    // But we have a secret weapon: our magical amulet.
    char *decrypted = decrypt(encrypted, amulet);

    // We decipher the message, revealing its hidden meaning.
    printf("And now, the secrets of world domination: %s\n", decrypted);

    // The amulet has served its purpose. We release its power back to the void.
    amulet_destroy(amulet);

    // We free the enchanted and deciphered messages.
    free(encrypted);
    free(decrypted);

    return 0;
}