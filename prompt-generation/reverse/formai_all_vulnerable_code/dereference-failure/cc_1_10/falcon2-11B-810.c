//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct queue_node {
    int data;
    struct queue_node *next;
} queue_node;

queue_node *front, *rear;

int main() {
    int choice, num, item;
    queue_node *temp;

    printf("Welcome to Queue Implementation!\n");

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to be enqueued: ");
                scanf("%d", &num);
                if (front == NULL) {
                    front = rear = (queue_node*)malloc(sizeof(queue_node));
                    front->data = num;
                    front->next = NULL;
                } else {
                    rear->next = (queue_node*)malloc(sizeof(queue_node));
                    rear->next->data = num;
                    rear->next->next = NULL;
                    rear = rear->next;
                }
                break;
            case 2:
                if (front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Dequeued item: %d\n", front->data);
                    temp = front;
                    front = front->next;
                    free(temp);
                }
                break;
            case 3:
                if (front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    queue_node *ptr = front;
                    while (ptr!= NULL) {
                        printf("%d ", ptr->data);
                        ptr = ptr->next;
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}