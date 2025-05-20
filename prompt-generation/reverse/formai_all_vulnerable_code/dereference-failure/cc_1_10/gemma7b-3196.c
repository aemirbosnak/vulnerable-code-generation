//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define ROAD_LENGTH 1000

typedef struct car {
    int x, y, direction, speed;
    struct car* next;
} car;

car* create_car(int x, int y, int direction, int speed) {
    car* new_car = (car*)malloc(sizeof(car));
    new_car->x = x;
    new_car->y = y;
    new_car->direction = direction;
    new_car->speed = speed;
    new_car->next = NULL;
    return new_car;
}

void simulate_traffic(car* cars) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (car* car = cars; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->y++;
                    break;
                case 2:
                    car->x--;
                    break;
                case 3:
                    car->y--;
                    break;
            }

            if (car->x >= ROAD_LENGTH || car->x <= 0) {
                car->direction *= -1;
            }

            if (car->y >= ROAD_LENGTH || car->y <= 0) {
                car->direction *= -1;
            }
        }

        sleep(1);
    }
}

int main() {
    car* cars = create_car(0, 0, 0, 5);
    simulate_traffic(cars);
    return 0;
}