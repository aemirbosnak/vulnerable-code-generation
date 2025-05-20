//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BELTS 3
#define BELT_CAPACITY 10

// A Baggage object contains information about a single piece of luggage.
typedef struct
{
    int id;  // unique identifier for each piece of luggage
    int weight;  // weight of the bag in kg
} Baggage;

// A Belt object contains information about a single conveyor belt.
typedef struct
{
    Baggage* bags[BELT_CAPACITY];  // array of pointers to Baggage objects on the belt
    int num_bags;  // number of bags on the belt
} Belt;

// Function prototypes
void print_belt(Belt belt);
int get_total_weight(Belt belt);
void move_bag(Baggage *bag, Belt *from_belt, Belt *to_belt);

int main()
{
    srand(time(NULL));  // seed the random number generator with the current time
    
    Belt conveyor_belts[NUM_BELTS];
    for (int i = 0; i < NUM_BELTS; i++)
    {
        conveyor_belts[i].num_bags = 0;
    }
    
    // Generate 30 random bags and add them to the first belt.
    printf("Generating 30 random bags...\n");
    for (int i = 0; i < 30; i++)
    {
        Baggage *bag = (Baggage*) malloc(sizeof(Baggage));
        bag->id = i;
        bag->weight = rand() % 30 + 1;  // generate random weight between 1 and 30 kg
        conveyor_belts[0].bags[conveyor_belts[0].num_bags] = bag;
        conveyor_belts[0].num_bags++;
    }
    
    // Print the first belt before any bags are moved.
    printf("\nInitial belt:\n");
    print_belt(conveyor_belts[0]);
    
    // Move bags from the first belt to the second belt based on weight.
    for (int i = 0; i < BELT_CAPACITY; i++)
    {
        if (conveyor_belts[0].bags[i] != NULL)
        {
            Baggage *bag = conveyor_belts[0].bags[i];
            if (get_total_weight(conveyor_belts[1]) + bag->weight <= 100)
            {
                move_bag(bag, &conveyor_belts[0], &conveyor_belts[1]);
                i--;  // adjust loop variable since bags are being removed from the first belt
            }
        }
    }
    
    // Print both belts after bags have been moved.
    printf("\nFirst belt after bags have been moved:\n");
    print_belt(conveyor_belts[0]);
    printf("\nSecond belt after bags have been moved:\n");
    print_belt(conveyor_belts[1]);
    
    // Move bags from the second belt to the third belt randomly.
    printf("\nMoving bags from second belt to third belt...\n");
    for (int i = 0; i < BELT_CAPACITY; i++)
    {
        if (conveyor_belts[1].bags[i] != NULL)
        {
            Baggage *bag = conveyor_belts[1].bags[i];
            int random_num = rand() % 2;  // generate either 0 or 1
            if (random_num == 0)
            {
                move_bag(bag, &conveyor_belts[1], &conveyor_belts[2]);
                i--;  // adjust loop variable since bags are being removed from the second belt
            }
        }
    }
    
    // Print all three belts after bags have been moved.
    printf("\nFirst belt after bags have been moved:\n");
    print_belt(conveyor_belts[0]);
    printf("\nSecond belt after bags have been moved:\n");
    print_belt(conveyor_belts[1]);
    printf("\nThird belt after bags have been moved:\n");
    print_belt(conveyor_belts[2]);
    
    // Free the memory allocated for each Baggage object.
    for (int i = 0; i < NUM_BELTS; i++)
    {
        for (int j = 0; j < BELT_CAPACITY; j++)
        {
            if (conveyor_belts[i].bags[j] != NULL)
            {
                free(conveyor_belts[i].bags[j]);
            }
        }
    }
    
    return 0;
}

// Prints the contents of a Belt object.
void print_belt(Belt belt)
{
    printf("Number of bags: %d\n", belt.num_bags);
    printf("Total weight: %d kg\n", get_total_weight(belt));
    printf("Baggage:");
    for (int i = 0; i < BELT_CAPACITY; i++)
    {
        if (belt.bags[i] != NULL)
        {
            printf(" %d", belt.bags[i]->id + 1);
        }
    }
    printf("\n");
}

// Returns the total weight of all bags on a Belt object.
int get_total_weight(Belt belt)
{
    int total_weight = 0;
    for (int i = 0; i < BELT_CAPACITY; i++)
    {
        if (belt.bags[i] != NULL)
        {
            total_weight += belt.bags[i]->weight;
        }
    }
    return total_weight;
}

// Removes a Baggage object from one Belt object and adds it to another.
void move_bag(Baggage *bag, Belt *from_belt, Belt *to_belt)
{
    for (int i = 0; i < BELT_CAPACITY; i++)
    {
        if (from_belt->bags[i] == bag)
        {
            from_belt->bags[i] = NULL;
            from_belt->num_bags--;
            break;
        }
    }
    for (int i = 0; i < BELT_CAPACITY; i++)
    {
        if (to_belt->bags[i] == NULL)
        {
            to_belt->bags[i] = bag;
            to_belt->num_bags++;
            break;
        }
    }
}