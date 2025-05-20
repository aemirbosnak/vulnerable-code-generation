//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LINE_LEN 1024
#define MAX_BUF_SIZE 4096

int main(void) {
  char *buf = mmap(NULL, MAX_BUF_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
  if (buf == MAP_FAILED) {
    perror("mmap failed");
    return 1;
  }

  char *line = NULL;
  size_t line_len = 0;
  char *prev_line = NULL;

  while (1) {
    char c = getchar();
    if (c == EOF) break;

    if (line == NULL) {
      line = buf;
      line_len = 1;
      prev_line = NULL;
    } else {
      if (line_len + 1 >= MAX_LINE_LEN) {
        line_len = 0;
        prev_line = line;
        line = buf;
      }

      line[line_len] = c;
      line_len++;

      if (c == '\n') {
        if (prev_line != NULL) {
          printf("%s\n", prev_line);
        }
        prev_line = line;
        line = NULL;
      }
    }
  }

  if (prev_line != NULL) {
    printf("%s\n", prev_line);
  }

  munmap(buf, MAX_BUF_SIZE);

  return 0;
}