//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to store binary number information
typedef struct {
    int num_digits;    // Number of digits in the binary number
    int digits[32];   // Array to store the binary digits
} binary_t;

// Function to convert a decimal number to binary
binary_t* decode_decimal(int dec) {
    binary_t* bin = malloc(sizeof(binary_t));
    int i = 0;

    // While the number is not zero
    while (dec != 0) {
        // Divide the number by 2 and store the remainder in the array
        bin->digits[i++] = dec % 2;
        dec /= 2;
    }

    // Set the number of digits in the binary number
    bin->num_digits = i;

    return bin;
}

// Function to convert a binary number to decimal
int decode_binary(binary_t* bin) {
    int dec = 0;
    int i = 0;

    // While the number of digits in the binary number is not zero
    while (bin->num_digits > 0) {
        // Multiply the current digit by 2 and add it to the sum
        dec += (bin->digits[i++] << (bin->num_digits - i));
    }

    return dec;
}

int main() {
    int dec = 123;
    binary_t* bin = decode_decimal(dec);

    // Print the binary representation of the number
    printf("Binary: ");
    for (int i = 0; i < bin->num_digits; i++) {
        printf("%d", bin->digits[i]);
    }
    printf("\n");

    // Convert the binary number back to decimal
    int dec_result = decode_binary(bin);

    // Print the result
    printf("Decimal: %d\n", dec_result);

    // Free the memory allocated for the binary number
    free(bin);

    return 0;
}