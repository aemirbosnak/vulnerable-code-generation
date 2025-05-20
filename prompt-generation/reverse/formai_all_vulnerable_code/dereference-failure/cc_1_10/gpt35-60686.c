//FormAI DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_MISSPELLINGS 10

char* randomWord() {
  const char* words[] = {
    "radiation",
    "mutant",
    "wasteland",
    "apocalypse",
    "survivor",
    "scavenger",
    "raider",
    "ghoul",
    "dystopia",
    "anarchy",
    "chaos",
    "doomsday",
    "nuclear",
    "desolate",
    "madness",
    "toxic",
    "barren",
    "danger",
    "armageddon",
    "endgame",
    "havoc",
    "cataclysm",
    "nightmare",
    "devastation",
    "ruin",
    "decay",
    "despair",
    "ruined",
    "ghastly",
    "grim",
    "forsaken",
    "uninhabitable",
    "scorched",
    "emptiness",
    "void",
    "desperation",
    "ominous",
    "feral",
    "destruction",
    "disaster",
    "apocalyptic",
    "post-apocalyptic",
    "zombie",
    "survival",
    "pandemic",
    "plague",
    "contagion",
    "virus",
    "epidemic"
  };
  const int size = sizeof(words) / sizeof(words[0]);
  int index = rand() % size;
  char* word = strdup(words[index]);
  return word;
}

int main() {
  srand(time(NULL));
  char* wordlist[MAX_WORD_LENGTH];
  int num_misspellings = 0;
  printf("Welcome to Post-Apocalyptic Spellchecker!\n");
  printf("Generating wordlist...\n");
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    wordlist[i] = randomWord();
  }
  printf("Wordlist generated!\n");
  printf("Enter text to spell check:\n");
  char input[1000];
  fgets(input, 1000, stdin);
  char* token = strtok(input, " .,:;?!-()\n");
  while (token != NULL) {
    char* word = strdup(token);
    int found = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
      if (strcasecmp(word, wordlist[i]) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      if (num_misspellings < MAX_MISSPELLINGS) {
        printf("Possible misspelling: %s\n", word);
        num_misspellings++;
      } else {
        printf("%s is not a valid word.\n", word);
      }
    }
    free(word);
    token = strtok(NULL, " .,:;?!-()\n");
  }
  printf("Spell check complete.\n");
  return 0;
}