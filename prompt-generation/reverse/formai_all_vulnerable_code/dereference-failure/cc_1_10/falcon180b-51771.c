//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
} EncryptionKey;

EncryptionKey generate_key(void) {
    EncryptionKey key;
    int i;

    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key.key[i] = rand() % 26 + 'a';
    }

    key.key_length = MAX_KEY_LENGTH;

    return key;
}

char encrypt_character(char character, EncryptionKey key) {
    char encrypted_character;

    if (isalpha(character)) {
        encrypted_character = toupper(character);
    } else {
        encrypted_character = character;
    }

    encrypted_character = encrypted_character + key.key[character % key.key_length];

    return encrypted_character;
}

void encrypt_file(FILE *input_file, FILE *output_file, EncryptionKey key) {
    char line[MAX_LINE_LENGTH];
    char encrypted_line[MAX_LINE_LENGTH];
    int line_length;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_length = strlen(line);

        for (int i = 0; i < line_length; i++) {
            encrypted_line[i] = encrypt_character(line[i], key);
        }

        encrypted_line[line_length] = '\0';

        fputs(encrypted_line, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    EncryptionKey key = generate_key();

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    return 0;
}