//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Romeo and Juliet
/*
  A C File Encryptor in the style of Romeo and Juliet
  By Your Creative Bard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For the purpose of this fateful script, we shall use a simple Caesar cipher.
#define SHIFT 3 // The shifting of our letters
#define MAX_LINE_LENGTH 256

void encrypt_char(char *ch) {
    // If the character is a letter, shift it according to our fateful design.
    if (*ch >= 'a' && *ch <= 'z') {
        *ch = ((*ch - 'a' + SHIFT) % 26) + 'a';
    } else if (*ch >= 'A' && *ch <= 'Z') {
        *ch = ((*ch - 'A' + SHIFT) % 26) + 'A';
    }
}

void decrypt_char(char *ch) {
    // If the character is a letter, shift it back to its original form.
    if (*ch >= 'a' && *ch <= 'z') {
        *ch = ((*ch - 'a' - SHIFT + 26) % 26) + 'a';
    } else if (*ch >= 'A' && *ch <= 'Z') {
        *ch = ((*ch - 'A' - SHIFT + 26) % 26) + 'A';
    }
}

void encrypt_file(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    char line[MAX_LINE_LENGTH];
    
    if (!input || !output) {
        fprintf(stderr, "Alas! The fates conspire against us, file not found.\n");
        return;
    }

    while (fgets(line, sizeof(line), input)) {
        for (int i = 0; line[i] != '\0'; i++) {
            encrypt_char(&line[i]); // Enclose in a warm embrace of encryption
        }
        fputs(line, output);
    }

    fclose(input);
    fclose(output);
    printf("Hark! The file hath been encrypted to %s\n", output_file);
}

void decrypt_file(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    char line[MAX_LINE_LENGTH];
    
    if (!input || !output) {
        fprintf(stderr, "Oh tragedy! The scroll cannot be found.\n");
        return;
    }

    while (fgets(line, sizeof(line), input)) {
        for (int i = 0; line[i] != '\0'; i++) {
            decrypt_char(&line[i]); // Release the chains of enigma
        }
        fputs(line, output);
    }

    fclose(input);
    fclose(output);
    printf("Thou hast resurrected the original text in %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "To encrypt or decrypt, declare thus:\n");
        fprintf(stderr, "  ./cipher <encrypt/decrypt> <input_file> <output_file>\n");
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];

    if (strcmp(action, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(action, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        fprintf(stderr, "Gentle reader, choose wisely: encrypt or decrypt?\n");
    }

    return EXIT_SUCCESS;
}