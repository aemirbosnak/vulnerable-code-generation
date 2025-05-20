//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define NUM_BAGS 10
#define AIRCRAFT_CAPACITY 5
#define CAROUSEL_CAPACITY 10

int bags[NUM_BAGS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int aircraft[AIRCRAFT_CAPACITY] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int carousel[CAROUSEL_CAPACITY] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void move_to_aircraft(int bag_num, int *aircraft) {
    int i;
    printf("Moving %d to aircraft\n", bag_num);
    for (i = 0; i < AIRCRAFT_CAPACITY; i++) {
        if (aircraft[i] == 0) {
            aircraft[i] = bag_num;
            printf("Bag %d moved to aircraft\n", bag_num);
            return;
        }
    }
    printf("Aircraft is full\n");
}

void move_to_carousel(int bag_num, int *carousel) {
    int i;
    printf("Moving %d to carousel\n", bag_num);
    for (i = 0; i < CAROUSEL_CAPACITY; i++) {
        if (carousel[i] == 0) {
            carousel[i] = bag_num;
            printf("Bag %d moved to carousel\n", bag_num);
            return;
        }
    }
    printf("Carousel is full\n");
}

void print_carousel(int *carousel) {
    int i;
    printf("Carousel:\n");
    for (i = 0; i < CAROUSEL_CAPACITY; i++) {
        printf("%d ", carousel[i]);
    }
    printf("\n");
}

void move_to_airport(int bag_num, int *aircraft, int *carousel) {
    int i;
    printf("Moving %d to airport\n", bag_num);
    for (i = 0; i < AIRCRAFT_CAPACITY; i++) {
        if (aircraft[i] == bag_num) {
            aircraft[i] = 0;
            printf("Bag %d moved from aircraft to carousel\n", bag_num);
            move_to_carousel(bag_num, carousel);
            return;
        }
    }
    printf("Aircraft is empty\n");
}

int main() {
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        bags[i] = i + 1;
        printf("Bag %d added to airport\n", bags[i]);
    }
    printf("Initial state:\n");
    print_carousel(aircraft);
    print_carousel(carousel);
    for (i = 0; i < NUM_BAGS; i++) {
        move_to_aircraft(bags[i], aircraft);
    }
    printf("\n");
    print_carousel(aircraft);
    print_carousel(carousel);
    for (i = 0; i < NUM_BAGS; i++) {
        move_to_carousel(bags[i], carousel);
    }
    printf("\n");
    print_carousel(aircraft);
    print_carousel(carousel);
    for (i = 0; i < NUM_BAGS; i++) {
        move_to_airport(bags[i], aircraft, carousel);
    }
    printf("\n");
    print_carousel(aircraft);
    print_carousel(carousel);
    printf("%d bags moved to carousel\n", bags[0]);
    return 0;
}