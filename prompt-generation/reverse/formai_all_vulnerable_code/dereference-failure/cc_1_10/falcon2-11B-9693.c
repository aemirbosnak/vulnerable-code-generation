//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 16

// Function to encrypt a string using a key
char* encrypt(const char* str, const char* key) {
    int key_len = strlen(key);
    int str_len = strlen(str);

    char* encrypted = (char*) malloc((str_len + 1) * sizeof(char));
    encrypted[str_len] = '\0';

    for (int i = 0; i < str_len; i++) {
        int char_val = str[i] - 'a';
        int key_val = key[i % key_len] - 'a';

        encrypted[i] = (char) (char_val ^ key_val);
    }

    return encrypted;
}

// Function to decrypt a string using a key
char* decrypt(const char* str, const char* key) {
    int key_len = strlen(key);
    int str_len = strlen(str);

    char* decrypted = (char*) malloc((str_len + 1) * sizeof(char));
    decrypted[str_len] = '\0';

    for (int i = 0; i < str_len; i++) {
        int char_val = str[i] - 'a';
        int key_val = key[i % key_len] - 'a';

        decrypted[i] = (char) (char_val ^ key_val);
    }

    return decrypted;
}

int main() {
    const char* key = "key123";
    const char* str = "message";

    char* encrypted = encrypt(str, key);
    printf("Encrypted: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}