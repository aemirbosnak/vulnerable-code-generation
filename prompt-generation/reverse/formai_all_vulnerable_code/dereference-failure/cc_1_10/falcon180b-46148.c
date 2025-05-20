//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

void pop(struct Node** top_ref){
    struct Node* top = *top_ref;
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    (*top_ref) = top;
}

void peek(struct Node* top){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

void display(struct Node* top){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(top!= NULL){
        printf("Element is %d\n", top->data);
        top = top->next;
    }
}

int main(){
    struct Node* top = NULL;
    int choice, data;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be pushed:\n");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}