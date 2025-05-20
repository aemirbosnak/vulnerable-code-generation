//FormAI DATASET v1.0 Category: modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

char* encrypt(char* input) {
    int input_len = strlen(input);
    int key_len = strlen(KEY);
    char* output = (char*)malloc(input_len+1);

    int i, j;
    for (i = 0, j = 0; i < input_len; i++, j++) {
        if (j >= key_len) {
            j = 0;
        }
        output[i] = (input[i] + KEY[j]) % 256;
    }
    output[i] = '\0';

    return output;
}

char* decrypt(char* input) {
    int input_len = strlen(input);
    int key_len = strlen(KEY);
    char* output = (char*)malloc(input_len+1);

    int i, j;
    for (i = 0, j = 0; i < input_len; i++, j++) {
        if (j >= key_len) {
            j = 0;
        }
        output[i] = (input[i] - KEY[j] + 256) % 256;
    }
    output[i] = '\0';

    return output;
}

int main() {
    char input[100];
    printf("Enter a message to encrypt: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    char* encrypted = encrypt(input);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}