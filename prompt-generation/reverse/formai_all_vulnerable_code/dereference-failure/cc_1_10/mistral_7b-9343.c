//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char data;
    int count;
} RLE_DATA;

void compress(unsigned char *input, unsigned char *output, int size) {
    RLE_DATA *rle_data = malloc(size * sizeof(RLE_DATA));
    int index = 0;
    int i = 0;

    while (i < size) {
        if (index > 0 && rle_data[index - 1].data == input[i]) {
            rle_data[index - 1].count++;
        } else {
            if (index > 0) {
                output[i] = (unsigned char)(rle_data[index - 1].count >> 1);
                i++;
                output[i] = rle_data[index - 1].data;
                index--;
                rle_data[index].data = input[i];
                rle_data[index].count = 1;
            } else {
                rle_data[index].data = input[i];
                rle_data[index].count = 1;
                index++;
            }
        }
        i++;
    }

    int compressed_size = index * sizeof(RLE_DATA);
    for (int j = 0; j < compressed_size; j++) {
        output[i] = (unsigned char)(rle_data[j].count >> 4);
        output[i + 1] = (unsigned char)(rle_data[j].count & 0xF);
        output[i + 2] = rle_data[j].data;
        i += 3;
    }

    free(rle_data);
}

void decompress(unsigned char *input, unsigned char *output, int size) {
    int index = 0;
    int i = 0;

    while (i < size) {
        unsigned char count_high = input[i++];
        unsigned char count_low = input[i++];
        unsigned char data = input[i++];

        for (int j = 0; j < (count_high << 4 | count_low); j++) {
            output[index++] = data;
        }
    }
}

int main() {
    unsigned char input[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03 };
    unsigned char output[25];
    int size = sizeof(input) / sizeof(input[0]);

    compress(input, output, size);

    printf("Compressed size: %d\n", (int)(sizeof(output) / sizeof(output[0])));

    decompress(output, input, sizeof(output) / sizeof(output[0]));

    printf("Decompressed data:\n");
    for (int i = 0; i < size; i++) {
        printf("%02X ", input[i]);
    }
    printf("\n");

    return 0;
}