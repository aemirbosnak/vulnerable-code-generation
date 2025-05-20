//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct QRCode {
  int size;
  char **data;
} QRCode;

QRCode *qrcode_init(int size)
{
  QRCode *qr = malloc(sizeof(QRCode));
  qr->size = size;
  qr->data = malloc(size * size * sizeof(char));
  return qr;
}

void qrcode_encode(QRCode *qr, char *str)
{
  int i, j, k, l, m, n, h, w;
  int d = strlen(str);

  for (i = 0; i < qr->size; i++)
    for (j = 0; j < qr->size; j++)
      qr->data[i][j] = 0;

  k = 0;
  for (l = 0; l < d; l++)
  {
    h = str[l] >> 8;
    w = str[l] & 0xFF;
    qr->data[h][w] = 1;
    k++;
  }

  qr->data[0][0] = k;
}

void qrcode_print(QRCode *qr)
{
  for (int i = 0; i < qr->size; i++)
  {
    for (int j = 0; j < qr->size; j++)
    {
      if (qr->data[i][j] == 1)
        printf("# ");
      else
        printf(". ");
    }
    printf("\n");
  }
}

int main()
{
  QRCode *qr = qrcode_init(20);
  qrcode_encode(qr, "Hello, world!");
  qrcode_print(qr);
  free(qr);

  return 0;
}