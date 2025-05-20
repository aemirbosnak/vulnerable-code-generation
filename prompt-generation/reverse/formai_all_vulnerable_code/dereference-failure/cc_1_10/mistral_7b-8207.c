//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <sys/random.h>

#define MAX_BINARY_SIZE 64
#define MAX_HEX_SIZE 17
#define MAX_DEC_SIZE 22

// Secure random number generator using /dev/urandom
uint32_t get_random_number(void) {
    uint32_t num;
    if (getrandom(&num, sizeof(num), 0) < 0) {
        perror("getrandom() failed");
        exit(EXIT_FAILURE);
    }
    return num;
}

// Convert binary to decimal
uint32_t binary_to_decimal(const char *binary) {
    uint32_t decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; ++i) {
        if (binary[i] < '0' || binary[i] > '1') {
            fprintf(stderr, "Invalid binary number: %s\n", binary);
            exit(EXIT_FAILURE);
        }
        int power = length - i - 1;
        decimal += (binary[i] - '0') * pow(2, power);
    }
    return decimal;
}

// Convert binary to hexadecimal
void binary_to_hex(const char *binary, char *hex) {
    int length = strlen(binary);
    for (int i = 0; i < length; i += 2) {
        int num = binary[i] - '0';
        num *= 16;
        num += binary[i+1] - '0';
        if (binary[i] > '9') num += (binary[i] - 'A' + 10);
        if (binary[i+1] > '9') num += (binary[i+1] - 'A' + 10);
        sprintf(hex + i/2 * 2, "%02x", num);
    }
    hex[length/2 * 3] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    bool valid_binary = true;
    char binary[MAX_BINARY_SIZE + 1];
    strcpy(binary, argv[1]);
    for (int i = 0; i < strlen(binary); ++i) {
        if (binary[i] < '0' || binary[i] > '1') {
            fprintf(stderr, "Invalid binary number: %s\n", argv[1]);
            valid_binary = false;
            break;
        }
    }

    if (!valid_binary) {
        exit(EXIT_FAILURE);
    }

    // Generate random seed for random number generator
    srandom(get_random_number());

    char hex[MAX_HEX_SIZE + 1];
    char dec_str[MAX_DEC_SIZE + 1];

    binary_to_hex(binary, hex);
    printf("Hexadecimal representation: %s\n", hex);

    uint32_t decimal = binary_to_decimal(binary);
    sprintf(dec_str, "%d", decimal);
    printf("Decimal representation: %s\n", dec_str);

    return EXIT_SUCCESS;
}