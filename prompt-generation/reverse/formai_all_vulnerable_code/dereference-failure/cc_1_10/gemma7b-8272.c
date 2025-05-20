//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10
#define MAX_GUESSES 5

typedef struct Node {
    int number;
    struct Node* next;
} Node;

void insertNode(Node** head, int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int searchNode(Node* head, int number) {
    while (head) {
        if (head->number == number) {
            return 1;
        } else if (head->number < number) {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    time_t t;
    srand(time(&t));

    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 3);
    insertNode(&head, 5);
    insertNode(&head, 7);
    insertNode(&head, 9);

    int guessNumber = rand() % MAX_NUMBER + 1;
    int guesses = 0;

    printf("I'm thinking of a number between 1 and %d. Guess what it is: ", MAX_NUMBER);

    while (guesses < MAX_GUESSES) {
        int guess = 0;

        scanf("Enter your guess: ", &guess);

        if (searchNode(head, guess) == 1) {
            printf("You guessed the number! Congratulations!\n");
            break;
        } else if (guess < guessNumber) {
            printf("Your guess is too low. Try again.\n");
        } else if (guess > guessNumber) {
            printf("Your guess is too high. Try again.\n");
        }

        guesses++;
    }

    if (guesses == MAX_GUESSES) {
        printf("Sorry, you ran out of guesses. The number was %d.\n", guessNumber);
    }

    return 0;
}