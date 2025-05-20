//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct {
    char key[SIZE];
    int index;
} Vigenere;

void initVigenere(Vigenere* v, char* key) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        v->key[i] = key[i % strlen(key)];
    }
    v->index = 0;
}

char encrypt(char c, Vigenere* v) {
    if (isalpha(c)) {
        c = (isupper(c))? 'A' : 'a';
        c = (c + v->key[v->index]) % 26;
        v->index = (v->index + 1) % SIZE;
        return c;
    } else {
        return c;
    }
}

char decrypt(char c, Vigenere* v) {
    if (isalpha(c)) {
        c = (isupper(c))? 'A' : 'a';
        c = (c - v->key[v->index]) % 26;
        v->index = (v->index - 1 + SIZE) % SIZE;
        return c;
    } else {
        return c;
    }
}

int main() {
    char message[1000];
    char key[100];
    Vigenere v;
    int i, j;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key (up to %d characters): ", SIZE - 1);
    fgets(key, sizeof(key), stdin);

    initVigenere(&v, key);

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = encrypt(message[i], &v);
        }
    }

    printf("Encrypted message: %s\n", message);

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = decrypt(message[i], &v);
        }
    }

    printf("Decrypted message: %s\n", message);

    return 0;
}