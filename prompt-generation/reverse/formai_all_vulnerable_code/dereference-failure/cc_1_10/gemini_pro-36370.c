//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Maze data
int maze[MAZE_WIDTH][MAZE_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Player data
typedef struct {
    int x;
    int y;
    int score;
} Player;

// Player array
Player players[4];

// Mutex to protect shared data
pthread_mutex_t mutex;

// Thread function
void *player_thread(void *arg) {
    // Get player index
    int player_index = *(int *)arg;

    // Lock mutex
    pthread_mutex_lock(&mutex);

    // Initialize player
    players[player_index].x = 1;
    players[player_index].y = 1;
    players[player_index].score = 0;

    // Game loop
    while (1) {
        // Get player input
        char input;
        printf("Player %d, enter a move (w, a, s, d): ", player_index + 1);
        scanf(" %c", &input);

        // Move player
        switch (input) {
            case 'w':
                if (maze[players[player_index].x][players[player_index].y - 1] == 0) {
                    players[player_index].y--;
                }
                break;
            case 'a':
                if (maze[players[player_index].x - 1][players[player_index].y] == 0) {
                    players[player_index].x--;
                }
                break;
            case 's':
                if (maze[players[player_index].x][players[player_index].y + 1] == 0) {
                    players[player_index].y++;
                }
                break;
            case 'd':
                if (maze[players[player_index].x + 1][players[player_index].y] == 0) {
                    players[player_index].x++;
                }
                break;
            default:
                printf("Invalid input\n");
                break;
        }

        // Check if player has reached the exit
        if (players[player_index].x == MAZE_WIDTH - 2 && players[player_index].y == MAZE_HEIGHT - 2) {
            printf("Player %d has reached the exit!\n", player_index + 1);
            break;
        }

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        int *player_index = malloc(sizeof(int));
        *player_index = i;
        pthread_create(&threads[i], NULL, player_thread, player_index);
    }

    // Join threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}