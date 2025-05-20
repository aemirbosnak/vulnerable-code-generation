//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
/* This is a program that reads in a text file, reverses the words in each line, 
and then outputs the modified content to a new file.
It uses dynamic memory allocation to store each line and each word in the line. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  FILE *fp_in = fopen("input.txt", "r");
  FILE *fp_out = fopen("output.txt", "w");
  char *line = NULL, *word = NULL;
  size_t len = 0;
  ssize_t read;
  
  if (fp_in == NULL || fp_out == NULL) {
    fprintf(stderr, "Error opening files.\n");
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &len, fp_in)) != -1) {
    // remove newline character
    line[strcspn(line, "\n")] = '\0';
    
    // tokenize line by space
    word = strtok(line, " ");
    char **words = malloc(sizeof(char *));
    int count = 0, size = 1;

    while (word) {
      // allocate memory for each word
      words[count] = malloc(strlen(word) + 1);
      strcpy(words[count], word);
      
      // double the array size when needed
      if (++count == size) {
        size *= 2;
        words = realloc(words, size * sizeof(char *));
      }
      
      word = strtok(NULL, " ");
    }
    
    // print words in reverse order
    for (int i = count-1; i >= 0; i--) {
      fprintf(fp_out, "%s ", words[i]);
      free(words[i]);
    }

    // free memory and print newline
    free(words);
    fprintf(fp_out, "\n");
  }

  // close files and free memory
  fclose(fp_in);
  fclose(fp_out);
  if (line)
    free(line);
    
  return 0;
}