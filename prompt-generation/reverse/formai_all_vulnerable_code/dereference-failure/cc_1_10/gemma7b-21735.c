//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FILES 10

struct file_info {
  char filename[256];
  pthread_mutex_t mutex;
  FILE *fp;
  int line_number;
  struct file_info *next;
};

struct file_info *head = NULL;

pthread_mutex_t file_mutex;

void add_file(char *filename) {
  pthread_mutex_lock(&file_mutex);

  struct file_info *new_file = malloc(sizeof(struct file_info));
  new_file->filename[0] = '\0';
  strcpy(new_file->filename, filename);
  new_file->fp = fopen(filename, "r");
  new_file->line_number = 1;
  new_file->next = head;
  head = new_file;

  pthread_mutex_unlock(&file_mutex);
}

void sync_line(int line_number) {
  pthread_mutex_lock(&file_mutex);

  struct file_info *file = head;
  while (file) {
    if (file->line_number == line_number) {
      pthread_mutex_lock(&file->mutex);
      printf("Line %d: %s\n", line_number, file->fp);
      pthread_mutex_unlock(&file->mutex);
    }
    file = file->next;
  }

  pthread_mutex_unlock(&file_mutex);
}

int main() {
  add_file("foo.txt");
  add_file("bar.txt");

  sync_line(10);
  sync_line(20);

  return 0;
}