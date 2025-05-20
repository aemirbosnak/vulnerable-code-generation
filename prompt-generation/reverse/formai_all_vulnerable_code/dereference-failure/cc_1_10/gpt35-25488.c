//FormAI DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to encrypt the contents of the given file */
void encrypt_file(char *in_file, char *out_file, char *key) {
    FILE *fin, *fout;
    char ch;
    int i = 0;
    int key_len = strlen(key);

    /* Open input and output file */
    fin = fopen(in_file, "rb");
    fout = fopen(out_file, "wb");

    /* Check if input and output file opened successfully */
    if (fin == NULL || fout == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    /* Loop through every character in input file */
    while ((ch = fgetc(fin)) != EOF) {
        /* Xor the character with the current key character */
        ch = ch ^ key[i];

        /* Write the encrypted character to output file */
        fputc(ch, fout);

        /* Increment key index and reset if end of key is reached */
        i++;
        if (i == key_len) {
            i = 0;
        }
    }

    /* Close input and output file */
    fclose(fin);
    fclose(fout);
}

/* Main function */
int main() {
    char in_file[] = "input.txt";
    char out_file[] = "output.txt";
    char key[] = "mysecretkey123";

    /* Encrypt input file and write to output file */
    encrypt_file(in_file, out_file, key);
    printf("File encrypted successfully!\n");

    return 0;
}