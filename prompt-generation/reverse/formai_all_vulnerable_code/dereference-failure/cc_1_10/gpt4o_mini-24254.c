//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LEN 20
#define GRID_SIZE 5

// Function prototypes
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int playerX, int playerY);
void movePlayer(int *playerX, int *playerY, char direction);
void performAction(int playerX, int playerY);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    char playerNames[MAX_PLAYERS][MAX_NAME_LEN];
    int playerPositions[MAX_PLAYERS][2]; // holds player positions (x, y)
    int playerCount, currentPlayer = 0;

    srand(time(0));
    initializeGrid(grid);

    printf("Welcome to the Surrealist Table Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", playerNames[i]);
        playerPositions[i][0] = rand() % GRID_SIZE; // Random x position
        playerPositions[i][1] = rand() % GRID_SIZE; // Random y position
    }

    while (1) {
        displayGrid(grid, playerPositions[currentPlayer][0], playerPositions[currentPlayer][1]);
        
        char direction;
        printf("%s's turn (enter direction: w/a/s/d for up/left/down/right, q to quit): ", playerNames[currentPlayer]);
        scanf(" %c", &direction);

        if (direction == 'q') {
            printf("Thank you for playing!\n");
            break;
        }

        movePlayer(&playerPositions[currentPlayer][0], &playerPositions[currentPlayer][1], direction);
        performAction(playerPositions[currentPlayer][0], playerPositions[currentPlayer][1]);

        currentPlayer = (currentPlayer + 1) % playerCount; // Move to next player
    }

    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int playerX, int playerY) {
    system("clear"); // Clear console before displaying the grid
    grid[playerX][playerY] = 'P'; // Mark player's position

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    grid[playerX][playerY] = '.'; // Reset the player position marker
}

void movePlayer(int *playerX, int *playerY, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (*playerX > 0) (*playerX)--;
            break;
        case 's': // Move down
            if (*playerX < GRID_SIZE - 1) (*playerX)++;
            break;
        case 'a': // Move left
            if (*playerY > 0) (*playerY)--;
            break;
        case 'd': // Move right
            if (*playerY < GRID_SIZE - 1) (*playerY)++;
            break;
        default:
            printf("Invalid move! Use w, a, s, d to move.\n");
    }
}

void performAction(int playerX, int playerY) {
    const char *surrealActions[] = {
        "finds a talking banana singing opera.",
        "encounters a flying fish offering existential advice.",
        "stumbles upon a painting that criticizes reality.",
        "meets a clock that runs backwards and tells time in dreams.",
        "discovers a book that whispers secrets of the universe."
    };

    int actionIndex = rand() % (sizeof(surrealActions) / sizeof(surrealActions[0]));
    printf("You %s\n", surrealActions[actionIndex]);
}