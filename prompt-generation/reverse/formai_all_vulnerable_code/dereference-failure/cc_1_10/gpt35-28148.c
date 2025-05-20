//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
/* 
   Introspective C Compression Algorithm 
   This algorithm uses concepts of run-length encoding 
   and binary search to compress data efficiently
   
   Author: AI
*/

#include <stdio.h>
#include <stdlib.h>

// Function to compress the data
void compress(char* data, int length){

  // Create an array to store the compressed data
  char* compressed_data = (char*)malloc(length * sizeof(char));

  // Initialize index variables
  int i = 0, j = 0;

  // Loop through the input data
  while(i < length) {

    // Get the character and its count
    char current_char = data[i];
    int count = 1;

    // Loop through the rest of the data and count consecutive characters
    while(i + count < length && data[i+count] == current_char) {
      count++;
    }

    // If the count is greater than 2, compress the data
    if(count > 2){

      // Store the count as a negative number to distinguish from characters
      compressed_data[j] = -count;
      j++;

      // Store the character
      compressed_data[j] = current_char;
      j++;

      // Move the index variable
      i += count;

    } else {

      // If the count is less than or equal to 2, add the characters as is
      for(int k = 0; k < count; k++){

        compressed_data[j] = current_char;
        j++;

      }

      // Move the index variable
      i += count;

    }

  }

  // Print the compressed data
  printf("Compressed Data: ");

  for(int i = 0; i < j; i++){

    printf("%d ", compressed_data[i]);

  }

  printf("\n");

  // Free the memory allocated for compressed data
  free(compressed_data);

}

// Driver code
int main(){

  // Input data
  char data[] = "AAAAABBCCCCDDDDDEFGHIIIIIIIIJKLMNO";
  int length = sizeof(data)/sizeof(char);

  printf("Original Data: %s\n", data);

  // Compress the data
  compress(data, length);

  return 0;
}