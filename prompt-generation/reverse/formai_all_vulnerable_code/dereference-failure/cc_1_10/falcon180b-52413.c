//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_LENGTH 64
#define HASH_ALPHABET "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

char *hash(const char *input) {
    unsigned char *hash_value = (unsigned char *)malloc(HASH_LENGTH * sizeof(unsigned char));
    int i, j, k;
    unsigned char ch;

    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        ch = tolower(input[i]);
        if (isalnum(ch)) {
            if (isalpha(ch)) {
                ch = toupper(ch);
                j += 2;
            } else {
                j++;
            }
        }
    }

    for (i = 0; i < j; i++) {
        hash_value[i] = 0;
    }

    for (i = 0; i < j - 3; i += 4) {
        hash_value[i] = ((unsigned int)input[i]) << 16;
        hash_value[i + 1] = ((unsigned int)input[i + 1]) << 8;
        hash_value[i + 2] = (unsigned int)input[i + 2];
        hash_value[i + 3] = (unsigned int)input[i + 3];
    }

    for (i = j - 3; i < j; i++) {
        hash_value[i] = (unsigned int)input[i];
    }

    for (i = 0; i < j; i++) {
        k = hash_value[i] % 58;
        hash_value[i] = HASH_ALPHABET[k];
    }

    return (char *)hash_value;
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);
    printf("Hash value: %s\n", hash(input));
    return 0;
}