//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *input_file;
    char *output_file;
    char password[20];
    int i, j = 0, len;
    FILE *fp_in, *fp_out;

    // Check for valid number of arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Get input and output file names
    input_file = argv[1];
    output_file = argv[2];

    // Open input file
    if ((fp_in = fopen(input_file, "rb")) == NULL) {
        printf("Unable to open input file.\n");
        return 1;
    }

    // Open output file
    if ((fp_out = fopen(output_file, "wb")) == NULL) {
        printf("Unable to open output file.\n");
        return 1;
    }

    // Get password from user
    printf("Enter password to encrypt file: ");
    scanf("%s", password);

    // Get length of password
    len = strlen(password);

    // Write password length to output file
    fwrite(&len, sizeof(int), 1, fp_out);

    // Encrypt file using XOR
    while (fread(&i, sizeof(int), 1, fp_in) == 1) {
        i ^= password[j++ % len];
        fwrite(&i, sizeof(int), 1, fp_out);
    }

    // Close files
    fclose(fp_in);
    fclose(fp_out);

    printf("File encryption successful.\n");

    return 0;
}