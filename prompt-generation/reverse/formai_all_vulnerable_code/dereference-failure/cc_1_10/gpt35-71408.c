//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct baggage{
    int id;
    char flight_code[10];
    char destination[10];
};

struct node{
    struct baggage data;
    struct node * next;
};

struct queue{
    struct node * front, * rear;
};

void enqueue(struct queue * q, struct baggage d){
    struct node * n = (struct node*) malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if(q->rear == NULL){
        q->front = n;
        q->rear = n;
    }
    else{
        q->rear->next = n;
        q->rear = n;
    }
}

struct baggage dequeue(struct queue * q){
    if(q->front == NULL)
        return (struct baggage){-1, "", ""};
    struct node * temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    struct baggage temp_data = temp->data;
    free(temp);
    return temp_data;
}

void display(struct queue q){
    if(q.front == NULL){
        printf("Queue is empty!\n");
        return;
    }
    struct node * curr = q.front;
    printf("BAG-ID\tFLT-CODE\tDEST\n");
    while(curr != NULL){
        printf("%d\t%s\t%s\n", curr->data.id, curr->data.flight_code, curr->data.destination);
        curr = curr->next;
    }
}

int main(){
    struct queue q = {NULL, NULL};
    int choice;
    struct baggage data;
    while(1){
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("AIRPORT BAGGAGE HANDLING SIMULATION USING QUEUE\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Add baggage to queue\n");
        printf("2. Remove baggage from queue\n");
        printf("3. Display details of all baggage in queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1: printf("Enter baggage ID, flight code, and destination separated by spaces: ");
                    scanf("%d %s %s", &data.id, data.flight_code, data.destination);
                    enqueue(&q, data);
                    break;
            case 2: data = dequeue(&q);
                    if(data.id == -1)
                        printf("\nQueue is empty!\n");
                    else
                        printf("\nBaggage with ID %d, Flight Code %s, and destination %s removed from queue.\n", data.id, data.flight_code, data.destination);
                    break;
            case 3: display(q);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice, try again!\n");
                     break;
       }
    }
    return 0;
}