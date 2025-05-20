//FormAI DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#define SHIFT 3 //Define the number of shifts in the cipher.

int main(){
   FILE *fileIn, *fileOut; // file pointers for input and output files
   char ch, inputfile[20], outputfile[20];

   printf("Enter the name of the file to encrypt: ");
   scanf("%s", inputfile);

   // Open input file in read mode
   fileIn = fopen(inputfile, "r");  
    
   if (fileIn == NULL){ // Check if file does not exist
      printf("Cannot open %s for reading.\n", inputfile);
      exit(1);
   }
   printf("Enter the output file name: ");
   scanf("%s", outputfile);

   // Open output file in write mode
   fileOut = fopen(outputfile, "w"); 

   if(fileOut == NULL){ // Check if file cannot be created
       printf("Cannot create output file %s.\n", outputfile);
       exit(1);
   }

   // Read each character from the input file and encrypt
   while ((ch = fgetc(fileIn)) != EOF){
       if (ch >= 'a' && ch <= 'z'){
            ch = ch + SHIFT;
            if (ch > 'z'){
                ch = ch - 26; // Wrap around to the beginning of the alphabet
            }
       }
       else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + SHIFT;
            if (ch > 'Z'){
                ch = ch - 26; // Wrap around to the beginning of the alphabet
            }
       }
       fputc(ch, fileOut); // Write the encrypted character to the output file
   }

   printf("File encryption successful.\n");

   fclose(fileIn); 

   fclose(fileOut); 

   return 0;
}