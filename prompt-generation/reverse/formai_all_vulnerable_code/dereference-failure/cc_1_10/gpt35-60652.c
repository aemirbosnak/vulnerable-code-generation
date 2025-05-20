//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

// Constants
#define MIN_FLOOR 1     // Minimum floor number 
#define MAX_FLOOR 10    // Maximum floor number
#define MAX_PEOPLE 8    // Maximum number of people entering the elevator
#define ELEVATOR_CAPACITY 6  // Maximum elevator capacity
#define DOOR_OPEN_TIME 2    // Time taken to open or close elevator door in seconds
#define FLOOR_PAUSE_TIME 4  // Time taken to move elevator to next floor in seconds

// Enum to define the direction of elevator travel
enum Direction {
    UP,
    DOWN,
    STATIONARY
};

// Struct that represents a person
struct Person {
    int id;     // Person's ID
    int src_floor;  // Source floor
    int dst_floor;  // Destination floor
};

// Struct that represents an elevator
struct Elevator {
    int current_floor;   // Elevator's current floor
    int capacity;        // Elevator's capacity
    int num_people;      // Number of people currently inside elevator
    enum Direction direction;   // Direction in which elevator is moving
};

// Thread that simulates adding people to elevator queue
void *add_people(void *arg)
{
    struct Person **people_queue = (struct Person**)arg;

    while(1)
    {
        // Simulate a person arriving at a random time
        sleep(rand()%10);

        // Generate a new person with random source and destination floors
        struct Person *p = (struct Person*)malloc(sizeof(struct Person));
        p->id = rand()%100;
        p->src_floor = rand()%MAX_FLOOR + 1;
        p->dst_floor = rand()%MAX_FLOOR + 1;

        // Add person to queue
        int i=0;
        while(people_queue[i] != NULL && i < MAX_PEOPLE)
            i++;
        if(i < MAX_PEOPLE)
            people_queue[i] = p;

        printf("New Person %d: Floor %d to Floor %d\n", p->id, p->src_floor, p->dst_floor);
    }
}

// Thread that simulates the elevator moving between floors
void *elevator(void *arg)
{
    struct Elevator *e = (struct Elevator*)arg;
    struct Person **people_queue = (struct Person**)calloc(MAX_PEOPLE, sizeof(struct Person*));
    
    while(1)
    {
        // Open door and unload people at current floor
        printf("Elevator Door Opening on Floor %d\n", e->current_floor);
        sleep(DOOR_OPEN_TIME);
        e->num_people = 0;

        // Check if any people are waiting to board
        int i=0;
        while(i < MAX_PEOPLE && people_queue[i] != NULL && e->num_people < e->capacity)
        {
            if(people_queue[i]->src_floor == e->current_floor)
            {
                // Let person enter elevator
                printf("Person %d entering Elevator on Floor %d\n", people_queue[i]->id, e->current_floor);
                e->num_people++;
                free(people_queue[i]);
                people_queue[i] = NULL;
            }
            i++;
        }

        // Close door and move to next floor
        printf("Elevator Door Closing on Floor %d\n", e->current_floor);
        sleep(DOOR_OPEN_TIME);
        if(e->direction == UP)
            e->current_floor++;
        else if(e->direction == DOWN)
            e->current_floor--;
        printf("Elevator Moving to Floor %d\n", e->current_floor);
        sleep(FLOOR_PAUSE_TIME);

        // Check if elevator has reached a new floor
        if(e->current_floor == MAX_FLOOR)
            e->direction = DOWN;
        else if(e->current_floor == MIN_FLOOR)
            e->direction = UP;
        else if(e->direction == UP)
        {
            // Check if there are any people waiting to board in the upward direction
            int i=0;
            while(i < MAX_PEOPLE && people_queue[i] != NULL)
            {
                if(people_queue[i]->src_floor > e->current_floor)
                {
                    e->direction = UP;
                    break;
                }
                i++;
            }
            // If there are no more people in the queue, switch direction
            if(i == MAX_PEOPLE || people_queue[i] == NULL)
                e->direction = DOWN;
        }
        else if(e->direction == DOWN)
        {
            // Check if there are any people waiting to board in the downward direction
            int i=0;
            while(i < MAX_PEOPLE && people_queue[i] != NULL)
            {
                if(people_queue[i]->src_floor < e->current_floor)
                {
                    e->direction = DOWN;
                    break;
                }
                i++;
            }
            // If there are no more people in the queue, switch direction
            if(i == MAX_PEOPLE || people_queue[i] == NULL)
                e->direction = UP;
        }
    }
}

int main()
{
    srand(time(0));
    struct Elevator *e = (struct Elevator*)malloc(sizeof(struct Elevator));
    e->current_floor = 1;
    e->capacity = ELEVATOR_CAPACITY;
    e->num_people = 0;
    e->direction = STATIONARY;

    pthread_t person_thread, elevator_thread;
    pthread_create(&person_thread, NULL, add_people, NULL);
    pthread_create(&elevator_thread, NULL, elevator, (void*)e);

    pthread_join(person_thread, NULL);
    pthread_join(elevator_thread, NULL);

    return 0;
}