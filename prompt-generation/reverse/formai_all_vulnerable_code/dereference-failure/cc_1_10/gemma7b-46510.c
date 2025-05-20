//Gemma-7B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_ERR_LEN 256

typedef struct Error {
  char *err_msg;
  int err_no;
} Error;

Error *err_alloc(int err_no, const char *err_msg)
{
  Error *err = malloc(sizeof(Error));
  if (!err) {
    perror("Error allocating memory");
    return NULL;
  }

  err->err_msg = malloc(MAX_ERR_LEN);
  if (!err->err_msg) {
    perror("Error allocating memory");
    free(err);
    return NULL;
  }

  strcpy(err->err_msg, err_msg);
  err->err_no = err_no;

  return err;
}

void err_print(Error *err)
{
  printf("Error: %s (err no: %d)\n", err->err_msg, err->err_no);
}

int main()
{
  Error *err = err_alloc(errno, "Invalid input");
  if (!err) {
    err_print(err);
    return 1;
  }

  err_print(err);
  free(err->err_msg);
  free(err);

  return 0;
}