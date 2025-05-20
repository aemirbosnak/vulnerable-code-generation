//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define KEY_LENGTH 256

void print_usage() {
    printf("Usage: ./cipher <mode> <key> <text>\n");
    printf("Modes:\n");
    printf("\t-e : Encrypt the text\n");
    printf("\t-d : Decrypt the text\n");
    printf("Key: A string used for the encryption/decryption\n");
    printf("Text: The input string to be encrypted or decrypted\n");
}

void encrypt(char *text, char *key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    char *encrypted_text = (char *)malloc(text_length + 1);

    for (int i = 0; i < text_length; i++) {
        encrypted_text[i] = text[i] ^ key[i % key_length];
    }
    encrypted_text[text_length] = '\0';
    
    printf("Encrypted Text: %s\n", encrypted_text);
    free(encrypted_text);
}

void decrypt(char *text, char *key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    char *decrypted_text = (char *)malloc(text_length + 1);

    for (int i = 0; i < text_length; i++) {
        decrypted_text[i] = text[i] ^ key[i % key_length];
    }
    decrypted_text[text_length] = '\0';
    
    printf("Decrypted Text: %s\n", decrypted_text);
    free(decrypted_text);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *key = argv[2];
    char *text = argv[3];
    
    if (strlen(key) > KEY_LENGTH) {
        printf("Error: Key length exceeds the maximum limit of %d characters.\n", KEY_LENGTH);
        return EXIT_FAILURE;
    }

    if (strcmp(mode, "-e") == 0) {
        encrypt(text, key);
    } else if (strcmp(mode, "-d") == 0) {
        decrypt(text, key);
    } else {
        print_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}