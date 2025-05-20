//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_CARRIERS 10
#define MAX_DELAY 120

typedef struct {
    int bag_id;
    char airline[10];
    char destination[10];
    int delay;
} Bag;

typedef struct {
    int carrier_id;
    char airline[10];
    int bags[MAX_BAGS];
    int num_bags;
} Carrier;

void print_bags(Bag bags[], int num_bags) {
    for (int i = 0; i < num_bags; i++) {
        printf("%d - %s - %s - %d\n", bags[i].bag_id, bags[i].airline, bags[i].destination, bags[i].delay);
    }
}

void print_carriers(Carrier carriers[], int num_carriers) {
    for (int i = 0; i < num_carriers; i++) {
        printf("Carrier %d: %s - ", carriers[i].carrier_id, carriers[i].airline);
        for (int j = 0; j < carriers[i].num_bags; j++) {
            printf("%d ", carriers[i].bags[j]);
        }
        printf("\n");
    }
}

void add_bag(Bag bags[], int num_bags, int bag_id, char airline[], char destination[], int delay) {
    for (int i = 0; i < num_bags; i++) {
        if (bags[i].bag_id == bag_id) {
            bags[i].delay = delay;
            return;
        }
    }
    bags[num_bags].bag_id = bag_id;
    strcpy(bags[num_bags].airline, airline);
    strcpy(bags[num_bags].destination, destination);
    bags[num_bags].delay = delay;
    num_bags++;
}

void add_carrier(Carrier carriers[], int num_carriers, int carrier_id, char airline[], int bags[], int num_bags) {
    for (int i = 0; i < num_carriers; i++) {
        if (carriers[i].carrier_id == carrier_id) {
            for (int j = 0; j < num_bags; j++) {
                carriers[i].bags[j] = bags[j];
            }
            carriers[i].num_bags = num_bags;
            return;
        }
    }
    carriers[num_carriers].carrier_id = carrier_id;
    strcpy(carriers[num_carriers].airline, airline);
    for (int j = 0; j < num_bags; j++) {
        carriers[num_carriers].bags[j] = bags[j];
    }
    carriers[num_carriers].num_bags = num_bags;
    num_carriers++;
}

int main() {
    srand(time(0));

    Bag bags[MAX_BAGS];
    Carrier carriers[MAX_CARRIERS];

    int num_bags = 0;
    int num_carriers = 0;

    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);
    printf("Enter the number of carriers: ");
    scanf("%d", &num_carriers);

    for (int i = 0; i < num_bags; i++) {
        printf("Enter the bag ID: ");
        scanf("%d", &bags[i].bag_id);
        printf("Enter the airline: ");
        scanf("%s", bags[i].airline);
        printf("Enter the destination: ");
        scanf("%s", bags[i].destination);
        printf("Enter the delay: ");
        scanf("%d", &bags[i].delay);
        add_bag(bags, num_bags, bags[i].bag_id, bags[i].airline, bags[i].destination, bags[i].delay);
    }

    for (int i = 0; i < num_carriers; i++) {
        printf("Enter the carrier ID: ");
        scanf("%d", &carriers[i].carrier_id);
        printf("Enter the airline: ");
        scanf("%s", carriers[i].airline);
        printf("Enter the bag IDs: ");
        for (int j = 0; j < MAX_BAGS; j++) {
            scanf("%d", &carriers[i].bags[j]);
        }
        add_carrier(carriers, num_carriers, carriers[i].carrier_id, carriers[i].airline, carriers[i].bags, MAX_BAGS);
    }

    printf("Baggage Handling Simulation\n");
    printf("Total number of bags: %d\n", num_bags);
    printf("Total number of carriers: %d\n", num_carriers);

    srand(time(0));

    int bag_id = rand() % num_bags;
    int carrier_id = rand() % num_carriers;
    char airline[10];
    char destination[10];

    printf("Bag %d will be loaded onto carrier %d\n", bag_id, carrier_id);
    printf("Loading bag %d onto carrier %d\n", bag_id, carrier_id);

    printf("Enter the airline: ");
    scanf("%s", airline);
    strcpy(destination, airline);

    add_bag(bags, num_bags, bag_id, airline, destination, 0);
    add_carrier(carriers, num_carriers, carrier_id, airline, bags, num_bags);

    print_bags(bags, num_bags);
    print_carriers(carriers, num_carriers);

    return 0;
}