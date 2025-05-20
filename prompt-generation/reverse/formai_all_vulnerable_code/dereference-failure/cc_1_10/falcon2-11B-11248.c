//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int bag_num;
    int weight;
    int dest;
    int arrival_time;
    int departure_time;
} Bag;

void print_bag(Bag *bag) {
    printf("Bag %d weight: %d, destination: %d, arrival_time: %d, departure_time: %d\n", bag->bag_num, bag->weight, bag->dest, bag->arrival_time, bag->departure_time);
}

int main() {
    srand(time(NULL));
    int num_bags = 10;
    Bag *bags = (Bag *)malloc(num_bags * sizeof(Bag));

    for(int i = 0; i < num_bags; i++) {
        bags[i].bag_num = rand() % 100;
        bags[i].weight = rand() % 50;
        bags[i].dest = rand() % 3;
        bags[i].arrival_time = rand() % 60;
        bags[i].departure_time = rand() % 60;
        print_bag(&bags[i]);
    }

    for(int i = 0; i < num_bags; i++) {
        bags[i].departure_time += bags[i].weight;
    }

    for(int i = 0; i < num_bags; i++) {
        if(bags[i].departure_time > 60) {
            bags[i].departure_time -= 60;
        }
    }

    for(int i = 0; i < num_bags; i++) {
        if(bags[i].departure_time < bags[i].arrival_time) {
            bags[i].departure_time += 60;
        }
    }

    for(int i = 0; i < num_bags; i++) {
        if(bags[i].departure_time < bags[i].arrival_time) {
            bags[i].departure_time += 60;
        }
    }

    for(int i = 0; i < num_bags; i++) {
        print_bag(&bags[i]);
    }

    free(bags);
    return 0;
}