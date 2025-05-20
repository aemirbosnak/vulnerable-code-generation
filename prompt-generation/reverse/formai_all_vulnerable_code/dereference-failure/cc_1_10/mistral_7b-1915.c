//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void createList(node **head, int data) {
    node *newNode = (node *)malloc(sizeof(node));

    if (*head == NULL) {
        *head = newNode;
        newNode->data = data;
        newNode->next = NULL;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->data = data;
    }
}

void printList(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int factorial(int n) {
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

node *reverseList(node **head) {
    node *current = *head, *previous = NULL, *next;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
    return *head;
}

int main() {
    node *head = NULL;
    int i;

    for (i = 1; i <= 10; i++) {
        createList(&head, i);
    }

    printf("Original List: ");
    printList(head);

    node *reversedHead = reverseList(&head);

    printf("Reversed List: ");
    printList(reversedHead);

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);

    return 0;
}