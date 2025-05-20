//FormAI DATASET v1.0 Category: QR code reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef struct 
{
    char* data;
    int length;
} QRCode;

bool isQRCodeValid(QRCode* qrCode)
{
    // check if the QR code has at least one character
    if (qrCode->length <= 0)
    {
        return false;
    }

    // check if the first two characters are "QR"
    if (qrCode->data[0] != 'Q' || qrCode->data[1] != 'R')
    {
        return false;
    }

    // check if the last two characters are "END"
    if (qrCode->data[qrCode->length - 2] != 'E' || qrCode->data[qrCode->length - 1] != 'N' || qrCode->data[qrCode->length - 3] != 'D')
    {
        return false;
    }

    // QR code is valid
    return true;
}

QRCode* readQRCodeFromFile(char* filename)
{
    // open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // read the contents of the file into a buffer
    char buffer[MAX_BUFFER_SIZE] = {0};
    int bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, file);
    if (bytes_read == 0)
    {
        printf("Error reading file %s\n", filename);
        fclose(file);
        return NULL;
    }

    // create a new QRCode object and copy the buffer data into it
    QRCode* qrCode = malloc(sizeof(QRCode));
    qrCode->data = malloc(sizeof(char) * (bytes_read + 1));
    memcpy(qrCode->data, buffer, bytes_read);
    qrCode->length = bytes_read;

    // close the file and return the QR code object
    fclose(file);
    return qrCode;
}

void printQRCode(QRCode* qrCode)
{
    printf("%s\n", qrCode->data);
}

int main()
{
    // read the QR code from a file
    QRCode* qrCode = readQRCodeFromFile("qrcode.txt");

    // check if the QR code is valid
    if (!isQRCodeValid(qrCode))
    {
        printf("Invalid QR code\n");
        free(qrCode->data);
        free(qrCode);
        return 1;
    }

    // print the QR code
    printQRCode(qrCode);

    // free the memory allocated for the QR code
    free(qrCode->data);
    free(qrCode);

    return 0;
}