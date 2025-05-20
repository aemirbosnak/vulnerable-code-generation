//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
// This spell checking program will read text from a file and check the spelling of each word against a dictionary file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to convert a word to lowercase
void toLowercase(char *word) {
  for (int i=0; i<strlen(word); i++) {
    word[i] = tolower(word[i]);
  }
}

int main() {
  FILE *dictionaryFile = fopen("dictionary.txt", "r");
  FILE *textFile = fopen("text.txt", "r");
  FILE *outputFile = fopen("output.txt", "w");

  if (dictionaryFile == NULL || textFile == NULL || outputFile == NULL) {
    printf("Error opening files.\n");
    exit(1);
  }

  char dictionaryWord[50];
  char textWord[50];
  int found;

  // read words from text file
  while (fscanf(textFile, "%s", textWord) == 1) {
    found = 0;

    // convert word to lowercase
    toLowercase(textWord);

    // compare word to words in dictionary file
    while (fscanf(dictionaryFile, "%s", dictionaryWord) == 1) {
      // convert dictionary word to lowercase
      toLowercase(dictionaryWord);

      // if words match, set found flag and break out of loop
      if (strcmp(textWord, dictionaryWord) == 0) {
        found = 1;
        break;
      }
    }

    // print word to output file if not found in dictionary
    if (!found) {
      fprintf(outputFile, "%s\n", textWord);
    }

    // reset file pointer to beginning of dictionary file
    rewind(dictionaryFile);
  }

  // close files
  fclose(dictionaryFile);
  fclose(textFile);
  fclose(outputFile);

  return 0;
}