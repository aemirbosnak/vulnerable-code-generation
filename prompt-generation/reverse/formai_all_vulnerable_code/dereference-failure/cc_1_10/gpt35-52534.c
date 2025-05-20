//FormAI DATASET v1.0 Category: QR code generator ; Style: secure
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

const uint8_t VERSION = 1; // QR code version
const uint8_t QR_SIZE = 21; // QR code size
static uint8_t qr_code[21][21]; // QR code array

/* Function to print the QR code */
static void print_qr_code()
{
    for(int i = 0; i < QR_SIZE; i++)
    {
        for(int j = 0; j < QR_SIZE; j++)
        {
            if(qr_code[i][j])
            {
                printf("█");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Function to generate QR code */
static void generate_qr_code(const char* data)
{
    uint8_t* ptr = (uint8_t*)data;
    int length = strlen(data);

    // Add version and length to QR code
    qr_code[0][0] = VERSION;
    qr_code[0][1] = length;

    // Add data to QR code
    for (int i = 0; i < length; i++)
    {
        uint8_t byte = *(ptr++);
        for (int j = 0; j < 8; j++)
        {
            uint8_t bit = (byte & (1 << (7 - j))) != 0;
            int x, y;

            // Choose the appropriate coordinate for each bit
            if (i % 2 == 0) {
                // Even row (goes right -> left)
                x = QR_SIZE - 2 - (i / 2);
            } else {
                // Odd row (goes left -> right)
                x = 1 + (i / 2);
            }

            if (j < 6) {
                // Main area of QR code
                y = 4 + j;
            } else if (j == 6) {
                // Separator bar
                y = 3;
            } else {
                // Quiet zone
                y = QR_SIZE - 4;
            }

            qr_code[x][y] = bit;
        }
    }

    // Add quiet zone
    for(int i = 0; i < QR_SIZE; i++)
    {
        for(int j = 0; j < QR_SIZE; j++)
        {
            if(i < 4 || i >= QR_SIZE - 4 || j < 4 || j >= QR_SIZE - 4)
            {
                qr_code[i][j] = 0;
            }
        }
    }
}

/* Main function */
int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage: %s <data>\n", argv[0]);
        return 1;
    }

    const char* data = argv[1];
    generate_qr_code(data);
    print_qr_code();

    return 0;
}