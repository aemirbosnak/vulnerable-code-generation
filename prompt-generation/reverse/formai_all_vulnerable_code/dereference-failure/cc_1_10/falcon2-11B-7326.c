//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Function to convert binary to hexadecimal
char *binaryToHex(const char *binary, int length) {
    char *hexadecimal = (char *)malloc(length * 2 + 1);
    int i, j;
    for (i = 0; i < length; i += 4) {
        sprintf(&hexadecimal[i * 2], "%02X", (unsigned int)(binary[i] << 24 | binary[i + 1] << 16 | binary[i + 2] << 8 | binary[i + 3]));
    }
    return hexadecimal;
}

// Function to convert hexadecimal to binary
char *hexToBinary(const char *hexadecimal, int length) {
    char *binary = (char *)malloc(length * 2 + 1);
    int i, j;
    for (i = 0; i < length; i += 2) {
        sprintf(&binary[i * 2], "%c%c", hexadecimal[i] == '0'? '0' : '1', hexadecimal[i + 1] == '0'? '0' : '1');
    }
    return binary;
}

// Main function
int main() {
    char binary[] = "10010101";
    int binaryLength = strlen(binary);
    char hexadecimal[binaryLength * 2 + 1];
    char binaryConverted[binaryLength * 2 + 1];
    char hexConverted[binaryLength * 2 + 1];

    // Convert binary to hexadecimal
    binaryToHex(binary, binaryLength);

    // Convert hexadecimal to binary
    hexToBinary(hexadecimal, binaryLength * 2);

    // Print the results
    printf("Binary: %s\n", binary);
    printf("Hexadecimal: %s\n", hexadecimal);
    printf("Binary converted from hexadecimal: %s\n", binaryConverted);
    printf("Hexadecimal converted from binary: %s\n", hexConverted);

    // Free memory
    free(hexadecimal);
    free(binaryConverted);
    free(hexConverted);

    return 0;
}