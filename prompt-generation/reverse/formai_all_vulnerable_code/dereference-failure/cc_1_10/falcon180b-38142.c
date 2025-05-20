//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch - 'a' + (int)key[0]) % 26 + 'a';
        }
        fputc(ch, output_file);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch - (int)key[0] + 'a') % 26 + 'a';
        }
        fputc(ch, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s [encrypt|decrypt] input_file output_file key\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char key[KEY_SIZE + 1];

    if (strcmp(operation, "encrypt") == 0) {
        generate_key(key);
        encrypt_file(fopen(input_file, "r"), fopen(output_file, "w"), key);
    } else if (strcmp(operation, "decrypt") == 0) {
        strcpy(key, argv[4]);
        decrypt_file(fopen(input_file, "r"), fopen(output_file, "w"), key);
    } else {
        printf("Invalid operation.\n");
        return 1;
    }

    printf("File %s successfully %s.\n", input_file, operation);

    return 0;
}