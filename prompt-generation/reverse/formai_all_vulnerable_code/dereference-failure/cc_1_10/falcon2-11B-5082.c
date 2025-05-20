//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
} List;

void insert(List* list, char letter) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->letter = letter;
    newNode->next = list->head;
    list->head = newNode;
}

void printList(List* list) {
    Node* curr = list->head;
    while (curr!= NULL) {
        printf("%c", curr->letter);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    List guesses;
    guesses.head = NULL;

    int tries = 6;
    char correct[8];
    strcpy(correct, "hangman");

    for (int i = 0; i < 8; i++) {
        insert(&guesses, correct[i]);
    }

    while (tries > 0) {
        printf("You have %d tries left.\n", tries);
        printf("Guess a letter: ");
        char guess;
        scanf("%c", &guess);

        if (guess == correct[0]) {
            printf("Correct!\n");
            tries--;
            printList(&guesses);
        } else {
            printf("Incorrect.\n");
            printList(&guesses);
            tries--;
        }
    }

    if (tries == 0) {
        printf("Sorry, you are hanged!\n");
    } else {
        printf("You guessed the word! You survived!\n");
    }

    return 0;
}