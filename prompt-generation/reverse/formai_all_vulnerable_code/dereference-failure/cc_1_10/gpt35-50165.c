//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

// structure of a node
struct node{
    int data;
    struct node* link;
};
struct node* t;    // global variable t to be used as temporary variable

// function to insert elements in the linked list
void insert(struct node* head, int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;

    // if list is empty
    if(head == NULL){
        head = temp;
        t = head;
    }
    else{
        t->link = temp;
        t = temp;
    }
}

// function to print the linked list
void display(struct node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    else{
        printf("Elements in linked list are: ");
        while(head != NULL){
            printf("%d ", head->data);
            head = head->link;
        }
        printf("\n");
    }
}

// function to find maximum element in the list
int maximum(struct node* head){
    int max = head->data;
    while(head != NULL){
        if(head->data > max)
            max = head->data;
        head = head->link;
    }
    return max;
}

// function to find minimum element in the list
int minimum(struct node* head){
    int min = head->data;
    while(head != NULL){
        if(head->data < min)
            min = head->data;
        head = head->link;
    }
    return min;
}

int main(){
    struct node* head = NULL;
    int n, x, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        insert(head, x);
    }
    display(head);
    printf("Maximum element in the list is: %d\n", maximum(head));
    printf("Minimum element in the list is: %d\n", minimum(head));
    return 0;
}