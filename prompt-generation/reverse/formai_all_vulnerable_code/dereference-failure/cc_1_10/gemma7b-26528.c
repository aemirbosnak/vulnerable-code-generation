//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void d_malloc(void **ptr, int sz) {
  *ptr = malloc(sz);
  if (*ptr == NULL) {
    printf("Error allocating memory.\n");
    exit(1);
  }
}

void d_free(void **ptr) {
  free(*ptr);
  *ptr = NULL;
}

int main() {
  char **diary = NULL;
  int size = 0;
  char line[1024];

  printf("Enter 'add' to add a new entry, 'read' to read entries, 'quit' to quit: ");
  scanf("%s", line);

  switch (line[0]) {
    case 'a':
      d_malloc(&diary, size * 1.2);
      printf("Enter your entry: ");
      scanf("%s", line);
      diary[size++] = strdup(line);
      break;
    case 'r':
      if (size == 0) {
        printf("There are no entries.\n");
      } else {
        printf("Entries:\n");
        for (int i = 0; i < size; i++) {
          printf("%d. %s\n", i + 1, diary[i]);
        }
      }
      break;
    case 'q':
      d_free(&diary);
      exit(0);
    default:
      printf("Invalid command.\n");
  }

  return 0;
}