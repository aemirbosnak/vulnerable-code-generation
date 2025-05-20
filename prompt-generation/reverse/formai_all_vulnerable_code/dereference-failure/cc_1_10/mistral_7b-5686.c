//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1024 * 1024
#define NUM_FILES 5

void create_random_file(char *filename) {
  int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  char *data = malloc(MAX_FILE_SIZE);
  int i;

  if (fd < 0) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < MAX_FILE_SIZE; i++) {
    data[i] = rand() % 256;
  }

  write(fd, data, MAX_FILE_SIZE);
  close(fd);
  free(data);
}

int main() {
  char *filename;
  int i;

  if (geteuid() != 0) {
    fprintf(stderr, "This program must be run as root\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < NUM_FILES; i++) {
    filename = malloc(sizeof(char) * 32);
    sprintf(filename, "/tmp/random_file_%d.txt", i);
    create_random_file(filename);
    free(filename);
  }

  printf("Successfully created %d random files in /tmp directory\n", NUM_FILES);

  return EXIT_SUCCESS;
}