//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char data;
    unsigned char count;
} COMPRESSED_DATA;

void compress(unsigned char *input, unsigned int input_length, unsigned char *output) {
    unsigned int i = 0;
    COMPRESSED_DATA *compressed_data = malloc(input_length * sizeof(COMPRESSED_DATA));

    for (; i < input_length; i++) {
        unsigned int j = i + 1;
        if (j < input_length && input[i] == input[j]) {
            compressed_data[i].count++;
            continue;
        }

        compressed_data[i].data = input[i];
        compressed_data[i].count = i - (i - 1) < 1 ? 1 : i - (i - 1);
        i++;
    }

    unsigned int compressed_size = i;
    unsigned char *compressed_output = output;

    for (i = 0; i < compressed_size; i++) {
        *compressed_output++ = compressed_data[i].data;
        *compressed_output++ = compressed_data[i].count;
    }

    free(compressed_data);
}

int main() {
    unsigned char input[BUFFER_SIZE] = {0};
    unsigned int input_length = 0;
    unsigned char output[BUFFER_SIZE * 2] = {0};

    scanf("%d", &input_length);
    fread(input, sizeof(unsigned char), input_length, stdin);

    compress(input, input_length, output);

    for (unsigned int i = 0; i < (input_length * 2); i++) {
        printf("%02x", output[i]);
    }

    return 0;
}