//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining the structure of baggage
struct Baggage{
    int id;
    char* origin;
    char* destination;
};

//defining the structure of conveyor belt
struct ConveyorBelt{
    int capacity;
    int count;
    struct Baggage** baggage_list;
};

//function to generate random origin and destination
char* generateLocation(){
    char* locations[6] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix", "Philadelphia"};
    int index = rand() % 6;
    return locations[index];
}

//function to generate baggage
struct Baggage* generateBaggage(int id){
    struct Baggage* baggage = (struct Baggage*) malloc(sizeof(struct Baggage));
    baggage->id = id;
    baggage->origin = generateLocation();
    baggage->destination = generateLocation();
    return baggage;
}

//function to create a conveyor belt
struct ConveyorBelt* createConveyorBelt(int capacity){
    struct ConveyorBelt* cb = (struct ConveyorBelt*) malloc(sizeof(struct ConveyorBelt));
    cb->capacity = capacity;
    cb->count = 0;
    cb->baggage_list = (struct Baggage**) malloc(capacity * sizeof(struct Baggage*));
    return cb;
}

//function to add baggage to conveyor belt
void addBaggage(struct ConveyorBelt* cb, struct Baggage* baggage){
    if(cb->count==cb->capacity){
        printf("Conveyor belt is full!\n");
        return;
    }
    
    cb->baggage_list[cb->count] = baggage;
    cb->count++;
    printf("Baggage with ID %d added to conveyor belt!\n", baggage->id);
}

//function to remove baggage from conveyor belt
void removeBaggage(struct ConveyorBelt* cb, int id){
    int index = -1;
    for(int i=0;i<cb->count;i++){
        if(cb->baggage_list[i]->id == id){
            index = i;
            break;
        }
    }
    
    if(index==-1){
        printf("Baggage with ID %d not found on conveyor belt!\n", id);
        return;
    }
    
    printf("Baggage with ID %d removed from conveyor belt!\n", cb->baggage_list[index]->id);
    for(int i=index+1;i<cb->count;i++){
        cb->baggage_list[i-1] = cb->baggage_list[i];
    }
    
    cb->count--;
}

int main(){
    srand(time(NULL));
    struct ConveyorBelt* cb = createConveyorBelt(5);
    addBaggage(cb, generateBaggage(1));
    addBaggage(cb, generateBaggage(2));
    addBaggage(cb, generateBaggage(3));
    addBaggage(cb, generateBaggage(4));
    addBaggage(cb, generateBaggage(5));
    addBaggage(cb, generateBaggage(6));
    removeBaggage(cb, 1);
    removeBaggage(cb, 3);
    removeBaggage(cb, 5);
    return 0;
}