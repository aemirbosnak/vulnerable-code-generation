//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

struct stack {
    int top;
    int capacity;
    int *arr;
};

void init_queue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_queue_empty(struct queue* q) {
    if (q->front == NULL)
        return 1;
    return 0;
}

void display_queue(struct queue *q) {
    if (is_queue_empty(q))
        printf("Queue is empty\n");
    else {
        struct node* temp = q->front;
        while (temp != NULL) {
            printf("%d <- ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void insert_queue(struct queue* q, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_queue_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void delete_queue(struct queue* q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", q->front->data);
    struct node* temp = q->front;
    q->front = q->front->next;
    free(temp);
}

void init_stack(struct stack* s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int)*capacity);
}

int is_stack_empty(struct stack* s) {
    if (s->top == -1)
        return 1;
    return 0;
}

int is_stack_full(struct stack* s) {
    if (s->top == s->capacity - 1)
        return 1;
    return 0;
}

void display_stack(struct stack* s) {
    if (is_stack_empty(s))
        printf("Stack is empty\n");
    else {
        int i;
        for (i = s->top; i >= 0; i--)
            printf("%d\n", s->arr[i]);
    }
}

void push(struct stack* s, int data) {
    if (is_stack_full(s)) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = data;
}

void pop(struct stack* s) {
    if (is_stack_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Deleted: %d\n", s->arr[s->top--]);
}

int main() {
    struct queue q;
    init_queue(&q);
    insert_queue(&q, 1);
    insert_queue(&q, 2);
    insert_queue(&q, 3);
    printf("Queue: ");
    display_queue(&q);
    delete_queue(&q);
    printf("Queue: ");
    display_queue(&q);
    delete_queue(&q);
    printf("Queue: ");
    display_queue(&q);
    
    struct stack s;
    init_stack(&s, 5);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("Stack:\n");
    display_stack(&s);
    pop(&s);
    printf("Stack:\n");
    display_stack(&s);
    pop(&s);
    printf("Stack:\n");
    display_stack(&s);
    
    return 0;
}