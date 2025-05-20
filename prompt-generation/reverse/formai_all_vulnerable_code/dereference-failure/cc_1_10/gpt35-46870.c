//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CAPACITY 100
#define MAX_FLIGHTS 10
#define MAX_LUGGAGE 20

typedef struct luggage{
    int weight;
    int flight_no;
}Luggage;

typedef struct node{
     Luggage l;
     struct node * next;
}Node;

typedef struct{
    Node * front, * rear;
    int size;
}Queue;

void initQueue(Queue * q){
    q->front=q->rear=NULL;
    q->size=0;
}

int isFull(const Queue * q){
    return q->size==CAPACITY;
}

int isEmpty(const Queue * q){
    return q->size==0;
}

void enQueue(Queue * q, Luggage l){
    if(isFull(q)){
        printf("Luggage Drop Off Service in busy now. Please try again later!\n");
        return;
    }
    Node * newL=(Node*)malloc(sizeof(Node));
    newL->l=l;
    newL->next=NULL;
    if(q->rear==NULL){
        q->front=q->rear=newL;
    }
    else {
        q->rear->next=newL;
        q->rear=q->rear->next;
    }
    q->size++;
}

Luggage deQueue(Queue * q){
    if(isEmpty(q)){
        Luggage l;
        l.weight=0;
        l.flight_no=0;
        printf("No Luggage Left Here!\n");
        return l;
    }
    Node * tmp=q->front;
    q->front=q->front->next;
    Luggage l=tmp->l;
    free(tmp);
    if(q->rear==NULL){
        q->front=NULL;
    }
    q->size--;
    return l;
}

void displayQ(Queue * q){
    Node * tmp=q->front;
    printf("Luggage List:\n");
    while(tmp!=NULL){
        printf("  Flight Number: %d, Weight: %dKg\n", tmp->l.flight_no, tmp->l.weight);
        tmp=tmp->next;
    }
}

int main(){
    srand(time(0));
    Queue queue;
    initQueue(&queue);
    int num_flights=rand()%MAX_FLIGHTS+1;
    Luggage luggage_list[MAX_LUGGAGE];
    printf("Today, %d flights are scheduled for departures:\n", num_flights);
    for(int i=0;i<num_flights;i++){
        printf("  Flight %d\n", i+1);
    }
    for(int i=0;i<MAX_LUGGAGE;i++){
        luggage_list[i].weight=rand()%50+1;
        luggage_list[i].flight_no=rand()%num_flights+1;
        printf("New Luggage Dropped Off: Flight %d, Weight: %dKg\n", luggage_list[i].flight_no, luggage_list[i].weight);
        enQueue(&queue, luggage_list[i]);
    }
    printf("\n\n========= Luggage Drop Off Finished. ================\n\n");
    displayQ(&queue);
    printf("\n\n========= Luggage Transfer to the Airport Cargo Finished. ================\n\n");
    printf("Next, Loading Starts at Gate No. 101\n\n");
    int i=1;
    while(!isEmpty(&queue)){
        Luggage l=deQueue(&queue);
        printf("Loading Luggage %d on Flight %d from Gate 101: Weight: %dKg\n", i, l.flight_no, l.weight);
        i++;
    }
    printf("\n\n========= Loading Finished. ================\n\n");
    return 0;
}