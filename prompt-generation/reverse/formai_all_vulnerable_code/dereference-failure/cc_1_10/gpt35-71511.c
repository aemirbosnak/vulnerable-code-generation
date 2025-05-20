//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
//Loading resources...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initializing the main function
int main(int argc, char *argv[]) {
  
  //Checking for minimum arguments
  if(argc < 2) {
    printf("Not enough arguments! Please provide a file name.\n");
    exit(EXIT_FAILURE);
  }
  
  //Opening the input file
  FILE *input = fopen(argv[1], "r");
  
  //Checking for errors in opening the file
  if(input == NULL) {
    printf("Error! Unable to open the input file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  
  //Initializing an array of pointers to hold the text
  char **text = malloc(sizeof(char *) * 1000);
  int i = 0;
  
  //Loading the text into the array
  while(!feof(input)) {
    text[i] = malloc(sizeof(char) * 100);
    fgets(text[i], 100, input);
    i++;
  }
  
  //Closing the input file
  fclose(input);
  
  //Initializing the summary string
  char *summary = malloc(sizeof(char) * 1000);
  strcpy(summary, "");
  
  //Processing each line of text
  for(int j=0; j<i; j++) {
    
    //Calculating the length of the line
    int len = strlen(text[j]);
    
    //Replacing the newline character with a space
    text[j][len - 1] = ' ';
    
    //Adding the line to the summary
    strcat(summary, text[j]);
    
    //Checking if the summary has exceeded the allowed length
    if(strlen(summary) > 1000) {
      break;
    }
  }
  
  //Printing the summary
  printf("Summary: %s\n", summary);
  
  //Freeing the memory
  for(int j=0; j<i; j++) {
    free(text[j]);
  }
  free(text);
  free(summary);
  
  //Exiting the program
  return 0;
}