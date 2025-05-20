//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_file_name[50], output_file_name[50], ch;
    int key, i, j;

    // Get input file name and output file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file_name);
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Get encryption key from user
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Open input file for reading
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create output file for writing
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // Loop through each character in input file
    while ((ch = fgetc(input_file))!= EOF) {
        // Encrypt character using key
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = (ch - 65 + key) % 26 + 65;
            } else {
                ch = (ch - 97 + key) % 26 + 97;
            }
        } else {
            ch = ch;
        }
        // Write encrypted character to output file
        fprintf(output_file, "%c", ch);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    return 0;
}