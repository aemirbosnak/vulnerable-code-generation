//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ROOMS 10
#define MIN_ROOMS 5
#define MAX_EXITS 4
#define MIN_EXITS 2

typedef struct room
{
    int id;
    int num_exits;
    int exits[MAX_EXITS];
    int visited;
} room;

typedef struct house
{
    int num_rooms;
    room rooms[MAX_ROOMS];
} house;

// Function to create a new house
house *create_house()
{
    // Allocate memory for the house
    house *h = (house *)malloc(sizeof(house));

    // Set the number of rooms in the house
    h->num_rooms = rand() % (MAX_ROOMS - MIN_ROOMS + 1) + MIN_ROOMS;

    // Create each room in the house
    for (int i = 0; i < h->num_rooms; i++)
    {
        // Set the room's ID
        h->rooms[i].id = i;

        // Set the number of exits in the room
        h->rooms[i].num_exits = rand() % (MAX_EXITS - MIN_EXITS + 1) + MIN_EXITS;

        // Set the exits in the room
        for (int j = 0; j < h->rooms[i].num_exits; j++)
        {
            // Get a random exit ID
            int exit_id = rand() % h->num_rooms;

            // Make sure the exit ID is not the same as the room's ID
            while (exit_id == i)
            {
                exit_id = rand() % h->num_rooms;
            }

            // Set the exit in the room
            h->rooms[i].exits[j] = exit_id;
        }

        // Set the room's visited flag to false
        h->rooms[i].visited = 0;
    }

    // Return the house
    return h;
}

// Function to print the house
void print_house(house *h)
{
    // Print the number of rooms in the house
    printf("Number of rooms: %d\n", h->num_rooms);

    // Print each room in the house
    for (int i = 0; i < h->num_rooms; i++)
    {
        // Print the room's ID
        printf("Room %d:\n", h->rooms[i].id);

        // Print the number of exits in the room
        printf("Number of exits: %d\n", h->rooms[i].num_exits);

        // Print the exits in the room
        printf("Exits: ");
        for (int j = 0; j < h->rooms[i].num_exits; j++)
        {
            printf("%d ", h->rooms[i].exits[j]);
        }
        printf("\n");

        // Print the room's visited flag
        printf("Visited: %d\n", h->rooms[i].visited);

        printf("\n");
    }
}

// Function to explore the house
void explore_house(house *h)
{
    // Create a stack to store the rooms that have been visited
    int stack[MAX_ROOMS];
    int top = -1;

    // Push the first room onto the stack
    stack[++top] = 0;

    // While there are still rooms to explore
    while (top >= 0)
    {
        // Pop the top room off the stack
        int room_id = stack[top--];

        // Mark the room as visited
        h->rooms[room_id].visited = 1;

        // Print the room
        printf("Exploring room %d\n", room_id);

        // Get the exits in the room
        int exits[MAX_EXITS];
        int num_exits = h->rooms[room_id].num_exits;
        for (int i = 0; i < num_exits; i++)
        {
            exits[i] = h->rooms[room_id].exits[i];
        }

        // Shuffle the exits
        for (int i = 0; i < num_exits; i++)
        {
            int j = rand() % num_exits;
            int temp = exits[i];
            exits[i] = exits[j];
            exits[j] = temp;
        }

        // Push the exits onto the stack
        for (int i = 0; i < num_exits; i++)
        {
            // If the exit has not been visited
            if (h->rooms[exits[i]].visited == 0)
            {
                stack[++top] = exits[i];
            }
        }
    }
}

// Main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a new house
    house *h = create_house();

    // Print the house
    print_house(h);

    // Explore the house
    explore_house(h);

    // Free the memory allocated for the house
    free(h);

    return 0;
}