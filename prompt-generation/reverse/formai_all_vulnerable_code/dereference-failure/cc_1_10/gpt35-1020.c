//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to its corresponding hexadecimal value
char* decimalToHexadecimal(int decimalNum) {
    int quotient = decimalNum;
    int remainder;
    char* hexEquivalent = malloc(sizeof(char)*100); // Allocate memory space for the hexadecimal equivalent
    
    int index = 0;
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexEquivalent[index++] = 48 + remainder; // Add the ASCII value of 0 to the remainder
        } else {
            hexEquivalent[index++] = 55 + remainder; // Add the ASCII value of A to the remainder
        }
        quotient = quotient / 16;
    }
    hexEquivalent[index] = '\0';
    
    // Reverse the hexadecimal equivalent string
    int start = 0;
    int end = strlen(hexEquivalent) - 1;
    char temp;
    while (start < end) {
        temp = hexEquivalent[start];
        hexEquivalent[start++] = hexEquivalent[end];
        hexEquivalent[end--] = temp;
    }
    
    return hexEquivalent;
}

// Function to convert a hexadecimal number to its corresponding decimal value
int hexadecimalToDecimal(char* hexNum) {
    int length = strlen(hexNum);
    int power = 1;
    int decimalEquivalent = 0;
    
    for (int i = length - 1; i >= 0; i--) {
        if (hexNum[i] >= '0' && hexNum[i] <= '9') {
            decimalEquivalent += (hexNum[i] - '0') * power;
            power = power * 16;
        } else if (hexNum[i] >= 'A' && hexNum[i] <= 'F') {
            decimalEquivalent += (hexNum[i] - 55) * power;
            power = power * 16;
        }
    }
    
    return decimalEquivalent;
}

int main() {
    int choice;
    int num;
    char hexNum[100];

    while(1) {
        printf("Choose an option:\n");
        printf("1. Convert decimal to hexadecimal\n");
        printf("2. Convert hexadecimal to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                char* hex = decimalToHexadecimal(num);
                printf("The hexadecimal equivalent is: %s\n\n", hex);
                free(hex); // Free the memory allocated for the hexadecimal equivalent
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNum);
                int decimal = hexadecimalToDecimal(hexNum);
                printf("The decimal equivalent is: %d\n\n", decimal);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    
    return 0;
}