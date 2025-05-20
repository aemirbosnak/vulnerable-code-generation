//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// A real-life example of a queue implementation could be a queue of customers waiting to be served at a bank.
// Each customer has a unique ID and a time of arrival.
// The queue should be able to handle the following operations:
// 1. Enqueue a new customer
// 2. Dequeue the next customer
// 3. Get the number of customers in the queue
// 4. Get the average time of arrival of the customers in the queue

// Define the structure of a customer
typedef struct customer {
    int id;
    int time_of_arrival;
} customer;

// Define the structure of a queue
typedef struct queue {
    customer* customers;
    int front;
    int rear;
    int size;
} queue;

// Initialize a new queue
queue* create_queue(int size) {
    queue* new_queue = (queue*)malloc(sizeof(queue));
    new_queue->customers = (customer*)malloc(sizeof(customer) * size);
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->size = size;
    return new_queue;
}

// Enqueue a new customer
void enqueue(queue* queue, int id, int time_of_arrival) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->customers[queue->rear].id = id;
    queue->customers[queue->rear].time_of_arrival = time_of_arrival;
    if (queue->front == -1) {
        queue->front++;
    }
}

// Dequeue the next customer
customer* dequeue(queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return NULL;
    }
    customer* customer = &queue->customers[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return customer;
}

// Get the number of customers in the queue
int get_size(queue* queue) {
    return queue->rear - queue->front + 1;
}

// Get the average time of arrival of the customers in the queue
float get_average_time_of_arrival(queue* queue) {
    int total_time_of_arrival = 0;
    int num_customers = get_size(queue);
    for (int i = queue->front; i <= queue->rear; i++) {
        total_time_of_arrival += queue->customers[i].time_of_arrival;
    }
    return (float)total_time_of_arrival / num_customers;
}

// Print the queue
void print_queue(queue* queue) {
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("(%d, %d) ", queue->customers[i].id, queue->customers[i].time_of_arrival);
    }
    printf("\n");
}

// Free the memory allocated for the queue
void free_queue(queue* queue) {
    free(queue->customers);
    free(queue);
}

// Main function
int main() {
    // Create a new queue
    queue* queue = create_queue(10);

    // Enqueue some customers
    enqueue(queue, 1, 10);
    enqueue(queue, 2, 12);
    enqueue(queue, 3, 15);
    enqueue(queue, 4, 18);
    enqueue(queue, 5, 20);

    // Print the queue
    print_queue(queue);

    // Dequeue the next customer
    customer* customer = dequeue(queue);
    printf("Dequeued customer: (%d, %d)\n", customer->id, customer->time_of_arrival);

    // Get the number of customers in the queue
    int size = get_size(queue);
    printf("Number of customers in the queue: %d\n", size);

    // Get the average time of arrival of the customers in the queue
    float average_time_of_arrival = get_average_time_of_arrival(queue);
    printf("Average time of arrival: %.2f\n", average_time_of_arrival);

    // Free the memory allocated for the queue
    free_queue(queue);

    return 0;
}