//FormAI DATASET v1.0 Category: QR code reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// QR code structure
typedef struct {
   uint8_t version;
   uint8_t error_correction_level;
   uint8_t mask_pattern;
   uint8_t *data;
   uint16_t data_length;
} QRCode;

// Reverse bit order
uint8_t reverse_bits(uint8_t x) {
   x = (((x & 0xaa) >> 1) | ((x & 0x55) << 1));
   x = (((x & 0xcc) >> 2) | ((x & 0x33) << 2));
   x = (((x & 0xf0) >> 4) | ((x & 0x0f) << 4));
   return x;
}

// Read QR code
QRCode read_qr_code(const char *filename) {
   // Open file
   FILE *file = fopen(filename, "rb");
   if (!file) {
      fprintf(stderr, "Error: Cannot open file\n");
      exit(EXIT_FAILURE);
   }

   // Read file header
   char header[7];
   fread(header, sizeof(char), 6, file);
   header[6] = '\0';
   if (strcmp(header, "QRCODE")) {
      fprintf(stderr, "Error: Invalid file format\n");
      exit(EXIT_FAILURE);
   }

   // Read version
   uint8_t version;
   fread(&version, sizeof(uint8_t), 1, file);

   // Read error correction level
   uint8_t error_correction_level;
   fread(&error_correction_level, sizeof(uint8_t), 1, file);

   // Read mask pattern
   uint8_t mask_pattern;
   fread(&mask_pattern, sizeof(uint8_t), 1, file);

   // Read data
   uint16_t data_length;
   fread(&data_length, sizeof(uint16_t), 1, file);
   data_length = reverse_bits(data_length);
   uint8_t *data = (uint8_t *) malloc(data_length * sizeof(uint8_t));
   fread(data, sizeof(uint8_t), data_length, file);

   // Create QR code structure
   QRCode qrcode;
   qrcode.version = version;
   qrcode.error_correction_level = error_correction_level;
   qrcode.mask_pattern = mask_pattern;
   qrcode.data = data;
   qrcode.data_length = data_length;

   // Close file
   fclose(file);

   return qrcode;
}

// Main function
int main(int argc, char *argv[]) {
   // Check command line arguments
   if (argc != 2) {
      fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
      return EXIT_FAILURE;
   }

   // Read QR code
   QRCode qrcode = read_qr_code(argv[1]);

   // Print QR code data
   printf("Version: %d\n", qrcode.version);
   printf("Error Correction Level: %d\n", qrcode.error_correction_level);
   printf("Mask Pattern: %d\n", qrcode.mask_pattern);
   printf("Data: ");
   for (int i = 0; i < qrcode.data_length; i++) {
      printf("%c", qrcode.data[i]);
   }
   printf("\n");

   // Free memory
   free(qrcode.data);

   return EXIT_SUCCESS;
}