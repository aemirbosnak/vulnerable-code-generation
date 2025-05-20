//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_BAGS 100
#define NUM_DESTINATIONS 10
#define BAG_SIZE 50

typedef struct {
    int destination;
    int weight;
} Bag;

Bag bags[NUM_BAGS];
char destinations[NUM_DESTINATIONS][20];
int num_destinations;
int max_bag_weight;

void generate_destinations() {
    FILE *f;
    char line[100];
    int i = 0;

    f = fopen("destinations.txt", "r");

    if (f == NULL) {
        printf("Error: could not open destinations file.\n");
        exit(1);
    }

    while (fgets(line, 100, f)!= NULL) {
        strcpy(destinations[i], line);
        i++;
    }

    num_destinations = i;

    fclose(f);
}

void generate_bags() {
    int i;

    for (i = 0; i < NUM_BAGS; i++) {
        bags[i].destination = rand() % num_destinations;
        bags[i].weight = rand() % (BAG_SIZE + 1);
    }
}

int compare_weights(const void *a, const void *b) {
    Bag *bag_a = (Bag *) a;
    Bag *bag_b = (Bag *) b;

    if (bag_a->weight > bag_b->weight) {
        return 1;
    } else if (bag_a->weight < bag_b->weight) {
        return -1;
    } else {
        return 0;
    }
}

void sort_bags() {
    qsort(bags, NUM_BAGS, sizeof(Bag), compare_weights);
}

void print_bags() {
    int i;

    for (i = 0; i < NUM_BAGS; i++) {
        printf("Bag %d: Destination %d, Weight %d\n", i + 1, bags[i].destination, bags[i].weight);
    }
}

int main() {
    srand(time(NULL));

    generate_destinations();
    generate_bags();
    sort_bags();

    printf("Sorted bags:\n");
    print_bags();

    return 0;
}