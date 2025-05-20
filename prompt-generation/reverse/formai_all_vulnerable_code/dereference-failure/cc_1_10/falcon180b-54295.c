//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    int key = 5; // Encryption key
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch + key) % 26;
            if (isalpha(ch)) {
                fputc(ch, output_file);
            }
        } else {
            fputc(ch, output_file);
        }
    }
    fclose(input_file);
    fclose(output_file);
}

// Function to decrypt the file
void decrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    int key = 5; // Decryption key
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (26 - (ch - key + 26) % 26);
            if (isalpha(ch)) {
                fputc(ch, output_file);
            }
        } else {
            fputc(ch, output_file);
        }
    }
    fclose(input_file);
    fclose(output_file);
}

// Main function
int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    int choice;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Output file could not be created.\n");
        fclose(input_file);
        return 2;
    }

    printf("Enter 1 to encrypt the file or 2 to decrypt the file: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt_file(input_file, output_file);
        printf("File encrypted successfully.\n");
    } else if (choice == 2) {
        decrypt_file(input_file, output_file);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}