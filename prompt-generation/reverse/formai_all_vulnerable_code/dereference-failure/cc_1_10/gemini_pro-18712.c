//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memory.h"

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct {
  node *head;
  node *tail;
} list;

void init_list(list *l) {
  l->head = NULL;
  l->tail = NULL;
}

void free_list(list *l) {
  node *current = l->head;
  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }
}

void add_to_list(list *l, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (l->head == NULL) {
    l->head = new_node;
  } else {
    l->tail->next = new_node;
  }
  l->tail = new_node;
}

int remove_from_list(list *l, int data) {
  node *current = l->head;
  node *prev = NULL;
  while (current != NULL) {
    if (current->data == data) {
      if (prev == NULL) {
        l->head = current->next;
      } else {
        prev->next = current->next;
      }
      if (current == l->tail) {
        l->tail = prev;
      }
      free(current);
      return 1;
    }
    prev = current;
    current = current->next;
  }
  return 0;
}

int find_in_list(list *l, int data) {
  node *current = l->head;
  while (current != NULL) {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void print_list(list *l) {
  node *current = l->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  list game_list;
  init_list(&game_list);
  int num_cards = 10;
  for (int i = 0; i < num_cards; i++) {
    int card = rand() % num_cards;
    add_to_list(&game_list, card);
  }
  print_list(&game_list);
  int guess1, guess2;
  printf("Enter two guesses (0-%d): ", num_cards - 1);
  scanf("%d %d", &guess1, &guess2);
  if (guess1 == guess2) {
    printf("Congratulations! You matched a pair!\n");
    remove_from_list(&game_list, guess1);
  } else {
    printf("Sorry, try again!\n");
  }
  print_list(&game_list);
  return 0;
}