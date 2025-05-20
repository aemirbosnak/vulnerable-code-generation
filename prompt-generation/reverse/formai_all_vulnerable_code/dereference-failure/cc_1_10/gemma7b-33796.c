//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void playMemoryGame(Node* head) {
    int guesses = 0;
    int target = rand() % MAX_MEMORY;

    while (guesses < MAX_MEMORY) {
        int guess = rand() % MAX_MEMORY;

        if (guess == target) {
            printf("You guessed the target!\n");
            break;
        } else if (guess < target) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }

        guesses++;
    }

    if (guesses == MAX_MEMORY) {
        printf("Sorry, you lost.\n");
    }
}

int main() {
    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    playMemoryGame(head);

    return 0;
}