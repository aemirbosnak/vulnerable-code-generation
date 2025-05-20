//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char *encrypt(char *plaintext, int key);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: could not open %s\n", argv[1]);
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: could not open %s\n", argv[2]);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *encrypted_line = encrypt(line, atoi(argv[2]));
        fputs(encrypted_line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

char *encrypt(char *plaintext, int key) {
    int length = strlen(plaintext);
    char *ciphertext = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = 'A' + ((plaintext[i] - 'A' + key) % 26);
            } else {
                ciphertext[i] = 'a' + ((plaintext[i] - 'a' + key) % 26);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[length] = '\0';

    return ciphertext;
}