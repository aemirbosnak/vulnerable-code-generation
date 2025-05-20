//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct node {
  char *name;
  struct node *next;
} node;

typedef struct list {
  node *head;
  node *tail;
} list;

void add(list *l, char *name) {
  node *n = (node *)malloc(sizeof(node));
  n->name = name;
  n->next = NULL;
  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
  } else {
    l->tail->next = n;
    l->tail = n;
  }
}

void print_list(list *l) {
  node *n = l->head;
  while (n != NULL) {
    printf("%s\n", n->name);
    n = n->next;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  char *directory = argv[1];
  DIR *dir = opendir(directory);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  list l;
  l.head = NULL;
  l.tail = NULL;

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *path = (char *)malloc(strlen(directory) + 1 + strlen(entry->d_name) + 1);
    strcpy(path, directory);
    strcat(path, "/");
    strcat(path, entry->d_name);

    struct stat st;
    if (stat(path, &st) != 0) {
      perror("stat");
      continue;
    }

    if (S_ISDIR(st.st_mode)) {
      add(&l, path);
    } else {
      printf("%s: %ld bytes\n", path, st.st_size);
    }

    free(path);
  }

  closedir(dir);

  print_list(&l);

  return 0;
}