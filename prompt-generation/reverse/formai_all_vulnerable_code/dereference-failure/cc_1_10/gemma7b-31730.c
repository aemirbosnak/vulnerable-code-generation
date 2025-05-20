//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1024

typedef struct word_node {
  char word[MAX_WORDS];
  struct word_node* next;
} word_node;

word_node* insert_word(word_node* head, char* word) {
  word_node* newNode = malloc(sizeof(word_node));
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  head->next = insert_word(head->next, word);
  return head;
}

double sentiment_analysis(word_node* head) {
  double sentiment = 0.0;
  char* words[] = {"good", "bad", "happy", "sad", "positive", "negative"};

  for (int i = 0; i < 6; i++) {
    char* word = words[i];
    if (search_word(head, word) == 1) {
      sentiment += 1.0;
    }
  }

  return sentiment;
}

int search_word(word_node* head, char* word) {
  while (head) {
    if (strcmp(head->word, word) == 0) {
      return 1;
    }
    head = head->next;
  }

  return 0;
}

int main() {
  word_node* head = NULL;
  insert_word(head, "good");
  insert_word(head, "bad");
  insert_word(head, "happy");
  insert_word(head, "sad");
  insert_word(head, "positive");
  insert_word(head, "negative");

  double sentiment = sentiment_analysis(head);
  printf("Sentiment: %.2f", sentiment);

  return 0;
}