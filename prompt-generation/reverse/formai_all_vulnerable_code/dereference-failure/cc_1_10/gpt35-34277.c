//FormAI DATASET v1.0 Category: QR code reader ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a string is a valid QR code
int isValidQR(char *str)
{
    // Simplistic validation - checking if the string contains 'QRCODE'
    if (strstr(str, "QRCODE") != NULL)
        return 1;
    else
        return 0;
}

// Function to extract data from the QR code
char* extractData(char *str)
{
    // Assuming the data is always between 'QRCODE:' and ';'
    char *start = strstr(str, "QRCODE:");
    char *end = strstr(str, ";");
    if (start == NULL || end == NULL)
        return NULL;

    // Allocating memory for the extracted data
    int size = end - start - strlen("QRCODE:");
    char *data = (char*) malloc(sizeof(char) * (size + 1));
    strncpy(data, start + strlen("QRCODE:"), size);
    data[size] = '\0';

    return data;
}

int main()
{
    // Input QR code
    char qrCode[100];

    printf("Enter the QR code: ");
    scanf("%99s", qrCode);

    // Checking if the QR code is valid
    if (!isValidQR(qrCode))
    {
        printf("Invalid QR code!");
        return 0;
    }

    // Extracting data from the QR code
    char *data = extractData(qrCode);
    if (data == NULL)
    {
        printf("Error in extracting data from QR code!");
        return 0;
    }

    printf("The extracted data from QR code is: %s", data);

    // Freeing the memory allocated for data
    free(data);

    return 0;
}