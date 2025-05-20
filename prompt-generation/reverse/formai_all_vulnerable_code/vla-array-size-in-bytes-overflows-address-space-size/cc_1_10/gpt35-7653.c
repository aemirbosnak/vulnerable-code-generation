//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Baggage{ 
   int id; 
   int weight; 
};

struct ConveyorBelt{
   int currentWeight;
   int maxWeight; 
   int occupancy;
   int capacity; 
};

void initialize(struct ConveyorBelt *cb, int mW, int cap){
   cb->maxWeight = mW;
   cb->capacity = cap;
   cb->currentWeight = 0;
   cb->occupancy = 0;
}

int addBaggage(struct ConveyorBelt *cb, struct Baggage *bg){
   if(cb->currentWeight + bg->weight > cb->maxWeight){
      printf("\n\nCONVEYOR BELT FULL!!! Cannot add more baggage...\n\n");
      return 0; 
   }
   else if(cb->occupancy >= cb->capacity){
      printf("\n\nCONVEYOR BELT CAPACITY FULL!!! Cannot add more baggage...\n\n");
      return 0; 
   }
   else{
      cb->currentWeight += bg->weight; 
      cb->occupancy++;  
      printf("\n\nBaggage ID: %d | Weight: %d | Added to Conveyor Belt\n\n", bg->id, bg->weight);
      return 1; 
   }    
}

void removeBaggage(struct ConveyorBelt *cb, struct Baggage *bg){
    if(cb->currentWeight == 0){
       printf("\n\nCONVEYOR BELT IS EMPTY!!! Nothing to remove...\n\n");
    }
    else{
        cb->currentWeight -= bg->weight;
        cb->occupancy--;
        printf("\n\nBaggage ID: %d | Weight: %d | Removed from Conveyor Belt\n\n", bg->id, bg->weight);
    }
}

int main(){
   int maxWeight, capacity;
   printf("\nEnter Max Weight of Conveyor Belt: ");
   scanf("%d", &maxWeight);
   printf("Enter Capacity of Conveyor Belt: ");
   scanf("%d", &capacity);

   struct ConveyorBelt cb;
   initialize(&cb, maxWeight, capacity);

   int bagsToAdd;
   printf("\n\nEnter Number of Baggage to Add: ");
   scanf("%d", &bagsToAdd);
   if(bagsToAdd > cb.capacity){
       printf("\n\nCANNOT ADD BAGGAGE...Capacity of Conveyor Belt is %d\n\n", cb.capacity);
       return 0;
   }

   struct Baggage bags[bagsToAdd]; 

   for(int i = 0; i < bagsToAdd; i++){
      bags[i].id = i+1;
      printf("\nEnter Weight of Baggage %d: ", bags[i].id);
      scanf("%d", &bags[i].weight);
   }

   srand(time(NULL));
   int baggageIndex = 0;

   while(cb.currentWeight != 0 || baggageIndex < bagsToAdd){
      int choice = rand() % 2;

      if(choice == 0 && cb.currentWeight != 0){
         int index = rand() % cb.occupancy;
         int j = 0;
         struct Baggage removedBaggage;
         for(int i = 0; i < bagsToAdd; i++){
            if(bags[i].weight != -1){
               j++;
            }
            if(j > index){
               removedBaggage = bags[i];
               bags[i].weight = -1;
               break;
            }
         }
         removeBaggage(&cb, &removedBaggage);
      }
      else if(choice == 1 && baggageIndex < bagsToAdd){
         struct Baggage addedBaggage = bags[baggageIndex];
         if(addBaggage(&cb, &addedBaggage)){
            baggageIndex++;
         }
      }
   }

   return 0;
}