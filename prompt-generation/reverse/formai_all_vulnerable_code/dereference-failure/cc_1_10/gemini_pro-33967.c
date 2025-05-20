//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_TOKENS 100

typedef struct {
  char *input;
  int length;
  int num_tokens;
  char **tokens;
} TokenizerArgs;

void *tokenize(void *args) {
  TokenizerArgs *tokenizerArgs = (TokenizerArgs *)args;

  char *input = tokenizerArgs->input;
  int length = tokenizerArgs->length;

  char *token = strtok(input, " ");
  while (token != NULL) {
    tokenizerArgs->tokens[tokenizerArgs->num_tokens++] = strdup(token);
    token = strtok(NULL, " ");
  }

  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
    return 1;
  }

  char *input = argv[1];
  int length = strlen(input);

  TokenizerArgs tokenizerArgs;
  tokenizerArgs.input = input;
  tokenizerArgs.length = length;
  tokenizerArgs.num_tokens = 0;
  tokenizerArgs.tokens = malloc(sizeof(char *) * MAX_TOKENS);

  pthread_t threads[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, tokenize, (void *)&tokenizerArgs);
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Tokens:\n");
  for (int i = 0; i < tokenizerArgs.num_tokens; i++) {
    printf("%s\n", tokenizerArgs.tokens[i]);
  }

  free(tokenizerArgs.tokens);

  return 0;
}