//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

typedef struct node {  // creating a linked list node structure
    int val;
    struct node* next;
} node;

typedef struct stack { // creating a stack structure
    int top;
    int capacity; 
    int* arr;
} stack;

void push(stack* stk, int item){   // function to push values to stack
    if(stk->top == stk->capacity - 1){   // checking if the stack is full
        printf("Stack Overflow\n");
        return;
    }
    stk->arr[++stk->top] = item;   // pushing item to stack
}

void pop(stack* stk){   // function to pop values from stack
    if(stk->top == -1){   // checking if the stack is empty
        printf("Stack Underflow\n");
        return;
    }
    stk->arr[stk->top--];   // popping item from stack
}

void display(stack* stk){   // function to display the contents of stack
    if(stk->top == -1){   // checking if the stack is empty
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Contents:\n");
    for(int i=stk->top;i>=0;i--){
        printf("%d\n", stk->arr[i]);  // printing stack contents
    }
}

int main(){
    node* head = NULL;
    stack stk;
    stk.top = -1;
    stk.capacity = 5;   // capacity of stack
    stk.arr = (int*)malloc(sizeof(int) * stk.capacity);

    printf("Creating Linked List...\n");
    for(int i=1;i<=5;i++){   // creating a linked list with 5 nodes
        node* temp = (node*)malloc(sizeof(node));
        temp->val = i*10;
        temp->next = head;
        head = temp;
    }
    printf("Linked List Created Successfully!\n\n");

    printf("Pushing to Stack...\n");
    for(int i=1;i<=5;i++){   // pushing the values of linked list to stack
        push(&stk, head->val);
        head = head->next;
    }
    printf("Values Pushed Successfully!\n\n");

    printf("Displaying Stack Contents...\n");
    display(&stk);   // displaying the contents of stack
    printf("\n");

    printf("Popping from Stack...\n");
    pop(&stk);   // popping an item from stack
    printf("Values Popped Successfully!\n\n");

    printf("Displaying Stack Contents...\n");
    display(&stk);   // displaying the contents of stack
    printf("\n");

    return 0;
}