//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    unsigned char data;
    int count;
} RLE_Compressed_Data;

void compress(const unsigned char *input, size_t input_length, RLE_Compressed_Data **output) {
    size_t i = 0;
    RLE_Compressed_Data *compressed_data = NULL;
    RLE_Compressed_Data *current_entry = NULL;

    *output = malloc(sizeof(RLE_Compressed_Data));
    current_entry = *output;

    while (i < input_length) {
        if (!current_entry || current_entry->data != input[i]) {
            if (current_entry) {
                current_entry->count = i - (sizeof(RLE_Compressed_Data) + (current_entry->count * sizeof(int)));
                current_entry = realloc(current_entry, sizeof(RLE_Compressed_Data) + current_entry->count * sizeof(int));
            }

            current_entry->data = input[i];
            current_entry->count = 1;
            i++;
        } else {
            current_entry->count++;
            i++;
        }
    }

    if (current_entry) {
        current_entry->count = i - (sizeof(RLE_Compressed_Data) + (current_entry->count * sizeof(int)));
    }

    *output = realloc(*output, (sizeof(RLE_Compressed_Data) + (current_entry->count * sizeof(int))) + sizeof(RLE_Compressed_Data));
    (*output)[current_entry->count + 1].data = '\0';
}

void decompress(const RLE_Compressed_Data *input, unsigned char *output) {
    size_t i = 0;
    while (input[i].data != '\0') {
        memset(output, input[i].data, input[i].count);
        output += input[i].count;
        i++;
    }
}

int main() {
    unsigned char input[] = { 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xBB, 0xBB, 0xBB, 0xCC, 0xCC, 0xCC, 0xCC };
    size_t input_length = sizeof(input) / sizeof(unsigned char);

    RLE_Compressed_Data *compressed_data = NULL;
    compress(input, input_length, &compressed_data);

    unsigned char output[input_length];
    decompress(compressed_data, output);

    size_t i;
    for (i = 0; i < input_length; i++) {
        printf("%02X ", output[i]);
    }

    free(compressed_data);

    return 0;
}