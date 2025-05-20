//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 15

struct Baggage{
    int id;
    char destination[MAX_SIZE], status[MAX_SIZE];
};

struct Node{
    struct Baggage data;
    struct Node *next;
};

struct Queue{
    struct Node *front, *rear;
};

void enqueue(struct Queue *queue, struct Baggage data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(queue->rear == NULL){
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}

void dequeue(struct Queue *queue){
    if(queue->front == NULL){
        return;
    }

    struct Node *temp = queue->front;
    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->rear = NULL;
    }

    free(temp);
}

void display(struct Queue *queue){
    if(queue->front == NULL){
        printf("\nQueue is empty");
        return;
    }

    struct Node *temp = queue->front;
    printf("\nBaggage ID\tDestination\tStatus");

    while(temp != NULL){
        printf("\n%d\t\t%s\t\t%s", temp->data.id, temp->data.destination, temp->data.status);
        temp = temp->next;
    }
}

int main(){
    struct Queue belt, xray;
    memset(&belt, 0, sizeof(belt));
    memset(&xray, 0, sizeof(xray));

    struct Baggage temp;
    int choice, id = 1;

    while(1){
        printf("\nAirport Baggage Handling Simulation\n");
        printf("1. Add Baggage to Belt\n");
        printf("2. Pass Baggage through X-Ray Machine\n");
        printf("3. Remove Baggage from Belt\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the destination of the baggage: ");
                scanf("%s", temp.destination);
                strcpy(temp.status, "On Belt");
                temp.id = id++;
                enqueue(&belt, temp);
                printf("\nBaggage with ID %d has been added to the belt", temp.id);
                break;

            case 2:
                if(xray.front != NULL){
                    printf("\nThe X-Ray machine is currently occupied");
                    break;
                }

                if(belt.front != NULL){
                    temp = belt.front->data;
                    dequeue(&belt);
                    printf("\nBaggage with ID %d is being passed through the X-Ray machine", temp.id);
                    strcpy(temp.status, "X-Ray Done");
                    enqueue(&xray, temp);
                }
                else{
                    printf("\nNo baggage on the belt to pass through X-Ray");
                }
                break;

            case 3:
                if(xray.front != NULL){
                    printf("\nThe baggage cannot be removed from the belt as it is being passed through the X-Ray machine");
                    break;
                }

                if(belt.front != NULL){
                    temp = belt.front->data;
                    dequeue(&belt);
                    printf("\nBaggage with ID %d has been removed from the belt", temp.id);
                    strcpy(temp.status, "Cleared");
                }
                else{
                    printf("\nNo baggage on the belt to remove");
                }

                if(temp.id != 0){
                    enqueue(&belt, temp);
                }
                break;

            case 4:
                printf("\nOn Belt:");
                display(&belt);
                printf("\n\nOn X-Ray:");
                display(&xray);
                break;

            case 5:
                printf("\nExiting...");
                exit(0);

            default: printf("\nInvalid choice");
        }
    }

    return 0;
}