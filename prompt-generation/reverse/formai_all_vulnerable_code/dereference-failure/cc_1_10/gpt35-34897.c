//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50
#define MAX_CAPACITY 80
#define MIN_ARR_TIME 5
#define MAX_ARR_TIME 10

typedef struct Baggage{
    int id;
    float weight;
}baggage;

typedef struct Node{
    baggage bag;
    struct Node *next;
}node;

node *front = NULL;
node *rear = NULL;

int size = 0;

void enqueue(baggage bg){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->bag = bg;
    new_node->next = NULL;
    if(front == NULL){
        front = new_node;
        rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
    size++;
}

baggage dequeue(){
    if(front == NULL){
        baggage empty_bag = {-1,0};
        return empty_bag;
    }
    else{
        baggage bg = front->bag;
        front = front->next;
        size--;
        return bg;
    }
}

int main(){
    srand(time(NULL));
    int total_bags = rand()%MAX_BAGS + 1;
    printf("Total Bags: %d\n",total_bags);
    for(int i=0; i<total_bags; i++){
        baggage bg;
        bg.id = i+1;
        bg.weight = rand() % MAX_WEIGHT + 1;
        enqueue(bg);
        printf("Bag %d Weight: %.2f kg\n",bg.id,bg.weight);
    }
    printf("\n\nBags being processed...\n\n");
    int total_weight = 0;
    int bags_processed = 0;
    while(front != NULL){
        baggage bg = dequeue();
        printf("Bag %d with weight %.2f kg processed.\n",bg.id,bg.weight);
        total_weight += bg.weight;
        bags_processed++;
        if(total_weight>=MAX_CAPACITY){
            printf("\n\nMaximum Capacity Reached!\n");
            break;
        }
        int arr_time = rand() % (MAX_ARR_TIME-MIN_ARR_TIME+1) + MIN_ARR_TIME;
        printf("Next Bag expected in %d seconds.\n",arr_time);
        printf("------------------------------------------------------\n");
        sleep(arr_time);
    }
    printf("\n\nTotal bags processed: %d\n",bags_processed);
    printf("Total weight processed: %d kg\n\n",total_weight);
    return 0;
}