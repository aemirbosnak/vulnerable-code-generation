//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextBlock {
  char *text;
  int size;
} TextBlock;

void textBlock_init(TextBlock *block, int size) {
  block->text = malloc(size);
  block->size = size;
}

void textBlock_append(TextBlock *block, char *text, int length) {
  int newSize = block->size + length + 1;
  block->text = realloc(block->text, newSize);
  memcpy(block->text + block->size, text, length);
  block->size += length;
}

char *textBlock_get(TextBlock *block) {
  return block->text;
}

int textBlock_size(TextBlock *block) {
  return block->size;
}

int main() {
  TextBlock *textBlock = NULL;
  textBlock_init(textBlock, MAX_BUFFER_SIZE);

  char *text = "This is a sample text that will be stored in the text block.";
  textBlock_append(textBlock, text, strlen(text));

  text = "This is additional text that will be appended to the text block.";
  textBlock_append(textBlock, text, strlen(text));

  printf("Text stored in the text block:\n");
  printf("%s", textBlock_get(textBlock));

  printf("\nTotal size of text block: %d bytes", textBlock_size(textBlock));

  free(textBlock->text);
  free(textBlock);

  return 0;
}