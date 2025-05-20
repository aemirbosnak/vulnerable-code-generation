//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* createWordList() {
  Word* head = malloc(sizeof(Word));
  head->next = NULL;
  return head;
}

void addWordToList(Word* head, char* word) {
  Word* newNode = malloc(sizeof(Word));
  newNode->word[0] = '\0';
  strcpy(newNode->word, word);
  newNode->next = head->next;
  head->next = newNode;
}

int main() {
  Word* head = createWordList();

  // Fill the word list with sample words
  addWordToList(head, "Hello");
  addWordToList(head, "World");
  addWordToList(head, "This");
  addWordToList(head, "Is");
  addWordToList(head, "A");
  addWordToList(head, "List");

  // Start the timer
  clock_t start = clock();

  // Type the words as fast as you can
  for (int i = 0; i < MAX_WORDS; i++) {
    char word[WORDS_PER_LINE];
    printf("Enter a word: ");
    scanf("%s", word);
    addWordToList(head, word);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the time taken
  int timeTaken = (end - start) / CLOCKS_PER_SEC;

  // Print the time taken
  printf("Time taken: %d seconds\n", timeTaken);

  return 0;
}