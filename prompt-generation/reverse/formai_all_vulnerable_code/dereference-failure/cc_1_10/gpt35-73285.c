//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_SIZE 5000

/* Define struct for holding dictionary words */
typedef struct {
  char word[MAX_WORD_LENGTH];
} dict_word;

/* A function to compare words in our dictionary */
int compare_words(const void* a, const void* b) {
  dict_word* dict_a = (dict_word*)a;
  dict_word* dict_b = (dict_word*)b;

  return strcmp(dict_a->word, dict_b->word);
}

/* A function to load words into our dictionary */
int load_dict(dict_word* dict) {
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  int word_count = 0;

  fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    printf("Error: unable to open dictionary file\n");
    return -1;
  }

  /* Read dictionary file line by line */
  while ((read = getline(&line, &len, fp)) != -1) {
    /* Remove newline character at end of line */
    line[strcspn(line, "\n")] = '\0';
    
    /* Copy word into dictionary array */
    strcpy(dict[word_count].word, line);
    word_count++;
  }

  fclose(fp);

  /* Sort dictionary array */
  qsort(dict, word_count, sizeof(dict_word), compare_words);

  return word_count;
}

/* A function to check if a word is spelled correctly */
void check_word(char* word, dict_word* dict, int dict_size) {
  /* Convert word to lowercase */
  int i;
  for (i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  /* Initialize binary search variables */
  int low = 0;
  int high = dict_size - 1;
  int mid;

  /* Binary search loop */
  while (low <= high) {
    mid = (low + high) / 2;

    /* Compare search term to middle word in dictionary */
    int cmp = strcmp(word, dict[mid].word);

    if (cmp == 0) {
      /* Word is in dictionary */
      printf("%s is spelled correctly!\n", word);
      return;
    } else if (cmp < 0) {
      /* Word is less than middle word in dictionary */
      high = mid - 1;
    } else {
      /* Word is greater than middle word in dictionary */
      low = mid + 1;
    }
  }

  /* Word is not in dictionary */
  printf("%s is not in the dictionary.\n", word);
}

int main() {
  dict_word dict[MAX_DICT_SIZE];
  int dict_size = load_dict(dict);

  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  /* Prompt user to enter text to spell-check */
  printf("Enter text to spellcheck (press CTRL+D to exit):\n");

  /* Read text line by line */
  while ((read = getline(&line, &len, stdin)) != -1) {
    /* Tokenize line into individual words */
    char* word = strtok(line, " \t\n");

    while (word != NULL) {
      /* Check if word is spelled correctly */
      check_word(word, dict, dict_size);

      /* Get next word */
      word = strtok(NULL, " \t\n");
    }
  }

  free(line);

  return 0;
}