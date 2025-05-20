//FormAI DATASET v1.0 Category: Spell checking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This program performs spell checking on a given input text file and outputs the misspelled words.

// This function converts a word to lowercase.
char * to_lowercase(char * word){
  int i;
  for(i=0; i<strlen(word); i++){
    word[i] = tolower(word[i]);
  }
  return word;
}

// This function checks if a word is in the dictionary.
int check_word(char * word, char ** dict, int dict_size){
  int i;
  for(i=0; i<dict_size; i++){
    if(strcmp(to_lowercase(word), dict[i])==0){// the word is found in the dictionary
      return 1;
    }
  }
  return 0; // the word is NOT found in the dictionary
}

int main(){
  FILE * input_file, * output_file;
  char * input_filename = "input.txt";
  char * output_filename = "output.txt";
  char * dict_filename = "dictionary.txt";
  char ** dictionary; // an array of strings that will hold the dictionary words.
  int dict_size = 0;
  char word[100]; // assumption: words in the file will not exceed 99 characters.

  // Load the dictionary into memory
  printf("Loading dictionary from file...\n");
  input_file = fopen(dict_filename, "r");
  if(input_file==NULL){
    printf("Error opening dictionary file.\n");
    return 1;
  }
  while(fscanf(input_file, "%s", word) != EOF){ // read each word in the dictionary
    dict_size++;
    dictionary = (char **)realloc(dictionary, dict_size*sizeof(char *));
    dictionary[dict_size-1] = (char *)malloc((strlen(word)+1)*sizeof(char));
    strcpy(dictionary[dict_size-1], word);
  }
  fclose(input_file);
  printf("Dictionary loaded successfully! Size = %d.\n", dict_size);

  // Open the input and output files
  input_file = fopen(input_filename, "r");
  output_file = fopen(output_filename, "w");
  if(input_file==NULL || output_file==NULL){
    printf("Error opening input or output file.\n");
    return 1;
  }

  // Read each word from the input file and check if it is misspelled
  while(fscanf(input_file, "%s", word) != EOF){
    if(!check_word(word, dictionary, dict_size)){ // the word is NOT found in the dictionary
      fprintf(output_file, "%s\n", word); // output the misspelled word to the output file
    }
  }

  // Close all files and free memory
  fclose(input_file);
  fclose(output_file);
  for(int i=0; i<dict_size; i++){
    free(dictionary[i]);
  }
  free(dictionary);

  printf("Spell checking completed successfully!\n");
  return 0;
}