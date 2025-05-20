//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *word;
  struct node *next;
} node;

node *create_node(char *word) {
  node *new_node = malloc(sizeof(node));
  new_node->word = strdup(word);
  new_node->next = NULL;
  return new_node;
}

void add_word(node **head, char *word) {
  if (*head == NULL) {
    *head = create_node(word);
    return;
  }
  node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = create_node(word);
}

int check_spelling(node *head, char *word) {
  node *current = head;
  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void free_list(node *head) {
  if (head == NULL) {
    return;
  }
  node *current = head;
  while (current->next != NULL) {
    node *next = current->next;
    free(current->word);
    free(current);
    current = next;
  }
  free(current->word);
  free(current);
}

int main() {
  node *head = NULL;

  // Let's add some words to our dictionary!
  add_word(&head, "hello");
  add_word(&head, "world");
  add_word(&head, "computer");
  add_word(&head, "science");
  add_word(&head, "programming");
  add_word(&head, "happy");
  add_word(&head, "excited");

  // Now, let's check some words!
  char *word = "hello";
  if (check_spelling(head, word)) {
    printf("Yay! '%s' is spelled correctly!\n", word);
  } else {
    printf("Oops! '%s' is spelled incorrectly.\n", word);
  }

  word = "computer1"; // Let's add a typo to see how our program handles it
  if (check_spelling(head, word)) {
    printf("Yay! '%s' is spelled correctly!\n", word);
  } else {
    printf("Oops! '%s' is spelled incorrectly.\n", word);
  }

  // Time to clean up our dictionary
  free_list(head);

  return 0;
}