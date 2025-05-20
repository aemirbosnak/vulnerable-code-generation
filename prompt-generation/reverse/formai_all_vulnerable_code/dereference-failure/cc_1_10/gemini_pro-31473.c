//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct node {
  char *path;
  struct node *next;
} node_t;

typedef struct list {
  node_t *head;
  node_t *tail;
} list_t;

void list_init(list_t *list) {
  list->head = NULL;
  list->tail = NULL;
}

void list_add(list_t *list, char *path) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->path = strdup(path);
  new_node->next = NULL;

  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void list_free(list_t *list) {
  node_t *current = list->head;

  while (current != NULL) {
    node_t *next = current->next;
    free(current->path);
    free(current);
    current = next;
  }

  list->head = NULL;
  list->tail = NULL;
}

long long get_file_size(char *path) {
  struct stat statbuf;

  if (stat(path, &statbuf) == -1) {
    return -1;
  }

  return statbuf.st_size;
}

void analyze_directory(char *path, list_t *list) {
  DIR *dir = opendir(path);

  if (dir == NULL) {
    return;
  }

  struct dirent *dirent;

  while ((dirent = readdir(dir)) != NULL) {
    if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
      continue;
    }

    char *full_path = malloc(strlen(path) + strlen(dirent->d_name) + 2);
    strcpy(full_path, path);
    strcat(full_path, "/");
    strcat(full_path, dirent->d_name);

    struct stat statbuf;

    if (stat(full_path, &statbuf) == -1) {
      free(full_path);
      continue;
    }

    if (S_ISDIR(statbuf.st_mode)) {
      analyze_directory(full_path, list);
    } else {
      list_add(list, full_path);
    }

    free(full_path);
  }

  closedir(dir);
}

int main() {
  char *path = "/path/to/directory";
  list_t list;
  list_init(&list);
  analyze_directory(path, &list);

  node_t *current = list.head;

  while (current != NULL) {
    long long size = get_file_size(current->path);

    if (size >= 0) {
      printf("%lld %s\n", size, current->path);
    }

    current = current->next;
  }

  list_free(&list);

  return 0;
}