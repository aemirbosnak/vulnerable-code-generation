//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODES 256

typedef struct {
    unsigned char letter;
    unsigned int frequency;
} Symbol;

typedef struct {
    unsigned char letter;
    unsigned int codeword;
} Code;

int compare_symbols(const void *a, const void *b) {
    const Symbol *sa = (const Symbol *)a;
    const Symbol *sb = (const Symbol *)b;
    return sa->frequency - sb->frequency;
}

void print_codes(const Code *codes, unsigned int num_codes) {
    for (unsigned int i = 0; i < num_codes; i++) {
        printf("%c: %u\n", codes[i].letter, codes[i].codeword);
    }
}

void huffman_encode(const unsigned char *input, unsigned int input_length, const Code *codes, unsigned int num_codes) {
    unsigned char *output = malloc(input_length * 8);
    unsigned int output_length = 0;
    unsigned int codeword_index = 0;
    
    for (unsigned int i = 0; i < input_length; i++) {
        unsigned char letter = input[i];
        for (unsigned int j = 0; j < num_codes; j++) {
            if (codes[j].letter == letter) {
                codeword_index = j;
                break;
            }
        }

        unsigned int codeword = codes[codeword_index].codeword;
        for (unsigned int j = 0; j < 8; j++) {
            output[output_length++] = (codeword >> (7 - j)) & 1;
        }
    }

    fwrite(output, 1, output_length, stdout);
    free(output);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(input_file, 0, SEEK_END);
    unsigned int input_length = ftell(input_file);
    rewind(input_file);

    unsigned char *input = malloc(input_length);
    if (input == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(input, 1, input_length, input_file);
    fclose(input_file);

    Symbol symbols[MAX_CODES];
    memset(symbols, 0, sizeof(symbols));
    for (unsigned int i = 0; i < input_length; i++) {
        symbols[input[i]].frequency++;
    }

    qsort(symbols, MAX_CODES, sizeof(Symbol), compare_symbols);

    Code codes[MAX_CODES];
    memset(codes, 0, sizeof(codes));
    unsigned int num_codes = 0;
    for (unsigned int i = 0; i < MAX_CODES; i++) {
        if (symbols[i].frequency == 0) {
            break;
        }
        codes[num_codes].letter = symbols[i].letter;
        codes[num_codes].codeword = 0;
        num_codes++;
    }

    print_codes(codes, num_codes);

    huffman_encode(input, input_length, codes, num_codes);

    free(input);

    return EXIT_SUCCESS;
}