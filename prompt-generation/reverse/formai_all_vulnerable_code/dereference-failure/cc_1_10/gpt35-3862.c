//FormAI DATASET v1.0 Category: QR code generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv)
{
  QRcode *qrcode;
  int size = 3, margin = 1, dpi;
  char *data;

  if (argc != 2) {
    printf("Usage: qr <data>\n");
    return -1;
  }

  data = argv[1];
  qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
  
  if (qrcode == NULL) {
    printf("Failed to create QR code\n");
    return -1;
  }

  printf("QR code data: %s\n", data);
  
  /* Print QR code as ASCII art */
  for (int i = 0; i < qrcode->width + margin * 2; i++) {
    printf("██");
  }
  printf("\n");
  for (int y = 0; y < qrcode->width; y++) {
    printf("██");
    for (int x = 0; x < qrcode->width; x++) {
      if (qrcode->data[y*qrcode->width+x] & 1) {
        printf("  ");
      } else {
        printf("██");
      }
    }
    printf("██\n");
  }
  for (int i = 0; i < qrcode->width + margin * 2; i++) {
    printf("██");
  }
  printf("\n");

  QRcode_free(qrcode);

  return 0;
}