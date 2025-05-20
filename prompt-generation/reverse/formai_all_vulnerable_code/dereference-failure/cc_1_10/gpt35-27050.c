//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal to binary */
void decimalToBinary(int decimalNum) {
    int binaryArr[32];
    int i = 0;
  
    while (decimalNum > 0) {
        binaryArr[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }
  
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryArr[j]);
}

/* Function to convert binary to decimal */
int binaryToDecimal(char binaryNum[]) {
    int len = strlen(binaryNum);
    int power = 1;
    int decimalNum = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (binaryNum[i] == '1')
            decimalNum += power;
        
        power = power * 2;
    }

    return decimalNum;
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <d|b> <number>\n", argv[0]);
        return 0;
    }

    char *type = argv[1];
    char *numberStr = argv[2];
  
    if (strcmp(type, "d") == 0) {
        int decimalNum = atoi(numberStr);
        decimalToBinary(decimalNum);
    } else if (strcmp(type, "b") == 0) {
        int decimalNum = binaryToDecimal(numberStr);
        printf("Decimal: %d\n", decimalNum);
    } else {
        printf("Invalid type '%s' (use 'd' for decimal or 'b' for binary)\n", type);
        return 0;
    }

    return 0;
}