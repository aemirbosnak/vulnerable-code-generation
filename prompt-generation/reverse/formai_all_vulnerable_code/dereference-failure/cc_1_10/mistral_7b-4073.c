//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    unsigned char data;
    int count;
} RLE_Compressed_Data;

int compress(unsigned char *input, size_t input_len, unsigned char *output) {
    size_t current_index = 0;
    RLE_Compressed_Data *rle_data = calloc(input_len, sizeof(RLE_Compressed_Data));

    if (!rle_data) {
        free(output);
        return 1;
    }

    int index = 0;
    for (; index < input_len - 1; index++) {
        if (input[index] == input[index + 1]) {
            rle_data[index].count++;
        } else {
            rle_data[index].data = input[index];
            if (index != current_index) {
                output[current_index++] = (unsigned char)(rle_data[index].data);
                if (rle_data[index].count > 1) {
                    output[current_index++] = (unsigned char)(rle_data[index].count & 0xFF);
                    output[current_index++] = (unsigned char)((rle_data[index].count >> 8) & 0xFF);
                }
            }
        }
    }

    output[current_index++] = (unsigned char)(rle_data[index].data);
    if (index != current_index - 1 && rle_data[index].count > 1) {
        output[current_index++] = (unsigned char)(rle_data[index].count & 0xFF);
        output[current_index++] = (unsigned char)((rle_data[index].count >> 8) & 0xFF);
    }

    free(rle_data);

    return current_index;
}

int main() {
    unsigned char input[MAX_BUFFER_SIZE] = {0};
    unsigned char compressed_output[MAX_BUFFER_SIZE] = {0};
    size_t input_len = 0;

    printf("Enter the data to compress (Ctrl+D to finish):\n");
    while ((input_len < MAX_BUFFER_SIZE) && (getchar() != EOF)) {
        input[input_len++] = (unsigned char)getchar();
    }

    if (compress(input, input_len, compressed_output)) {
        printf("Compression failed.\n");
        return 1;
    }

    printf("Compressed data size: %ld bytes.\n", (long)compress(input, input_len, compressed_output));
    printf("Compressed data:\n");
    for (size_t i = 0; i < compress(input, input_len, compressed_output); i++) {
        printf("%02X ", compressed_output[i]);
    }
    printf("\n");

    return 0;
}