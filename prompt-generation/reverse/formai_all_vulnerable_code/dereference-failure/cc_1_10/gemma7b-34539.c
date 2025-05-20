//Gemma-7B DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERR_MSG_LEN 256

typedef struct Error {
  int code;
  char message[MAX_ERR_MSG_LEN];
} Error;

Error* err_new(int code, char* msg) {
  Error* err = malloc(sizeof(Error));
  err->code = code;
  strncpy(err->message, msg, MAX_ERR_MSG_LEN);
  return err;
}

void err_print(Error* err) {
  fprintf(stderr, "Error: code %d, message: %s\n", err->code, err->message);
}

int main() {
  Error* err = NULL;
  int result = 0;

  // Malformed data
  char* malformed_data = "This data is malformed!";
  err = err_new(101, malformed_data);
  err_print(err);

  // Missing data
  char* missing_data = "";
  err = err_new(102, missing_data);
  err_print(err);

  // Invalid data format
  char* invalid_format = "This data is in an invalid format!";
  err = err_new(103, invalid_format);
  err_print(err);

  // Unexpected error
  err = err_new(104, "An unexpected error occurred!");
  err_print(err);

  if (err) {
    result = 1;
  }

  return result;
}