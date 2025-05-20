//FormAI DATASET v1.0 Category: QR code reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

/* Function to check if the input string contains valid QR code */
bool isValidQRCode(char* inputString) {
   int length = strlen(inputString);
   return (strstr(inputString, "QR_CODE") != NULL && length == 64);
}

/* Function to read QR code from the input file */
char* readQRCode(FILE* inputFile) {
   char* buffer = malloc(sizeof(char) * MAX_BUFFER_SIZE);
   fgets(buffer, MAX_BUFFER_SIZE, inputFile);
   return buffer;
}

int main(int argc, char** argv) {
   /* Check if input file path is provided */
   if (argc < 2) {
      printf("Error: Please provide input file path\n");
      return 0;
   }

   /* Open input file */
   FILE* inputFile = fopen(argv[1], "r");
   if (inputFile == NULL) {
      printf("Error: Failed to open input file\n");
      return 0;
   }

   /* Read QR code from input file */
   char* qrCode = readQRCode(inputFile);
   fclose(inputFile);

   /* Check if the input is a valid QR code */
   if (!isValidQRCode(qrCode)) {
      printf("Error: Invalid QR Code\n");
      return 0;
   }

   /* Decrypt QR code */
   for (int i = 0; i < strlen(qrCode); i++) {
      qrCode[i] = qrCode[i] ^ i;
   }

   /* Display decrypted QR code */
   printf("Decrypted QR Code: %s\n", qrCode);

   /* Free allocated memory */
   free(qrCode);

   return 0;
}