//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

// Structure to represent a car
struct Car {
    int x;
    int y;
    bool direction;
};

// Function to move a car
void moveCar(struct Car* car, int grid[10][10], bool* collision) {
    int dx = car->direction? 1 : -1;
    int dy = car->direction? -1 : 1;

    if (grid[car->x + dx][car->y + dy]!= 0 ||
        car->x < 0 ||
        car->x >= 10 ||
        car->y < 0 ||
        car->y >= 10) {
        *collision = true;
        return;
    }

    grid[car->x + dx][car->y + dy] = 1;
    car->x += dx;
    car->y += dy;
}

// Function to detect collision
bool collisionDetection(struct Car* car1, struct Car* car2, bool* collision) {
    if (car1->x == car2->x && car1->y == car2->y) {
        *collision = true;
        return true;
    }
    return false;
}

// Function to initialize grid
void initGrid(int grid[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to print grid
void printGrid(int grid[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to start the game
void startGame(int grid[10][10], struct Car car1, struct Car car2, bool* collision) {
    while (!collision[0] &&!collision[1]) {
        moveCar(&car1, grid, collision);
        moveCar(&car2, grid, collision);
        if (collisionDetection(&car1, &car2, collision)) {
            printf("Game Over\n");
            break;
        }
        if (car1.x == 5 && car1.y == 5) {
            printf("Player 1 Wins\n");
            break;
        }
        if (car2.x == 5 && car2.y == 5) {
            printf("Player 2 Wins\n");
            break;
        }
    }
    if (collision[0] || collision[1]) {
        printf("Tie\n");
    }
}

int main() {
    int grid[10][10];
    initGrid(grid);

    struct Car car1 = {5, 5, true};
    struct Car car2 = {5, 5, false};
    bool collision[2];
    collision[0] = false;
    collision[1] = false;

    startGame(grid, car1, car2, collision);

    return 0;
}