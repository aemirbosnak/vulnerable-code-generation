//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert natural language date to numeric format
void convert_date(char *input, char *output) {

  // list of days and months to match against
  char *days[] = {"zero", "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth", "thirteenth", "fourteenth", "fifteenth", "sixteenth", "seventeenth", "eighteenth", "nineteenth", "twentieth", "twenty-first", "twenty-second", "twenty-third", "twenty-fourth", "twenty-fifth", "twenty-sixth", "twenty-seventh", "twenty-eighth", "twenty-ninth", "thirtieth", "thirty-first"};
  
  char *months[] = {"", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

  // remove leading and trailing spaces in input
  int length = strlen(input), index = 0, previous_index = -1;
  while (input[index] == ' ' && index < length) index++; // move past initial spaces
  
  for (int i = index; i <= length; i++) {
    if (input[i] == '\0' || input[i] == ' ') { // word boundary
      int word_length = i - previous_index - 1;
      char *word = calloc(word_length + 1, sizeof(char));
      strncpy(word, input + previous_index + 1, word_length);
      
      char *lowercase_word = calloc(word_length + 1, sizeof(char));
      for (int j = 0; j < word_length; j++) {
        lowercase_word[j] = tolower(word[j]); // convert to lowercase
      }
      free(word);
      
      if (i == length || input[i] == ' ') { // tag the word
        for (int j = 1; j <= 31; j++) { // check if word is a day
          if (strcmp(lowercase_word, days[j]) == 0) { 
            if (j < 10) {
              sprintf(output + strlen(output), "0%d", j);
            } else {
              sprintf(output + strlen(output), "%d", j);
            }
          }
        }
        
        for (int j = 1; j <= 12; j++) { // check if word is a month
          if (strcmp(lowercase_word, months[j]) == 0) {
            if (j < 10) {
              sprintf(output + strlen(output), "/0%d/", j);
            } else {
              sprintf(output + strlen(output), "/%d/", j);
            }
          }
        }
      }
      
      if (i == length) continue; // if end of string, skip space counting
      
      previous_index = i;
    }
  }
}

int main() {
  char input[100], output[10];
  printf("Enter a date in natural language. Example: \"the twenty-fourth of december\" \n");
  fgets(input, 100, stdin);
  input[strlen(input)-1] = '\0'; // remove newline character from input
  
  convert_date(input, output);
  printf("The converted date is: %s", output);
  
  return 0;
}