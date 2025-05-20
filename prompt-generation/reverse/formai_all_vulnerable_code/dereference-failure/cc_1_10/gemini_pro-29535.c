//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *word;
  int count;
  struct node *next;
} node_t;

typedef struct {
  node_t *head;
  node_t *tail;
  int size;
} linked_list_t;

linked_list_t *create_linked_list() {
  linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void add_to_linked_list(linked_list_t *list, char *word) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->word = (char *)malloc(strlen(word) + 1);
  strcpy(new_node->word, word);
  new_node->count = 1;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }

  list->size++;
}

void print_linked_list(linked_list_t *list) {
  node_t *current_node = list->head;
  while (current_node != NULL) {
    printf("%s: %d\n", current_node->word, current_node->count);
    current_node = current_node->next;
  }
}

void free_linked_list(linked_list_t *list) {
  node_t *current_node = list->head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node->word);
    free(current_node);
    current_node = next_node;
  }

  free(list);
}

int main() {
  linked_list_t *positive_words = create_linked_list();
  add_to_linked_list(positive_words, "good");
  add_to_linked_list(positive_words, "great");
  add_to_linked_list(positive_words, "excellent");
  add_to_linked_list(positive_words, "amazing");
  add_to_linked_list(positive_words, "wonderful");

  linked_list_t *negative_words = create_linked_list();
  add_to_linked_list(negative_words, "bad");
  add_to_linked_list(negative_words, "terrible");
  add_to_linked_list(negative_words, "awful");
  add_to_linked_list(negative_words, "horrible");
  add_to_linked_list(negative_words, "disgusting");

  char *sentence = "The movie was great and the acting was terrible.";
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    int found_positive = 0;
    node_t *current_node = positive_words->head;
    while (current_node != NULL) {
      if (strcmp(token, current_node->word) == 0) {
        current_node->count++;
        found_positive = 1;
        break;
      }
      current_node = current_node->next;
    }

    if (!found_positive) {
      node_t *current_node = negative_words->head;
      while (current_node != NULL) {
        if (strcmp(token, current_node->word) == 0) {
          current_node->count++;
          break;
        }
        current_node = current_node->next;
      }
    }

    token = strtok(NULL, " ");
  }

  printf("Positive words:\n");
  print_linked_list(positive_words);

  printf("\nNegative words:\n");
  print_linked_list(negative_words);

  free_linked_list(positive_words);
  free_linked_list(negative_words);

  return 0;
}