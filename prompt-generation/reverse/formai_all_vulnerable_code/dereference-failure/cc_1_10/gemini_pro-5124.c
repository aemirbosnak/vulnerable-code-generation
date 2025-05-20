//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 100

typedef struct {
  char word[MAX_WORD_LEN];
  int len;
} Word;

typedef struct {
  Word words[MAX_WORDS];
  int num_words;
} Dictionary;

void load_dictionary(Dictionary *dict, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LEN];
  while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
    // Remove newline character
    line[strlen(line) - 1] = '\0';

    // Copy word into dictionary
    strcpy(dict->words[dict->num_words].word, line);
    dict->words[dict->num_words].len = strlen(line);

    dict->num_words++;
  }

  fclose(fp);
}

void print_dictionary(Dictionary *dict) {
  for (int i = 0; i < dict->num_words; i++) {
    printf("%s\n", dict->words[i].word);
  }
}

void test_typing_speed(Dictionary *dict) {
  int start_time = time(NULL);

  char input[MAX_WORD_LEN];
  int correct_words = 0;

  for (int i = 0; i < dict->num_words; i++) {
    printf("%s: ", dict->words[i].word);
    scanf("%s", input);

    if (strcmp(input, dict->words[i].word) == 0) {
      correct_words++;
    }
  }

  int end_time = time(NULL);
  int elapsed_time = end_time - start_time;

  float typing_speed = (float)correct_words / elapsed_time * 60;

  printf("Your typing speed is %.2f words per minute\n", typing_speed);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <dictionary_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  Dictionary dict;
  load_dictionary(&dict, argv[1]);

  // Uncomment to print the dictionary
  // print_dictionary(&dict);

  test_typing_speed(&dict);

  return EXIT_SUCCESS;
}