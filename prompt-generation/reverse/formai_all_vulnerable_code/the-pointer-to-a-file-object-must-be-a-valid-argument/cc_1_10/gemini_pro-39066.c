//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ** GENIUS **

typedef struct _node {
  char *word;
  struct _node *next;
} Node;

typedef struct _list {
  Node *head;
  Node *tail;
  int size;
} List;

List* create_list() {
  List *list = (List*)malloc(sizeof(List));
  list->head = list->tail = NULL;
  list->size = 0;
  return list;
}

void add_to_list(List *list, char *word) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->word = strdup(word);
  node->next = NULL;
  if (list->size == 0) {
    list->head = list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

void free_list(List *list) {
  Node *current = list->head;
  while (current != NULL) {
    Node *next = current->next;
    free(current->word);
    free(current);
    current = next;
  }
  free(list);
}

int compare_strings(const char *s1, const char *s2) {
  return strcmp(s1, s2);
}

int main() {
  // ** GENIUS **

  // Initialize the random number generator.
  srand(time(NULL));

  // Create a list of words.
  List *words = create_list();
  FILE *fp = fopen("words.txt", "r");
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    char *word = strtok(buffer, "\n");
    add_to_list(words, word);
  }
  fclose(fp);

  // Get the user's input.
  char input[1024];
  printf("Type the following words as quickly and accurately as possible:\n");
  for (int i = 0; i < words->size; i++) {
    Node *node = words->head;
    while (node != NULL) {
      printf("%s ", node->word);
      node = node->next;
    }
  }
  printf("\n");
  scanf("%s", input);

  // Compare the user's input to the list of words.
  int errors = 0;
  Node *current = words->head;
  char *token = strtok(input, " ");
  while (token != NULL) {
    if (compare_strings(token, current->word) != 0) {
      errors++;
    }
    current = current->next;
    token = strtok(NULL, " ");
  }

  // Print the results.
  printf("You made %d errors.\n", errors);

  // Free the list of words.
  free_list(words);

  return 0;
}