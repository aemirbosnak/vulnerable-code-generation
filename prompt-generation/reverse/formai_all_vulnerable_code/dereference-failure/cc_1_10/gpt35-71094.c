//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10000
#define MAX_CODEBOOK_SIZE 100
#define MAX_SYMBOLS 256

typedef struct {
    char prefix[MAX_CODEBOOK_SIZE];
    char suffix;
} code;

// function prototypes
void initialize_codebook(code *codebook);
int search_codebook(code symbol, code *codebook, int codebook_size);
void insert_codebook(code symbol, code *codebook, int *codebook_size);
int compress(char *input_file, char *output_file, code *codebook, int *codebook_size);

// initialize the codebook with all single characters
void initialize_codebook(code *codebook) {
    int i;
    for (i = 0; i < MAX_SYMBOLS; i++) {
        codebook[i].prefix[0] = (char) i;
        codebook[i].prefix[1] = '\0';
        codebook[i].suffix = (char) i;
    }
}

// search for a symbol in the codebook
int search_codebook(code symbol, code *codebook, int codebook_size) {
    int i;
    for (i = 0; i < codebook_size; i++) {
        if (strcmp(symbol.prefix, codebook[i].prefix) == 0 && symbol.suffix == codebook[i].suffix) {
            return i;
        }
    }
    return -1;
}

// insert a new symbol into the codebook
void insert_codebook(code symbol, code *codebook, int *codebook_size) {
    codebook[*codebook_size] = symbol;
    (*codebook_size)++;
}

// compress the input file
int compress(char *input_file, char *output_file, code *codebook, int *codebook_size) {
    int i, index, output_size = 0, input_size = 0;
    char input_buffer[MAX_BUFFER_SIZE], output_buffer[MAX_BUFFER_SIZE * 2];
    code current_code, new_code;

    FILE *in = fopen(input_file, "r");
    if (in == NULL) {
        return -1;
    }

    // read the entire input file into a buffer
    while (!feof(in)) {
        input_buffer[input_size++] = (char) fgetc(in);
    }
    fclose(in);

    // compress the input buffer
    current_code.prefix[0] = input_buffer[0];
    current_code.prefix[1] = '\0';
    for (i = 1; i < input_size; i++) {
        new_code.prefix[0] = input_buffer[i];
        new_code.prefix[1] = '\0';

        index = search_codebook(current_code, codebook, *codebook_size);

        if (index != -1) {
            // the symbol is already in the codebook, so extend the prefix
            strcat(current_code.prefix, new_code.prefix);
        } else {
            // the symbol is not in the codebook, so output the current prefix and insert the new symbol
            output_buffer[output_size++] = (char) index;
            insert_codebook(current_code, codebook, codebook_size);
            current_code = new_code;
        }
    }

    // output the final code
    index = search_codebook(current_code, codebook, *codebook_size);
    output_buffer[output_size++] = (char) index;

    // write the output buffer to the output file
    FILE *out = fopen(output_file, "w");
    if (out == NULL) {
        return -1;
    }
    fwrite(output_buffer, sizeof(char), output_size, out);
    fclose(out);

    return 0;
}

// main program
int main() {
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    code codebook[MAX_CODEBOOK_SIZE];
    int codebook_size = 0;

    // initialize the codebook
    initialize_codebook(codebook);
    codebook_size = MAX_SYMBOLS;

    // compress the input file
    int result = compress(input_file, output_file, codebook, &codebook_size);
    if (result == -1) {
        printf("Error: Could not compress file.\n");
    } else {
        printf("File compressed successfully.\n");
    }

    return 0;
}