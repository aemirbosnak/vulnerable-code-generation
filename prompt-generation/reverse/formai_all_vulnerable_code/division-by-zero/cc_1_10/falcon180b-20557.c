//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define ROTATION_VALUE 13

/* Function to encrypt the given file using Caesar cipher */
void encryptFile(FILE* inputFile, FILE* outputFile, char* key) {
    char ch;
    int keyIndex = 0;
    while ((ch = fgetc(inputFile))!= EOF) {
        /* Encrypt uppercase characters */
        if (isupper(ch)) {
            ch = toupper(ch) + keyIndex;
            if (ch > 'Z') {
                ch = ch - 26;
            }
        }
        /* Encrypt lowercase characters */
        else if (islower(ch)) {
            ch = tolower(ch) + keyIndex;
            if (ch > 'z') {
                ch = ch - 26;
            }
        }
        /* Encrypt non-alphabetic characters */
        else {
            ch = ch;
        }
        fputc(ch, outputFile);
        keyIndex = (keyIndex + 1) % strlen(key);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    FILE* inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE* outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    char* key = argv[3];
    if (strlen(key) > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        exit(1);
    }

    encryptFile(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.\n");
    return 0;
}