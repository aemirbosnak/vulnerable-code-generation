//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 4096
#define MAX_CODE_LENGTH 12
#define MAX_DICT_SIZE 4096

// Function to initialize the dictionary with the given input file
void init_dict(FILE *input, unsigned char dict[MAX_DICT_SIZE]) {
    unsigned char c;
    int i = 0;

    while ((c = fgetc(input))!= EOF) {
        dict[i++] = c;
    }
}

// Function to compress the input file using the given dictionary
void compress(FILE *input, FILE *output, unsigned char dict[MAX_DICT_SIZE]) {
    unsigned char code[MAX_CODE_SIZE];
    int code_length = 0;
    int dict_index = 0;
    int i = 0;

    while ((code[code_length] = fgetc(input))!= EOF) {
        code_length++;

        if (code_length == MAX_CODE_LENGTH) {
            // Write the code to the output file and reset the code length
            fwrite(code, 1, code_length, output);
            code_length = 0;
        }
    }

    // Write the last code to the output file
    fwrite(code, 1, code_length, output);
}

// Function to decompress the compressed input file using the given dictionary
void decompress(FILE *input, FILE *output, unsigned char dict[MAX_DICT_SIZE]) {
    unsigned char code[MAX_CODE_SIZE];
    int code_length = 0;
    int dict_index = 0;
    int i = 0;

    while ((code_length = fread(code, 1, MAX_CODE_SIZE, input)) > 0) {
        for (i = 0; i < code_length; i++) {
            if (code[i] < dict_index) {
                // Found a match in the dictionary
                fputc(dict[code[i]], output);
            } else {
                // No match found, write the character to the output file
                fputc(code[i], output);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    unsigned char dict[MAX_DICT_SIZE];

    if (argc!= 4) {
        printf("Usage: %s input_file output_file mode\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "rb");
    output = fopen(argv[2], "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (strcmp(argv[3], "compress") == 0) {
        // Compress mode
        init_dict(input, dict);
        compress(input, output, dict);
    } else if (strcmp(argv[3], "decompress") == 0) {
        // Decompress mode
        decompress(input, output, dict);
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    fclose(input);
    fclose(output);

    return 0;
}