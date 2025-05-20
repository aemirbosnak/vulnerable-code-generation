//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_LANES 3
#define MAX_SPEED 100
#define MAX_DIST 1000
#define CAR_DENSITY 100
#define TIME_STEP 1

typedef struct car {
    int speed;
    int position;
} Car;

Car **init_traffic_map(int lanes, int length) {
    Car **map = malloc(lanes * sizeof(Car *));
    for (int i = 0; i < lanes; ++i) {
        map[i] = malloc(length * sizeof(Car));
        for (int j = 0; j < length; ++j) {
            map[i][j].speed = 0;
            map[i][j].position = 0;
        }
    }
    return map;
}

void print_traffic_map(Car **map, int lanes, int length) {
    for (int i = 0; i < lanes; ++i) {
        for (int j = 0; j < length; ++j) {
            if (map[i][j].speed > 0) {
                printf("     %d       ", map[i][j].speed);
            } else {
                printf("              ");
            }
        }
        printf("\n");
        for (int j = 0; j < length; ++j) {
            printf("[");
            for (int k = 0; k < 5; ++k) {
                if (j == map[i][j].position && k == 2) {
                    printf("@");
                } else {
                    printf("-");
                }
            }
            printf("]");
        }
        printf("\n");
    }
    printf("\n");
}

void clear_traffic_map(Car **map, int lanes, int length) {
    for (int i = 0; i < lanes; ++i) {
        for (int j = 0; j < length; ++j) {
            map[i][j].speed = 0;
            map[i][j].position = 0;
        }
    }
}

void generate_traffic(Car **map, int lanes, int length) {
    int max_cars = lanes * length * CAR_DENSITY / 100;
    int car_count = 0;
    while (car_count < max_cars) {
        int lane = rand() % lanes;
        int pos = rand() % length;
        if (map[lane][pos].speed == 0) {
            map[lane][pos].speed = rand() % MAX_SPEED + 1;
            map[lane][pos].position = pos;
            ++car_count;
        }
    }
}

void move_car(Car **map, int lanes, int length, int lane, int pos) {
    int speed = map[lane][pos].speed;
    int dist = 0;
    while (dist < speed) {
        ++dist;
        int new_pos = (pos + dist) % length;
        if (map[lane][new_pos].speed > 0) {
            break;
        }
    }
    int new_speed = dist;
    if (new_speed < speed) {
        new_speed = new_speed + 1;
    }
    if (new_speed > MAX_SPEED) {
        new_speed = MAX_SPEED;
    }
    map[lane][pos].speed = new_speed;
    if (new_speed == 0) {
        map[lane][pos].position = -1;
        return;
    }
    int new_pos = (pos + new_speed) % length;
    map[lane][new_pos].speed = new_speed;
    map[lane][new_pos].position = new_pos;
}

void handle_lanes(Car **map, int lanes, int length) {
    for (int i = 0; i < lanes; ++i) {
        for (int j = 0; j < length; ++j) {
            if (map[i][j].speed > 0) {
                move_car(map, lanes, length, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int length = MAX_DIST;
    int lanes = TOTAL_LANES;
    Car **traffic_map = init_traffic_map(lanes, length);
    generate_traffic(traffic_map, lanes, length);

    int time = 0;
    while (time < 100) {
        clear_traffic_map(traffic_map, lanes, length);
        handle_lanes(traffic_map, lanes, length);
        print_traffic_map(traffic_map, lanes, length);
        ++time;
    }

    free(traffic_map);
    return 0;
}