//FormAI DATASET v1.0 Category: QR code generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrencode.h"

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Error: Invalid format. Please enter text and output filename.\n");
        return 0;
    }

    char* data = argv[1];
    char* filename = argv[2];
    FILE* fp = fopen(filename, "wb");

    if(fp == NULL)
    {
        printf("Error: Could not open file.\n");
        return 0;
    }

    // Configuring QR code encoding
    QRcode* qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    int size = qr->width;
    unsigned char* buffer = qr->data;

    // Generating QR code
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(buffer[i*size+j] & 1)
            {
                fprintf(fp, "##");
            }
            else
            {
                fprintf(fp, "  ");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    QRcode_free(qr);
    printf("QR code generated successfully!\n");

    return 0;
}