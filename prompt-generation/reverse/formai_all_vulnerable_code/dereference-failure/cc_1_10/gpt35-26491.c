//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#define MAX_BAGGAGE 100 // maximum number of baggage
#define MAX_CAPACITY 10 // maximum capacity of conveyor belt
#define TRUE 1
#define FALSE 0

typedef struct Baggage_struct{  //structure to store baggage info
  int id; //unique id for baggage
  int weight; //weight of baggage
  int is_priority; //flag to indicate whether baggage is priority or not
  int is_loaded; //flag to indicate whether baggage is loaded on plane or not
}Baggage;

typedef struct Conveyor_struct{ //structure for conveyor belt
  Baggage** baggages; //array of pointers to baggage
  int count; //number of baggage on conveyor belt
  int is_full; //flag to indicate whether conveyor belt is full or not
}Conveyor_belt;

typedef struct Plane_struct{ //structure for plane
  Baggage** baggages; //array of pointers to baggage
  int count; //number of baggage on plane
  int max_weight; //maximum weight that the plane can carry
}Plane;

int total_baggages = 0; //total number of baggage

void add_baggage(Baggage** baggages, int* count, int* max_id); //function to add baggage to queue of conveyor belt
void load_baggage(Baggage** baggages, int* count, char* plane_id); //function to load baggage on plane
void print_baggage_details(Baggage** baggages, int count); //function to print all the baggage currently in the system
int is_empty_conveyor_belt(Conveyor_belt* belt); //function to check whether the conveyor belt is empty or not
void set_priority_baggages(Baggage** baggages, int count); //function to set priority flag for baggage

int main() {
  Conveyor_belt belt; //initialize conveyor belt
  belt.baggages = (Baggage**)malloc(MAX_CAPACITY * sizeof(Baggage*)); //allocate memory for baggage
  belt.count = 0;
  belt.is_full = FALSE;
  Plane plane; //initialize plane
  plane.baggages = (Baggage**)malloc(MAX_BAGGAGE * sizeof(Baggage*)); //allocate memory for baggage
  plane.count = 0;
  plane.max_weight = 1000; //set maximum weight of plane
  
  int choice; //variable to store user choice
  while(1) {
    printf("\nAirport Baggage Handling Simulation\n");
    printf("1. Add baggage to conveyor belt queue\n");
    printf("2. Load baggage on plane\n");
    printf("3. View all baggage details\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        add_baggage(belt.baggages, &belt.count, &total_baggages);
        break;
      case 2:
        load_baggage(plane.baggages, &plane.count, "123");
        break;
      case 3:
        print_baggage_details(plane.baggages, plane.count);
        print_baggage_details(belt.baggages, belt.count);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

void add_baggage(Baggage** baggages, int* count, int* max_id){
  if(*count == MAX_CAPACITY) {
    printf("Conveyor belt is full\n");
    return;
  }
  Baggage* baggage = (Baggage*)malloc(sizeof(Baggage)); //allocate memory for baggage
  baggage->id = ++(*max_id); //assign unique id
  printf("Enter the weight of the baggage: ");
  scanf("%d", &baggage->weight); //get weight of baggage
  printf("Is the baggage priority?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  int choice;
  scanf("%d", &choice);
  switch(choice) {
    case 1:
      baggage->is_priority = TRUE; //set priority flag
      break;
    case 2:
      baggage->is_priority = FALSE;
      break;
    default:
      printf("Invalid choice\n");
      free(baggage); //free memory if user enters invalid choice
      return;
  }
  baggage->is_loaded = FALSE; //set loaded flag as false
  baggages[(*count)++] = baggage; //add baggage to conveyor belt
  printf("Baggage with id %d added to conveyor belt\n", baggage->id);
}

void load_baggage(Baggage** baggages, int* count, char* plane_id) {
  set_priority_baggages(baggages, *count);
  int current_weight = 0; //initialize current weight as 0
  int i = 0;
  while(i < *count && current_weight < 1000) { //load baggage until the maximum weight of plane is reached
    Baggage* baggage = baggages[i];
    if(!baggage->is_loaded) { //load only if baggage is not already loaded
      printf("Loading baggage with id %d on plane %s\n", baggage->id, plane_id);
      baggage->is_loaded = TRUE; //set loaded flag as true
      current_weight += baggage->weight; //add weight of baggage to the current weight of plane
    }
    i++;
  }
  printf("Total weight of baggage loaded on plane: %d\n", current_weight);
}

void print_baggage_details(Baggage** baggages, int count) {
  printf("\nTotal number of baggage: %d\n", count);
  printf("%-10s %-10s %-10s %-10s\n", "ID", "Weight", "Priority", "Loaded");
  for(int i = 0; i < count; i++) {
    Baggage* baggage = baggages[i];
    printf("%-10d %-10d %-10s %-10s\n", baggage->id, baggage->weight, baggage->is_priority ? "Yes" : "No", baggage->is_loaded ? "Yes" : "No");
  }
}

int is_empty_conveyor_belt(Conveyor_belt* belt) {
  return belt->count == 0 ? TRUE : FALSE;
}

void set_priority_baggages(Baggage** baggages, int count) {
  for(int i = 0; i < count; i++) {
    Baggage* baggage = baggages[i];
    if(baggage->is_priority) {
      Baggage* temp = baggage;
      int j = i - 1;
      while(j >= 0 && baggages[j]->is_priority != TRUE) {
        baggages[j+1] = baggages[j];
        j--;
      }
      baggages[j+1] = temp;
    }
  }
}