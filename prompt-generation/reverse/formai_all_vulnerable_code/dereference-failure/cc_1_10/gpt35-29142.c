//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_WAITING 10
#define MAX_CAPACITY 5

typedef struct _node {
    int data;
    struct _node* next;
} Node;

typedef struct _queue {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize_queue();
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
void print_waiting(Queue* q);

int main() {
    int current_floor = 1;
    int count = 0;
    int direction = 1;
    int passengers = 0;
    int dest[MAX_CAPACITY];
    Queue* up_waiting = initialize_queue();
    Queue* down_waiting = initialize_queue();

    while (1) {
        printf("Current Floor: %d\n", current_floor);

        // Check if anyone wants to board and add to capacity
        if (direction == 1) {
            Node* curr = up_waiting->front;
            while (curr != NULL) {
                if (curr->data == current_floor && passengers < MAX_CAPACITY) {
                    printf("Passenger boards\n");
                    dest[passengers] = rand() % 10 + 2;
                    passengers++;
                    count++;
                    dequeue(up_waiting);
                }
                curr = curr->next;
            }
        } else {
            Node* curr = down_waiting->front;
            while (curr != NULL) {
                if (curr->data == current_floor && passengers < MAX_CAPACITY) {
                    printf("Passenger boards\n");
                    dest[passengers] = rand() % current_floor + 1;
                    passengers++;
                    count++;
                    dequeue(down_waiting);
                }
                curr = curr->next;
            }
        }

        // Check if anyone wants to leave and decrement capacity
        int i;
        for (i = 0; i < passengers; i++) {
            if (dest[i] == current_floor) {
                printf("Passenger exits\n");
                dest[i] = -1;
                passengers--;
            }
        }

        // Check if any new passengers want to enter and add to waiting list
        if (count < MAX_WAITING) {
            int dir = rand() % 2;
            int dest_floor = rand() % 10 + 2;
            if (dir == 1 && current_floor <= 10) {
                printf("Passenger wants to go up\n");
                enqueue(up_waiting, dest_floor);
                count++;
            } else if (dir == 0 && current_floor >= 2) {
                printf("Passenger wants to go down\n");
                enqueue(down_waiting, dest_floor);
                count++;
            }
        }

        print_waiting(up_waiting);
        print_waiting(down_waiting);

        current_floor += direction;
        if (current_floor == 11) {
            direction = -1;
        } else if (current_floor == 1) {
            direction = 1;
        }
    }

    return 0;
}

Queue* initialize_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    Node* to_delete = q->front;
    int data = to_delete->data;
    q->front = q->front->next;
    free(to_delete);
    return data;
}

void print_waiting(Queue* q) {
    Node* curr = q->front;
    printf("Waiting: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}