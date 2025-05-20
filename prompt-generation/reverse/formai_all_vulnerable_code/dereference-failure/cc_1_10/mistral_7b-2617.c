//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define KEY_SIZE 26

void encrypt(char *plaintext, char *key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = (plaintext[i] + key[i % KEY_SIZE] - 'a');
            if (plaintext[i] > 'z')
                plaintext[i] -= 26;
        }
    }
}

int main() {
    char *buf, *key, *plaintext, *ciphertext;
    int len;

    buf = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (buf == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter a plaintext message: ");
    fgets(buf, BUF_SIZE, stdin);
    len = strlen(buf);
    plaintext = malloc(len + 1);
    strncpy(plaintext, buf, len + 1);

    key = mmap(NULL, KEY_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (key == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }

    encrypt(plaintext, key);

    ciphertext = malloc(len + 1);
    strcpy(ciphertext, plaintext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%c ", key[i]);
    }
    printf("\n");

    printf("Ciphertext: ");
    for (int i = 0; i < len; i++) {
        putchar(ciphertext[i] + key[i % KEY_SIZE] - 'a' + 'a');
        if (i != len - 1)
            putchar(' ');
    }
    putchar('\n');

    munmap(key, KEY_SIZE);
    munmap(plaintext, len + 1);
    munmap(ciphertext, len + 1);
    munmap(buf, BUF_SIZE);

    return EXIT_SUCCESS;
}