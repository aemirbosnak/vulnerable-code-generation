//Falcon-180B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH + 1)

typedef struct {
    char *key;
    int key_length;
} EncryptionContext;

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[length] = '\0';
}

void encrypt(EncryptionContext *context, char *input, char *output) {
    int input_length = strlen(input);
    int output_length = input_length;

    for (int i = 0; i < input_length; i++) {
        char c = tolower(input[i]);
        c += context->key[i % context->key_length];
        if (isalpha(c)) {
            output[i] = c;
        } else {
            output[i] = input[i];
        }
    }

    output[output_length] = '\0';
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <key> <input>\n", argv[0]);
        return 1;
    }

    char *key = argv[1];
    char *input = argv[2];

    int key_length = strlen(key);

    if (key_length == 0 || key_length > MAX_KEY_LENGTH) {
        printf("Invalid key length.\n");
        return 1;
    }

    EncryptionContext context;
    context.key = key;
    context.key_length = key_length;

    char *output = malloc(MAX_OUTPUT_LENGTH * sizeof(char));
    if (output == NULL) {
        printf("Memory error.\n");
        return 1;
    }

    encrypt(&context, input, output);

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    free(output);
    return 0;
}