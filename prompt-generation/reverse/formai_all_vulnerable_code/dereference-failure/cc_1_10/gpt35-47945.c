//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LETTERS 26 // maximum number of letters for flight code
#define MAX_FLIGHTS 100 // maximum number of flights in the airport
#define MAX_BAGS 10 // maximum number of bags per flight
#define MAX_CAPACITY 50 // maximum capacity of the baggage belt

// define structures
typedef struct BaggageBag
{
    char* id; // ID of the baggage bag
    char* flight; // flight code of the bag's associated flight
} BaggageBag;

typedef struct BaggageBelt
{
    int capacity; // current capacity of the baggage belt
    BaggageBag* bags[MAX_CAPACITY]; // array of pointers to baggage bags on the belt
} BaggageBelt;

typedef struct Flight
{
    char* code; // flight code of the flight
    BaggageBag* bags[MAX_BAGS]; // array of pointers to bags associated with the flight
} Flight;

typedef struct Airport
{
    Flight* flights[MAX_FLIGHTS]; // array of pointers to flights in the airport
    int num_flights; // current number of flights in the airport
    BaggageBelt* belt; // pointer to the baggage belt in the airport
} Airport;

// functions
char* generate_flight_code();
char* generate_bag_id();
void add_flight(Airport* airport);
void add_bag_to_flight(Airport* airport, Flight* flight);
void move_bags_to_belt(Airport* airport);

// generate a random 4-letter flight code
char* generate_flight_code()
{
    char* code = malloc(sizeof(char) * 5);
    for(int i=0; i<4; i++)
    {
        code[i] = 'A' + rand() % MAX_LETTERS;
    }
    code[4] = '\0';
    return code;
}

// generate a random 6-digit baggage ID
char* generate_bag_id()
{
    char* id = malloc(sizeof(char) * 7);
    for(int i=0; i<6; i++)
    {
        id[i] = '0' + rand() % 10;
    }
    id[6] = '\0';
    return id;
}

// add a new flight to the airport
void add_flight(Airport* airport)
{
    if(airport->num_flights >= MAX_FLIGHTS)
    {
        printf("Maximum number of flights reached.\n");
        return;
    }

    // create new flight
    Flight* new_flight = malloc(sizeof(Flight));
    new_flight->code = generate_flight_code();
    for(int i=0; i<MAX_BAGS; i++)
    {
        new_flight->bags[i] = NULL; // initialize bag pointers to NULL
    }

    // add flight to airport
    airport->flights[airport->num_flights] = new_flight;
    airport->num_flights++;
    printf("Flight %s added to airport.\n", new_flight->code);
}

// add a new bag to a flight
void add_bag_to_flight(Airport* airport, Flight* flight)
{
    int empty_slot = -1; // index of first empty slot in the flight's bags array
    for(int i=0; i<MAX_BAGS; i++)
    {
        if(flight->bags[i] == NULL)
        {
            empty_slot = i;
            break;
        }
    }

    if(empty_slot == -1)
    {
        printf("Flight %s has reached maximum number of bags.\n", flight->code);
        return;
    }

    // create new bag and assign to flight
    BaggageBag* new_bag = malloc(sizeof(BaggageBag));
    new_bag->id = generate_bag_id();
    new_bag->flight = flight->code;
    flight->bags[empty_slot] = new_bag;
    printf("Bag with ID %s added to flight %s.\n", new_bag->id, flight->code);
}

// move bags from flights to the baggage belt
void move_bags_to_belt(Airport* airport)
{
    printf("Moving bags to baggage belt...\n");

    // move bags from each flight to the baggage belt
    for(int i=0; i<airport->num_flights; i++)
    {
        for(int j=0; j<MAX_BAGS; j++)
        {
            if(airport->flights[i]->bags[j] != NULL)
            {
                if(airport->belt->capacity >= MAX_CAPACITY)
                {
                    printf("Baggage belt has reached maximum capacity.\n");
                    return;
                }

                // add bag to baggage belt
                airport->belt->bags[airport->belt->capacity] = airport->flights[i]->bags[j];
                airport->belt->capacity++;
                airport->flights[i]->bags[j] = NULL; // remove bag from flight
            }
        }
    }

    printf("Bags moved to baggage belt.\n");
    printf("Baggage belt now has %d bags.\n", airport->belt->capacity);
}

int main()
{
    srand(time(NULL)); // seed random number generator

    // initialize airport
    Airport airport;
    airport.num_flights = 0;
    airport.belt = malloc(sizeof(BaggageBelt));
    airport.belt->capacity = 0;

    // main loop
    while(1)
    {
        printf("Enter command: ");
        char input[20];
        fgets(input, 20, stdin);

        if(strcmp(input, "add flight\n") == 0)
        {
            add_flight(&airport);
        }
        else if(strcmp(input, "add bag\n") == 0)
        {
            if(airport.num_flights == 0)
            {
                printf("No flights in airport.\n");
                continue;
            }

            printf("Enter flight code: ");
            char flight_code[5];
            fgets(flight_code, 5, stdin);
            flight_code[strlen(flight_code)-1] = '\0'; // remove newline character

            Flight* target_flight = NULL;
            for(int i=0; i<airport.num_flights; i++)
            {
                if(strcmp(airport.flights[i]->code, flight_code) == 0)
                {
                    target_flight = airport.flights[i];
                    break;
                }
            }

            if(target_flight == NULL)
            {
                printf("Invalid flight code.\n");
                continue;
            }

            add_bag_to_flight(&airport, target_flight);
        }
        else if(strcmp(input, "move bags\n") == 0)
        {
            move_bags_to_belt(&airport);
        }
        else if(strcmp(input, "exit\n") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    // free memory
    for(int i=0; i<airport.num_flights; i++)
    {
        for(int j=0; j<MAX_BAGS; j++)
        {
            if(airport.flights[i]->bags[j] != NULL)
            {
                free(airport.flights[i]->bags[j]);
            }
        }
        free(airport.flights[i]);
    }
    free(airport.belt);
}