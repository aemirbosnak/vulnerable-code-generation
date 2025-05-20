//FormAI DATASET v1.0 Category: Error handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

/* This program is not responsible for any weird, 
   surreal or unexpected errors occurring during its execution */

int main(void) {
  
  /* Declare variables for input and output file names */
  char *input_file_name;
  char *output_file_name;
  
  /* Allocate memory for input file name */
  input_file_name = malloc(50 * sizeof(char));
  
  /* Allocate memory for output file name */
  output_file_name = malloc(50 * sizeof(char));
  
  /* Check if memory allocation was successful */
  if (input_file_name == NULL) {
    printf("I'm sorry, I cannot allocate memory for the input file name.\n");
    exit(EXIT_FAILURE);
  }
  
  if (output_file_name == NULL) {
    printf("I'm sorry, I cannot allocate memory for the output file name.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Prompt user to enter input file name */
  printf("Please enter the name of the input file: ");
  scanf("%s", input_file_name);
  
  /* Prompt user to enter output file name */
  printf("Please enter the name of the output file: ");
  scanf("%s", output_file_name);
  
  /* Declare file pointers for input and output files */
  FILE *input_file;
  FILE *output_file;
  
  /* Attempt to open input file for reading */
  input_file = fopen(input_file_name, "r");
  
  if (input_file == NULL) {
    printf("Cannot find file '%s'.\n", input_file_name);
    exit(EXIT_FAILURE);
  }
  
  /* Attempt to open output file for writing */
  output_file = fopen(output_file_name, "w");
  
  if (output_file == NULL) {
    printf("Cannot open file '%s' for writing.\n", output_file_name);
    exit(EXIT_FAILURE);
  }
  
  /* Declare variables for reading input file */
  char read_buffer[50];
  int read_counter = 0;
  
  /* Read from input file and write to output file */
  while (fgets(read_buffer, 50, input_file)) {
    fprintf(output_file, "%d: %s", read_counter, read_buffer);
    read_counter++;
  }
  
  /* Close input and output files */
  fclose(input_file);
  fclose(output_file);
  
  /* Free allocated memory */
  free(input_file_name);
  free(output_file_name);
  
  /* Display surreal message */
  printf("Do you hear that? It's the sound of reality bending as this program ends...\n");
  
  /* Return success */
  return 0;
}