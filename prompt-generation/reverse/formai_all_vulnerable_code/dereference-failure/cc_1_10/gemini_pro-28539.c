//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *name;
  struct node *next;
} node;

typedef struct list {
  struct node *head;
  struct node *tail;
} list;

void list_init(list *l) {
  l->head = NULL;
  l->tail = NULL;
}

void list_add(list *l, char *name) {
  struct node *n = malloc(sizeof(struct node));
  n->name = strdup(name);
  n->next = NULL;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
  } else {
    l->tail->next = n;
    l->tail = n;
  }
}

void list_free(list *l) {
  struct node *n = l->head;
  while (n != NULL) {
    struct node *next = n->next;
    free(n->name);
    free(n);
    n = next;
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s src dest\n", argv[0]);
    return EXIT_FAILURE;
  }

  list src_files;
  list_init(&src_files);

  FILE *src = fopen(argv[1], "r");
  if (src == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char line[1024];
  while (fgets(line, sizeof(line), src) != NULL) {
    list_add(&src_files, line);
  }

  fclose(src);

  list dest_files;
  list_init(&dest_files);

  FILE *dest = fopen(argv[2], "r");
  if (dest == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(line, sizeof(line), dest) != NULL) {
    list_add(&dest_files, line);
  }

  fclose(dest);

  struct node *src_node = src_files.head;
  struct node *dest_node = dest_files.head;

  while (src_node != NULL && dest_node != NULL) {
    int cmp = strcmp(src_node->name, dest_node->name);
    if (cmp == 0) {
      src_node = src_node->next;
      dest_node = dest_node->next;
    } else if (cmp < 0) {
      printf("Only in src: %s\n", src_node->name);
      src_node = src_node->next;
    } else {
      printf("Only in dest: %s\n", dest_node->name);
      dest_node = dest_node->next;
    }
  }

  while (src_node != NULL) {
    printf("Only in src: %s\n", src_node->name);
    src_node = src_node->next;
  }

  while (dest_node != NULL) {
    printf("Only in dest: %s\n", dest_node->name);
    dest_node = dest_node->next;
  }

  list_free(&src_files);
  list_free(&dest_files);

  return EXIT_SUCCESS;
}