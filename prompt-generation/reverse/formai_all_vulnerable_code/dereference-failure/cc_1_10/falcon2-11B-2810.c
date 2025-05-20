//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LZW encoding and decoding functions
int encode_lzw(char* input, char* output, int len) {
    // Create dictionary of unique characters
    int* dict = malloc(256 * sizeof(int));
    for (int i = 0; i < len; i++) {
        dict[input[i]]++;
    }
    int max_char = 0;
    int max_count = 0;
    for (int i = 0; i < 256; i++) {
        if (dict[i] > max_count) {
            max_char = i;
            max_count = dict[i];
        }
    }
    int count = 1;
    int code = max_char;
    char* output_buffer = malloc(sizeof(char));
    for (int i = 0; i < len; i++) {
        if (input[i] == max_char) {
            output[count++] = code;
            if (count == max_count) {
                count = 1;
                code++;
            }
        } else {
            output[count++] = 0;
            for (int j = 0; j < max_count; j++) {
                if (dict[code] > 0) {
                    dict[code]--;
                    code = (code << 1) + 1;
                    if (code > 255) {
                        code = 1;
                    }
                    break;
                }
            }
            code = max_char;
        }
        output_buffer[i] = output[count - 1];
    }
    output_buffer[count] = '\0';
    return count;
}

int decode_lzw(char* input, char* output, int len) {
    int* dict = malloc(256 * sizeof(int));
    for (int i = 0; i < len; i++) {
        dict[input[i]]++;
    }
    int count = 1;
    int code = 0;
    char* output_buffer = malloc(sizeof(char));
    for (int i = 0; i < len; i++) {
        if (input[i] == code) {
            output[count++] = output_buffer[i];
            if (count == len) {
                break;
            }
            code++;
            if (code > 255) {
                code = 1;
            }
        } else {
            for (int j = 0; j < len; j++) {
                if (output_buffer[j] == input[i]) {
                    output[count++] = output_buffer[j];
                    code = 0;
                    break;
                }
            }
            output_buffer[i] = 0;
        }
    }
    output_buffer[count] = '\0';
    return count;
}

// Example usage
int main() {
    char input[] = "hello world";
    char output[strlen(input) + 100];
    int len = encode_lzw(input, output, strlen(input));
    printf("Encoded: %s\n", output);
    len = decode_lzw(output, input, len);
    printf("Decoded: %s\n", input);
    return 0;
}