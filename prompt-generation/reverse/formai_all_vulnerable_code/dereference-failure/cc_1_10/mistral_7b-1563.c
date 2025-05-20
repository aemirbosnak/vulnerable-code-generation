//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define KEY_SIZE 256

typedef struct {
    unsigned char key[KEY_SIZE];
} Key;

void generate_key(Key* key) {
    time_t t;
    struct tm* tm;

    time(&t);
    tm = localtime(&t);

    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key->key[i] = tm->tm_sec + tm->tm_min * 60 + tm->tm_hour * 60 * 60;
        if (i % 16 == 0) key->key[i] += 65;
        tm++;
    }
}

void print_key(Key key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        printf("%c", isprint(key.key[i]) ? key.key[i] : '.');
        if ((i + 1) % 16 == 0 || i == KEY_SIZE - 1) printf("\n");
    }
}

void encrypt(const char* plaintext, const Key* key, char* ciphertext) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key->key[i % KEY_SIZE];
    }
    ciphertext[i] = '\0';
}

void decrypt(const char* ciphertext, const Key* key, char* plaintext) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key->key[i % KEY_SIZE];
    }
    plaintext[i] = '\0';
}

int main() {
    Key my_key;
    generate_key(&my_key);
    printf("My secret key:\n");
    print_key(my_key);

    char plaintext[100] = "Roses are red, violets are blue, I love you more than words can say, my dear.";
    char ciphertext[100];
    char decrypted[100];

    encrypt(plaintext, &my_key, ciphertext);
    printf("\nEncrypted message:\n");
    puts(ciphertext);

    decrypt(ciphertext, &my_key, decrypted);
    printf("\nDecrypted message:\n");
    puts(decrypted);

    return 0;
}