//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_SIZE 10000

typedef struct node {
  char word[MAX_WORD_LEN];
  struct node *next;
} node_t;

node_t *dict_head = NULL;

int load_dictionary(char *filename) {
  FILE *fp;
  char line[MAX_WORD_LEN];
  node_t *new_node;

  if ((fp = fopen(filename, "r")) == NULL) {
    perror("fopen");
    return -1;
  }

  while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
    new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
      perror("malloc");
      return -1;
    }

    strcpy(new_node->word, line);
    new_node->next = dict_head;
    dict_head = new_node;
  }

  fclose(fp);

  return 0;
}

int check_spelling(char *word) {
  node_t *current = dict_head;

  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }

    current = current->next;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <dictionary file> <input file>\n", argv[0]);
    return -1;
  }

  if (load_dictionary(argv[1]) != 0) {
    return -1;
  }

  FILE *fp;
  char line[MAX_WORD_LEN];
  int errors = 0;

  if ((fp = fopen(argv[2], "r")) == NULL) {
    perror("fopen");
    return -1;
  }

  while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
    if (!check_spelling(line)) {
      printf("Error: %s is not in the dictionary.\n", line);
      errors++;
    }
  }

  fclose(fp);

  printf("%d errors found.\n", errors);

  return 0;
}