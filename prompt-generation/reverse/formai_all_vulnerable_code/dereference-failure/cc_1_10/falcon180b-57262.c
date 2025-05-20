//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CAROUSELS 5
#define TIME_DELAY 2

struct Bag {
    int carousel;
    int destination;
    int time_left;
};

void print_bag(struct Bag bag) {
    printf("Carousel %d, Destination %d, Time Left %d\n", bag.carousel, bag.destination, bag.time_left);
}

void move_bag(struct Bag *bag, int carousel_index) {
    bag->carousel = carousel_index;
    bag->time_left -= TIME_DELAY;
}

int main() {
    srand(time(NULL));

    struct Bag *bags = malloc(NUM_BAGS * sizeof(struct Bag));
    int *carousel_indices = malloc(NUM_BAGS * sizeof(int));

    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].carousel = rand() % NUM_CAROUSELS;
        bags[i].destination = rand() % NUM_CAROUSELS;
        bags[i].time_left = rand() % 30 + 10;
        carousel_indices[i] = bags[i].carousel;
    }

    int current_carousel = 0;

    while (1) {
        printf("Current carousel: %d\n", current_carousel);

        for (int i = 0; i < NUM_BAGS; i++) {
            if (bags[i].carousel == current_carousel && bags[i].time_left > 0) {
                print_bag(bags[i]);
                bags[i].time_left--;
            }
        }

        int next_carousel = (current_carousel + 1) % NUM_CAROUSELS;

        for (int i = 0; i < NUM_BAGS; i++) {
            if (carousel_indices[i] == current_carousel && bags[i].time_left == 0) {
                move_bag(&bags[i], next_carousel);
            }
        }

        current_carousel = next_carousel;

        usleep(100000);
    }

    free(bags);
    free(carousel_indices);

    return 0;
}