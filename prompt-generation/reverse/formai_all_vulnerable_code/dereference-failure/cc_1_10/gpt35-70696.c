//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include<stdio.h>
#include<stdlib.h>

typedef struct element{
    int value;
    struct element *next;
}element;

typedef struct stack{
    element *top;
    int size;
}stack;

void initStack(stack *s);
void push(stack *s, int v);
void pop(stack *s);
void displayStack(stack s);

int main(){
    stack s;
    initStack(&s);

    push(&s, 5);
    push(&s, 7);
    push(&s, 9);

    printf("Stack after pushing 5, 7, and 9:\n");
    displayStack(s);

    pop(&s);
    printf("Stack after popping top element:\n");
    displayStack(s);

    return 0;
}

void initStack(stack *s){
    s->top = NULL;
    s->size = 0;
}

void push(stack *s, int v){
    element *e = (element*)malloc(sizeof(element));
    e->value = v;
    e->next = s->top;
    s->top = e;
    s->size++;
}

void pop(stack *s){
    if(s->size == 0){
        printf("Error: Stack is empty\n");
        return;
    }
    element *e = s->top;
    s->top = s->top->next;
    free(e);
    s->size--;
}

void displayStack(stack s){
    if(s.size == 0){
        printf("Stack is empty\n");
        return;
    }
    element *e = s.top;
    printf("TOP\n");
    while(e != NULL){
        printf("%d\n", e->value);
        e = e->next;
    }
    printf("BOTTOM\n");
}