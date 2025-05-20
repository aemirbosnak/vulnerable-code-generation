//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    unsigned char byte_1;
    unsigned char byte_2;
    unsigned char byte_3;
    unsigned char byte_4;
    unsigned char byte_5;
    unsigned char byte_6;
    unsigned char byte_7;
    unsigned char byte_8;
} byte_array;

void calculate_checksum(const byte_array *array, unsigned char *sum) {
    int i;
    for (i = 0; i < 8; i++) {
        *sum ^= array->byte_8 - i;
        array++;
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    byte_array message;
    unsigned char checksum;

    printf("Enter message in ancient script:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Convert ancient script to binary
    int i, j, k;
    for (i = 0, j = 0; i < strlen(input); i++, j += 8) {
        message.byte_8 = 0;
        for (k = 0; k < 7; k++) {
            if (input[i] == '1')
                message.byte_8 |= (1 << k);
            else if (input[i] != '0') {
                printf("Invalid character: %c\n", input[i]);
                return 1;
            }
        }
        calculate_checksum(&message, &checksum);
        if (j < strlen(input) * 8 - 1) {
            message.byte_8 = input[i] == '.' ? 0x00 : 0xFF;
            calculate_checksum(&message, &checksum);
        }
    }

    printf("Message checksum: 0x%02X\n", checksum);

    return 0;
}