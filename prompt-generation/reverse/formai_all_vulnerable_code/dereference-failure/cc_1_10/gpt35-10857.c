//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_BAGS 100     // Maximum number of bags
#define MAX_CONVEYOR 10  // Conveyor max capacity
#define MAX_ROBOTS 3     // Maximum number of robots
#define MAX_FLIGHTS 5    // Maximum number of flights
#define MAX_DEST 3       // Total number of destinations

// Mutex and condition variables to control the access to conveyor and robot
pthread_mutex_t mutex_conveyor = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_robot[MAX_ROBOTS] = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER
};
pthread_cond_t cv_conveyor = PTHREAD_COND_INITIALIZER;
pthread_cond_t cv_robot[MAX_ROBOTS] = {
    PTHREAD_COND_INITIALIZER,
    PTHREAD_COND_INITIALIZER,
    PTHREAD_COND_INITIALIZER
};

// Define a bag structure which contains the bag id and its destination
typedef struct bag {
    int id;
    int destination;
} bag_t;

// Define a global array of bags and atomic variable to track its current size
bag_t bags[MAX_BAGS];
int bag_count = 0;

// Define a global array of destinations and associated mutexes to control access
int destinations[MAX_DEST] = {1, 2, 3};
pthread_mutex_t mutex_dest[MAX_DEST] = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER
};

// Function to return random destination from the available list
int get_random_dest() {
    srand(time(NULL));
    return destinations[rand() % MAX_DEST];
}

// Function to add a new bag to the conveyor
void add_bag_to_conveyer(int id) {
    // Wait until there's space on the conveyor
    pthread_mutex_lock(&mutex_conveyor);
    while (bag_count >= MAX_CONVEYOR) {
        printf("Conveyor is full. Waiting...\n");
        pthread_cond_wait(&cv_conveyor, &mutex_conveyor);
    }  
    // Add the bag to the conveyor and signal the robots
    bags[bag_count].id = id;
    bags[bag_count].destination = get_random_dest();
    bag_count++;
    printf("Bag %d added to conveyor. Destination: %d\n", id, bags[bag_count-1].destination);  
    pthread_cond_signal(&cv_robot[bag_count % MAX_ROBOTS]);
    pthread_mutex_unlock(&mutex_conveyor);
}

// Function to process a bag by robot
void process_bag(int robot_id) {
    // Wait until there's a bag for the robot to process
    pthread_mutex_lock(&mutex_robot[robot_id]);
    while(bag_count == 0 || (bag_count % MAX_ROBOTS) != robot_id) {
        printf("Robot %d waiting...\n", robot_id);
        pthread_cond_wait(&cv_robot[robot_id], &mutex_robot[robot_id]);
    }
    // Get the bag and process it
    bag_t bag = bags[bag_count-1];
    printf("Robot %d processing bag %d for destination %d\n", robot_id, bag.id, bag.destination);
    // Release the mutex and sleep for some time
    sleep(2);
    pthread_mutex_unlock(&mutex_robot[robot_id]);
    // Move the bag to its respective destination conveyor
    pthread_mutex_lock(&mutex_dest[bag.destination-1]);
    printf("Bag %d is heading to destination %d\n", bag.id, bag.destination);
    bag_count--;
    pthread_cond_signal(&cv_conveyor);
    pthread_mutex_unlock(&mutex_dest[bag.destination-1]);
}

int main() {
    // Create threads for each robot
    pthread_t robots[MAX_ROBOTS];
    int robot_ids[MAX_ROBOTS] = {0, 1, 2};
    for(int i = 0; i < MAX_ROBOTS; i++) {
        pthread_create(&robots[i], NULL, (void*) &process_bag, &robot_ids[i]);
    }
    // Add bags to the conveyor
    for(int i = 1; i <= MAX_FLIGHTS; i++) {
        for(int j = 0; j < 10; j++) {
            add_bag_to_conveyer((i-1)*10+j);
        }
    }
    // Wait for all the robots to complete
    for(int i = 0; i < MAX_ROBOTS; i++) {
        pthread_join(robots[i], NULL);
    }
    return 0;
}