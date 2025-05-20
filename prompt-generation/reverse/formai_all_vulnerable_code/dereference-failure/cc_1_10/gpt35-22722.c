//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

//this program is going to read the contents of an input file and write it to an output file

int main() {

  FILE *input_file;
  FILE *output_file;
  
  //open the input file
  
  input_file = fopen("input.txt", "r");
  
  if (input_file == NULL) {
    
    printf("Sorry, unable to open input file");
    exit(0);
  }

  //open the output file
  
  output_file = fopen("output.txt", "w");
  
  if (output_file == NULL) {
    
    printf("Sorry, unable to open output file");
    exit(0);
  }

  printf("**** FILE HANDLING PROGRAM ****\n");

  char c;

  //read characters from the input_file and write them to the output_file
  
  while ((c = fgetc(input_file)) != EOF) {
    
    fputc(c, output_file);
  }

  printf("File successfully copied!\n");

  //close the input and output files
  
  fclose(input_file);
  fclose(output_file);

  return 0;
}