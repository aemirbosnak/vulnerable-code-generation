//FormAI DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char *str, char *key) {
    int len = strlen(str);
    char *encrypted = (char*)malloc(sizeof(char) * (len + 1));
    memset(encrypted, 0, sizeof(char) * (len + 1));

    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            encrypted[i] = (char)(((str[i] - 'a' + key[keyIndex] - 'a') % 26) + 'a');

            keyIndex++;
            if (keyIndex >= keyLen) {
                keyIndex = 0;
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            encrypted[i] = (char)(((str[i] - 'A' + key[keyIndex] - 'a') % 26) + 'A');

            keyIndex++;
            if (keyIndex >= keyLen) {
                keyIndex = 0;
            }
        }
        else {
            encrypted[i] = str[i];
        }
    }

    return encrypted;
}

int main() {
    char *str = "This is a secret message!";
    char *key = "somerandomkey";

    char *encrypted = encrypt(str, key);

    printf("Original String: %s\n", str);
    printf("Encrypted String: %s\n", encrypted);

    free(encrypted);

    return 0;
}