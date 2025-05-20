//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024
#define REPEAT_THRESHOLD 4

typedef struct {
    char *str;
    int len;
} compressed_str;

int compression_algorithm(char *input_str, int input_len, compressed_str *output) {
    int i, j, k, repeat_count = 0;
    char *output_str = NULL;
    int output_len = 0;

    // Step 1: Repeat Detection
    for (i = 0; i < input_len; i++) {
        if (input_str[i] == 'a' || input_str[i] == 'e' || input_str[i] == 'o' || input_str[i] == 'u') {
            repeat_count++;
            if (repeat_count >= REPEAT_THRESHOLD) {
                repeat_count = 0;
                output_str[output_len++] = 'x';
            }
        } else {
            repeat_count = 0;
        }
    }

    // Step 2: Huffman Coding
    for (i = 0; i < input_len; i++) {
        if (input_str[i] == 'x') {
            output_str[output_len++] = 'x';
        } else {
            int freq = 1;
            for (j = i + 1; j < input_len; j++) {
                if (input_str[j] == 'x') {
                    freq++;
                }
            }
            output_str[output_len++] = 'x';
            for (k = i + 1; k < input_len; k++) {
                if (input_str[k] == 'x') {
                    freq--;
                }
            }
            if (freq > 0) {
                output_str[output_len++] = 'x';
            }
        }
    }

    // Step 3: Bit Packing
    for (i = 0; i < output_len; i++) {
        if (output_str[i] == 'x') {
            output_str[i] = (char)((i & 1) << 1) + (char)(i >> 1);
        }
    }

    output->str = output_str;
    output->len = output_len;

    return output_len;
}

int main() {
    char input_str[] = "The quick brown fox jumps over the lazy dog";
    int input_len = strlen(input_str);
    compressed_str output;

    int compressed_len = compression_algorithm(input_str, input_len, &output);
    printf("Original String: %s\n", input_str);
    printf("Compressed String: %s\n", output.str);
    printf("Compression Ratio: %f\n", (float)compressed_len / input_len);

    return 0;
}