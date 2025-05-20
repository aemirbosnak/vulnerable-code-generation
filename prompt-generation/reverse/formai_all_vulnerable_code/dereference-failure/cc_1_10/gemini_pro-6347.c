//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *buf = NULL;
  size_t bufsize = 0;
  FILE *f = NULL;
  int pid = 0;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s pid\n", argv[0]);
    return EXIT_FAILURE;
  }

  pid = atoi(argv[1]);
  if (pid <= 0) {
    fprintf(stderr, "Invalid PID: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  snprintf(buf, bufsize, "/proc/%d/status", pid);
  f = fopen(buf, "r");
  if (f == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (getline(&buf, &bufsize, f) != -1) {
    char *key = NULL;
    char *value = NULL;

    if (buf[0] == '\n') {
      continue;
    }

    key = strtok(buf, ":");
    if (key == NULL) {
      continue;
    }

    value = strtok(NULL, "\n");
    if (value == NULL) {
      continue;
    }

    printf("%s: %s\n", key, value);
  }

  fclose(f);
  free(buf);

  return EXIT_SUCCESS;
}