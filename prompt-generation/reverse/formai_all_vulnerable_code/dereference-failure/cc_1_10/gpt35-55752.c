//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void addNode(Node **head, int data) {
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        Node *temp = head;
        printf("List : ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    printf("******************************\n");
    printf("C DATA STRUCTURES VISUALIZATION\n");
    printf("******************************\n");

    Node *head = NULL;

    printf("Creating a list with the following values : 1, 2, 3, 4, 5\n");
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printf("\n");
    printf("----------------------\n");
    printf("Current State of List :\n");
    printf("----------------------\n");
    printList(head);

    printf("\n");
    printf("----------------------\n");
    printf("Visual Representation :\n");
    printf("----------------------\n");

    printf("      ___\n");
    printf("     | 1 | --> ");
    printf("| 2 | --> ");
    printf("| 3 | --> ");
    printf("| 4 | --> ");
    printf("| 5 |\n");

    printf("\n");
    printf("-------------------------------------\n");
    printf("Inserting new value 6 at the end.\n");
    printf("-------------------------------------\n");
    addNode(&head, 6);

    printf("\n");
    printf("----------------------\n");
    printf("Current State of List :\n");
    printf("----------------------\n");
    printList(head);

    printf("\n");
    printf("----------------------\n");
    printf("Visual Representation :\n");
    printf("----------------------\n");

    printf("      ___\n");
    printf("     | 1 | --> ");
    printf("| 2 | --> ");
    printf("| 3 | --> ");
    printf("| 4 | --> ");
    printf("| 5 | --> ");
    printf("| 6 |\n");

    printf("\n");
    printf("----------------------------------------\n");
    printf("Deleting the value at position 3 (3rd value)\n");
    printf("----------------------------------------\n");
    Node *temp = head;
    Node *prev;
    int pos = 3, count = 1;

    while (temp != NULL && count != pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    prev->next = temp->next;
    free(temp);

    printf("\n");
    printf("----------------------\n");
    printf("Current State of List :\n");
    printf("----------------------\n");
    printList(head);

    printf("\n");
    printf("----------------------\n");
    printf("Visual Representation :\n");
    printf("----------------------\n");

    printf("      ___\n");
    printf("     | 1 | --> ");
    printf("| 2 | --> ");
    printf("| 4 | --> ");
    printf("| 5 | --> ");
    printf("| 6 |\n");

    printf("\n");

    return 0;
}