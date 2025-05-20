//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ENCRYPT 1
#define DECRYPT 2

/* Function to encrypt/decrypt the file */
void process_file(FILE *file, int mode) {
    char ch;
    int key = 5; // Encryption key
    int encrypted_char;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                encrypted_char = ((ch + key - 65) % 26) + 65;
            } else {
                encrypted_char = ((ch + key - 97) % 26) + 97;
            }
        } else {
            encrypted_char = ch;
        }
        if (mode == ENCRYPT) {
            fputc(encrypted_char, stdout);
        } else {
            fputc((encrypted_char - key - 97) % 26 + 97, stdout);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    int mode = 0;
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <mode>\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    if (strcmp(argv[3], "encrypt") == 0) {
        mode = ENCRYPT;
    } else if (strcmp(argv[3], "decrypt") == 0) {
        mode = DECRYPT;
    } else {
        printf("Invalid mode\n");
        return 1;
    }
    file = fopen(argv[2], "w");
    if (file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    process_file(file, mode);
    fclose(file);
    return 0;
}