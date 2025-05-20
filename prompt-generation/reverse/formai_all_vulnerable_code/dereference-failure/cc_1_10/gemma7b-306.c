//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void initialize(Node** head) {
  *head = NULL;
}

void insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void playGame(Node* head) {
  int guessNumber, guessCount = 0;

  printf("Guess a number between 1 and %d: ", MAX_SIZE);
  scanf("%d", &guessNumber);

  while (head && guessNumber != head->data) {
    guessCount++;
    printf("Wrong guess. Try again: ");
    scanf("%d", &guessNumber);
  }

  if (guessNumber == head->data) {
    printf("Congratulations! You won! It took you %d guesses.\n", guessCount);
  } else {
    printf("Sorry, you lose. The number was %d.\n", head->data);
  }
}

int main() {
  Node* head = NULL;
  initialize(&head);

  insert(head, 5);
  insert(head, 3);
  insert(head, 8);
  insert(head, 2);

  playGame(head);

  return 0;
}