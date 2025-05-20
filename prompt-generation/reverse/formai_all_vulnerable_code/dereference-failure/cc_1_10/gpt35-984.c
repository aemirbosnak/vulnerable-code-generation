//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 1000

typedef struct {
   int id;
   int weight;
   int destination;
} Bag;

typedef struct {
   int id;
   int capacity;
   int *destination_list;
   int dest_count;
} ConveyorBelt;

void add_bag_to_belt(Bag bag, ConveyorBelt *belt) {
   if(belt->capacity == MAX_BAGS)
      printf("\nBelt is at maximum capacity, cannot add bag!\n");
   else {
      belt->destination_list[belt->dest_count] = bag.destination;
      belt->dest_count++;
      printf("\nAdding bag with ID %d to belt %d\n", bag.id, belt->id);
   }
}

int main() {
   int num_belts, num_bags;
   Bag all_bags[MAX_BAGS];
   ConveyorBelt all_belts[MAX_BAGS];
   
   // Get the number of belts and bags from user
   printf("Enter number of conveyor belts: ");
   scanf("%d", &num_belts);
   printf("Enter number of bags: ");
   scanf("%d", &num_bags);
   
   // Fill in the details of each conveyor belt
   for(int i=0; i<num_belts; i++) {
      all_belts[i].id = i+1;
      printf("\nEnter capacity of belt %d: ", all_belts[i].id);
      scanf("%d", &all_belts[i].capacity);
      all_belts[i].destination_list = (int*) malloc(num_bags * sizeof(int));
      all_belts[i].dest_count = 0;
      
      printf("\nEnter destinations of belt %d (-1 to stop): ", all_belts[i].id);
      int dest;
      scanf("%d", &dest);
      while(dest != -1) {
         all_belts[i].destination_list[all_belts[i].dest_count] = dest;
         all_belts[i].dest_count++;
         scanf("%d", &dest);
      }
   }
   
   // Fill in the details of each bag
   for(int i=0; i<num_bags; i++) {
      all_bags[i].id = i+1;
      printf("\nEnter weight of bag %d: ", all_bags[i].id);
      scanf("%d", &all_bags[i].weight);
      printf("\nEnter destination of bag %d: ", all_bags[i].id);
      scanf("%d", &all_bags[i].destination);
   }
   
   // Add each bag to corresponding belt based on destination
   for(int i=0; i<num_bags; i++) {
      int bag_dest = all_bags[i].destination;
      for(int j=0; j<num_belts; j++) {
         ConveyorBelt belt = all_belts[j];
         for(int k=0; k<belt.dest_count; k++) {
            if(belt.destination_list[k] == bag_dest)
               add_bag_to_belt(all_bags[i], &belt);
         }
      }
   }
   
   // Free memory
   for(int i=0; i<num_belts; i++) {
      free(all_belts[i].destination_list);
   }
   
   return 0;
}