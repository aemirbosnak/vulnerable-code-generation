//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct task {
    int priority;
    int burst_time;
    char name[20];
} Task;

typedef struct node {
    Task data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void push(Task data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void pop() {
    if(front == NULL) {
        printf("No tasks to schedule!\n");
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        Node* temp = front;
        front = front->next;
        free(temp);
    }
}

void display() {
    if(front == NULL) {
        printf("No tasks to display!\n");
        return;
    }
    Node* temp = front;
    while(temp != NULL) {
        printf("%s (priority: %d, burst time: %d)\n", temp->data.name, temp->data.priority, temp->data.burst_time);
        temp = temp->next;
    }
}

int main() {
    Task task1 = {1, 3, "Task 1"};
    Task task2 = {3, 2, "Task 2"};
    Task task3 = {2, 4, "Task 3"};
    Task task4 = {1, 2, "Task 4"};
    Task task5 = {2, 1, "Task 5"};
    push(task1);
    push(task2);
    push(task3);
    push(task4);
    push(task5);
    printf("Tasks before scheduling:\n");
    display();
    printf("\nScheduling tasks...\n\n");
    while(front != NULL) {
        printf("Running task: %s\n", front->data.name);
        pop();
    }
    printf("\nAll tasks finished!\n");
    return 0;
}