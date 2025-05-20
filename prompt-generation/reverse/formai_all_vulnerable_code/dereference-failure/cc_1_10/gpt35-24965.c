//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BAGS 20

// Utility functions
void clearScreen(){
    system("clear||cls");
}

void pause(){
    printf("\nPress Enter to continue...");
    getchar();
}

// Structs
typedef struct {
    int number;
    int weight;
    char destination[20];
} Bag;

typedef struct {
    Bag *bag[MAX_BAGS];
    int count;
} Bin;

typedef struct {
    Bin *bins[10];
} ConveyorBelt;

// Function prototypes
void addBagToConveyorBelt(ConveyorBelt *cb);
void removeBagFromConveyorBelt(ConveyorBelt *cb);
void printConveyorBelt(ConveyorBelt *cb);

// Main function
int main(){
    ConveyorBelt *cb = (ConveyorBelt*) malloc(sizeof(ConveyorBelt));
    for(int i = 0; i < 10; i++){
        cb->bins[i] = (Bin*) malloc(sizeof(Bin));
        cb->bins[i]->count = 0;
    }
    int option;
    do {
        clearScreen();
        printf("Airport Baggage Handling Simulation\n");
        printf("1. Add bag to conveyor belt\n");
        printf("2. Remove bag from conveyor belt\n");
        printf("3. Print conveyor belt\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                addBagToConveyorBelt(cb);
                pause();
                break;
            case 2:
                removeBagFromConveyorBelt(cb);
                pause();
                break;
            case 3:
                printConveyorBelt(cb);
                pause();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                pause();
                break;
        }
    } while(option != 4);
    return 0;
}

void addBagToConveyorBelt(ConveyorBelt *cb){
    if(cb->bins[0]->count == MAX_BAGS){
        printf("Conveyor belt is full. Cannot add more bags.\n");
        return;
    }
    Bag *bag = (Bag*) malloc(sizeof(Bag));
    printf("Enter bag number: ");
    scanf("%d", &bag->number);
    printf("Enter bag weight: ");
    scanf("%d", &bag->weight);
    printf("Enter bag destination: ");
    scanf("%s", bag->destination);
    cb->bins[0]->bag[cb->bins[0]->count++] = bag;
    printf("Bag added to conveyor belt successfully.\n");
}

void removeBagFromConveyorBelt(ConveyorBelt *cb){
    if(cb->bins[0]->count == 0){
        printf("Conveyor belt is empty. Cannot remove bags.\n");
        return;
    }
    Bag *bag = cb->bins[0]->bag[--cb->bins[0]->count];
    char confirm;
    printf("Bag with number %d and weight %d to %s is being removed from conveyor belt. Confirm? (Y/N): ", bag->number, bag->weight, bag->destination);
    scanf(" %c", &confirm);
    if(confirm == 'Y'){
        printf("Bag removed from conveyor belt successfully.\n");
    } else {
        cb->bins[0]->bag[cb->bins[0]->count++] = bag;
        printf("Bag not removed from conveyor belt.\n");
    }
}

void printConveyorBelt(ConveyorBelt *cb){
    printf("Conveyor Belt:\n");
    for(int i = 0; i < 10; i++){
        printf("Bin %d: ", i);
        for(int j = 0; j < cb->bins[i]->count; j++){
            Bag *bag = cb->bins[i]->bag[j];
            printf("(%d, %d, %s) ", bag->number, bag->weight, bag->destination);
        }
        printf("\n");
    }
}