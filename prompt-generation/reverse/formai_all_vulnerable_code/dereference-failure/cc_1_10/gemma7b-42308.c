//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insert(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void playGame() {
  Node* head = NULL;
  int i, guess, score = 0;

  for (i = 0; i < MAX_SIZE; i++) {
    insert(head, rand() % MAX_SIZE);
  }

  printf("Enter your guess: ");
  scanf("%d", &guess);

  while (head && head->data != guess) {
    score++;
    printf("Wrong guess. Try again: ");
    scanf("%d", &guess);
  }

  if (head->data == guess) {
    printf("Congratulations! You won with %d guesses!\n", score);
  } else {
    printf("Sorry, you lost. The answer was %d.\n", head->data);
  }
}

int main() {
  srand(time(NULL));
  playGame();
  return 0;
}