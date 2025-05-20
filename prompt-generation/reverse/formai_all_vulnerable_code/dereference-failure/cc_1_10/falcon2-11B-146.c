//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// This function converts a byte array to a string
char* byteArrayToString(unsigned char *byteArray, int length)
{
    char* string = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        sprintf(&string[i], "%02X", byteArray[i]);
    }
    return string;
}

// This function converts a string to a byte array
unsigned char* stringToByteArray(char* str)
{
    unsigned char* byteArray = (unsigned char*) malloc(strlen(str) * sizeof(char));
    for (int i = 0; i < strlen(str); i++)
    {
        byteArray[i] = str[i] - '0';
    }
    return byteArray;
}

// This function generates a QR code from a byte array
void generateQRCode(unsigned char* byteArray, int byteLength)
{
    int numRows = (byteLength + 7) / 8;
    int numCols = (byteLength + 7) / 8;
    char* matrix = (char*) malloc(numRows * numCols * sizeof(char));
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            int index = i * numCols + j;
            int mask = 1 << (7 - (byteLength - index));
            matrix[index] = byteArray[index] & mask? 'X' : '.';
        }
    }
    printf("QR Code:\n");
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            printf("%c", matrix[i * numCols + j]);
        }
        printf("\n");
    }
    free(matrix);
}

int main()
{
    unsigned char byteArray[] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF };
    int byteLength = 8;
    char* str = byteArrayToString(byteArray, byteLength);
    printf("Byte Array: %s\n", str);
    free(str);
    str = stringToByteArray(str);
    generateQRCode(str, byteLength);
    free(str);
    return 0;
}