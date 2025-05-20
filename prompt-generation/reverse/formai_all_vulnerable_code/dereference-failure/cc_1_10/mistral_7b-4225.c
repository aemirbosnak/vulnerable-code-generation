//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char data[256];
    unsigned short sum;
} checksum_t;

void calc_checksum(checksum_t *cs, const char *str, size_t len) {
    cs->sum = 0;
    for (size_t i = 0; i < len; i++) {
        cs->data[i] = str[i];
        cs->sum += cs->data[i];
    }

    for (size_t i = 0; i < 256; i++) {
        unsigned short temp = cs->sum;
        cs->sum = (cs->sum & 0xFF) + (cs->sum >> 8);
        cs->sum += temp;
        cs->data[i + 256] = cs->sum;
        cs->sum = (cs->sum & 0xFF) + (cs->sum >> 8);
    }
}

void print_checksum(const checksum_t *cs) {
    printf("Checksum: 0x%04X\n", cs->sum);
    printf("Data:    ");
    for (size_t i = 0; i < 256; i++) {
        printf("%02X ", cs->data[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    char input[1024];

    printf("Enter text to calculate checksum for: ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 1023) len = 1023;

    checksum_t cs;
    calc_checksum(&cs, input, len);
    print_checksum(&cs);

    return 0;
}

// Sherlock Holmes would say:
// "It is a simple matter of mathematics and logic, Watson.
// We shall calculate the checksum of the given text and compare it to the expected value.
// The discrepancy, if any, will lead us to the truth."