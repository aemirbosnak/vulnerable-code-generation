//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main(int argc, char* argv[])
{
   char* virusSignature = "663A756E313630373838";
   char fileName[50];
   char* buffer;
   long fileSize;
   size_t bytesRead;
   int signatureMatch = 0;

   if(argc != 2)
   {
      printf("Usage: %s [filename]\n", argv[0]);
      return 0;
   }

   FILE *file = fopen(argv[1], "rb");
   if(!file)
   {
      printf("Could not open file %s\n", argv[1]);
      return 1;
   }

   fseek(file, 0L, SEEK_END);
   fileSize = ftell(file);
   rewind(file);

   if (fileSize > MAX_FILE_SIZE)
   {
       printf("File size is too large!\n");
       return 1;
   }

   buffer = malloc(fileSize + 1);
   if(!buffer)
   {
      printf("Memory allocation error\n");
      return 1;
   }

   bytesRead = fread(buffer, 1, fileSize, file);
   buffer[bytesRead] = '\0';

   fclose(file);

   for(int i = 0; i < bytesRead-15; i++)
   {
       if (buffer[i] == virusSignature[0])
       {  
           signatureMatch = 1;
           for(int j = 1; j < 16; j++)
           {
               if (buffer[i+j] != virusSignature[j])
               {
                   signatureMatch = 0;
                   break;
               }
           }
           if (signatureMatch)
           {
                printf("File %s is infected with virus signature!\n", argv[1]);
                return 1;
           }
       }
   }

   printf("No virus signature found in file %s\n", argv[1]);

   free(buffer);

   return 0;
}