//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Paranoid encryption function
char* encrypt(const char* plaintext, const char* key) {
    int key_len = strlen(key);
    char* ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// Paranoid decryption function
char* decrypt(const char* ciphertext, const char* key) {
    int key_len = strlen(key);
    char* plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    // Set up paranoid password and diary file
    char* password = getenv("DIARY_PASSWORD");
    if (password == NULL) {
        fprintf(stderr, "Error: DIARY_PASSWORD environment variable not set.\n");
        return EXIT_FAILURE;
    }
    char* diary_file = getenv("DIARY_FILE");
    if (diary_file == NULL) {
        fprintf(stderr, "Error: DIARY_FILE environment variable not set.\n");
        return EXIT_FAILURE;
    }

    // Read diary file into memory
    FILE* diary = fopen(diary_file, "r");
    if (diary == NULL) {
        fprintf(stderr, "Error: Could not open diary file (%s).\n", diary_file);
        return EXIT_FAILURE;
    }
    fseek(diary, 0, SEEK_END);
    long diary_size = ftell(diary);
    fseek(diary, 0, SEEK_SET);
    char* diary_text = malloc(diary_size + 1);
    fread(diary_text, 1, diary_size, diary);
    diary_text[diary_size] = '\0';
    fclose(diary);

    // Decrypt diary text using paranoid password
    char* decrypted_text = decrypt(diary_text, password);
    free(diary_text);

    // Write decrypted text to stdout
    printf("%s", decrypted_text);
    free(decrypted_text);

    // Paranoid cleanup
    memset(password, 0, strlen(password));
    memset(diary_file, 0, strlen(diary_file));
    return EXIT_SUCCESS;
}