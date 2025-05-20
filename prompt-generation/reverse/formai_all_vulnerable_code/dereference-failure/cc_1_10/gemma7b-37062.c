//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CODE_SIZE 256

typedef struct qr_code {
  int size;
  char **data;
} qr_code;

qr_code *qr_code_new(int size)
{
  qr_code *qr = malloc(sizeof(qr_code));
  qr->size = size;
  qr->data = malloc(size * size * sizeof(char));
  return qr;
}

void qr_code_encode(qr_code *qr, char *str)
{
  int i, j, k, l, n, d;
  n = strlen(str);
  k = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < qr->size; j++)
    {
      for (l = 0; l < qr->size; l++)
      {
        if (k >= n)
          break;
        d = str[k] - 'a' + 1;
        qr->data[j][l] = (d & 0x0f) << 4 | (d & 0x0f) >> 4;
        k++;
      }
    }
  }
}

int main()
{
  qr_code *qr = qr_code_new(16);
  qr_code_encode(qr, "Hello, world!");
  for (int i = 0; i < qr->size; i++)
  {
    for (int j = 0; j < qr->size; j++)
    {
      printf("%c ", qr->data[i][j]);
    }
    printf("\n");
  }
  return 0;
}