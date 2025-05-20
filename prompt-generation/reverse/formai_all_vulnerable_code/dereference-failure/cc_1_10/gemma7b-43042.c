//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct QRCode {
  int size;
  char **data;
} QRCode;

QRCode *qrcode_new(int size)
{
  QRCode *qr = malloc(sizeof(QRCode));
  qr->size = size;
  qr->data = malloc(size * size * sizeof(char));
  return qr;
}

void qrcode_encode(QRCode *qr, char *str)
{
  int i, j, k, l, m;
  l = strlen(str);
  k = qr->size;
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < k; j++)
    {
      qr->data[i][j] = 0;
    }
  }
  m = 0;
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < k; j++)
    {
      if (str[m] == str[i])
      {
        qr->data[i][j] = 1;
      }
      m++;
    }
  }
}

void qrcode_print(QRCode *qr)
{
  int i, j;
  for (i = 0; i < qr->size; i++)
  {
    for (j = 0; j < qr->size; j++)
    {
      printf("%c ", qr->data[i][j] ? '#' : '.');
    }
    printf("\n");
  }
}

int main()
{
  QRCode *qr = qrcode_new(10);
  qrcode_encode(qr, "HELLO WORLD");
  qrcode_print(qr);

  free(qr->data);
  free(qr);

  return 0;
}