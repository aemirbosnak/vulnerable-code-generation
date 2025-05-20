//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

//Structure representing a stack
struct Stack {
    int top; //index of the top element
    int arr[MAX]; //array to hold elements
};

//Function to create a new stack and return a pointer to it
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack)); //allocate memory for a new stack
    s->top = -1; //set top to -1 indicating an empty stack
    return s;
}

//Function to push an element onto the stack
int push(struct Stack* s, int element) {
    if(s->top == MAX-1) { //if stack is already full
        return 0;
    }
    s->top++; //increment the stack top index
    s->arr[s->top] = element; //add the element to the top of the stack
    return 1;
}

//Function to pop an element from the stack
int pop(struct Stack* s) {
    if(s->top == -1) { //if stack is already empty
        return -1;
    }
    int popped_element = s->arr[s->top]; //get the element at the top of the stack
    s->top--; //decrement the stack top index
    return popped_element; //return the popped element
}

//Function to display the contents of the stack
void display(struct Stack* s) {
    if(s->top == -1) { //if stack is empty
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for(int i=s->top; i>=0; i--) { //start from the top element and go downwards
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    srand(time(NULL)); //seed the random number generator
    struct Stack* s = createStack(); //create a new stack
    int choice, element, success, popped_element;
    printf("Stack operations menu:\n");
    printf("1. Push element\n");
    printf("2. Pop element\n");
    printf("3. Display stack contents\n");
    printf("4. Quit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                element = rand()%100; //generate a random element between 0 and 99
                success = push(s, element); //push the element onto the stack
                if(success) {
                    printf("%d pushed onto the stack.\n", element);
                } else {
                    printf("Stack is full. %d not pushed.\n", element);
                }
                break;
            case 2:
                popped_element = pop(s); //pop an element from the stack
                if(popped_element == -1) {
                    printf("Stack is empty. Nothing to pop.\n");
                } else {
                    printf("%d popped from the stack.\n", popped_element);
                }
                break;
            case 3:
                display(s); //display the contents of the stack
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}