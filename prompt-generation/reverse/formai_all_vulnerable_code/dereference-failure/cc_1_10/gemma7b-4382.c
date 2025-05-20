//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ParserState {
  char *buffer;
  int bufferSize;
  int position;
  int state;
  struct ParserState *next;
} ParserState;

void initParserState(ParserState *state) {
  state->buffer = NULL;
  state->bufferSize = MAX_BUFFER_SIZE;
  state->position = 0;
  state->state = 0;
  state->next = NULL;
}

void parseXml(ParserState *state, char *xml) {
  state->buffer = realloc(state->buffer, state->bufferSize * 2);
  state->bufferSize *= 2;
  state->position = 0;
  state->state = 0;

  for (int i = 0; xml[i] != '\0'; i++) {
    switch (state->state) {
      case 0:
        if (xml[i] == '<') {
          state->state = 1;
        } else {
          state->position++;
        }
        break;
      case 1:
        if (xml[i] == '>') {
          state->state = 2;
        } else {
          state->position++;
        }
        break;
      case 2:
        if (xml[i] == '/') {
          state->state = 0;
        } else {
          state->position++;
        }
        break;
    }

    state->buffer[state->position] = xml[i];
  }

  state->buffer[state->position] = '\0';
}

int main() {
  ParserState *state = malloc(sizeof(ParserState));
  initParserState(state);

  char xml[] = "<?xml version=\"1.0\" encoding=\"UTF-8\">Hello, world!</xml>";
  parseXml(state, xml);

  printf("%s\n", state->buffer);

  free(state->buffer);
  free(state);

  return 0;
}