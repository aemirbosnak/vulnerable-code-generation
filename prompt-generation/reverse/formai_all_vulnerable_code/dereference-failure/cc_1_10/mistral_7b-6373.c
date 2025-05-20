//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

typedef struct {
    unsigned char data[BUFFER_SIZE];
    unsigned int length;
    unsigned int position;
} compression_buffer;

void compress(unsigned char *input, unsigned int length, compression_buffer *output) {
    unsigned char current = input[0];
    unsigned int count = 1;

    output->position = 0;
    output->length = 0;

    for (unsigned int i = 1; i < length; i++) {
        if (input[i] == current) {
            count++;
        } else {
            if (count > 1) {
                output->data[output->position++] = count;
                output->data[output->position++] = current;
                count = 1;
            }
            current = input[i];
        }
    }

    if (count > 1) {
        output->data[output->position++] = count;
        output->data[output->position++] = current;
    }

    output->length = output->position;
}

void decompress(compression_buffer compressed, unsigned char *output) {
    unsigned int position = 0;
    unsigned char current = compressed.data[position++];
    unsigned int count = current;

    for (unsigned int i = 0; i < compressed.length; i++) {
        output[i] = current;

        if (count > 0) {
            for (unsigned int j = 0; j < count; j++) {
                output[i + j] = current;
            }
            count = compressed.data[position++];
        } else {
            current = compressed.data[position++];
        }
    }
}

int main() {
    unsigned char input[] = {0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03};
    unsigned int input_length = sizeof(input) / sizeof(input[0]);

    compression_buffer output;
    compress(input, input_length, &output);

    unsigned char output_buffer[output.length];
    decompress(output, output_buffer);

    for (unsigned int i = 0; i < output.length; i++) {
        printf("%02x", output_buffer[i]);
    }

    return 0;
}