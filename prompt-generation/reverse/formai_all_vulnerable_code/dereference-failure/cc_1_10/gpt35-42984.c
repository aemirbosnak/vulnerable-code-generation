//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50 // maximum length of a word
#define MAX_WORDS 1000 // maximum number of unique words to count
#define MAX_CONFIG_VALUES 5 // maximum number of configurable values

int numWords = 0; // number of unique words
char words[MAX_WORDS][MAX_WORD_LEN]; // array to hold unique words
int frequencies[MAX_WORDS] = {0}; // array to hold word frequencies
char configNames[MAX_CONFIG_VALUES][MAX_WORD_LEN]; // array to hold configuration names
int configValues[MAX_CONFIG_VALUES] = {0}; // array to hold configuration values
int numConfigValues = 0; // number of configurable values
char inputFilename[MAX_WORD_LEN]; // name of input file
char outputFilename[MAX_WORD_LEN]; // name of output file

// function to add a word to the list of unique words
void addWord(char* word) {
  // check if word is already in array and increment frequency if it is
  for (int i = 0; i < numWords; i++) {
    if (strcmp(word, words[i]) == 0) {
      frequencies[i]++;
      return;
    }
  }
  // add new word to array
  strcpy(words[numWords], word);
  frequencies[numWords] = 1;
  numWords++;
}

// function to parse a line of text into words
void parseLine(char* line) {
  char* word = strtok(line, " .,!?\n");
  while (word != NULL) {
    // convert to lowercase
    for (int i = 0; word[i]; i++) {
      word[i] = tolower(word[i]);
    }
    addWord(word);
    word = strtok(NULL, " .,!?\n");
  }
}

// function to print the list of unique words and their frequencies to a file
void printWordFrequencies(char* outputFile) {
  FILE* fp = fopen(outputFile, "w");
  if (fp == NULL) {
    printf("Error: could not open output file\n");
    exit(1);
  }
  for (int i = 0; i < numWords; i++) {
    fprintf(fp, "%s: %d\n", words[i], frequencies[i]);
  }
  fclose(fp);
}

// function to read configuration values from a file
void readConfigFile(char* configFile) {
  FILE* fp = fopen(configFile, "r");
  if (fp == NULL) {
    printf("Error: could not open config file\n");
    exit(1);
  }
  char line[MAX_WORD_LEN];
  while (fgets(line, sizeof(line), fp)) {
    char* name = strtok(line, "=");
    char* value = strtok(NULL, "=");
    // trim whitespace from value
    while (isspace(value[0])) {
      value++;
    }
    char* endptr;
    configValues[numConfigValues] = strtol(value, &endptr, 10);
    if (*endptr != '\0') {
      printf("Error: invalid value in config file\n");
      exit(1);
    }
    strcpy(configNames[numConfigValues], name);
    numConfigValues++;
  }
  fclose(fp);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: wordfreq <input file> [<config file>] [-o <output file>]\n");
    exit(1);
  }

  // parse command line arguments
  strcpy(inputFilename, argv[1]);
  if (argc > 2 && strcmp(argv[2], "-o") != 0) {
    readConfigFile(argv[2]);
  }
  for (int i = 3; i < argc; i++) {
    if (strcmp(argv[i], "-o") == 0 && i+1 < argc) {
      strcpy(outputFilename, argv[i+1]);
      i++;
    }
  }

  // process input file
  FILE* fp = fopen(inputFilename, "r");
  if (fp == NULL) {
    printf("Error: could not open input file\n");
    exit(1);
  }
  char line[MAX_WORD_LEN];
  while (fgets(line, sizeof(line), fp)) {
    parseLine(line);
  }
  fclose(fp);

  // apply configuration values
  for (int i = 0; i < numConfigValues; i++) {
    if (strcmp(configNames[i], "max_words") == 0) {
      if (configValues[i] < numWords) {
        numWords = configValues[i];
      }
    } else if (strcmp(configNames[i], "min_freq") == 0) {
      for (int j = 0; j < numWords; j++) {
        if (frequencies[j] < configValues[i]) {
          numWords = j;
          break;
        }
      }
    }
  }

  // print word frequencies to output file
  if (strlen(outputFilename) > 0) {
    printWordFrequencies(outputFilename);
  } else {
    for (int i = 0; i < numWords; i++) {
      printf("%s: %d\n", words[i], frequencies[i]);
    }
  }

  return 0;
}