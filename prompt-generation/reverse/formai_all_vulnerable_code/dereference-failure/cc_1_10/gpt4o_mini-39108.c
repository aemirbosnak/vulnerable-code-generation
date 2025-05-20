//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define GRID_SIZE 10
#define INITIAL_X 0
#define INITIAL_Y 0

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    char grid[GRID_SIZE][GRID_SIZE];
    pthread_mutex_t lock;
} Robot;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void displayGrid(Robot *robot) {
    pthread_mutex_lock(&robot->lock);
    system("clear");
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(i == robot->pos.x && j == robot->pos.y) {
                printf("R ");
            } else {
                printf("%c ", robot->grid[i][j]);
            }
        }
        printf("\n");
    }
    pthread_mutex_unlock(&robot->lock);
}

void moveUp(Robot *robot) {
    pthread_mutex_lock(&robot->lock);
    if(robot->pos.x > 0) {
        robot->pos.x--;
    }
    displayGrid(robot);
    pthread_mutex_unlock(&robot->lock);
}

void moveDown(Robot *robot) {
    pthread_mutex_lock(&robot->lock);
    if(robot->pos.x < GRID_SIZE - 1) {
        robot->pos.x++;
    }
    displayGrid(robot);
    pthread_mutex_unlock(&robot->lock);
}

void moveLeft(Robot *robot) {
    pthread_mutex_lock(&robot->lock);
    if(robot->pos.y > 0) {
        robot->pos.y--;
    }
    displayGrid(robot);
    pthread_mutex_unlock(&robot->lock);
}

void moveRight(Robot *robot) {
    pthread_mutex_lock(&robot->lock);
    if(robot->pos.y < GRID_SIZE - 1) {
        robot->pos.y++;
    }
    displayGrid(robot);
    pthread_mutex_unlock(&robot->lock);
}

void *controlRobot(void *arg) {
    Robot *robot = (Robot *)arg;
    char command;

    while(1) {
        printf("Enter command (w: up, s: down, a: left, d: right, q: quit): ");
        command = getchar();
        getchar(); // Consume the newline character

        switch(command) {
            case 'w': moveUp(robot); break;
            case 's': moveDown(robot); break;
            case 'a': moveLeft(robot); break;
            case 'd': moveRight(robot); break;
            case 'q':
                printf("Quitting...\n");
                pthread_exit(NULL);
                break;
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
    }
}

int main() {
    Robot *robot = malloc(sizeof(Robot));
    robot->pos.x = INITIAL_X;
    robot->pos.y = INITIAL_Y;
    initializeGrid(robot->grid);
    pthread_mutex_init(&robot->lock, NULL);

    displayGrid(robot);

    pthread_t controlThread;
    if(pthread_create(&controlThread, NULL, controlRobot, robot) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        free(robot);
        return 1;
    }

    pthread_join(controlThread, NULL);

    pthread_mutex_destroy(&robot->lock);
    free(robot);
    return 0;
}