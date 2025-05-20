//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 256
#define KEY_SIZE 16

void print_usage(const char *prog_name) {
    printf("Usage: %s [encrypt|decrypt] <text>\n", prog_name);
}

void generate_key(unsigned char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void xor_encrypt_decrypt(const unsigned char *input, unsigned char *output, const unsigned char *key, size_t len) {
    for (size_t i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i % KEY_SIZE];
    }
}

void encrypt(const char *text, unsigned char *encrypted_text, const unsigned char *key) {
    size_t len = strlen(text);
    xor_encrypt_decrypt((unsigned char *)text, encrypted_text, key, len);
}

void decrypt(const unsigned char *encrypted_text, char *decrypted_text, const unsigned char *key, size_t len) {
    xor_encrypt_decrypt(encrypted_text, (unsigned char *)decrypted_text, key, len);
    decrypted_text[len] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char key[KEY_SIZE];
    generate_key(key);

    char *action = argv[1];
    char *input_text = argv[2];
    
    if (strcmp(action, "encrypt") == 0) {
        unsigned char encrypted[MAX_INPUT_SIZE];
        encrypt(input_text, encrypted, key);
        printf("Encrypted text (hex): ");
        for (size_t i = 0; i < strlen(input_text); i++) {
            printf("%02x", encrypted[i]);
        }
        printf("\nKey (hex): ");
        for (int i = 0; i < KEY_SIZE; i++) {
            printf("%02x", key[i]);
        }
        printf("\n");
    } else if (strcmp(action, "decrypt") == 0) {
        unsigned char encrypted[MAX_INPUT_SIZE];
        size_t len = strlen(input_text) / 2;
        for (size_t i = 0; i < len; i++) {
            sscanf(input_text + 2 * i, "%2hhx", &encrypted[i]);
        }
        
        char decrypted[MAX_INPUT_SIZE];
        decrypt(encrypted, decrypted, key, len);
        printf("Decrypted text: %s\n", decrypted);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}