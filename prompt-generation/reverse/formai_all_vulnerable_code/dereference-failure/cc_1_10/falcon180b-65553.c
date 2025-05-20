//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Stack structure using linked list
struct stack {
    struct node* top;
};

// Initialize an empty stack
void init(struct stack* s) {
    s->top = NULL;
}

// Push an element onto the stack
void push(struct stack* s, int data) {
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop an element from the stack
int pop(struct stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    struct node* temp = s->top;
    int data = s->top->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Display the contents of the stack
void display(struct stack* s) {
    struct node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Thread function to push elements onto the stack
void* push_thread(void* arg) {
    struct stack* s = (struct stack*) arg;
    int i;
    for (i = 0; i < 10; i++) {
        push(s, i);
        sleep(1);
    }
    return NULL;
}

// Thread function to pop elements from the stack
void* pop_thread(void* arg) {
    struct stack* s = (struct stack*) arg;
    int i;
    for (i = 0; i < 10; i++) {
        pop(s);
        sleep(1);
    }
    return NULL;
}

int main() {
    struct stack s;
    init(&s);
    pthread_t thread_id[2];

    // Create threads for pushing and popping elements
    pthread_create(&thread_id[0], NULL, push_thread, &s);
    pthread_create(&thread_id[1], NULL, pop_thread, &s);

    // Join the threads
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    // Display the final contents of the stack
    display(&s);

    return 0;
}