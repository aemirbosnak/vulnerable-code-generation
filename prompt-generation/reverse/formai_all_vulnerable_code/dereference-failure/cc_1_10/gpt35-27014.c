//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILENAME_SIZE 50
#define VIRUS_SIGNATURE "I_LOVE_HAPPY_CODES"

int main() {
   char filename[MAX_FILENAME_SIZE];
   char file_content[MAX_FILE_SIZE];
   FILE *fp;
   int file_size, i, virus_found = 0;
   
   printf("Hey there! I am the Happy Antivirus Scanner!\n");
   printf("Tell me the file name you want to scan: ");
   scanf("%s", filename);

   fp = fopen(filename, "r");
   
   if(fp == NULL) {
      printf("Error: Unable to open file!");
      exit(1);
   }

   fseek(fp, 0L, SEEK_END);
   file_size = ftell(fp);
   fseek(fp, 0L, SEEK_SET);
   
   if(file_size > MAX_FILE_SIZE) {
      printf("Error: File size too large!");
      exit(1);
   }
   
   fread(file_content, 1, file_size, fp);
   fclose(fp);

   for(i = 0; i < file_size - strlen(VIRUS_SIGNATURE); i++) {
      if(strncmp(file_content + i, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
         virus_found = 1;
         break;
      }
   }

   if(virus_found == 1) {
      printf("Alert! Virus detected in file %s!\n", filename);
      printf("Don't worry, I am the Happy Antivirus and I have removed the virus!\n");
      
      fp = fopen(filename, "w");
      fwrite("", 1, 0, fp);
      fseek(fp, 0L, SEEK_SET);
      fclose(fp);
   }
   else {
      printf("Congratulations! File %s is clean!\n", filename);
      printf("You are awesome for writing happy code! Keep it up!\n");
   }

   return 0;
}