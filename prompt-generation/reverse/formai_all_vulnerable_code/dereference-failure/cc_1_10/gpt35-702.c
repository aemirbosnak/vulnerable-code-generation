//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int n){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head){
    if (head == NULL)
        printf("List empty\n");
    else{
        Node* tmp = head;
        while (tmp != NULL){
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        }
    }
    printf("NULL\n\n");
}

void freeList(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        head = head->next;
        free(tmp);
        tmp = head;
    }
}

int main(){
    srand(time(NULL));
    Node* head = NULL;
    int i;

    //creating random linked list
    for (i = 0; i < MAX; i++){
        int n = rand() % 20 + 1;
        Node* newNode = createNode(n);
        newNode->next = head;
        head = newNode;
    }

    printf("Random linked list of size %d:\n", MAX);
    display(head);

    printf("Enter the position to insert a new node (1-%d): ", MAX + 1);
    int pos;
    while (scanf("%d", &pos) != 1 || pos < 1 || pos > MAX + 1){
        printf("Invalid input, try again: ");
        while (getchar() != '\n');
    }

    printf("Enter the data for the new node: ");
    int n;
    while (scanf("%d", &n) != 1 || n < 1 || n > 20){
        printf("Invalid input, try again: ");
        while (getchar() != '\n');
    }

    Node* newNode = createNode(n);
    if (pos == 1){
        newNode->next = head;
        head = newNode;
    }
    else{
        Node* tmp = head;
        for (i = 1; i < pos - 1; i++)
            tmp = tmp->next;
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    printf("Linked list after inserting new node:\n");
    display(head);

    freeList(head);

    return 0;
}