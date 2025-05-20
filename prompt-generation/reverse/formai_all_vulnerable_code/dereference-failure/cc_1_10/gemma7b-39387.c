//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ANSWERS 5

typedef struct _Oracle {
  char **answers;
  int current_answer_index;
  int num_answers;
} Oracle;

Oracle* oracle_init() {
  Oracle* oracle = malloc(sizeof(Oracle));
  oracle->answers = NULL;
  oracle->current_answer_index = 0;
  oracle->num_answers = 0;
  return oracle;
}

void oracle_add_answer(Oracle* oracle, char* answer) {
  oracle->num_answers++;
  oracle->answers = realloc(oracle->answers, oracle->num_answers * sizeof(char*));
  oracle->answers[oracle->current_answer_index] = answer;
  oracle->current_answer_index++;
}

char* oracle_get_answer(Oracle* oracle) {
  if (oracle->num_answers == 0) {
    return NULL;
  }
  return oracle->answers[oracle->current_answer_index - 1];
}

int main() {
  Oracle* oracle = oracle_init();
  oracle_add_answer(oracle, "You will have a lucky day.");
  oracle_add_answer(oracle, "You will find love.");
  oracle_add_answer(oracle, "You will be wealthy.");
  oracle_add_answer(oracle, "You will be successful.");
  oracle_add_answer(oracle, "You will be happy.");

  srand(time(NULL));
  int random_answer_index = rand() % oracle->num_answers;
  char* answer = oracle_get_answer(oracle);

  if (answer) {
    printf("Your fortune is: %s\n", answer);
  } else {
    printf("Sorry, I have no answers for you.\n");
  }

  return 0;
}