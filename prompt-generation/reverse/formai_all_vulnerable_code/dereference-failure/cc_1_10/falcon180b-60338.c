//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret_key"

void encrypt(char *input_file, char *output_file) {
    FILE *input, *output;
    char ch;
    int i = 0;

    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while ((ch = fgetc(input))!= EOF) {
        ch ^= KEY[i];
        fputc(ch, output);
        i = (i + 1) % strlen(KEY);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char *input_file, char *output_file) {
    FILE *input, *output;
    char ch;
    int i = 0;

    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while ((ch = fgetc(input))!= EOF) {
        ch ^= KEY[i];
        fputc(ch, output);
        i = (i + 1) % strlen(KEY);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file mode [encrypt|decrypt]\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *mode = argv[3];
    char *operation = argv[4];

    if (strcmp(mode, "binary")!= 0) {
        printf("Invalid mode. Please use 'binary'.\n");
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(input_file, output_file);
    } else {
        printf("Invalid operation. Please use 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    printf("Operation completed successfully!\n");

    return 0;
}