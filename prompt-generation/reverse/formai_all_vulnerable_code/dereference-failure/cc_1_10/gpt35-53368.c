//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct bitstream {
    uint64_t bit_count;
    uint8_t *data;
    int pos;
} bitstream_t;

void write_bit(bitstream_t *stream, int bit) {
    uint64_t byte_pos = stream->bit_count >> 3;
    uint8_t bit_pos = 7 - (stream->bit_count & 7);
    stream->bit_count++;

    if (stream->pos <= byte_pos) {
        stream->pos = byte_pos + 1;
        stream->data = (uint8_t*) realloc(stream->data, stream->pos);
    }

    stream->data[byte_pos] |= (bit << bit_pos);
}

void write_bits(bitstream_t *stream, uint32_t bits, uint8_t num_bits) {
    for (int i = 0; i < num_bits; i++) {
        write_bit(stream, bits & 1);
        bits >>= 1;
    }
}

void compress(const uint8_t *data, uint64_t data_len, bitstream_t *compressed_data) {
    int num_bits = 0;
    uint32_t code = 0;
    uint32_t max_code = (1 << 12) - 1;
    uint32_t *table = (uint32_t*) malloc((1 << 17) * sizeof(uint32_t));

    for (uint32_t i = 0; i <= max_code; i++) {
        table[i] = i;
    }

    for (uint64_t i = 0; i < data_len; i++) {
        uint8_t symbol = data[i];

        uint32_t next_code = (code << 8) | symbol;

        if (table[next_code] != 0) {
            code = table[next_code];
        } else {
            write_bits(compressed_data, code, num_bits);
            table[next_code] = ++max_code;

            if (max_code >= (1 << num_bits)) {
                num_bits++;
                max_code = (1 << num_bits) - 1;
            }

            code = symbol;
        }
    }

    write_bits(compressed_data, code, num_bits);
    free(table);
}

int main() {
    const uint8_t data[] = "abbabbabba";
    uint64_t data_len = sizeof(data) - 1;
    bitstream_t compressed_data = { 0, NULL, 0 };

    compress(data, data_len, &compressed_data);

    printf("Original size: %lu bits\n", 8 * data_len);
    printf("Compressed size: %lu bits\n", compressed_data.bit_count);

    free(compressed_data.data);

    return 0;
}