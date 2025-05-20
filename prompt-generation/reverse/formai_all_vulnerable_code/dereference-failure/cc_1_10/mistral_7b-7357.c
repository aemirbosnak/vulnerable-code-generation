//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>

#define CHECKSUM_SIZE 2

uint16_t calc_checksum(uint16_t sum, const void *buf, size_t len) {
    const uint8_t *data = buf;
    size_t remain = len;

    while (remain) {
        sum += *data++;
        remain -= sizeof(uint8_t);

        if (remain && (len & 1)) {
            sum = (sum >> 8) + (sum & 0xff);
        }
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum = sum & 0xffff;

    return sum;
}

int main(int argc, char *argv[]) {
    const char *input;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    input = argv[1];

    size_t len = strlen(input);
    uint8_t *buffer = malloc(len + CHECKSUM_SIZE);

    memcpy(buffer, input, len);
    uint16_t sum = htons(0xFFFF);

    sum = calc_checksum(sum, buffer, len + CHECKSUM_SIZE);
    memcpy(buffer + len, &sum, CHECKSUM_SIZE);

    printf("Input string: %s\n", input);
    printf("Checksum: ");
    for (size_t i = 0; i < CHECKSUM_SIZE; ++i) {
        putchar(buffer[len + i]);
    }
    putchar('\n');

    free(buffer);

    return EXIT_SUCCESS;
}