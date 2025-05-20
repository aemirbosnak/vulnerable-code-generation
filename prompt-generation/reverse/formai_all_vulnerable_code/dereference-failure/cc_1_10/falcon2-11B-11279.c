//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* name;
    char* destination;
    char* size;
} Baggage;

typedef struct {
    int id;
    int bag_count;
    Baggage* bags;
} Airport;

void* bag_handler(void* arg) {
    Airport* airport = (Airport*)arg;
    Baggage* bag = malloc(sizeof(Baggage));
    bag->name = "Test Baggage";
    bag->destination = "Paris";
    bag->size = "Large";
    
    airport->bag_count++;
    airport->bags = realloc(airport->bags, (airport->bag_count + 1) * sizeof(Baggage));
    airport->bags[airport->bag_count] = *bag;
    
    pthread_exit(NULL);
}

void* bag_creator(void* arg) {
    Airport* airport = (Airport*)arg;
    Baggage* bag = malloc(sizeof(Baggage));
    bag->name = "Test Baggage";
    bag->destination = "Paris";
    bag->size = "Large";
    
    airport->bag_count++;
    airport->bags = realloc(airport->bags, (airport->bag_count + 1) * sizeof(Baggage));
    airport->bags[airport->bag_count] = *bag;
    
    pthread_exit(NULL);
}

int main() {
    Airport* airport = malloc(sizeof(Airport));
    airport->bag_count = 0;
    airport->bags = malloc(sizeof(Baggage));
    
    pthread_t bag_thread;
    pthread_create(&bag_thread, NULL, bag_creator, (void*)airport);
    pthread_join(bag_thread, NULL);
    
    pthread_t handler_thread;
    pthread_create(&handler_thread, NULL, bag_handler, (void*)airport);
    pthread_join(handler_thread, NULL);
    
    printf("Baggage Count: %d\n", airport->bag_count);
    for (int i = 0; i < airport->bag_count; i++) {
        printf("Baggage %d: %s - %s - %s\n", i+1, airport->bags[i].name, airport->bags[i].destination, airport->bags[i].size);
    }
    
    free(airport->bags);
    free(airport);
    return 0;
}