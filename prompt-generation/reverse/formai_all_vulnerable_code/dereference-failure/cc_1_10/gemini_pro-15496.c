//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: irregular
// The full moon casts its enigmatic glow upon the ancient stone,
// its runes whispering secrets of forgotten epochs.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// A pale knight emerges from the shadows, his eyes gleaming with arcane knowledge.
// He wields a quill of shadows, its ink flowing like molten obsidian.
typedef struct {
    char *key;
    int key_len;
} cipher_t;

// The knight whispers an incantation, and the runes begin to shimmer.
// Their ancient power flows into your veins, granting you the ability to weave words into spells.
cipher_t *cipher_init(const char *key) {
    cipher_t *cipher = malloc(sizeof(cipher_t));
    cipher->key = malloc(strlen(key) + 1);
    strcpy(cipher->key, key);
    cipher->key_len = strlen(key);
    return cipher;
}

// The knight draws his sword, its blade inscribed with runes of power.
// With each stroke, the runes flare to life, unleashing their cryptic enchantment.
char *cipher_encrypt(cipher_t *cipher, const char *plaintext) {
    int plaintext_len = strlen(plaintext);
    char *ciphertext = malloc(plaintext_len + 1);
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = (plaintext[i] + cipher->key[i % cipher->key_len]) % 256;
    }
    ciphertext[plaintext_len] = '\0';
    return ciphertext;
}

// The knight sheaths his sword, its runes fading into slumber.
// The runes' power lingers in the air, their whispers guiding your thoughts.
char *cipher_decrypt(cipher_t *cipher, const char *ciphertext) {
    int ciphertext_len = strlen(ciphertext);
    char *plaintext = malloc(ciphertext_len + 1);
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = (ciphertext[i] - cipher->key[i % cipher->key_len] + 256) % 256;
    }
    plaintext[ciphertext_len] = '\0';
    return plaintext;
}

// The knight vanishes into the darkness, leaving you with the ancient knowledge.
// You feel the runes pulsing within you, their power a beacon in the shadows.
void cipher_free(cipher_t *cipher) {
    free(cipher->key);
    free(cipher);
}

// As the moon reaches its zenith, the runes glow with an ethereal luminescence.
// They guide your hand, weaving words into incantations of power.
int main() {
    // Candlelight flickers in the stillness of the crypt.
    srand(time(NULL));
    const char *plaintext = "The runes whisper secrets long forgotten.";
    const char *key = "Enchantment";

    // The runes dance before you, their patterns shifting like a cosmic ballet.
    cipher_t *cipher = cipher_init(key);
    char *ciphertext = cipher_encrypt(cipher, plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    // The runes shimmer, their power flowing through your mind.
    char *decrypted_text = cipher_decrypt(cipher, ciphertext);
    printf("Decrypted text: %s\n", decrypted_text);

    // The runes fade into darkness, their whispers echoing in the void.
    cipher_free(cipher);
    free(ciphertext);
    free(decrypted_text);
    return 0;
}