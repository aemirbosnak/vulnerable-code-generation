//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Function to encrypt a file */
void encrypt(FILE *ifp, FILE *ofp, char *key) {
    int key_length = strlen(key);
    int i = 0;
    char current_char;

    while ((current_char = fgetc(ifp)) != EOF) {
        fputc(current_char ^ key[i], ofp);
        i++;
        if (i == key_length) {
            i = 0;
        }
    }
}

/* Function to decrypt a file */
void decrypt(FILE *ifp, FILE *ofp, char *key) {
    encrypt(ifp, ofp, key); /* Reversing encrypt function for decryption */
}

int main(int argc, char *argv[]) {
    /* Check if the user has provided valid arguments */
    if (argc != 4) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open input file for reading */
    FILE *ifp = fopen(argv[2], "rb");
    if (!ifp) {
        printf("Could not open file %s for reading.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    /* Open output file for writing */
    FILE *ofp = fopen(argv[3], "wb");
    if (!ofp) {
        printf("Could not open file %s for writing.\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    /* Get the key from the user */
    printf("Enter encryption/decryption key: ");
    char key[256];
    fgets(key, 256, stdin);
    key[strcspn(key, "\n")] = 0; /* Remove trailing newline character */

    /* Encrypt or decrypt based on user input */
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(ifp, ofp, key);
        printf("File encrypted successfully and saved to %s.\n", argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(ifp, ofp, key);
        printf("File decrypted successfully and saved to %s.\n", argv[3]);
    } else {
        printf("Invalid command. Please enter either 'encrypt' or 'decrypt'.\n");
    }

    /* Close input and output files */
    fclose(ifp);
    fclose(ofp);

    return 0;
}