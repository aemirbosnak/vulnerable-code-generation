//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_file(char *filename);

int main(int argc, char *argv[]) {
   if(argc != 2) {
      printf("Usage: %s filename\n", argv[0]);
      exit(-1);
   }
   scan_file(argv[1]);
   printf("Scanning completed!\n");
   return 0;
}

void scan_file(char *filename) {
   FILE *fp;
   long file_size;
   char *buffer;
   int c, i;
   
   fp = fopen(filename, "rb");
   
   if(fp == NULL) {
      printf("Error opening file %s\n", filename);
      exit(-1);
   }
   
   fseek(fp, 0L, SEEK_END);
   file_size = ftell(fp);
   rewind(fp);
   
   buffer = (char*) malloc((file_size + 1) * sizeof(char));
   
   if(buffer == NULL) {
      printf("Memory allocation error.\n");
      exit(-1);
   }
   
   fread(buffer, sizeof(char), file_size, fp);
   fclose(fp);
   
   for(i = 0; i < file_size; i++) {
      c = buffer[i];
      if(c == 'm' || c == 'a' || c == 'l' || c == 'w' || c == 'a' || c == 'r' || c == 'e') {
         printf("Warning!\n");
         printf("File %s contains a potential virus.\n", filename);
         free(buffer);
         return;
      }
   }
   printf("File %s is safe.\n", filename);
   free(buffer);
}