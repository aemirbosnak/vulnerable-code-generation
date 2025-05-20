//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

typedef struct Car {
    int x, y;
    char direction;
    struct Car* next;
} Car;

Car* create_car() {
    Car* new_car = malloc(sizeof(Car));
    new_car->x = rand() % 1000;
    new_car->y = rand() % 1000;
    new_car->direction = rand() % 4 + 1;
    new_car->next = NULL;
    return new_car;
}

void simulate_traffic(Car* head) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 1:
                    car->x++;
                    break;
                case 2:
                    car->x--;
                    break;
                case 3:
                    car->y++;
                    break;
                case 4:
                    car->y--;
                    break;
            }

            if (car->x > 1000 || car->x < 0) {
                car->direction *= -1;
            }

            if (car->y > 1000 || car->y < 0) {
                car->direction *= -1;
            }
        }

        sleep(1);
    }
}

int main() {
    Car* head = create_car();
    simulate_traffic(head);

    return 0;
}