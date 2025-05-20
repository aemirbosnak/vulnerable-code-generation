//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

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

void play(Node** head) {
    int num1, num2, guess, score = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    guess = rand() % (num2 - num1 + 1) + num1;

    printf("Guess the number: ");
    scanf("%d", &guess);

    if (guess == guess) {
        score++;
        printf("Congratulations! You won a point!\n");
    } else {
        printf("Sorry, you lost. The number was %d.\n", guess);
    }

    printf("Your score: %d\n", score);
}

int main() {
    Node* head = NULL;
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);

    play(&head);

    return 0;
}