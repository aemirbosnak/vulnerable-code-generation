//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

// function to encrypt the file
void encrypt(FILE *input, FILE *output) {
    char ch;
    int i = 0;
    while ((ch = fgetc(input))!= EOF) {
        ch = ch ^ KEY[i];
        i++;
        if (i == strlen(KEY)) {
            i = 0;
        }
        fputc(ch, output);
    }
}

// function to decrypt the file
void decrypt(FILE *input, FILE *output) {
    char ch;
    int i = 0;
    while ((ch = fgetc(input))!= EOF) {
        ch = ch ^ KEY[i];
        i++;
        if (i == strlen(KEY)) {
            i = 0;
        }
        fputc(ch, output);
    }
}

int main() {
    FILE *input, *output;
    char filename[100];

    // get the filename from the user
    printf("Enter filename: ");
    scanf("%s", filename);

    // open the input file
    input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // create the output file
    output = fopen("encrypted.txt", "w");
    if (output == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // encrypt the file
    encrypt(input, output);

    // close the input and output files
    fclose(input);
    fclose(output);

    // open the output file for reading
    input = fopen("encrypted.txt", "r");
    if (input == NULL) {
        printf("Error opening encrypted file.\n");
        exit(1);
    }

    // create the decrypted file
    output = fopen("decrypted.txt", "w");
    if (output == NULL) {
        printf("Error creating decrypted file.\n");
        exit(1);
    }

    // decrypt the file
    decrypt(input, output);

    // close the input and output files
    fclose(input);
    fclose(output);

    printf("File encrypted and decrypted successfully.\n");

    return 0;
}