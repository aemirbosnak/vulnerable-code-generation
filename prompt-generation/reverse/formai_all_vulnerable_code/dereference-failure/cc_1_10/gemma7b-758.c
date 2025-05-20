//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 10
#define MAX_NUM_WORDS 5

typedef struct MemoryCell {
  char **words;
  int usedWords;
  int nextAvailableWord;
} MemoryCell;

MemoryCell *createMemoryCell() {
  MemoryCell *cell = malloc(sizeof(MemoryCell));
  cell->words = malloc(sizeof(char *) * MAX_NUM_WORDS);
  cell->usedWords = 0;
  cell->nextAvailableWord = 0;
  return cell;
}

void addWordToMemory(MemoryCell *cell, char *word) {
  if (cell->usedWords == MAX_NUM_WORDS) {
    return;
  }
  cell->words[cell->nextAvailableWord] = strdup(word);
  cell->usedWords++;
  cell->nextAvailableWord++;
}

int findWordInMemory(MemoryCell *cell, char *word) {
  for (int i = 0; i < cell->usedWords; i++) {
    if (strcmp(cell->words[i], word) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  MemoryCell *cell = createMemoryCell();
  addWordToMemory(cell, "apple");
  addWordToMemory(cell, "banana");
  addWordToMemory(cell, "orange");
  addWordToMemory(cell, "peach");
  addWordToMemory(cell, "apricot");

  int index = findWordInMemory(cell, "banana");
  if (index != -1) {
    printf("Word found at index %d: %s\n", index, cell->words[index]);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}