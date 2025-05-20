//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTIMENT_WORDS 1024

typedef struct SentimentWord {
  char *word;
  int sentiment;
  struct SentimentWord *next;
} SentimentWord;

SentimentWord *sentiment_word_insert(SentimentWord *head, char *word, int sentiment)
{
  SentimentWord *new_word = malloc(sizeof(SentimentWord));
  new_word->word = strdup(word);
  new_word->sentiment = sentiment;
  new_word->next = NULL;

  if (head == NULL) {
    head = new_word;
  } else {
    head->next = sentiment_word_insert(head->next, word, sentiment);
  }

  return head;
}

int sentiment_analysis(SentimentWord *head, char *sentence)
{
  int sentiment = 0;
  char *word = strtok(sentence, " ");

  while (word) {
    SentimentWord *word_node = sentiment_word_insert(head, word, sentiment_analysis(head, word));

    if (word_node->sentiment > sentiment) {
      sentiment = word_node->sentiment;
    }

    word = strtok(NULL, " ");
  }

  return sentiment;
}

int main()
{
  SentimentWord *head = NULL;

  sentiment_word_insert(head, "Happy", 1);
  sentiment_word_insert(head, "Sad", -1);
  sentiment_word_insert(head, "Angry", -2);
  sentiment_word_insert(head, "Joyful", 2);

  char *sentence = "I am happy today, but I am sad because I lost my phone.";

  int sentiment = sentiment_analysis(head, sentence);

  printf("Sentiment of sentence: %d\n", sentiment);

  return 0;
}