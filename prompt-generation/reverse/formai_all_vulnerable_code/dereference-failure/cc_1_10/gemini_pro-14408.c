//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The following function is based on Claude Shannon's "A Mathematical Theory of Communication"

unsigned int shannon_fano_coding(unsigned int *symbols, unsigned int *frequencies, unsigned int num_symbols) {
    unsigned int *codewords = malloc(num_symbols * sizeof(unsigned int));
    unsigned int *codeword_lengths = malloc(num_symbols * sizeof(unsigned int));
    unsigned int total_length = 0;

    // Sort the symbols by frequency in descending order
    for (unsigned int i = 0; i < num_symbols; i++) {
        for (unsigned int j = i + 1; j < num_symbols; j++) {
            if (frequencies[i] < frequencies[j]) {
                unsigned int temp = symbols[i];
                symbols[i] = symbols[j];
                symbols[j] = temp;

                temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;
            }
        }
    }

    // Calculate the codeword lengths
    for (unsigned int i = 0; i < num_symbols; i++) {
        codeword_lengths[i] = (unsigned int)log2(1.0 / frequencies[i]);
        total_length += frequencies[i] * codeword_lengths[i];
    }

    // Calculate the codewords
    unsigned int codeword = 0;
    unsigned int bit_index = 0;
    for (unsigned int i = 0; i < num_symbols; i++) {
        for (unsigned int j = 0; j < frequencies[i]; j++) {
            codeword |= (1 << bit_index);
            bit_index += codeword_lengths[i];
            codewords[i] = codeword;
        }
    }

    // Print the codewords
    for (unsigned int i = 0; i < num_symbols; i++) {
        printf("%u: %u (%u bits)\n", symbols[i], codewords[i], codeword_lengths[i]);
    }

    // Free the allocated memory
    free(codewords);
    free(codeword_lengths);

    return total_length;
}

int main() {
    // Define the symbols and their frequencies
    unsigned int symbols[] = {1, 2, 3, 4, 5};
    unsigned int frequencies[] = {5, 4, 3, 2, 1};
    unsigned int num_symbols = 5;

    // Calculate the total length of the code
    unsigned int total_length = shannon_fano_coding(symbols, frequencies, num_symbols);

    // Print the total length of the code
    printf("Total length: %u bits\n", total_length);

    return 0;
}