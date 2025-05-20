//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <string.h>

// This function is used to encrypt a string
char* encrypt(char* str, int key) {
    int len = strlen(str);
    char* new_str = (char*)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        int temp = ((str[i] - 'a') + key) % 26;
        if (temp < 0) {
            temp += 26;
        }
        new_str[j++] = (char)temp + 'a';
    }
    new_str[j] = '\0';
    return new_str;
}

// This function is used to decrypt a string
char* decrypt(char* str, int key) {
    int len = strlen(str);
    char* new_str = (char*)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        int temp = ((str[i] - 'a') - key) % 26;
        if (temp < 0) {
            temp += 26;
        }
        new_str[j++] = (char)temp + 'a';
    }
    new_str[j] = '\0';
    return new_str;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing the newline character from the input string

    int key = 5;
    char* encrypted = encrypt(str, key);
    printf("Encrypted string: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted string: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}