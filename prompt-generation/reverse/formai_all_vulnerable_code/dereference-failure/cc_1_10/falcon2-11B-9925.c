//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct node* head = NULL;
    int num, data;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insert(&head, data);
    }

    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    printf("Enter the element to be searched: ");
    scanf("%d", &data);

    struct node* search = head;
    while (search!= NULL) {
        if (search->data == data) {
            printf("Element found at index %d\n", search - head);
            break;
        }
        search = search->next;
    }
    if (search == NULL) {
        printf("Element not found\n");
    }

    return 0;
}