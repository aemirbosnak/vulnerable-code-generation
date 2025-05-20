//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CHECKSUM_SIZE 4

typedef struct {
    uint8_t magic[2];
    uint16_t length;
    uint8_t data[1];
} packet_t;

uint32_t checksum(const void *data, size_t length) {
    uint8_t *buf = (uint8_t *) data;
    uint32_t sum = 0xFFFF;

    for (size_t i = 0; i < length; i++) {
        sum += buf[i];
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum = sum & 0xFFFF;

    return sum;
}

void print_packet(const packet_t *packet) {
    printf("|%02X %02X| %04X|", packet->magic[0], packet->magic[1], packet->length);

    size_t data_len = packet->length - sizeof(packet_t);
    for (size_t i = 0; i < data_len; i++) {
        printf(" %02X", packet->data[i]);
    }

    uint32_t csum = checksum(packet, sizeof(packet_t) + data_len);
    printf("| %04X|", csum);

    puts("");
}

int main() {
    const char *msg = "Hello, World!";
    size_t msg_len = strlen(msg) + 1;

    packet_t packet = { { 'M', 'P' }, (uint16_t)(sizeof(packet_t) + msg_len), {} };

    memcpy(packet.data, msg, msg_len);

    print_packet(&packet);

    return 0;
}