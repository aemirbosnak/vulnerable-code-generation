//FormAI DATASET v1.0 Category: QR code generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function declarations
void generateQRCode(int *qrCode, int size);
void printQRCode(int *qrCode, int size);

int main()
{
    //seed the random number generator
    srand(time(NULL));

    //define the size of the QR code
    int size = 25;

    //create an array for the QR code
    int *qrCode = (int*)malloc(size * sizeof(int));

    //generate the QR code
    generateQRCode(qrCode, size);

    //print the QR code
    printQRCode(qrCode, size);

    //free memory
    free(qrCode);

    return 0;
}

//function to generate the QR code
void generateQRCode(int *qrCode, int size)
{
    int i;

    //populate the QR code with random values (0 or 1)
    for(i = 0; i < size; i++)
    {
        qrCode[i] = rand() % 2;
    }
}

//function to print the QR code
void printQRCode(int *qrCode, int size)
{
    int i, j;

    //print the top border of the QR code
    for(i = 0; i < size+2; i++)
    {
        printf("-");
    }
    printf("\n");

    //print the QR code itself
    for(i = 0; i < size; i++)
    {
        printf("|");
        for(j = 0; j < size; j++)
        {
            if(qrCode[i*size+j] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("|\n");
    }

    //print the bottom border of the QR code
    for(i = 0; i < size+2; i++)
    {
        printf("-");
    }
    printf("\n");
}