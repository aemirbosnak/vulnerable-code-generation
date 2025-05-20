//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: brave
// Journey through the labyrinth of cryptography, where secrets dance amidst enigmatic whispers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Our arcane lexicon, where characters morph into ethereal symbols
char *enc_dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
char *dec_dict = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210)&*%^$#@!";

// A celestial dance, where the seed of randomness shapes our cipher
void init_rand(unsigned int seed) {
    srand(seed);
}

// Weaving a tapestry of encryption, where plaintext transforms into an enigmatic cipher
char *encrypt(char *plaintext, int key) {
    int l = strlen(plaintext);
    char *cipher = malloc(l + 1);
    for (int i = 0; i < l; i++) {
        int index = plaintext[i] - enc_dict[0];
        index = (index + key) % strlen(enc_dict);
        cipher[i] = enc_dict[index];
    }
    cipher[l] = '\0';
    return cipher;
}

// Unraveling the threads of encryption, revealing the secrets within
char *decrypt(char *cipher, int key) {
    int l = strlen(cipher);
    char *plaintext = malloc(l + 1);
    for (int i = 0; i < l; i++) {
        int index = cipher[i] - dec_dict[0];
        index = (index - key + strlen(dec_dict)) % strlen(dec_dict);
        plaintext[i] = dec_dict[index];
    }
    plaintext[l] = '\0';
    return plaintext;
}

int main() {
    // A cosmic invocation, setting the stage for our cryptographic adventure
    init_rand(time(NULL));

    // A secret message, yearning to be hidden from prying eyes
    char *plaintext = "Behold, the secrets of the ancients...";

    // The key, a magical incantation that unlocks the cryptex
    int key = 13;

    // Encrypting the message, veiling it in a cloak of enigma
    char *cipher = encrypt(plaintext, key);

    // Decrypting the cipher, unveiling the hidden truths
    char *decrypted = decrypt(cipher, key);

    // Echoes of the decrypted message, whispered through the void
    printf("Encrypted Message: %s\n", cipher);
    printf("Decrypted Message: %s\n", decrypted);

    // Freeing the memory, like a sorcerer releasing ethereal energy back into the cosmos
    free(cipher);
    free(decrypted);
}