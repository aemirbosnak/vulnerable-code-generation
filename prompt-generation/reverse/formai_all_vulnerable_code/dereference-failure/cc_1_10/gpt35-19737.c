//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Queue Structure
typedef struct {
    int* arr;
    int front, rear, size;
} Queue;

// Initializing the Queue
void init(Queue* q, int size) {
    q->arr = (int*)malloc(sizeof(int) * size);
    q->front = q->rear = -1;
    q->size = size;
}

// Check if the Queue is Empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the Queue is Full
int isFull(Queue* q) {
    return ((q->rear + 1) % q->size) == q->front;
}

// Add an element to the Queue
void enqueue(Queue* q, int item) {
    if(isFull(q)) {
        printf("Peek-a-boo! Queue is full. Can't add any more elements\n");
        return;
    }
    if(q->front == -1) 
        q->front = q->rear = 0;
    else 
        q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = item;
    printf("Little Johnny just pushed %d into the Queue\n", item);
}

// Remove an element from the Queue
int dequeue(Queue* q) {
    if(isEmpty(q)) {
        printf("Well, well, well! Queue is empty and there's nothing to remove\n");
        return -1;
    }
    int item = q->arr[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;
    printf("Tommy just removed %d from the Queue\n", item);
    return item;
}

// Return the front element of the Queue without removing it
int peek(Queue* q) {
    if(isEmpty(q)) {
        printf("Oh no! Queue is empty and there's nothing to peek\n");
        return -1;
    }
    printf("Let's take a sneak peek: The front element is %d\n", q->arr[q->front]);
    return q->arr[q->front];
}

int main() {
    srand(time(NULL));
    Queue q;
    int size = 5;
    init(&q, size);

    printf("Welcome to our Queue program based on a children's playground!\n\n");

    while(1) {
        printf("\n=========================================\n");
        printf("Please select any of the following options:\n");
        printf("1. Push a kid to the Queue\n");
        printf("2. Make a kid leave the Queue\n");
        printf("3. Let's peek at the front element\n");
        printf("4. Just let the kids play in the Queue\n");
        printf("5. Send the kids home (Exit the program)\n\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the kid you want to push: ");
                char name[100];
                scanf("%s", name);
                printf("How old is %s? : ", name);
                int age;
                scanf("%d", &age);
                enqueue(&q, age);
                break;
            case 2:
                printf("How many kids would you like to remove? : ");
                int num;
                scanf("%d", &num);
                printf("\nSending the following kids home: \n");
                for(int i=0; i<num; i++) {
                    int removed = dequeue(&q);
                    if(removed != -1) 
                        printf("Kid aged %d\n", removed);
                }
                break;
            case 3:
                printf("\nLet's take a peek at the kids: \n");
                peek(&q);
                break;
            case 4:
                printf("\nThe kids are having a blast! The Queue is as follows:\n");
                for(int i=q.front; i<q.rear+1; i++) {
                    printf("Kid aged %d\n", q.arr[i]);
                }
                break;
            case 5:
                printf("\nGoodbye! Time to send the kids home!\n\n");
                exit(0);
            default:
                printf("Oops! That's not a valid option, please try again.\n");
        }
    }
    return 0;
}