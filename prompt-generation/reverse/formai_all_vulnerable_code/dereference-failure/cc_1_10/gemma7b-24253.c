//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

struct Solver {
  Node* head;
  int score;
  char currentWord[MAX_BUFFER_SIZE];
  char nextWord[MAX_BUFFER_SIZE];
};

void insertNode(struct Solver* solver, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (solver->head == NULL) {
    solver->head = newNode;
  } else {
    solver->head->next = newNode;
  }
}

void solveWord(struct Solver* solver) {
  solver->score++;
  strcpy(solver->currentWord, solver->nextWord);
  insertNode(solver, solver->nextWord[0]);
  solver->nextWord[0] = '\0';
}

int main() {
  struct Solver solver;
  solver.head = NULL;
  solver.score = 0;
  strcpy(solver.currentWord, "");
  strcpy(solver.nextWord, "apple");

  solveWord(&solver);
  printf("%s\n", solver.currentWord);
  printf("Score: %d\n", solver.score);

  return 0;
}