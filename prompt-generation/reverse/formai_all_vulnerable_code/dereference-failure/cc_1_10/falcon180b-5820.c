//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1000000

typedef struct {
    uint8_t *data;
    size_t size;
} BitBuffer;

BitBuffer *create_bit_buffer() {
    BitBuffer *buffer = (BitBuffer *) malloc(sizeof(BitBuffer));
    buffer->data = (uint8_t *) malloc(MAX_SIZE);
    buffer->size = 0;
    return buffer;
}

void destroy_bit_buffer(BitBuffer *buffer) {
    free(buffer->data);
    free(buffer);
}

void write_bit(BitBuffer *buffer, int bit) {
    if (buffer->size == MAX_SIZE) {
        fprintf(stderr, "Buffer overflow\n");
        exit(1);
    }
    uint8_t mask = 1 << (7 - buffer->size % 8);
    buffer->data[buffer->size / 8] |= mask;
    buffer->size++;
}

int read_bit(BitBuffer *buffer) {
    if (buffer->size == 0) {
        fprintf(stderr, "Buffer underflow\n");
        exit(1);
    }
    int bit = (buffer->data[buffer->size / 8] >> (7 - buffer->size % 8)) & 1;
    buffer->size--;
    return bit;
}

void write_byte(BitBuffer *buffer, uint8_t byte) {
    for (int i = 0; i < 8; i++) {
        write_bit(buffer, (byte >> i) & 1);
    }
}

uint8_t read_byte(BitBuffer *buffer) {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++) {
        byte |= (read_bit(buffer) << i);
    }
    return byte;
}

int main() {
    BitBuffer *buffer = create_bit_buffer();
    write_byte(buffer, 0xAA);
    write_byte(buffer, 0xBB);
    write_byte(buffer, 0xCC);
    write_byte(buffer, 0xDD);
    write_byte(buffer, 0xEE);
    write_byte(buffer, 0xFF);
    write_byte(buffer, 0x00);

    int bit;
    while ((bit = read_bit(buffer))!= -1) {
        printf("%d", bit);
    }

    destroy_bit_buffer(buffer);
    return 0;
}