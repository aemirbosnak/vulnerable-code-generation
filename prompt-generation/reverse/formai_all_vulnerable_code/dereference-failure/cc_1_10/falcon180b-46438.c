//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAX_LEN 1000
#define PRIME 31
#define MAX_DIGITS 10

typedef struct {
    int num;
    char *str;
} Key;

Key *generate_keys() {
    Key *keys = malloc(sizeof(Key) * 2);
    srand(time(NULL));
    int num = rand() % MAX_NUM;
    char *str = malloc(MAX_LEN);
    sprintf(str, "%d", num);
    keys[0].num = num;
    keys[0].str = str;
    keys[1].num = 0;
    keys[1].str = NULL;
    return keys;
}

int *encrypt_message(const char *message, Key *keys) {
    int len = strlen(message);
    int *result = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (c >= '0' && c <= '9') {
            result[i] = c - '0';
        } else {
            result[i] = 0;
        }
    }
    int num = keys[0].num;
    for (int i = 0; i < len; i++) {
        result[i] = (result[i] * num + 1) % MAX_NUM;
    }
    return result;
}

char *decrypt_message(int *message, Key *keys) {
    int len = sizeof(message) / sizeof(int);
    char *result = malloc(sizeof(char) * MAX_LEN);
    int num = keys[0].num;
    for (int i = 0; i < len; i++) {
        int c = (message[i] * num - 1) % MAX_NUM;
        if (c >= 0 && c <= MAX_DIGITS) {
            sprintf(result + i, "%d", c);
        } else {
            sprintf(result + i, " ");
        }
    }
    result[len] = '\0';
    return result;
}

void main() {
    Key *keys = generate_keys();
    int *encrypted = encrypt_message("Hello, world!", keys);
    char *decrypted = decrypt_message(encrypted, keys);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    free(keys);
}