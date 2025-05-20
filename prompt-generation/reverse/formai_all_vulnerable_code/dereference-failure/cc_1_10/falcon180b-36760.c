//Falcon-180B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_INPUT_LENGTH 1000

char *generate_key(int key_length) {
    char *key = malloc(key_length + 1);
    if (key == NULL) {
        fprintf(stderr, "Error: could not allocate memory for key.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';

    return key;
}

void encrypt(char *input, char *key, char *output) {
    int input_length = strlen(input);
    int key_length = strlen(key);

    if (input_length > MAX_INPUT_LENGTH) {
        fprintf(stderr, "Error: input is too long.\n");
        exit(1);
    }
    if (key_length > MAX_KEY_LENGTH) {
        fprintf(stderr, "Error: key is too long.\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < input_length; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = 'A' + ((input[i] - 'A' + j) % 26);
            } else {
                output[i] = 'a' + ((input[i] - 'a' + j) % 26);
            }
        } else {
            output[i] = input[i];
        }
        j = (j + key[i % key_length] - 'a' + 1) % 26;
    }
    output[input_length] = '\0';
}

int main() {
    char *input;
    char *key;
    char *output;

    printf("Enter an input string: ");
    scanf("%s", input);

    printf("Enter a key: ");
    scanf("%s", key);

    output = malloc(strlen(input) + 1);
    if (output == NULL) {
        fprintf(stderr, "Error: could not allocate memory for output.\n");
        exit(1);
    }

    encrypt(input, key, output);

    printf("Encrypted string: %s\n", output);

    free(output);
    free(key);
    free(input);

    return 0;
}