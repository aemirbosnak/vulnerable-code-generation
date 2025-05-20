//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_DESTINATIONS 10
#define BAG_SIZE 50

typedef struct {
    int destination;
    int size;
} Bag;

Bag bags[NUM_BAGS];
int destinations[NUM_DESTINATIONS];
int num_destinations;

void generate_bags() {
    srand(time(NULL));

    for (int i = 0; i < NUM_BAGS; i++) {
        int size = rand() % BAG_SIZE + 1;
        bags[i].size = size;
        bags[i].destination = rand() % num_destinations;
    }
}

void sort_bags() {
    for (int i = 0; i < NUM_BAGS - 1; i++) {
        for (int j = i + 1; j < NUM_BAGS; j++) {
            if (bags[i].destination > bags[j].destination) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

void print_bags() {
    for (int i = 0; i < NUM_BAGS; i++) {
        printf("Bag %d: Size %d, Destination %d\n", i + 1, bags[i].size, bags[i].destination);
    }
}

int main() {
    destinations[0] = 1;
    num_destinations = 1;

    printf("Enter the number of destinations: ");
    scanf("%d", &num_destinations);

    for (int i = 1; i < num_destinations; i++) {
        printf("Enter destination %d: ", i);
        scanf("%d", &destinations[i]);
    }

    generate_bags();
    sort_bags();
    print_bags();

    return 0;
}