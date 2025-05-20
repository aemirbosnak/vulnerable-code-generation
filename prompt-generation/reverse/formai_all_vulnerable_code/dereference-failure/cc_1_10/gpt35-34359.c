//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

//function to print menu and return choice
int printMenu(){
    int choice;
    printf("------Airport Baggage Handling Simulation------\n");
    printf("1. Add passenger to the queue\n");
    printf("2. Process passenger from the queue\n");
    printf("3. Display number of passengers left in the queue\n");
    printf("4. Exit program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

//structure to represent a passenger
struct Passenger{
    int id;
    char name[25];
    struct Passenger *next;
};

//structure to represent the queue
struct Queue{
    int count;
    struct Passenger *front, *rear;
};

//function to create a new passenger node
struct Passenger* createPassenger(int id, char name[25]){
    struct Passenger *newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
    newPassenger->id = id;
    strcpy(newPassenger->name, name);
    newPassenger->next = NULL;
    return newPassenger;
}

//function to create a new queue
struct Queue* createQueue(){
    struct Queue *newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->count = 0;
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

//function to add a passenger to the queue
void addPassenger(struct Queue *queue){
    char name[25];
    int id;
    printf("Enter passenger name: ");
    scanf("%s", name);
    printf("Enter passenger id: ");
    scanf("%d", &id);
    struct Passenger *newPassenger = createPassenger(id, name);
    if(queue->rear==NULL){
        queue->front = queue->rear = newPassenger;
    }
    else{
        queue->rear->next = newPassenger;
        queue->rear = newPassenger;
    }
    queue->count++;
    printf("Passenger added to queue successfully!\n");
}

//function to process the front passenger from the queue
void processPassenger(struct Queue *queue){
    if(queue->front==NULL){
        printf("Error: Queue is empty!\n");
        return;
    }
    struct Passenger *temp = queue->front;
    queue->front = queue->front->next;
    printf("Processed passenger with id %d and name %s\n", temp->id, temp->name);
    free(temp);
    queue->count--;
}

//function to display number of passengers left in the queue
void displayCount(struct Queue *queue){
    printf("Number of passengers in the queue: %d\n", queue->count);
}

int main(){
    struct Queue *queue = createQueue();
    int choice;
    do{
        choice = printMenu();
        switch(choice){
            case 1:
                addPassenger(queue);
                break;
            case 2:
                processPassenger(queue);
                break;
            case 3:
                displayCount(queue);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again...\n");
        }
    }while(choice!=4);
    return 0;
}