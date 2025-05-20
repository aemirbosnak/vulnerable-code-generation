//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct Word
{
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
  Word *newWord = (Word *)malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL)
  {
    head = newWord;
  }
  else
  {
    head->next = insertWord(head->next, word);
  }

  return head;
}

void translateCCat(Word *head)
{
  while (head)
  {
    char *original = head->word;
    char *translated = malloc(strlen(original) * 2);

    for (int i = 0; i < strlen(original); i++)
    {
      switch (original[i])
      {
        case 'a':
          translated[i] = 'A';
          break;
        case 'e':
          translated[i] = 'E';
          break;
        case 'i':
          translated[i] = 'I';
          break;
        case 'o':
          translated[i] = 'O';
          break;
        case 'u':
          translated[i] = 'U';
          break;
        default:
          translated[i] = original[i];
          break;
      }
    }

    printf("%s - > %s\n", original, translated);

    free(translated);
    head = head->next;
  }
}

int main()
{
  Word *head = insertWord(NULL, "Meow");
  insertWord(head, "Purr");
  insertWord(head, "Meow");
  insertWord(head, "Woof");

  translateCCat(head);

  return 0;
}