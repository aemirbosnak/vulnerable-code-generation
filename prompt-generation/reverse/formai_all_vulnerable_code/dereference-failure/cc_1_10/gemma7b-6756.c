//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct Word
{
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL)
  {
    return newWord;
  }

  head->next = insertWord(head->next, word);
  return head;
}

void translate(Word *head, char *source, char *target)
{
  char *sourceWord = strtok(source, " ");
  char *targetWord = strtok(target, " ");

  while (sourceWord && targetWord)
  {
    Word *word = head;

    while (word)
    {
      if (strcmp(word->word, sourceWord) == 0)
      {
        strcpy(targetWord, word->word);
        break;
      }

      word = word->next;
    }

    sourceWord = strtok(NULL, " ");
    targetWord = strtok(NULL, " ");
  }
}

int main()
{
  Word *head = NULL;
  insertWord(head, "Hello");
  insertWord(head, "World");
  insertWord(head, "Cat");

  char *source = "Hello World Cat";
  char *target = "Bonjour le Chat";

  translate(head, source, target);

  printf("%s", target);

  return 0;
}