//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

int main(){

  char line[MAX_LINE_LEN]; // This array will store each line of the input text file
  char output[MAX_LINE_LEN]; // This array will store the output string
  char * token; // This variable will store each word/token from the input string
  char * search_word = "example"; // This is the word we will search for in each line
  int line_num = 0; // This variable will keep track of the line number

  FILE * fp_in; // Input file pointer
  FILE * fp_out; // Output file pointer

  fp_in = fopen("input.txt", "r"); // Open input file in read mode

  if(fp_in == NULL){
    printf("Error opening input file\n");
    exit(1);
  }

  fp_out = fopen("output.txt", "w"); // Open output file in write mode

  if(fp_out == NULL){
    printf("Error opening output file\n");
    exit(1);
  }

  // Loop through each line of the input file until the end of file is reached
  while(fgets(line, MAX_LINE_LEN, fp_in) != NULL){

    line_num++; // Increment line number

    // Copy the entire line to the output string
    strcpy(output, line);

    // Search for the search word in the line
    token = strtok(line, " ");
    while(token != NULL){

      if(strcmp(token, search_word) == 0){ // If the search word is found

        // Replace the search word with another word
        char * replace_word = "program";
        char * temp = strstr(output, search_word);
        int index = temp - output; // Get the index of the first character of the search word in the output string
        memmove(&output[index], replace_word, strlen(replace_word)); // Replace the search word with the replace word in the output string
      }

      token = strtok(NULL, " ");
    }

    fprintf(fp_out, "%d: %s", line_num, output); // Write the output string along with the line number to the output file
  }

  fclose(fp_in); // Close the input file
  fclose(fp_out); // Close the output file

  printf("Output file generated successfully\n");

  return 0;
}