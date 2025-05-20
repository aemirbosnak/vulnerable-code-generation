//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct car {
    int lane;
    int speed;
    int position;
    struct car* next;
} car;

car* create_car(int lane, int speed, int position) {
    car* new_car = (car*)malloc(sizeof(car));
    new_car->lane = lane;
    new_car->speed = speed;
    new_car->position = position;
    new_car->next = NULL;
    return new_car;
}

void simulate_traffic(car* head) {
    time_t start_time = time(NULL);
    time_t current_time = start_time;
    while (current_time - start_time < 10) {
        current_time = time(NULL);
        for (car* car = head; car; car = car->next) {
            switch (car->lane) {
                case 0:
                    car->position++;
                    break;
                case 1:
                    car->position++;
                    break;
                case 2:
                    car->position--;
                    break;
            }
        }

        printf("Time: %ld, Cars: ", current_time - start_time);
        for (car* car = head; car; car = car->next) {
            printf("Lane %d, Position: %d, Speed: %d ", car->lane, car->position, car->speed);
        }
        printf("\n");
    }
}

int main() {
    car* head = create_car(0, 5, 0);
    head = create_car(1, 3, 10);
    head = create_car(2, 2, 20);

    simulate_traffic(head);

    return 0;
}