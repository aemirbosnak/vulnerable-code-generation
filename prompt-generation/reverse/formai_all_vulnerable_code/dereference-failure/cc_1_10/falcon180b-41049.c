//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 8

void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    int c;
    while ((c = fgetc(input_file))!= EOF) {
        if (isalpha(c)) {
            c = toupper(c) - 'A' + 1;
            c = (c + ((int)key[c % KEY_SIZE])) % 26;
            c += 'A';
        }
        fputc(c, output_file);
    }
}

void decrypt_file(FILE* input_file, FILE* output_file, char* key) {
    int c;
    while ((c = fgetc(input_file))!= EOF) {
        if (isalpha(c)) {
            c = toupper(c) - 'A' + 1;
            c = ((int)key[c % KEY_SIZE] - c + 26) % 26;
            c += 'A';
        }
        fputc(c, output_file);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s -e/-d input_file output_file key\n", argv[0]);
        return 1;
    }

    char operation = argv[1][0];
    FILE* input_file = fopen(argv[2], "r");
    FILE* output_file = fopen(argv[3], "w");
    char* key = argv[4];

    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    if (strcmp(key, "") == 0) {
        generate_key(key);
        printf("Generated key: %s\n", key);
    }

    if (operation == 'e') {
        encrypt_file(input_file, output_file, key);
    } else if (operation == 'd') {
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Invalid operation.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}