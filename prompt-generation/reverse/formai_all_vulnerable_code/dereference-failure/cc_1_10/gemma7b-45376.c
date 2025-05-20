//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = insertWord(head->next, word);
  }

  return head;
}

int detectSpam(Word *head, char *text) {
  int spamScore = 0;
  char *words = strtok(text, " ");

  for (Word *word = head; word; word = word->next) {
    if (strstr(words, word->word)) {
      spamScore++;
    }
  }

  return spamScore;
}

int main() {
  Word *head = insertWord(NULL, "spam");
  insertWord(head, "eggs");
  insertWord(head, "ham");

  char *text = "The quick brown fox jumps over the lazy spam.";

  int spamScore = detectSpam(head, text);

  printf("Spam score: %d", spamScore);

  return 0;
}