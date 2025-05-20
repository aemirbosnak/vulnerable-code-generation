//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char data;
    unsigned char count;
} RLE_PACKET;

void compress(unsigned char *input, unsigned int input_len, unsigned char *output) {
    unsigned int i = 0;
    RLE_PACKET *packet = malloc(input_len * sizeof(RLE_PACKET));

    while (i < input_len) {
        unsigned int j = i + 1;
        if (j < input_len && input[i] == input[j]) {
            packet[i].count++;
            i++;
        } else {
            packet[i].data = input[i];
            if (i > 0 && packet[i-1].data == packet[i].data) {
                packet[i].count += packet[i-1].count;
            } else {
                packet[i].count = 1;
            }
            i++;
        }
    }

    unsigned int packet_index = 0;
    for (unsigned int k = 0; k < input_len; k++) {
        if (packet[packet_index].count > 1) {
            output[k] = packet[packet_index].data;
            unsigned char count_bytes = (packet[packet_index].count >> 1) + 1;
            for (unsigned int l = 0; l < count_bytes; l++) {
                output[k + 1 + l] = packet[packet_index].count & 0xFF;
                k++;
                if (++packet_index >= input_len) break;
            }
        } else {
            output[k] = packet[packet_index].data;
            packet_index++;
        }
    }

    free(packet);
}

void decompress(unsigned char *input, unsigned int input_len, unsigned char *output) {
    unsigned int i = 0;

    while (i < input_len) {
        if (input[i] >= 0x80) {
            unsigned char data = input[i] & 0x7F;
            unsigned char count = 0;
            while (input[i + 1] < 0x80) {
                count = (count << 7) | input[i + 1];
                i++;
            }
            i++;

            while (count--) {
                output[i++] = data;
            }
        } else {
            output[i] = input[i];
            i++;
        }
    }
}

int main(void) {
    unsigned char input[] = {0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAB, 0xAB, 0xAB, 0xAB};
    unsigned char output[32] = {0};

    compress(input, sizeof(input), output);

    unsigned char decompressed[sizeof(input)] = {0};
    decompress(output, sizeof(output), decompressed);

    for (unsigned int i = 0; i < sizeof(input); i++) {
        if (input[i] != decompressed[i]) {
            printf("Error at index %d\n", i);
            return 1;
        }
    }

    printf("Compression and decompression successful!\n");

    return 0;
}