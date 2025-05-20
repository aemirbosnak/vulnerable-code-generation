//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define ROTATION_VALUE 13

int main() {
    char input_file_name[100], output_file_name[100], key[MAX_KEY_SIZE];
    FILE *input_file, *output_file;
    int i, j, key_size, num_chars;
    char ch, encrypted_ch;

    // Get input file name and key from user
    printf("Enter input file name: ");
    scanf("%s", input_file_name);
    printf("Enter key: ");
    scanf("%s", key);
    key_size = strlen(key);

    // Open input and output files
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }
    output_file = fopen("encrypted.txt", "w");
    if (output_file == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    // Read input file and encrypt contents
    num_chars = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            encrypted_ch = (ch - 65 + ROTATION_VALUE) % 26 + 65;
        } else {
            encrypted_ch = ch;
        }
        for (i = 0; i < key_size; i++) {
            encrypted_ch = encrypted_ch ^ key[i];
        }
        fputc(encrypted_ch, output_file);
        num_chars++;
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    // Print number of characters encrypted
    printf("Number of characters encrypted: %d\n", num_chars);

    return 0;
}