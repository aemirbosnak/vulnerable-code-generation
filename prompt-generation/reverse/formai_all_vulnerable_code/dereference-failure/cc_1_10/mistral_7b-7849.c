//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define QUEUE_SIZE 10
#define QUEUE_NAME "WhimsyWicket"
#define ELEMENT_SIZE 50

typedef struct {
    int front;
    int rear;
    int count;
    char elements[QUEUE_SIZE][ELEMENT_SIZE];
} WhimsyQueue;

void enqueue(WhimsyQueue *queue, char *element) {
    if ((queue->count) == QUEUE_SIZE) {
        printf("Error: Queue is full!\n");
        return;
    }
    strcpy(queue->elements[queue->rear], element);
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->count++;
    printf("Element '%s' enqueued successfully!\n", element);
}

char *dequeue(WhimsyQueue *queue) {
    if ((queue->count) == 0) {
        printf("Error: Queue is empty!\n");
        return NULL;
    }
    char *element = malloc(strlen(queue->elements[queue->front]) + 1);
    strcpy(element, queue->elements[queue->front]);
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->count--;
    return element;
}

void print_queue(WhimsyQueue queue) {
    int i;
    printf("\nContents of the %s:\n", QUEUE_NAME);
    for (i = queue.front; i != queue.rear; i = (i + 1) % QUEUE_SIZE) {
        printf("%s\n", queue.elements[i]);
    }
    if (queue.rear == queue.front) {
        printf("The %s is empty!\n", QUEUE_NAME);
    }
}

int main() {
    pid_t pid;
    WhimsyQueue my_queue;
    my_queue.front = my_queue.rear = -1;
    my_queue.count = 0;

    printf("\nWelcome to the Whimsical Queue!\n");

    while (1) {
        printf("\nPlease enter a string to enqueue or type 'exit' to quit: ");
        char input[ELEMENT_SIZE];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            break;
        }
        enqueue(&my_queue, input);
        print_queue(my_queue);

        pid = fork();
        if (pid > 0) {
            wait(NULL);
            printf("\nParent: Dequeued: %s\n", dequeue(&my_queue));
            print_queue(my_queue);
        } else {
            char *element = dequeue(&my_queue);
            printf("\nChild: Received: %s\n", element);
            free(element);
            exit(0);
        }
    }

    return 0;
}