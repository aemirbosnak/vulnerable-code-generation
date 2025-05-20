//FormAI DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: ./file-encryptor <filename> <key>\n");
        return 1;
    }

    char *filename = argv[1];
    char *key = argv[2];

    printf("Encrypting file '%s' with key '%s'...\n", filename, key);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        return 1;
    }

    char *plaintext = malloc(MAX_FILE_SIZE * sizeof(char));

    int i = 0;
    char c;
    while ((c = getc(file)) != EOF) {
        plaintext[i++] = c;
    }
    plaintext[i] = '\0';

    fclose(file);

    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);

    char *ciphertext = malloc(plaintext_len * sizeof(char));

    for (i = 0; i < plaintext_len; i++) {
        char xored = plaintext[i] ^ key[i % key_len];
        ciphertext[i] = xored;
    }

    char *new_filename = malloc((strlen(filename) + 5) * sizeof(char));
    strcpy(new_filename, filename);
    strcat(new_filename, ".enc");

    file = fopen(new_filename, "w");

    fwrite(ciphertext, sizeof(char), plaintext_len, file);

    printf("File successfully encrypted and saved as '%s'\n", new_filename);

    free(plaintext);
    free(ciphertext);
    free(new_filename);

    fclose(file);

    return 0;
}