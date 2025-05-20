//FormAI DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *newNode(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data  = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node
void insert(struct node **head, int data) {
    struct node *temp = *head;
    if(*head == NULL) {
        *head = newNode(data);
        return;
    }
    insert(&temp->next, data);
}

// Function to display the linked list
void display(struct node *head) {
    if(head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ",head->data);
    display(head->next);
}

// Function to read the Ebook
void readEbook(struct node *head) {
    if(head == NULL) {
        printf("\nEnd of Ebook\n");
        return;
    }
    printf("%d\n",head->data);
    head = head->next;
    readEbook(head);
}

int main() {
    struct node *head = NULL;
    int n, i, num;
    printf("Enter the number of pages in the Ebook: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter page %d of the Ebook: ",i+1);
        scanf("%d",&num);
        insert(&head, num);
    }
    printf("Ebook contents are:\n");
    display(head);
    printf("\n\nReading Ebook:\n");
    readEbook(head);
    return 0;
}