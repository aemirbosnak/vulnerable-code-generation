//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *addWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }

  return head;
}

int detectSpam(Word *head) {
  int flags = 0;
  char *keywords[] = {"free", "lottery", "miracle", "prize", "offer"};

  for (Word *word = head; word; word = word->next) {
    for (int i = 0; i < MAX_WORDS; i++) {
      if (strcmp(word->word, keywords[i]) == 0) {
        flags++;
      }
    }
  }

  return flags;
}

int main() {
  Word *head = NULL;
  addWord(head, "Free lottery!");
  addWord(head, "Miracle prize!");
  addWord(head, "Offer of a lifetime!");

  int flags = detectSpam(head);

  printf("Number of spam flags: %d", flags);

  return 0;
}