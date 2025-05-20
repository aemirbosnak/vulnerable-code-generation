//FormAI DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(FILE *input, FILE *output, char *key)
{
    int ch, i = 0;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key[i], output);
        i++;
        if (i == strlen(key)) {
            i = 0;
        }
    }
}

int main(int argc, char** argv)
{
    char key[20];
    printf("Enter the encryption key (max length 20): ");
    fgets(key, 20, stdin);
    key[strcspn(key, "\n")] = 0;  // remove trailing newline

    FILE *input_file, *output_file;
    char input_name[50], output_name[50];

    printf("Enter the name of the file to encrypt: ");
    fgets(input_name, 50, stdin);
    input_name[strcspn(input_name, "\n")] = 0;

    printf("Enter the name of the encrypted file to be saved: ");
    fgets(output_name, 50, stdin);
    output_name[strcspn(output_name, "\n")] = 0;

    input_file = fopen(input_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(output_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    encrypt(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");

    return 0;
}