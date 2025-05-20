//FormAI DATASET v1.0 Category: QR code generator ; Style: mind-bending
#include <qrencode.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_QR_SIZE 1024

int main(int argc, char **argv) {
  
  // variables
  QRcode *qr;
  unsigned char *data;
  int qr_size, i, j;
  char *message = "Hello World!";
  FILE *fp;

  // generate QR code
  qr = QRcode_encodeString(message, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
  
  if (qr == NULL) {
    printf("Error: Unable to generate QR code.\n");
    return EXIT_FAILURE;
  }

  // convert QR code to pixel data
  qr_size = qr->width > MAX_QR_SIZE ? MAX_QR_SIZE : qr->width;
  data = qr->data;

  // create PNG file from pixel data
  fp = fopen("qrcode.png", "wb");
  fprintf(fp, "\x89\x50\x4e\x47\x0d\x0a\x1a\x0a");
  fprintf(fp, "%c%c%c%c%c%c%c%c", 0, 0, 0, 13, 'I', 'H', 'D', 'R');
  fprintf(fp, "%c%c%c%c", qr_size, qr_size, 0, 0);
  fprintf(fp, "%c%c%c%c%c%c%c", 0, 0, 0, 0, 8, 2, 0);
  fprintf(fp, "%c%c%c%c%c", 0, 0, 0, '\x90', 0);
  fprintf(fp, "%c%c%c%c", 'I', 'D', 'A', 'T');
  
  for (i = 0; i < qr_size; i++) {
    fprintf(fp, "%c", data[i] == 0 ? '\0' : '\xFF');
    for (j = 0; j < qr_size; j++) {
      fprintf(fp, "%c", data[j * qr_size + i] == 0 ? '\xFF' : '\0');
    }
  }
  
  fprintf(fp, "%c%c%c%c%c", '\x04', '\x00', '\x00', '\x00', '\xff');
  fprintf(fp, "%c%c%c%c", 'I', 'E', 'N', 'D');
  fprintf(fp, "%c%c%c%c%c", '\xae', '\x42', '\x60', '\x82', '\x00');

  printf("QR code generated successfully and saved as 'qrcode.png'\n");

  // cleanup
  fclose(fp);
  QRcode_free(qr);

  return EXIT_SUCCESS;
}