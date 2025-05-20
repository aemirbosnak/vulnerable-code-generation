//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QR_MAX_SIZE 255
#define QR_COLOR_BLACK 0
#define QR_COLOR_WHITE 1

typedef struct QRCode {
    int size;
    int **data;
} QRCode;

QRCode *qrcode_new(int size)
{
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = size;
    qrcode->data = malloc(size * size * sizeof(int));
    return qrcode;
}

void qrcode_encode(QRCode *qrcode, char *data)
{
    int i, j, k;
    int data_len = strlen(data);
    qrcode->data = realloc(qrcode->data, qrcode->size * qrcode->size * sizeof(int));

    for (i = 0; i < qrcode->size; i++)
    {
        for (j = 0; j < qrcode->size; j++)
        {
            qrcode->data[i][j] = QR_COLOR_WHITE;
        }
    }

    k = 0;
    for (i = 0; i < data_len; i++)
    {
        switch (data[i])
        {
            case 'A':
                qrcode->data[k/QR_MAX_SIZE][k%QR_MAX_SIZE] = QR_COLOR_BLACK;
                break;
            case 'B':
                qrcode->data[k/QR_MAX_SIZE][k%QR_MAX_SIZE] = QR_COLOR_BLACK;
                qrcode->data[k/QR_MAX_SIZE][k%QR_MAX_SIZE] = QR_COLOR_BLACK;
                break;
            case 'C':
                qrcode->data[k/QR_MAX_SIZE][k%QR_MAX_SIZE] = QR_COLOR_BLACK;
                qrcode->data[k/QR_MAX_SIZE][k%QR_MAX_SIZE] = QR_COLOR_BLACK;
                qrcode->data[k/QR_MAX_SIZE][k%QR_MAX_SIZE] = QR_COLOR_BLACK;
                break;
            default:
                break;
        }
        k++;
    }
}

void qrcode_draw(QRCode *qrcode)
{
    int i, j;
    for (i = 0; i < qrcode->size; i++)
    {
        for (j = 0; j < qrcode->size; j++)
        {
            if (qrcode->data[i][j] == QR_COLOR_BLACK)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    QRCode *qrcode = qrcode_new(2);
    qrcode_encode(qrcode, "ABC");
    qrcode_draw(qrcode);

    return 0;
}