//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A retro-style input sanitizer that uses a state machine to validate input
// and prevent buffer overflows.

// The state machine states
enum state {
  START,
  DIGIT,
  DOT,
  E,
  SIGN,
  INVALID
};

// The state machine transitions
const int transitions[][6] = {
  // START state
  {DIGIT, DOT, INVALID, INVALID, INVALID, INVALID},
  // DIGIT state
  {DIGIT, DOT, E, INVALID, INVALID, INVALID},
  // DOT state
  {DIGIT, INVALID, INVALID, INVALID, INVALID, INVALID},
  // E state
  {DIGIT, INVALID, INVALID, SIGN, INVALID, INVALID},
  // SIGN state
  {DIGIT, INVALID, INVALID, INVALID, INVALID, INVALID},
  // INVALID state
  {INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}
};

// The input sanitization function
char *sanitize(char *input) {
  int state = START;
  char *sanitized = malloc(strlen(input) + 1);
  int i = 0;
  int j = 0;
  while (input[i] != '\0') {
    char c = input[i];
    int next_state = transitions[state][c - '0'];
    if (next_state == INVALID) {
      break;
    }
    if (next_state != START) {
      sanitized[j++] = c;
    }
    state = next_state;
    i++;
  }
  sanitized[j] = '\0';
  return sanitized;
}

// A retro-style main function that demonstrates the input sanitizer
int main() {
  char *input = "123.45e+6";
  char *sanitized = sanitize(input);
  printf("Input: %s\n", input);
  printf("Sanitized: %s\n", sanitized);
  free(sanitized);
  return 0;
}