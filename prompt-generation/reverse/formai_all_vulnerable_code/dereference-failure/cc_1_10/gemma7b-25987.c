//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 5

typedef struct Card {
  int number;
  struct Card* next;
} Card;

void createCard(int number, Card** head) {
  Card* newCard = malloc(sizeof(Card));
  newCard->number = number;
  newCard->next = NULL;

  if (*head == NULL) {
    *head = newCard;
  } else {
    (*head)->next = newCard;
  }
}

void playGame(Card* head) {
  int guessNumber;
  printf("Enter a number between 1 and %d: ", MAX_CARDS);
  scanf("%d", &guessNumber);

  Card* currentCard = head;
  while (currentCard) {
    if (currentCard->number == guessNumber) {
      printf("Congratulations! You guessed the number.\n");
      return;
    } else if (currentCard->number < guessNumber) {
      currentCard = currentCard->next;
    }
  }

  printf("Sorry, the number was not found.\n");
}

int main() {
  Card* head = NULL;

  createCard(1, &head);
  createCard(2, &head);
  createCard(3, &head);
  createCard(4, &head);
  createCard(5, &head);

  playGame(head);

  return 0;
}