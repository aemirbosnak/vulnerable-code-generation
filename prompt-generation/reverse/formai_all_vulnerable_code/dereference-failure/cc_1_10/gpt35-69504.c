//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100
#define UNLOAD_INTERVAL 5

typedef struct Baggage Buffer;
struct Baggage {
    int id;
};

typedef struct {
    int front, rear;
    Buffer *arr[MAX_CAPACITY];
} Queue;

void init_queue(Queue *queue);
bool is_full(Queue *queue);
bool is_empty(Queue *queue);
void enqueue(Queue *queue, Buffer *baggage);
Buffer* dequeue(Queue *queue);

int main() {
    Queue arrivals, baggage_claim;
    Buffer *temp, *luggage;
    int choice, time = 0;
    bool status = false;
    
    init_queue(&arrivals);
    init_queue(&baggage_claim);

    do {
        printf("\n\nTime elapsed: %d minutes\n\n", time);
        printf("1. Add new luggage\n");
        printf("2. Unload luggage\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                temp = (Buffer*) malloc(sizeof(Buffer));
                temp->id = time;
                status = is_full(&arrivals);
                if (status) {
                    printf("\nAirport is full. Please try again later.\n");
                    break;
                } else {
                    enqueue(&arrivals, temp);
                    printf("\nBaggage successfully added!\n");
                }
                break;

            case 2:
                status = is_empty(&arrivals);
                if (status) {
                    printf("\nNo luggage to unload.\n");
                    break;
                }
                if (!(time % UNLOAD_INTERVAL)) {
                    luggage = dequeue(&arrivals);
                    enqueue(&baggage_claim, luggage);
                    printf("\nLuggage with ID %d unloaded successfully.\n", luggage->id);
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a correct option.");
        }
        time++;
    } while(choice != 3);
    return 0;
}

void init_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

bool is_full(Queue *queue) {
    return queue->rear == MAX_CAPACITY - 1;
}

bool is_empty(Queue *queue) {
    return queue->rear < queue->front;
}

void enqueue(Queue *queue, Buffer *baggage) {
    queue->arr[++queue->rear] = baggage;
}

Buffer* dequeue(Queue *queue) {
    if (is_empty(queue))
        return NULL;
    else
        return queue->arr[queue->front++];
}