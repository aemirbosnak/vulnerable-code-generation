//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   char data;
   struct node *next;
} Node;

typedef struct stack {
   Node *top;
} Stack;

void push(Stack *s, char data) {
   Node *newNode = (Node *) malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   if(s->top == NULL) {
      s->top = newNode;
   } else {
      newNode->next = s->top;
      s->top = newNode;
   }
   printf("Node with value %c pushed onto the stack\n", data);
}

char pop(Stack *s) {
   if(s->top == NULL) {
      printf("Stack is empty\n");
      return '\0';
   } else {
      char data = s->top->data;
      Node *temp = s->top;
      s->top = s->top->next;
      free(temp);
      temp = NULL;
      printf("Node with value %c popped from the stack\n", data);
      return data;
   }
}

void display(Stack *s) {
   if(s->top == NULL) {
      printf("Stack is empty\n");
   } else {
      Node *current = s->top;
      printf("Elements of stack are: ");
      while(current != NULL) {
         printf("%c ", current->data);
         current = current->next;
      }
   }
}

int main() {
   Stack myStack;
   myStack.top = NULL;

   push(&myStack, 'H');
   push(&myStack, 'e');
   push(&myStack, 'l');
   push(&myStack, 'l');
   push(&myStack, 'o');

   display(&myStack);

   pop(&myStack);
   pop(&myStack);

   display(&myStack);

   return 0;
}