//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct Bag {
    char* name;
    int weight;
    int status;
} Bag;

void print_bag(Bag bag) {
    printf("Name: %s\n", bag.name);
    printf("Weight: %d\n", bag.weight);
    printf("Status: %d\n", bag.status);
}

void process_bag(Bag* bags, int num_bags, int weight_limit, int min_size) {
    for (int i = 0; i < num_bags; i++) {
        if (bags[i].weight <= weight_limit && bags[i].weight >= min_size) {
            bags[i].status = 1; // Bag is accepted
            printf("Bag %d: Accepted\n", i + 1);
        } else {
            bags[i].status = 0; // Bag is rejected
            printf("Bag %d: Rejected\n", i + 1);
        }
    }
}

int main() {
    int num_bags = 5; // Number of bags in the system
    int weight_limit = 50; // Maximum weight limit for a bag
    int min_size = 20; // Minimum size for a bag

    Bag* bags = (Bag*) malloc(num_bags * sizeof(Bag));

    for (int i = 0; i < num_bags; i++) {
        char name[100];
        int weight;
        scanf("%s %d", name, &weight);
        bags[i].name = name;
        bags[i].weight = weight;
        bags[i].status = 0; // Bag is rejected by default
    }

    print_bag(bags[0]);
    print_bag(bags[1]);
    print_bag(bags[2]);
    print_bag(bags[3]);
    print_bag(bags[4]);

    process_bag(bags, num_bags, weight_limit, min_size);

    for (int i = 0; i < num_bags; i++) {
        print_bag(bags[i]);
    }

    free(bags);

    return 0;
}