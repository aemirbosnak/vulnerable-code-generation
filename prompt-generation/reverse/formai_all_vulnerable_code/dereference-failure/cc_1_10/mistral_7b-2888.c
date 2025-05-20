//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024
#define KEY_SIZE 32
#define ROT_AMOUNT 3

char key[KEY_SIZE];
int key_index;

void encrypt(char* plaintext) {
    char ciphertext[BUF_SIZE];
    int i, j;

    memset(ciphertext, 0, BUF_SIZE);
    strcpy(ciphertext, plaintext);

    for (i = 0; i < strlen(plaintext); i++) {
        j = (i + key_index) % strlen(key);
        ciphertext[i] = ciphertext[i] ^ key[j];
    }

    printf("Encrypted: %s\n", ciphertext);
}

void generate_key() {
    char rand_char;
    int i;

    key_index = time(NULL) % strlen(key);

    printf("Key Index: %d\n", key_index);

    for (i = 0; i < KEY_SIZE; i++) {
        rand_char = rand() % 128 + 33;
        if (rand_char > 125) rand_char += 32;
        key[i] = rand_char;
    }

    printf("Generated Key: ");
    for (i = 0; i < KEY_SIZE; i++) {
        printf("%c", key[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    char plaintext[BUF_SIZE];
    int choice;

    if (argc < 2) {
        printf("Usage: %s <encrypt|decrypt> <plaintext>\n", argv[0]);
        return 1;
    }

    choice = atoi(argv[1]);

    if (choice == 1) {
        printf("Enter plaintext: ");
        fgets(plaintext, BUF_SIZE, stdin);
        plaintext[strlen(plaintext) - 1] = '\0';
        generate_key();
        encrypt(plaintext);
    } else if (choice == 2) {
        printf("Enter ciphertext: ");
        fgets(plaintext, BUF_SIZE, stdin);
        plaintext[strlen(plaintext) - 1] = '\0';
        generate_key();
        for (int i = 0; i < strlen(plaintext); i++) {
            int j = (i + key_index) % strlen(key);
            plaintext[i] = plaintext[i] ^ key[j];
        }
        printf("Decrypted: %s\n", plaintext);
    } else {
        printf("Invalid choice. Use 1 for encryption or 2 for decryption.\n");
    }

    return 0;
}