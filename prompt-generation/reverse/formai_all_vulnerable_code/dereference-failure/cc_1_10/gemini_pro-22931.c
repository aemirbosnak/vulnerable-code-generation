//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAR_LENGTH 5
#define CAR_WIDTH 3
#define ROAD_WIDTH 20
#define ROAD_LENGTH 100

struct car {
    int x;
    int y;
    int direction; // 0 for left, 1 for right
};

struct road {
    char **grid;
};

struct remote {
    int throttle;
    int steering;
};

void print_road(struct road *road) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        for (int j = 0; j < ROAD_WIDTH; j++) {
            printf("%c", road->grid[i][j]);
        }
        printf("\n");
    }
}

void print_car(struct car *car, struct road *road) {
    for (int i = 0; i < CAR_LENGTH; i++) {
        for (int j = 0; j < CAR_WIDTH; j++) {
            road->grid[car->y + i][car->x + j] = '#';
        }
    }
}

void move_car(struct car *car, struct remote *remote) {
    if (remote->steering == 0) {
        car->x--;
    } else if (remote->steering == 1) {
        car->x++;
    }
    if (remote->throttle == 1) {
        car->y++;
    }
}

int main() {
    srand(time(NULL));

    struct road road;
    road.grid = (char **) malloc(ROAD_LENGTH * sizeof(char *));
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road.grid[i] = (char *) malloc(ROAD_WIDTH * sizeof(char));
        for (int j = 0; j < ROAD_WIDTH; j++) {
            road.grid[i][j] = ' ';
        }
    }

    struct car car;
    car.x = ROAD_WIDTH / 2;
    car.y = 0;
    car.direction = 0;

    struct remote remote;
    remote.throttle = 0;
    remote.steering = 0;

    while (1) {
        print_road(&road);
        print_car(&car, &road);

        printf("Enter throttle (0 for stop, 1 for go): ");
        scanf("%d", &remote.throttle);

        printf("Enter steering (0 for left, 1 for right): ");
        scanf("%d", &remote.steering);

        move_car(&car, &remote);

        // Check for collisions with the edges of the road
        if (car.x < 0 || car.x >= ROAD_WIDTH || car.y >= ROAD_LENGTH) {
            printf("You crashed! Game over!\n");
            break;
        }
    }

    // Free the memory allocated for the road
    for (int i = 0; i < ROAD_LENGTH; i++) {
        free(road.grid[i]);
    }
    free(road.grid);

    return 0;
}