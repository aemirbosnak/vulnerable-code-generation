//FormAI DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   // Check for the correct number of arguments (program name, input file, output file, encryption key)
   if (argc != 4) {
      printf("Syntax: %s <input file> <output file> <encryption key>\n", argv[0]);
      exit(1);
   }

   // Open the input file for reading
   FILE *inputFile = fopen(argv[1], "rb");

   // Check if the input file can be opened
   if (inputFile == NULL) {
      printf("Cannot open input file \"%s\".\n", argv[1]);
      exit(1);
   }

   // Open the output file for writing
   FILE *outputFile = fopen(argv[2], "wb");

   // Check if the output file can be opened
   if (outputFile == NULL) {
      printf("Cannot open output file \"%s\".\n", argv[2]);
      exit(1);
   }

   // Get the length of the encryption key
   int keyLength = strlen(argv[3]);

   // Loop through each byte of the input file and xor it with the corresponding byte of the encryption key
   int byte;
   int keyIndex = 0;
   while ((byte = fgetc(inputFile)) != EOF) {
      fputc(byte ^ argv[3][keyIndex], outputFile);

      // Increase the index of the encryption key
      keyIndex++;

      // Reset the index of the encryption key if it exceeds the key length
      if (keyIndex >= keyLength) {
         keyIndex = 0;
      }
   }

   // Close the input and output files
   fclose(inputFile);
   fclose(outputFile);

   printf("Encryption complete.\n");

   return 0;
}