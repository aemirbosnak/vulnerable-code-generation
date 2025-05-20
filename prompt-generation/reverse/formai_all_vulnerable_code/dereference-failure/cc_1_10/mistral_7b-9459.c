//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct binary_conversion {
    uint8_t byte_1;
    uint8_t byte_2;
    uint8_t byte_3;
    uint8_t byte_4;
} binary_t;

void dec_to_bin(uint8_t dec_num, uint8_t* bin_num) {
    int i;
    for (i = 7; i >= 0; i--) {
        bin_num[i] = dec_num % 2;
        dec_num /= 2;
    }
}

void print_binary(binary_t bin) {
    uint8_t bin_num[4];
    int i;

    dec_to_bin(bin.byte_1, bin_num);
    for (i = 0; i < 8; i++)
        printf("%d", bin_num[i]);

    printf(" ");

    dec_to_bin(bin.byte_2, bin_num);
    for (i = 0; i < 8; i++)
        printf("%d", bin_num[i]);

    printf(" ");

    dec_to_bin(bin.byte_3, bin_num);
    for (i = 0; i < 8; i++)
        printf("%d", bin_num[i]);

    printf(" ");

    dec_to_bin(bin.byte_4, bin_num);
    for (i = 0; i < 8; i++)
        printf("%d", bin_num[i]);

    printf(" Yearrgh!\n");
}

int main(void) {
    binary_t my_binary = { 0x0A, 0x1B, 0x2C, 0x3D };

    printf("The binary representation of this decimal number is:\n");
    print_binary(my_binary);

    return 0;
}