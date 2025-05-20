//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int num;
    struct node* next;
} node;

void generateRandomNumbers(node** head) {
    node* current = *head;
    node* newNode;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        if (current == NULL) {
            *head = (node*) malloc(sizeof(node));
            current = *head;
            current->num = rand() % 100 + 1;
            current->next = NULL;
        } else {
            newNode = (node*) malloc(sizeof(node));
            newNode->num = rand() % 100 + 1;
            current->next = newNode;
            current = newNode;
        }
    }
}

void printList(node* head) {
    node* current = head;

    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }

    printf("\n");
}

void sumLists(node* head1, node* head2, node** sumHead) {
    node* current1 = head1;
    node* current2 = head2;
    node* newNode = NULL;
    int carry = 0;

    *sumHead = NULL;

    while (current1 != NULL || current2 != NULL) {
        int sum = carry;

        if (current1 != NULL) {
            sum += current1->num;
            current1 = current1->next;
        }

        if (current2 != NULL) {
            sum += current2->num;
            current2 = current2->next;
        }

        newNode = (node*) malloc(sizeof(node));
        newNode->num = sum % 10;
        newNode->next = *sumHead;
        *sumHead = newNode;

        carry = sum / 10;
    }

    if (carry > 0) {
        newNode = (node*) malloc(sizeof(node));
        newNode->num = carry;
        newNode->next = *sumHead;
        *sumHead = newNode;
    }
}

int main() {
    node* list1 = NULL;
    node* list2 = NULL;
    node* sumList = NULL;

    generateRandomNumbers(&list1);
    generateRandomNumbers(&list2);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    sumLists(list1, list2, &sumList);

    printf("Sum: ");
    printList(sumList);

    free(list1);
    free(list2);
    free(sumList);

    return 0;
}