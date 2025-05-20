//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX_VEHICLES 100
#define MAX_ROADS 10
#define MAX_CARS_PER_ROAD 20
#define MAX_SIMULATION_TIME 100

typedef enum {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
} Direction;

typedef struct {
    int x;
    int y;
    Direction direction;
} Car;

typedef struct {
    Car* cars[MAX_CARS_PER_ROAD];
    int car_count;
} Road;

typedef struct {
    Road roads[MAX_ROADS];
    int road_count;
} Map;

void init_map(Map* map);
void print_map(Map* map);
void move_car(Map* map, int road_index, int car_index);
void simulate_traffic(Map* map);

int main() {
    Map map;
    srand(time(NULL));
    init_map(&map);
    print_map(&map);
    simulate_traffic(&map);
    return 0;
}

void init_map(Map* map) {
    map->road_count = MAX_ROADS;
    for (int i = 0; i < MAX_ROADS; i++) {
        map->roads[i].car_count = (rand() % MAX_CARS_PER_ROAD) + 1;
        for (int j = 0; j < map->roads[i].car_count; j++) {
            Car* car = (Car*)malloc(sizeof(Car));
            car->x = j;
            car->y = i;
            car->direction = rand() % 4;
            map->roads[i].cars[j] = car;
        }
    }
}

void print_map(Map* map) {
    for (int i = 0; i < MAX_ROADS; i++) {
        for (int j = 0; j < map->roads[i].car_count; j++) {
            printf("(%d,%d,%d)", map->roads[i].cars[j]->x, map->roads[i].cars[j]->y, map->roads[i].cars[j]->direction);
        }
        printf("\n");
    }
}

void move_car(Map* map, int road_index, int car_index) {
    Car* car = map->roads[road_index].cars[car_index];
    switch (car->direction) {
        case NORTH:
            car->y--;
            break;
        case EAST:
            car->x++;
            break;
        case SOUTH:
            car->y++;
            break;
        case WEST:
            car->x--;
            break;
    }
    if (car->x >= MAX_CARS_PER_ROAD) {
        map->roads[road_index].car_count--;
        free(map->roads[road_index].cars[car_index]);
        for (int i = car_index; i < map->roads[road_index].car_count; i++) {
            map->roads[road_index].cars[i] = map->roads[road_index].cars[i + 1];
        }
    }
}

void simulate_traffic(Map* map) {
    for (int i = 0; i < MAX_SIMULATION_TIME; i++) {
        for (int j = 0; j < MAX_ROADS; j++) {
            for (int k = 0; k < map->roads[j].car_count; k++) {
                move_car(map, j, k);
            }
        }
        print_map(map);
    }
}