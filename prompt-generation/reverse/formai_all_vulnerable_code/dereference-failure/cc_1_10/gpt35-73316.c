//FormAI DATASET v1.0 Category: QR code generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[])
{
    // Check if arguments are at least 2
    if (argc < 2)
    {
        printf("Usage: %s string-to-convert\n", argv[0]);
        return -1;
    }

    // Generate QR Code for given string
    QRcode *qr;
    int version = 1;    // QR Code version number (1-40)
    int level = QR_ECLEVEL_H;    // Error correction level
    qr = QRcode_encodeString(argv[1], version, level, QR_MODE_8, 1);

    // Check if QR code is successfully generated
    if (qr == NULL)
    {
        printf("QR Code generation failed!\n");
        return -1;
    }

    // Print QR code in ASCII format
    int width = qr->width;
    unsigned char *data = qr->data;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int index = i * width + j;
            if (data[index] & 0x01)
            {
                printf("  ");
            }
            else
            {
                printf("##");
            }
        }
        printf("\n");
    }

    // Free memory used by QR code
    QRcode_free(qr);

    return 0;
}