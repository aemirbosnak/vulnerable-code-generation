//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 1000000

// Function to encrypt the file using the given key
void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char ch;
    int key_index = 0;

    // Read the input file character by character
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            // If the character is a letter, encrypt it using the key
            ch = toupper(ch);
            ch = (ch + key[key_index % strlen(key)]) % 26;
        } else {
            // If the character is not a letter, leave it as is
            ch = ch;
        }
        // Write the encrypted character to the output file
        fputc(ch, output_file);
        // Increment the key index
        key_index++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    // Open the input and output files
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        return 1;
    }

    // Read the key from the command line
    char key[MAX_KEY_SIZE];
    strncpy(key, argv[3], strlen(argv[3]));

    // Encrypt the file
    encrypt_file(input_file, output_file, key);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}