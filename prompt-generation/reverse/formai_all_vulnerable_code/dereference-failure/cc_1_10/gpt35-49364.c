//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024

void compress(char* input, char* output) {
    int input_len = strlen(input);
    int i = 0, j = 0;

    while (i < input_len) {
        int count = 1;
        while (input[i] == input[i+1]) {
            count++;
            i++;
        }
        output[j] = input[i];
        if (count > 1) {
            char count_str[10];
            sprintf(count_str, "%d", count);
            strcat(output, count_str);
            j += strlen(count_str);
        }
        i++;
        j++;
    }
    output[j] = '\0';
}

void decompress(char* input, char* output) {
    int input_len = strlen(input);
    int i = 0, j = 0;

    while (i < input_len) {
        char c = input[i];
        if (c >= '0' && c <= '9') {
            int count = c - '0';
            while (input[i+1] >= '0' && input[i+1] <= '9') {
                count = count * 10 + (input[i+1] - '0');
                i++;
            }
            for (int k = 0; k < count-1; k++) {
                output[j] = output[j-1];
                j++;
            }
        } else {
            output[j] = c;
            j++;
        }
        i++;
    }
    output[j] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE];
    char compressed[MAX_OUTPUT_SIZE];
    char decompressed[MAX_INPUT_SIZE];

    printf("Enter the input string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    compress(input, compressed);
    printf("Compressed string: %s\n", compressed);

    decompress(compressed, decompressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}