//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
char *decToHex(int num) {
    // Initialize the output string with null character
    char *output = (char *)malloc(10 * sizeof(char));
    strcpy(output, "");

    // Calculate the hexadecimal value
    int hex = num & 0xF;

    // Convert hex to hex string
    char hex_str[10];
    sprintf(hex_str, "%02X", hex);

    // Append the hex string to the output string
    strcat(output, hex_str);

    return output;
}

// Function to convert hexadecimal to decimal
int hexToDec(char *hex) {
    // Convert hex string to decimal
    int dec = 0;
    int power = 1;
    for (int i = 0; i < strlen(hex); i++) {
        char ch = hex[i];
        if (ch >= '0' && ch <= '9') {
            dec += power * (ch - '0');
        } else if (ch >= 'A' && ch <= 'F') {
            dec += power * (ch - 'A' + 10);
        } else {
            dec += power * (ch - 'a' + 10);
        }
        power *= 16;
    }

    return dec;
}

int main() {
    // Convert decimal to hexadecimal
    int num = 0xDEADBEEF;
    char *hex_str = decToHex(num);
    printf("Decimal: %d\n", num);
    printf("Hexadecimal: %s\n", hex_str);

    // Convert hexadecimal to decimal
    char hex_str2[] = "DEADBEEF";
    int dec = hexToDec(hex_str2);
    printf("Hexadecimal: %s\n", hex_str2);
    printf("Decimal: %d\n", dec);

    return 0;
}