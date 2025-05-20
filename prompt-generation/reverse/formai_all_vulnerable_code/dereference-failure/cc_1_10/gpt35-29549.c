//FormAI DATASET v1.0 Category: QR code generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateQRCode(int size);
void printQRCode(int** QRCode, int size);
void shiftRight(int** QRCode, int size);
void shiftLeft(int** QRCode, int size);
void shiftUp(int** QRCode, int size);
void shiftDown(int** QRCode, int size);

int main()
{
    int size;

    // Set the seed for the random number generator
    srand(time(NULL));

    // Prompt the user for the size of the QR code
    printf("Enter the size of the QR code: ");
    scanf("%d", &size);

    // Generate the QR code
    generateQRCode(size);

    return 0;
}

void generateQRCode(int size)
{
    int** QRCode;
    int i, j;

    // Allocate memory for the QR code
    QRCode = (int**)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++)
    {
        QRCode[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the QR code to 0s and 1s randomly
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            QRCode[i][j] = rand() % 2;
        }
    }

    // Print the initial QR code
    printf("Initial QR code:\n");
    printQRCode(QRCode, size);

    // Shift the QR code randomly
    for (i = 0; i < rand() % 10 + 5; i++)
    {
        switch (rand() % 4)
        {
            case 0:
                shiftRight(QRCode, size);
                break;
            case 1:
                shiftLeft(QRCode, size);
                break;
            case 2:
                shiftUp(QRCode, size);
                break;
            case 3:
                shiftDown(QRCode, size);
                break;
        }
    }

    // Print the final QR code
    printf("Final QR code:\n");
    printQRCode(QRCode, size);

    // Free the memory allocated for the QR code
    for (i = 0; i < size; i++)
    {
        free(QRCode[i]);
    }
    free(QRCode);
}

void printQRCode(int** QRCode, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", QRCode[i][j]);
        }
        printf("\n");
    }
}

void shiftRight(int** QRCode, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = size - 1; j > 0; j--)
        {
            QRCode[i][j] = QRCode[i][j - 1];
        }
        QRCode[i][0] = rand() % 2;
    }
}

void shiftLeft(int** QRCode, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            QRCode[i][j] = QRCode[i][j + 1];
        }
        QRCode[i][size - 1] = rand() % 2;
    }
}

void shiftUp(int** QRCode, int size)
{
    int i, j;

    for (j = 0; j < size; j++)
    {
        for (i = 0; i < size - 1; i++)
        {
            QRCode[i][j] = QRCode[i + 1][j];
        }
        QRCode[size - 1][j] = rand() % 2;
    }
}

void shiftDown(int** QRCode, int size)
{
    int i, j;

    for (j = 0; j < size; j++)
    {
        for (i = size - 1; i > 0; i--)
        {
            QRCode[i][j] = QRCode[i - 1][j];
        }
        QRCode[0][j] = rand() % 2;
    }
}