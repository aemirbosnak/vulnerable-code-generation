//FormAI DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   FILE *fpIn, *fpOut;
   char c;

   fpIn = fopen("input.html", "r"); //opening the input file
   fpOut = fopen("output.html", "w"); //opening the output file

   if (fpIn == NULL || fpOut == NULL) 
   {
      printf("Error opening file");
      exit(1);
   }

   while( (c = fgetc(fpIn)) != EOF ) //parsing each character of the file
   {
      if(c == '<') //if opening tag, indent and print
      {
         putc('\n',fpOut); //newline
         putc(c,fpOut); //print opening tag
         c = fgetc(fpIn);

         while(c != '>') //print the opening tag attributes
         {
            putc(c,fpOut);
            c = fgetc(fpIn);
         }
         putc(c,fpOut); //print the closing bracket for the opening tag
         putc('\n',fpOut); //newline
      }
      else if (c == '>') //printing the closing bracket of non-empty tag
      {
         putc(c,fpOut); //print the closing bracket of the tag
         putc('\n',fpOut); //newline
      }
      else
      {
         putc(c,fpOut); //simply printing the remaining part of the tag
      }

   }

   fclose(fpIn); //closing both files
   fclose(fpOut);

   return 0;
}