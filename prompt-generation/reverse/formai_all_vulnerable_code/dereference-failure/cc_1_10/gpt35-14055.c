//FormAI DATASET v1.0 Category: Queue Implementation ; Style: imaginative
//Welcome to the Magical Queue Program
//Where elements disappear and appear
//In a snap of a finger

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10000

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

Queue* initialize_queue();
void enqueue(Queue* q, int num);
int dequeue(Queue* q);
void display_queue(Queue* q);

int main() {
    Queue* magic_queue = initialize_queue();

    printf("Welcome to the Magical Queue Program!\n");
    printf("Add some magic to your numbers by queueing them in our magical queue!\n\n");

    int num_ops = -1;

    while (num_ops < 0) {
        printf("How many magical operations would you like to perform? ");
        scanf("%d", &num_ops);

        if (num_ops < 0) printf("Please enter a non-negative number.\n\n");
    }

    printf("\n");

    for (int i=0; i<num_ops; i++) {
        int choice = -1;

        while (choice < 0 || choice > 2) {
            printf("What would you like to do next?\n");
            printf("1. Add a number to the magical queue\n");
            printf("2. Remove a number from the magical queue\n");
            printf("3. Display the magical queue\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice < 0 || choice > 2) printf("Please enter a valid choice (1-3).\n\n");
        }

        printf("\n");

        switch (choice) {
            case 1: {
                int num = -1;

                while (num < 0) {
                    printf("Enter the number you want to add: ");
                    scanf("%d", &num);

                    if (num < 0) printf("Please enter a non-negative number.\n\n");
                }

                enqueue(magic_queue, num);

                printf("Your number has been added to the magical queue! Poof!\n\n");

                break;
            }
            case 2: {
                if (magic_queue->front == magic_queue->rear) {
                    printf("The magical queue is empty! You cannot remove any numbers.\n\n");
                } else {
                    int num = dequeue(magic_queue);
                    printf("Your magical number \"%d\" has been removed from the queue!\n\n", num);
                }

                break;
            }
            case 3: {
                display_queue(magic_queue);
                printf("\n");

                break;
            }
            default: {
                break;
            }
        }
    }

    printf("Thank you for using the Magical Queue Program! Come back soon!\n");

    free(magic_queue);

    return 0;
}

Queue* initialize_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = 0;
    return q;
}

void enqueue(Queue* q, int num) {
    if ((q->rear+1)%MAX_QUEUE_SIZE == q->front) {
        printf("The magical queue is full! You cannot add any more numbers.\n\n");
    } else {
        q->items[q->rear] = num;
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    }
}

int dequeue(Queue* q) {
    int num = q->items[q->front];
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    return num;
}

void display_queue(Queue* q) {
    printf("The magical queue currently looks like this:\n[ ");
    
    int i = q->front;
    
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i+1)%MAX_QUEUE_SIZE;
    }

    printf("]");
}