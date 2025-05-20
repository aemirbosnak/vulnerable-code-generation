//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct UserInput {
  char *buffer;
  int length;
  int capacity;
} UserInput;

UserInput *userInput_alloc(int capacity) {
  UserInput *user_input = malloc(sizeof(UserInput));
  user_input->buffer = malloc(capacity * sizeof(char));
  user_input->length = 0;
  user_input->capacity = capacity;

  return user_input;
}

void userInput_free(UserInput *user_input) {
  free(user_input->buffer);
  free(user_input);
}

int userInput_append(UserInput *user_input, const char *data, int data_length) {
  if (user_input->length + data_length > user_input->capacity) {
    return -1;
  }

  memcpy(user_input->buffer + user_input->length, data, data_length);
  user_input->length += data_length;

  return 0;
}

int main() {
  UserInput *user_input = userInput_alloc(MAX_BUFFER_SIZE);

  // Asynchronous user input
  write(1, "Enter a message: ", 20);
  char data[MAX_BUFFER_SIZE];
  int data_length = read(0, data, MAX_BUFFER_SIZE);

  if (userInput_append(user_input, data, data_length) == -1) {
    write(2, "Error: Input buffer overflow.", 38);
  } else {
    write(1, "Message: ", 9);
    write(1, user_input->buffer, user_input->length);
  }

  userInput_free(user_input);

  return 0;
}