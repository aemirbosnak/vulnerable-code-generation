//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(front == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

void dequeue(){
    struct node* temp = front;
    if(front!= NULL){
        front = front->next;
        free(temp);
    }
    else{
        printf("Queue is empty\n");
    }
}

void display(){
    struct node* temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}