//FormAI DATASET v1.0 Category: Data structures visualization ; Style: excited
// Hey there folks!
// Are you ready to explore the magic of data structures?
// Then fasten your seat belts and let's dive in!

#include<stdio.h>
#include<stdlib.h>

// First, let's create our own data structure - a linked list!

struct node {
    int data;
    struct node *next;
};

// Now, let's create a function to display our linked list in a cool way!

void showLinkedList(struct node *head) {
    struct node *temp = head;
    printf("\n******************************************************************\n");
    printf("\t\tHere is your beautiful linked list!\n");
    printf("******************************************************************\n");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("******************************************************************\n");
}

int main() {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    // Time to add some elements to our linked list!

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // And voila! Our linked list is ready!

    showLinkedList(head);

    return 0;
}