//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Encrypts a file by replacing each character with its ASCII value plus a key value */
void encrypt_file(char* filename, int key) {

    FILE* file;
    file = fopen(filename, "rb+");

    if (file == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            fputc(((ch - 65 + key) % 26) + 65, file);
        }
        else if (isdigit(ch)) {
            fputc(((ch - 48 + key) % 10) + 48, file);
        }
        else {
            fputc(ch + key, file);
        }
    }

    fclose(file);

    printf("Encryption complete!\n");
}

/* Main function */
int main(int argc, char* argv[]) {

    /* Check for correct command-line arguments */
    if (argc != 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 0;
    }

    /* Get filename and key from command-line arguments */
    char* filename = argv[1];
    int key = atoi(argv[2]);

    /* Call the encrypt_file function */
    encrypt_file(filename, key);

    return 0;
}