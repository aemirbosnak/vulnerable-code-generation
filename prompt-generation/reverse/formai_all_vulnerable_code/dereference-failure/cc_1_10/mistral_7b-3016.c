//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int front;
    int rear;
    int queue_array[MAX_QUEUE_SIZE];
} queue;

queue my_queue;

void initialize_queue() {
    my_queue.front = 0;
    my_queue.rear = 0;
}

int is_queue_full() {
    return (my_queue.rear + 1) % MAX_QUEUE_SIZE == my_queue.front;
}

int is_queue_empty() {
    return my_queue.front == my_queue.rear;
}

void enqueue(char *item) {
    if (is_queue_full()) {
        printf("O pardon, fair queue, thy capacity\n");
        printf("Is but a shade, a fleeting shadow,\n");
        printf("That canst not bear the weight of love\n");
        return;
    }

    strcpy(my_queue.queue_array[my_queue.rear], item);
    my_queue.rear = (my_queue.rear + 1) % MAX_QUEUE_SIZE;
}

char *dequeue() {
    if (is_queue_empty()) {
        printf("Alas, fair queue, thou art forlorn,\n");
        printf("Thy once resplendent court is empty now,\n");
        printf("No love, no joy, no tender words,\n");
        return NULL;
    }

    char *item = my_queue.queue_array[my_queue.front];
    my_queue.front = (my_queue.front + 1) % MAX_QUEUE_SIZE;
    return item;
}

int main() {
    initialize_queue();

    char *messages[2][3] = {{"Romeo: My bounty is as boundless as the sea,\n", "as deep. ", "as shores unmeasured. "},
                            {"Juliet: O speak again, bright angel,\n", "I prithee, bright angel, say,\n", "Do not forsake me."}};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            enqueue(messages[i][j]);
        }

        for (int k = 0; k < 3; ++k) {
            printf("%s", dequeue());
        }

        printf("\n");
    }

    return 0;
}