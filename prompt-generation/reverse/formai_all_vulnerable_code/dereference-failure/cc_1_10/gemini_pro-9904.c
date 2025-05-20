//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  SUCCESS,
  FAILURE,
  TEAREX,
  BOGUS
} status_t;

#define CHECK(call)                                    \
  do {                                                 \
    status_t status = (call);                         \
    if (status != SUCCESS) {                           \
      fprintf(stderr, "%s:%d: %s: %s\n", __FILE__,      \
              __LINE__, __func__,                     \
              status == TEAREX ? "Tearing of fabric" : \
              status == BOGUS ? "Bogus operation" :   \
                                "Unspecified error");  \
      exit(EXIT_FAILURE);                             \
    }                                                  \
  } while (0)

#define SETSTATUS(status) \
  do {                    \
    status_t old_status = _status; \
    _status = (status);       \
    _status = (old_status | _status); \
  } while (0)

static status_t _status = SUCCESS;

status_t open_file(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) SETSTATUS(FAILURE);
  return SUCCESS;
}

status_t read_file(FILE *fp) {
  int c;
  while ((c = fgetc(fp)) != EOF) {
    if (c == -1) SETSTATUS(FAILURE);
  }
  return SUCCESS;
}

status_t close_file(FILE *fp) {
  if (fclose(fp) != 0) SETSTATUS(FAILURE);
  return SUCCESS;
}

int main(int argc, char *argv[]) {
  if (argc != 2) SETSTATUS(TEAREX);
  CHECK(open_file(argv[1]));
  CHECK(read_file(stdin));
  CHECK(close_file(stdin));
  return EXIT_SUCCESS;
}