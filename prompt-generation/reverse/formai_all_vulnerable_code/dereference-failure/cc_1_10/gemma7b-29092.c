//Gemma-7B DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define MAX_Turns 5

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

void playGame() {
  srand(time(NULL));
  int currentTurn = 0;
  int player1Score = 0;
  int player2Score = 0;

  Node* head = NULL;
  insertAtTail(&head, 1);
  insertAtTail(&head, 2);
  insertAtTail(&head, 3);
  insertAtTail(&head, 4);
  insertAtTail(&head, 5);

  while (currentTurn < MAX_Turns) {
    int rollNumber = rand() % MAX_NUM + 1;
    printf("Roll number: %d\n", rollNumber);

    if (rollNumber == 6) {
      printf("Player 1 turn!\n");
      player1Score++;
    } else if (rollNumber == 8) {
      printf("Player 2 turn!\n");
      player2Score++;
    }

    currentTurn++;
  }

  printf("Game over!\n");
  printf("Player 1 score: %d\n", player1Score);
  printf("Player 2 score: %d\n", player2Score);
}

int main() {
  playGame();

  return 0;
}