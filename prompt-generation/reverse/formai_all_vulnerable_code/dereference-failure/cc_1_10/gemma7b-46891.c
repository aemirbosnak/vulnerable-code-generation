//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 10
#define BUFFER_SIZE 1024

typedef struct file_sync_t {
  pthread_mutex_t mutex;
  pthread_cond_t cond_wait;
  char filename[256];
  FILE *fp;
  int position;
  struct file_sync_t *next;
} file_sync_t;

file_sync_t *head = NULL;

void file_sync_add(char *filename) {
  file_sync_t *new_node = malloc(sizeof(file_sync_t));
  pthread_mutex_init(&new_node->mutex, NULL);
  pthread_cond_init(&new_node->cond_wait, NULL);
  strcpy(new_node->filename, filename);
  new_node->fp = fopen(filename, "r");
  new_node->position = 0;
  new_node->next = head;
  head = new_node;
}

void file_sync_read(char *buffer, int size) {
  pthread_mutex_lock(&head->mutex);
  fseek(head->fp, head->position, SEEK_SET);
  int read_size = fread(buffer, 1, size, head->fp);
  head->position += read_size;
  pthread_mutex_unlock(&head->mutex);
}

void file_sync_write(char *buffer, int size) {
  pthread_mutex_lock(&head->mutex);
  fseek(head->fp, head->position, SEEK_SET);
  int write_size = fwrite(buffer, 1, size, head->fp);
  head->position += write_size;
  pthread_mutex_unlock(&head->mutex);
}

int main() {
  file_sync_add("test.txt");
  file_sync_add("another.txt");

  char buffer[BUFFER_SIZE];

  file_sync_read(buffer, BUFFER_SIZE);
  file_sync_write(buffer, BUFFER_SIZE);

  return 0;
}