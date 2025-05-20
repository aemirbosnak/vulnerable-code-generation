//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include<stdio.h>

// Function to perform digital watermarking
void digitalWatermarking(char *inputFile, char *outputFile, char *watermark){
  
  FILE *fptr1, *fptr2;
  char ch;
  
  // Open input file
  fptr1 = fopen(inputFile, "r");
  
  if (fptr1 == NULL){
    printf("Error: File not found");
    return;
  }
  
  // Open output file
  fptr2 = fopen(outputFile, "w");
  
  if (fptr2 == NULL){
    printf("Error: File not found");
    return;
  }
  
  // Start watermarking process
  while ((ch = fgetc(fptr1)) != EOF){
    
    // Check if character is a space or newline
    if (ch == ' ' || ch == '\n'){
      
      // Write watermark
      fwrite(watermark, sizeof(char), strlen(watermark), fptr2);
    }
    
    // Write original character
    fwrite(&ch, sizeof(char), 1, fptr2);
  }
  
  // Close files
  fclose(fptr1);
  fclose(fptr2);
  
}

int main(){
  
  // Input file
  char *inputFile = "input.txt";
  
  // Output file
  char *outputFile = "output.txt";
  
  // Watermark
  char *watermark = "Digital Watermarking Example";
  
  // Perform digital watermarking
  digitalWatermarking(inputFile, outputFile, watermark);
  
  printf("Digital Watermarking Successful!");
  
  return 0;
}