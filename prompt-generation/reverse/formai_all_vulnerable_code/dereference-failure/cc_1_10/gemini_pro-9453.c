//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct car {
    int x, y;
    int speed;
    int direction;
} car;

typedef struct road {
    int length;
    int width;
    int cars;
    car* car_array;
} road;

void create_road(road* r, int length, int width) {
    r->length = length;
    r->width = width;
    r->cars = 0;
    r->car_array = malloc(sizeof(car) * length * width);
}

void destroy_road(road* r) {
    free(r->car_array);
}

void add_car(road* r, int x, int y, int speed, int direction) {
    r->car_array[r->cars].x = x;
    r->car_array[r->cars].y = y;
    r->car_array[r->cars].speed = speed;
    r->car_array[r->cars].direction = direction;
    r->cars++;
}

void move_cars(road* r) {
    for (int i = 0; i < r->cars; i++) {
        car* c = &r->car_array[i];
        c->x += c->speed * c->direction;
        if (c->x < 0 || c->x > r->length) {
            c->x = -c->x;
            c->direction = -c->direction;
        }
        if (c->y < 0 || c->y > r->width) {
            c->y = -c->y;
            c->direction = -c->direction;
        }
    }
}

void draw_road(road* r) {
    for (int i = 0; i < r->length; i++) {
        for (int j = 0; j < r->width; j++) {
            int car_found = 0;
            for (int k = 0; k < r->cars; k++) {
                car* c = &r->car_array[k];
                if (c->x == i && c->y == j) {
                    printf("O");
                    car_found = 1;
                    break;
                }
            }
            if (!car_found) {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    road r;
    create_road(&r, 100, 100);

    for (int i = 0; i < 100; i++) {
        int x = rand() % r.length;
        int y = rand() % r.width;
        int speed = rand() % 5 + 1;
        int direction = rand() % 2 * 2 - 1;
        add_car(&r, x, y, speed, direction);
    }

    draw_road(&r);

    while (1) {
        move_cars(&r);
        draw_road(&r);
    }

    destroy_road(&r);

    return 0;
}