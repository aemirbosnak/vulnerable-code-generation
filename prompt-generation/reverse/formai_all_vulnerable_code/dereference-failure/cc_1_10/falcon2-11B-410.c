//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <string.h>

// Function to encrypt a string using Caesar cipher
char* encrypt(char* str, int shift) {
    int len = strlen(str);
    char encrypted[len];

    for (int i = 0; i < len; i++) {
        encrypted[i] = str[i] + shift;
        if (encrypted[i] > 'z') {
            encrypted[i] -= 26;
        } else if (encrypted[i] < 'a') {
            encrypted[i] += 26;
        }
    }
    return encrypted;
}

// Function to decrypt a string using Caesar cipher
char* decrypt(char* str, int shift) {
    int len = strlen(str);
    char decrypted[len];

    for (int i = 0; i < len; i++) {
        decrypted[i] = str[i] - shift;
        if (decrypted[i] < 'a') {
            decrypted[i] += 26;
        } else if (decrypted[i] > 'z') {
            decrypted[i] -= 26;
        }
    }
    return decrypted;
}

int main() {
    char str[100];
    int shift;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter shift: ");
    scanf("%d", &shift);

    char* encryptedStr = encrypt(str, shift);
    printf("Encrypted string: %s\n", encryptedStr);

    char* decryptedStr = decrypt(encryptedStr, shift);
    printf("Decrypted string: %s\n", decryptedStr);

    return 0;
}