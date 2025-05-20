//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define MIN_NUM 1

typedef struct oracle {
  int num;
  struct oracle *next;
} Oracle;

void initializeOracle(Oracle *oracle) {
  oracle->num = rand() % MAX_NUM + MIN_NUM;
  oracle->next = NULL;
}

void addOracle(Oracle *oracle) {
  Oracle *newOracle = malloc(sizeof(Oracle));
  initializeOracle(newOracle);
  if (oracle) {
    oracle->next = newOracle;
  } else {
    oracle = newOracle;
  }
}

int interpretOracle(Oracle *oracle) {
  if (oracle) {
    return oracle->num;
  } else {
    return -1;
  }
}

int main() {
  Oracle *oracle = NULL;
  initializeOracle(oracle);
  addOracle(oracle);
  addOracle(oracle);
  addOracle(oracle);

  int number = interpretOracle(oracle);
  if (number != -1) {
    printf("Your lucky number is: %d\n", number);
  } else {
    printf("No oracle available.\n");
  }

  return 0;
}