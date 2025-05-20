//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the frequency array
int freq[256] = {0};

// Calculate the frequency of each character in the input string
void calculate_freq(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        freq[str[i]]++;
    }
}

// Build the Huffman tree
void build_huffman_tree(int *freq, int num_symbols) {
    int i, j, min_index;
    int *children[2];

    if (num_symbols == 1) {
        return;
    }

    // Find the symbol with the minimum frequency
    min_index = 0;
    for (i = 1; i < num_symbols; i++) {
        if (freq[i] < freq[min_index]) {
            min_index = i;
        }
    }

    // Build the children of the minimum frequency symbol
    children[0] = malloc(num_symbols * sizeof(int));
    children[1] = malloc(num_symbols * sizeof(int));

    for (i = 0; i < num_symbols; i++) {
        if (i!= min_index) {
            children[0][i] = freq[i];
            children[1][i] = i;
        }
    }

    // Recursively build the Huffman tree for the children
    build_huffman_tree(children[0], num_symbols - 1);
    build_huffman_tree(children[1], num_symbols - 1);

    // Build the Huffman tree
    int *p = malloc(num_symbols * sizeof(int));
    p[0] = min_index;
    int index = 1;
    for (i = 0; i < num_symbols - 1; i++) {
        if (children[0][i] < children[1][i]) {
            p[index] = children[0][i];
            index++;
        } else {
            p[index] = children[1][i];
            index++;
        }
    }
    p[index] = -1;
    free(children[0]);
    free(children[1]);
}

// Convert the Huffman tree to a code table
void huffman_code_table(int *tree, int num_symbols, char **code_table) {
    int i, j;
    char *code_str = malloc((num_symbols + 1) * sizeof(char));

    code_str[0] = '\0';
    for (i = 0; i < num_symbols; i++) {
        code_str[0] = tree[i];
        for (j = 1; j <= num_symbols; j++) {
            code_str[j] = '0';
        }
        code_str[j] = '\0';
        *code_table[i] = code_str;
    }
    free(code_str);
}

// Huffman code the input string
void huffman_code(char *str) {
    // Calculate the frequency of each character in the input string
    calculate_freq(str);

    // Build the Huffman tree
    build_huffman_tree(freq, 256);

    // Convert the Huffman tree to a code table
    char *code_table[256];
    huffman_code_table(freq, 256, code_table);

    // Code the input string
    int i, j;
    char code[256];
    for (i = 0; str[i]!= '\0'; i++) {
        int index = code_table[str[i] - 'a'][0];
        for (j = 1; j <= 8; j++) {
            code[j - 1] = code_table[index - 1][j];
        }
    }

    // Print the code string
    printf("Code string: %s\n", code);
}

int main() {
    char str[] = "abracadabra";
    huffman_code(str);
    return 0;
}