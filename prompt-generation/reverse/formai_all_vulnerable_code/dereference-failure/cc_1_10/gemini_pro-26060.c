//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
  char *data;
  struct node *next;
} node;

node *head = NULL;

void insert(char *data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = malloc(strlen(data) + 1);
  strcpy(new_node->data, data);
  new_node->next = head;
  head = new_node;
}

void print_list() {
  node *current = head;
  while (current != NULL) {
    printf("%s\n", current->data);
    current = current->next;
  }
}

void free_list() {
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free(current->data);
    free(current);
    current = next;
  }
  head = NULL;
}

int main() {
  // The lost love letters
  char *letters[] = {
    "My dearest, I miss you more than words can say.",
    "I remember the day we met, like it was a fairy tale.",
    "Your eyes sparkled like diamonds, and your smile lit up my world.",
    "We shared so many beautiful moments together, moments I will cherish forever.",
    "But then you left, and my heart was broken into a million pieces.",
    "I've been searching for you ever since, my love.",
    "I know we're meant to be together, and I will never give up hope.",
    "Please come back to me, my darling.",
    "I love you more than anything in the world.",
    "Yours forever and always,"
  };

  // The scattered words
  char *words[] = {
    "dearest", "miss", "more", "words", "say",
    "remember", "day", "met", "fairy", "tale",
    "eyes", "sparkled", "diamonds", "smile", "lit", "world",
    "shared", "beautiful", "moments", "cherish", "forever",
    "left", "heart", "broken", "pieces", "searching",
    "love", "meant", "together", "never", "give", "hope",
    "back", "darling", "anything", "world", "yours", "always",
  };

  // Recover the lost love letters
  for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
    insert(words[i]);
  }

  // Print the recovered love letters
  printf("My recovered love letters:\n");
  print_list();

  // Free the recovered love letters
  free_list();

  return 0;
}