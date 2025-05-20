//MISTRAL-7B DATASET v1.0 Category: Checkers Game ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    struct Node *next;
} Node;

Node *head = NULL;

void push(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = head;
    head = newNode;
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

int main() {
    int choice, num, sum = 0;

    while (1) {
        printf("\nMenu:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &num);
                push(num);
                sum += num;
                break;
            case 2:
                pop();
                sum -= head->value;
                break;
            case 3:
                printf("Stack elements: ");
                Node *temp = head;
                while (temp != NULL) {
                    printf("%d ", temp->value);
                    temp = temp->next;
                }
                printf("\nSum = %d", sum);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}