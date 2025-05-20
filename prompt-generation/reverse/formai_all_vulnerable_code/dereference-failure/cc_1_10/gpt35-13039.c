//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <time.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 20

// Global variables
int player_counter = 0; // Total players connected
int player_turn = 0; // Player turn
sem_t *sem; // Semaphore for synchronizing turns
char *map; // Shared memory pointer for game board 

// Player struct
typedef struct {
    int id;
    int row;
    int col;
    bool is_alive;
} Player;

Player players[MAX_PLAYERS];

// Function to initialize game board
void initialize_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(i == 0 || j == 0 || i == BOARD_SIZE-1 || j == BOARD_SIZE-1)
                *(map + i*BOARD_SIZE + j) = '#';
            else
                *(map + i*BOARD_SIZE + j) = ' ';
        }
    }
}

// Function to print game map
void print_map() {
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", *(map + i*BOARD_SIZE + j));
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a move is valid
bool is_valid_move(int row, int col) {
    if(*(map + row*BOARD_SIZE + col) == ' ')
        return true;
    else
        return false;
}

// Function to update player's position on the game board
void update_player_position(int player_id, int new_row, int new_col) {
    *(map + players[player_id].row*BOARD_SIZE + players[player_id].col) = ' ';
    *(map + new_row*BOARD_SIZE + new_col) = player_id + '0';
    players[player_id].row = new_row;
    players[player_id].col = new_col;
}

// Function to handle player's turn
void handle_turn(int player_id) {
    int steps;
    bool valid_input = false;
    while(!valid_input) {
        printf("\nPlayer %d: Enter number of steps to move (1-3 only): ", player_id);
        scanf("%d", &steps);
        if(steps >= 1 && steps <= 3)
            valid_input = true;
        else
            printf("Invalid input. Please enter a number from 1-3 only.\n");
    }

    // Move player
    int new_row, new_col;
    bool valid_move = false;
    while(!valid_move) {
        // Generate random direction
        int direction = rand() % 4;
        if(direction == 0) { // Move up
            new_row = players[player_id].row - steps;
            new_col = players[player_id].col;
        } else if(direction == 1) { // Move down
            new_row = players[player_id].row + steps;
            new_col = players[player_id].col;
        } else if(direction == 2) { // Move left
            new_row = players[player_id].row;
            new_col = players[player_id].col - steps;
        } else { // Move right
            new_row = players[player_id].row;
            new_col = players[player_id].col + steps;
        }
        if(is_valid_move(new_row, new_col))
            valid_move = true;
    }

    // Update player position
    update_player_position(player_id, new_row, new_col);
    printf("Player %d moved to (%d,%d)\n", player_id, new_row, new_col);
}

// Function for each player thread
void *player_thread_function(void *arg) {
    // Player initialization
    int player_id = *(int *)arg;
    players[player_id].id = player_id;
    players[player_id].row = player_id + 1;
    players[player_id].col = player_id + 1;
    players[player_id].is_alive = true;

    // Wait for all players to connect
    while(player_counter < MAX_PLAYERS)
        usleep(1000);

    // Game loop
    while(1) {
        sem_wait(sem); // Acquire semaphore
        if(players[player_id].is_alive) { // Check if player is still alive
            if(player_id == player_turn) { // Check if it's player's turn
                printf("\nPlayer %d's turn\n", player_id);
                handle_turn(player_id);
                // Check if player reached other side of the board
                if(player_id == 0 && players[player_id].row == BOARD_SIZE-2) {
                    printf("\nPlayer %d has reached the other side of the board and is the winner!!!\n", player_id);
                    exit(0);
                }
                // Update player turn
                player_turn = (player_turn + 1) % MAX_PLAYERS;
            }
        }
        sem_post(sem); // Release semaphore
        usleep(1000); // Allow other players to perform their turns
    }   
}

int main() {
    // Initialize shared memory and semaphore
    int fd = shm_open("/shm", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, BOARD_SIZE*BOARD_SIZE);
    map = (char *) mmap(NULL, BOARD_SIZE*BOARD_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    sem = sem_open("/sem", O_CREAT | O_RDWR, 0666, 1);

    // Initialize game board
    initialize_board();

    // Create player threads
    pthread_t players_thread[MAX_PLAYERS];
    int player_ids[MAX_PLAYERS];
    for(int i = 0; i < MAX_PLAYERS; i++) {
        player_ids[i] = i;
        pthread_create(&players_thread[i], NULL, player_thread_function, &player_ids[i]);
        player_counter++;
    }

    // Wait for players to finish
    for(int i = 0; i < MAX_PLAYERS; i++)
        pthread_join(players_thread[i], NULL);

    return 0;
}