//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

typedef struct Node {
    int number;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int number) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->number = number;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

void fortuneTeller(Node* head) {
    int number = getRandomNumber(1, MAX_NUM);
    Node* current = head;

    while (current) {
        if (current->number == number) {
            printf("Your number is %d, and your fortune is: ", number);
            switch (number) {
                case 1:
                    printf("You will have a prosperous future.\n");
                    break;
                case 2:
                    printf("You will have a bright future.\n");
                    break;
                case 3:
                    printf("You will have a good future.\n");
                    break;
                default:
                    printf("You will have a mediocre future.\n");
                    break;
            }
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Your number is not in the list.\n");
    }
}

int main() {
    Node* head = insertAtTail(NULL, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    fortuneTeller(head);

    return 0;
}