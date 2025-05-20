//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SIZE 5 // Size of the game board
#define SHM_KEY 1234 // Shared memory key

// Structures
typedef struct message {
    char type;
    int data1;
    int data2;
} Message;

typedef struct player {
    int id;
    char symbol;
    int score;
} Player;

// Global variables
Player *players;
char **board;
int turn;
int shmid;

// Function prototypes
void *playerTask(void *arg);
void printBoard();
int checkWin(char symbol);
void sendMessage(int player, int type, int data1, int data2);

int main() {
    int i;
    pthread_t threadID[SIZE]; // Array of thread IDs
    pthread_attr_t attr;
    
    // Allocate shared memory for players
    shmid = shmget(SHM_KEY, SIZE * sizeof(Player), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    players = shmat(shmid, NULL, 0);
    if (players == (Player*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    memset(players, 0, SIZE * sizeof(Player));

    // Allocate memory for game board
    board = (char**) malloc(SIZE * sizeof(char*));
    for (i = 0; i < SIZE; i++) {
        board[i] = (char*) malloc(SIZE * sizeof(char));
        memset(board[i], ' ', SIZE * sizeof(char));
    }

    // Initialize variables
    turn = 0;

    // Set thread attributes
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Create player threads
    for (i = 0; i < SIZE; i++) {
        players[i].id = i;
        players[i].symbol = i == 0 ? 'X' : 'O';
        players[i].score = 0;
        pthread_create(&threadID[i], &attr, playerTask, (void*) &players[i]);
    }

    // Wait for all player threads to finish
    for (i = 0; i < SIZE; i++) {
        pthread_join(threadID[i], NULL);
    }

    // Detach and deallocate shared memory
    shmdt(players);
    shmctl(shmid, IPC_RMID, NULL);

    // Free memory allocated for game board
    for (i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

void *playerTask(void *arg) {
    Player *player = (Player*) arg;
    int win = 0;
    int x, y;
    Message msg;

    printf("Player %d (%c) has joined the game!\n", player->id + 1, player->symbol);

    while (!win) {
        // Wait for turn
        while (turn != player->id) {
            usleep(1000);
        }

        // Print game board and player info
        printf("Player %d's turn\n", player->id + 1);
        printf("Score: %d\n", player->score);
        printBoard();

        // Prompt player to make move
        printf("Enter cell coordinates (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if move is valid
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Make move
        board[x][y] = player->symbol;

        // Check for win condition
        if (checkWin(player->symbol)) {
            player->score++;
            printf("Player %d wins!\n", player->id + 1);
            win = 1;
        }

        // Send message to next player
        turn = (turn + 1) % SIZE;
        msg.type = 'm';
        msg.data1 = x;
        msg.data2 = y;
        sendMessage(turn, msg.type, msg.data1, msg.data2);
    }

    printf("Player %d (%c) is now leaving the game.\n", player->id + 1, player->symbol);

    pthread_exit(NULL);
}

void printBoard() {
    int i, j;

    printf("   ");
    for (i = 0; i < SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf(" %d ", i);
        for (j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char symbol) {
    int i, j;
    int row, col, diag1, diag2;

    // Check rows
    for (i = 0; i < SIZE; i++) {
        row = 1;
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != symbol) {
                row = 0;
                break;
            }
        }
        if (row) return 1;
    }

    // Check columns
    for (j = 0; j < SIZE; j++) {
        col = 1;
        for (i = 0; i < SIZE; i++) {
            if (board[i][j] != symbol) {
                col = 0;
                break;
            }
        }
        if (col) return 1;
    }

    // Check diagonals
    diag1 = 1;
    diag2 = 1;
    for (i = 0; i < SIZE; i++) {
        if (board[i][i] != symbol) {
            diag1 = 0;
        }
        if (board[i][SIZE - i - 1] != symbol) {
            diag2 = 0;
        }
    }
    if (diag1 || diag2) return 1;

    return 0;
}

void sendMessage(int player, int type, int data1, int data2) {
    Message *buffer;

    // Allocate shared memory for message
    shmid = shmget(SHM_KEY + player + 1, sizeof(Message), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    buffer = shmat(shmid, NULL, 0);
    if (buffer == (Message*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Send message
    buffer->type = type;
    buffer->data1 = data1;
    buffer->data2 = data2;

    // Deallocate shared memory for message
    shmdt(buffer);
    shmctl(shmid, IPC_RMID, NULL);
}