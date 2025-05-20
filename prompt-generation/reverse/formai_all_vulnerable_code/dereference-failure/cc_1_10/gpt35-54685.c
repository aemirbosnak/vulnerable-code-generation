//FormAI DATASET v1.0 Category: QR code generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Usage: ./qrgen <text>\n");
    return 1;
  }

  //Create QR Code
  QRcode *code;

  //Set EC Level and QR Version
  int level = QR_ECLEVEL_L;
  int version = 7;
  int width = 1;
  int margin = 0;

  //Generate QR Code
  code = QRcode_encodeString(argv[1], version, level, QR_MODE_8, 1);

  //Write QR Code to PNG File
  FILE *fp;
  char filename[100];
  sprintf(filename, "%s.png", argv[1]);
  fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("Error: Failed to open file\n");
    return 1;
  }

  int x, y;
  unsigned char *p, *q;
  for (y = 0; y < code->width; y++) {
    p = code->data + y * code->width;
    for (x = 0; x < code->width; x++) {
      q = p + x;
      if (*q == 0) {
        fwrite(&width, 1, 1, fp);
      } else {
        fwrite(&margin, 1, 1, fp);
      }
    }
    fwrite("\n", 1, 1, fp);
  }

  fclose(fp);
  QRcode_free(code);
  printf("QR code successfully generated!\n");

  return 0;
}