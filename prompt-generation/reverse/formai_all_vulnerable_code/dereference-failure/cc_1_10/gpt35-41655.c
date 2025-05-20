//FormAI DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mindbendingcoder"

void encrypt(FILE *plaintext, FILE *ciphertext);

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s <plaintext file> <ciphertext file>\n", argv[0]);
        exit(1);
    }

    FILE *plaintext = fopen(argv[1], "r");
    FILE *ciphertext = fopen(argv[2], "w");

    if(!plaintext || !ciphertext) {
        printf("Error: Could not open files.\n");
        exit(1);
    }

    encrypt(plaintext, ciphertext);

    fclose(plaintext);
    fclose(ciphertext);

    printf("File encrypted successfully.\n");

    return 0;
}

void encrypt(FILE *plaintext, FILE *ciphertext) {
    char key[strlen(KEY)];
    strcpy(key, KEY);

    int plain_char, key_char, cipher_char, count = 0;
    while((plain_char = fgetc(plaintext)) != EOF) {

        if(count == strlen(KEY)) {
            count = 0;
        }

        key_char = key[count];
        cipher_char = plain_char ^ key_char;
        fprintf(ciphertext, "%02x", cipher_char);
        count++;
    }

    fprintf(ciphertext, "\n");
    return;
}