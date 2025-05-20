//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to convert decimal to hexadecimal
void dec_to_hex(char* dec, char* hex) {
    int i = strlen(dec) - 1;
    hex[i] = '\0';
    while (i >= 0) {
        int digit = dec[i] - '0';
        hex[i] = (digit < 10)? digit + '0' : digit + 'A' - 10;
        i--;
    }
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char* hex) {
    int dec = 0;
    int i = strlen(hex) - 1;
    while (i >= 0) {
        int digit = hex[i];
        if (digit >= '0' && digit <= '9') {
            dec += digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            dec += digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            dec += digit - 'a' + 10;
        }
        i--;
    }
    return dec;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <decimal_number> <hexadecimal_number>\n", argv[0]);
        return 1;
    }

    char dec[MAX_SIZE];
    char hex[MAX_SIZE];

    // Convert decimal to hexadecimal
    strcpy(dec, argv[1]);
    dec_to_hex(dec, hex);
    printf("Hexadecimal representation: %s\n", hex);

    // Convert hexadecimal to decimal
    int dec_num = hex_to_dec(hex);
    printf("Decimal representation: %d\n", dec_num);

    return 0;
}