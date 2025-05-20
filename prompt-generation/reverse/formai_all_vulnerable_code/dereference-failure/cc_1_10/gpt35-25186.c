//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
// This HTML beautifier program is designed to make your code more readable and uniform
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove extra whitespace from a string
char *clean(char *str) {
  char *cleaned = calloc(strlen(str) + 1, sizeof(char));
  int i, j, flag = 0;
  
  for(i = 0, j = 0; str[i] != '\0'; i++) {
    // If char is not a whitespace
    if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
      flag = 0;
      cleaned[j++] = str[i];
    }
    // If char is a whitespace
    else {
      if(flag == 0) {
        flag = 1;
        cleaned[j++] = ' ';
      }
    }
  }
  
  cleaned[j] = '\0';
  return cleaned;
}

int main() {
  // Opening the input file
  FILE *input = fopen("input.html", "r");

  // If the input file does not exist
  if (!input) {
    printf("The input file does not exist\n");
    return 1;
  }

  // Creating and opening the output file
  FILE *output = fopen("output.html", "w");

  // Reading each line of the input file and printing it to the output file
  char line[1024];

  while (fgets(line, 1024, input)) {
    // Removing extra whitespace from the line
    char *cleaned = clean(line);

    // Printing the cleaned line to the output file
    fputs(cleaned, output);
     
    // Free the memory allocated for cleaned string
    free(cleaned);
  }

  // Closing the input and output files
  fclose(input);
  fclose(output);

  // Printing success message
  printf("The HTML file has been beautified and saved to output.html");

  return 0;
}