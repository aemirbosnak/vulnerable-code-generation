//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
  int data;
  struct Node* next;
} Node;

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

void playGame() {
  Node* head = NULL;
  int size = 0;

  // Insert some data into the linked list
  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  insert(&head, 50);

  // Initialize the number of guesses
  int guesses = 0;

  // Start the game loop
  while (size != guesses) {
    // Get the user's guess
    int guess = 0;
    printf("Guess a number: ");
    scanf("%d", &guess);

    // Check if the guess is correct
    if (guess == head->data) {
      // Increment the number of guesses
      guesses++;

      // Print the guess is correct
      printf("Congratulations! You guessed the number: %d\n", guess);

      // Move to the next node
      head = head->next;

      // Update the size of the list
      size++;
    } else if (guess < head->data) {
      // Print the guess is too low
      printf("Your guess is too low. Please try again.\n");
    } else {
      // Print the guess is too high
      printf("Your guess is too high. Please try again.\n");
    }
  }

  // End the game loop
  printf("Thank you for playing! You have won!\n");
}

int main() {
  playGame();

  return 0;
}