//Falcon-180B DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY 100

struct key_value {
    char key[MAX_KEY];
    int value;
};

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

int get_value(char* key) {
    int value = 0;
    for (int i = 0; i < strlen(key); i++) {
        value += (int)key[i] - 97;
    }
    return value;
}

int encrypt(char* input, char* key, char* output) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    int output_len = input_len + 1;
    output[output_len - 1] = '\0';

    for (int i = 0; i < input_len; i++) {
        if (isalpha(input[i])) {
            int input_value = (int)input[i] - 97;
            int key_value = get_value(key);

            int encrypted_value = (input_value + key_value) % 26;
            if (isupper(input[i])) {
                output[i] = encrypted_value + 'A';
            } else {
                output[i] = encrypted_value + 'a';
            }
        } else {
            output[i] = input[i];
        }
    }

    return 0;
}

int decrypt(char* input, char* key, char* output) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    int output_len = input_len;
    output[output_len - 1] = '\0';

    for (int i = 0; i < input_len; i++) {
        if (isalpha(input[i])) {
            int input_value = (int)input[i] - 97;
            int key_value = get_value(key);

            int decrypted_value = (input_value - key_value + 26) % 26;
            if (isupper(input[i])) {
                output[i] = decrypted_value + 'A';
            } else {
                output[i] = decrypted_value + 'a';
            }
        } else {
            output[i] = input[i];
        }
    }

    return 0;
}

int main() {
    char input[MAX_KEY];
    char key[MAX_KEY];
    char output[MAX_KEY];

    printf("Enter the message to encrypt: ");
    scanf("%s", input);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(input, key, output);

    printf("Encrypted message: %s\n", output);

    decrypt(output, key, input);

    printf("Decrypted message: %s\n", input);

    return 0;
}