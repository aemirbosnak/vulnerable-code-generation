//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
// A Kaleidoscope of Hexadecimal Conversions

#include <stdio.h>
#include <stdlib.h>

// An Array of Colorful Characters
char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// Function to Convert an Integer to Hexadecimal
char* intToHex(int num) {
    // Allocate Memory for the Hexadecimal String
    char *hexString = malloc(sizeof(char) * 9);

    // Initialize the Index of the Hexadecimal String
    int index = 0;

    // Loop Until the Integer is Zero
    while (num != 0) {
        // Get the Last Digit of the Integer
        int digit = num % 16;

        // Convert the Digit to a Hexadecimal Character
        hexString[index++] = hexDigits[digit];

        // Divide the Integer by 16 to Remove the Last Digit
        num /= 16;
    }

    // Reverse the Hexadecimal String
    for (int i = 0; i < index / 2; i++) {
        char temp = hexString[i];
        hexString[i] = hexString[index - i - 1];
        hexString[index - i - 1] = temp;
    }

    // Add the Null-Terminator to the String
    hexString[index] = '\0';

    // Return the Hexadecimal String
    return hexString;
}

// Function to Convert a Hexadecimal String to an Integer
int hexToInt(char *hexString) {
    // Initialize the Integer to Zero
    int num = 0;

    // Loop Through the Hexadecimal String
    for (int i = 0; hexString[i] != '\0'; i++) {
        // Get the Current Character
        char ch = hexString[i];

        // Convert the Character to a Digit
        int digit;
        if (ch >= '0' && ch <= '9') {
            digit = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            digit = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            digit = ch - 'a' + 10;
        } else {
            // Invalid Hexadecimal Digit
            return -1;
        }

        // Shift the Integer Left by 4 Bits
        num <<= 4;

        // Add the Digit to the Integer
        num += digit;
    }

    // Return the Integer
    return num;
}

// Function to Print a Hexadecimal Grid
void printHexGrid(int numRows, int numCols) {
    // Loop Through the Rows
    for (int i = 0; i < numRows; i++) {
        // Loop Through the Columns
        for (int j = 0; j < numCols; j++) {
            // Convert the Row and Column to Hexadecimal
            char *hexRow = intToHex(i);
            char *hexCol = intToHex(j);

            // Print the Hexadecimal Cell
            printf("%s%s  ", hexRow, hexCol);

            // Free the Hexadecimal Strings
            free(hexRow);
            free(hexCol);
        }

        // Print a Newline
        printf("\n");
    }
}

// Main Function
int main(void) {
    // Convert an Integer to Hexadecimal
    int num = 12345;
    char *hexString = intToHex(num);
    printf("Integer %d in Hexadecimal: %s\n", num, hexString);

    // Convert a Hexadecimal String to an Integer
    char *hexString2 = "ABCD";
    int num2 = hexToInt(hexString2);
    printf("Hexadecimal String %s in Integer: %d\n", hexString2, num2);

    // Print a Hexadecimal Grid
    printHexGrid(16, 16);

    // Free the Memory Allocated for the Hexadecimal Strings
    free(hexString);

    return 0;
}