//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_PLANES 10
#define NUM_BAGGAGES 50
#define NUM_DESTINATIONS 20

//Structure for a plane
typedef struct {
    int plane_id;
    int num_baggage;
    int *baggage_id;
    char **destinations;
} Plane;

//Structure for a bag
typedef struct {
    int bag_id;
    char *destination;
} Bag;

void generate_planes(Plane *planes, int num_planes) {
    for (int i = 0; i < num_planes; i++) {
        planes[i].plane_id = i + 1;
        planes[i].num_baggage = rand() % 10 + 1;
        planes[i].baggage_id = (int *) malloc(sizeof(int) * planes[i].num_baggage);
        planes[i].destinations = (char **) malloc(sizeof(char *) * planes[i].num_baggage);
        for (int j = 0; j < planes[i].num_baggage; j++) {
            planes[i].baggage_id[j] = rand() % NUM_BAGS + 1;
            planes[i].destinations[j] = (char *) malloc(sizeof(char) * 50);
            sprintf(planes[i].destinations[j], "Destination %d", rand() % NUM_DESTINATIONS + 1);
        }
    }
}

void generate_bags(Bag *bags, int num_bags) {
    for (int i = 0; i < num_bags; i++) {
        bags[i].bag_id = i + 1;
        bags[i].destination = (char *) malloc(sizeof(char) * 50);
        sprintf(bags[i].destination, "Destination %d", rand() % NUM_DESTINATIONS + 1);
    }
}

void print_plane(Plane plane) {
    printf("Plane ID: %d\n", plane.plane_id);
    printf("Number of Baggage: %d\n", plane.num_baggage);
    for (int i = 0; i < plane.num_baggage; i++) {
        printf("Baggage ID: %d, Destination: %s\n", plane.baggage_id[i], plane.destinations[i]);
    }
}

void print_bag(Bag bag) {
    printf("Bag ID: %d, Destination: %s\n", bag.bag_id, bag.destination);
}

int main() {
    srand(time(0));

    Plane planes[NUM_PLANES];
    generate_planes(planes, NUM_PLANES);

    Bag bags[NUM_BAGS];
    generate_bags(bags, NUM_BAGS);

    for (int i = 0; i < NUM_PLANES; i++) {
        printf("Plane %d:\n", planes[i].plane_id);
        for (int j = 0; j < planes[i].num_baggage; j++) {
            print_bag(bags[planes[i].baggage_id[j] - 1]);
        }
    }

    return 0;
}