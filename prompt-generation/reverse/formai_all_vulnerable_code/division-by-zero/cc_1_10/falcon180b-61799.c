//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BITS 32

void print_binary(unsigned int num) {
    int i;
    for (i = MAX_NUM_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main(void) {
    srand(time(NULL));
    int num_bits = rand() % MAX_NUM_BITS + 1;
    unsigned int num = rand() % (1 << num_bits);

    printf("The number of bits is: %d\n", num_bits);
    printf("The binary representation of the number is: ");
    print_binary(num);
    printf("\n");

    int num_operations = rand() % 5 + 1;

    printf("Performing %d bitwise operations...\n", num_operations);

    unsigned int result = num;

    switch (num_operations) {
        case 1:
            // Bitwise AND operation
            result &= (1 << num_bits) - 1;
            printf("Bitwise AND operation performed.\n");
            break;
        case 2:
            // Bitwise OR operation
            result |= (1 << num_bits) - 1;
            printf("Bitwise OR operation performed.\n");
            break;
        case 3:
            // Bitwise XOR operation
            result ^= (1 << num_bits) - 1;
            printf("Bitwise XOR operation performed.\n");
            break;
        case 4:
            // Left shift operation
            result <<= num_bits;
            printf("Left shift operation performed.\n");
            break;
        case 5:
            // Right shift operation
            result >>= num_bits;
            printf("Right shift operation performed.\n");
            break;
    }

    printf("The result of the operations is: ");
    print_binary(result);
    printf("\n");

    return 0;
}