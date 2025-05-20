//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_LANE 3

typedef struct Car {
    int x, y, speed, direction;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
    time_t t = time(NULL);
    int i, j, k;

    while (head) {
        for (i = 0; i < MAX_LANE; i++) {
            for (j = 0; j < MAX_CARS; j++) {
                if (head->x == i && head->y == j) {
                    switch (head->direction) {
                        case 0:
                            head->x++;
                            break;
                        case 1:
                            head->x--;
                            break;
                        case 2:
                            head->y++;
                            break;
                        case 3:
                            head->y--;
                            break;
                    }
                }
            }
        }

        head = head->next;
    }

    t = time(NULL) - t;
    printf("Time elapsed: %d seconds\n", t);
}

int main() {
    Car* head = NULL;

    // Create some sample cars
    head = malloc(sizeof(Car));
    head->x = 1;
    head->y = 0;
    head->speed = 2;
    head->direction = 0;
    head->next = malloc(sizeof(Car));
    head->next->x = 2;
    head->next->y = 1;
    head->next->speed = 1;
    head->next->direction = 2;
    head->next->next = malloc(sizeof(Car));
    head->next->next->x = 0;
    head->next->next->y = 2;
    head->next->next->speed = 3;
    head->next->next->direction = 3;

    simulateTrafficFlow(head);

    return 0;
}