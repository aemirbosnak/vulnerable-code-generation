//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Convert a decimal number to hexadecimal */
void decToHex(unsigned int decimal, int bits, char* hex) {
    
    /* Create an array to store HEX values */
    char hexTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    /* Initialize the HEX string with 0 */
    memset(hex, '0', bits / 4);
    hex[bits / 4] = '\0';
    
    /* Decimal to HEX conversion */
    int idx = bits / 4 - 1;
    while(decimal > 0 && idx >= 0) {
        int rem = decimal % 16;
        hex[idx] = hexTable[rem];
        decimal /= 16;
        idx--;
    }
}

int main() {
    
    printf("Enter a decimal number: ");
    unsigned int decimal = 0;
    scanf("%u", &decimal);
    
    printf("Enter the number of bits in the output HEX string: ");
    int bits = 0;
    scanf("%d", &bits);
    
    /* Check if the number of bits is valid */
    if(bits % 4 != 0) {
        printf("The number of bits should be a multiple of 4.\n");
        exit(1);
    }
    
    /* Convert decimal to HEX */
    char *hex = (char*)malloc(sizeof(char) * (bits / 4 + 1));
    decToHex(decimal, bits, hex);
    
    printf("The hexadecimal representation of %u is %s.\n", decimal, hex);
    
    /* Free memory */
    free(hex);
    
    return 0;
}