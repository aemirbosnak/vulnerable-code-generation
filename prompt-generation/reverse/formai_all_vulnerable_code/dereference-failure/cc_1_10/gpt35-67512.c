//FormAI DATASET v1.0 Category: QR code generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <qrencode.h>

#define QR_VERSION 5 // Set the version of the QR code (1-40)
#define QR_ECCLEVEL QR_ECLEVEL_L // Set the error correction level (L, M, Q, or H)

int main(int argc, char *argv[])
{
   if (argc != 2) {
      printf("Usage: %s <text to encode>\n", argv[0]);
      return 1;
   }

   char *text = argv[1];
   QRcode *qr = QRcode_encodeString(text, 0, QR_ECCLEVEL, QR_MODE_8, 1);
   if (qr == NULL) {
      printf("Failed to generate QR code.\n");
      return 1;
   }

   uint8_t *data = qr->data;
   int width = qr->width;

   printf("QR code for text: %s\n", text);
   printf("+");
   for (int i = 0; i < width; i++) {
      printf("--");
   }
   printf("+\n");

   for (int row = 0; row < width; row++) {
      printf("|");
      for (int col = 0; col < width; col++) {
         if (data[row * width + col] & 1) {
            printf("  ");
         } else {
            printf("██");
         }
      }
      printf("|\n");
   }

   printf("+");
   for (int i = 0; i < width; i++) {
      printf("--");
   }
   printf("+\n");

   QRcode_free(qr);

   return 0;
}