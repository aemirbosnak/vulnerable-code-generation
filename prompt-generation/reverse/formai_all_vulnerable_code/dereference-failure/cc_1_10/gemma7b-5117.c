//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    int number = getRandomNumber(1, MAX_NUM);

    for (Node* current = head; current; current = current->next) {
        if (current->data == number) {
            printf("Your number is %d, and your fortune is...", number);
            switch (getRandomNumber(1, 5)) {
                case 1:
                    printf("You will have a lucky day.\n");
                    break;
                case 2:
                    printf("You will have a day full of happiness.\n");
                    break;
                case 3:
                    printf("You will have a day filled with joy.\n");
                    break;
                case 4:
                    printf("You will have a day of great success.\n");
                    break;
                case 5:
                    printf("You will have a day of peace and tranquility.\n");
                    break;
            }
            break;
        }
    }

    return 0;
}