//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 10
#define NUM_COLS 20
#define ROW_SIZE 40
#define COL_SIZE 40

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

typedef struct {
    int x, y;
    char color;
} car;

car *create_car(int x, int y)
{
    car *c = (car *)malloc(sizeof(car));
    c->x = x;
    c->y = y;
    c->color = RED;
    return c;
}

void move_car(car *c, int dx, int dy)
{
    c->x += dx;
    c->y += dy;
}

void draw_car(car *c)
{
    int x = c->x * COL_SIZE + (COL_SIZE / 2);
    int y = c->y * ROW_SIZE + (ROW_SIZE / 2);

    printf("%c[%d;%dH%c", 27, y, x, c->color);
}

void remove_car(car *c)
{
    free(c);
}

int main()
{
    srand(time(NULL));

    int cars_count = rand() % 10 + 1;
    car **cars = (car **)malloc(sizeof(car *) * cars_count);

    for (int i = 0; i < cars_count; i++) {
        int x = rand() % NUM_COLS;
        int y = rand() % NUM_ROWS;
        cars[i] = create_car(x, y);
    }

    int delay = 100;

    while (1) {
        system("clear");

        for (int i = 0; i < cars_count; i++) {
            draw_car(cars[i]);
        }

        for (int i = 0; i < cars_count; i++) {
            move_car(cars[i], rand() % 3 - 1, rand() % 3 - 1);

            if (cars[i]->x < 0 || cars[i]->x >= NUM_COLS || cars[i]->y < 0 || cars[i]->y >= NUM_ROWS) {
                remove_car(cars[i]);
                i--;
            }
        }

        for (int i = 0; i < cars_count; i++) {
            if (cars[i]->x == cars[(i + 1) % cars_count]->x && cars[i]->y == cars[(i + 1) % cars_count]->y) {
                remove_car(cars[i]);
                remove_car(cars[(i + 1) % cars_count]);
                i--;
            }
        }

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}