//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_WEIGHT 50

typedef struct Baggage{
    int bag_no;
    int weight;
}baggage;

typedef struct Node{
    baggage *b;
    struct Node *next;
}node;

node *head = NULL;
int totalBags = 0;

void display_current_stats(){
    int count = 0, weight = 0;
    node *temp = head;
    while(temp != NULL){
        count++;
        weight += temp->b->weight;
        temp = temp->next;
    }
    printf("\nCurrent total bags: %d", count);
    printf("\nCurrent total weight: %d kg", weight);
}

void add_bag(){
    if(totalBags >= MAX_BAGS){
        printf("\nSorry, the baggage belt is full.");
        return;
    }
    baggage *b = (baggage *) malloc(sizeof(baggage));
    b->bag_no = totalBags+1;
    b->weight = (rand() % MAX_WEIGHT) + 1;
    node *newNode = (node *) malloc(sizeof(node));
    newNode->b = b;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nBag %d (weight:%d kg) added successfully.", b->bag_no, b->weight);
    totalBags++;
    display_current_stats();
}

void remove_bag(){
    if(totalBags == 0){
        printf("\nSorry, the baggage belt is empty.");
        return;
    }
    baggage *b;
    node *temp = head;
    head = head->next;
    b = temp->b;
    free(temp);
    totalBags--;
    printf("\nBag %d (weight:%d kg) removed successfully.", b->bag_no, b->weight);
    display_current_stats();
}

int main(){
    srand(time(0));
    int choice;
    printf("\nWelcome to the Baggage Handling Simulation");
    while(1){
        printf("\n\nPlease select an option:");
        printf("\n1. Add a new baggage");
        printf("\n2. Remove a baggage");
        printf("\n3. Exit the simulation");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_bag();
                    break;
            case 2: remove_bag();
                    break;
            case 3: exit(0);
            default: printf("\nPlease enter a valid choice.");
        }
    }
    return 0;
}