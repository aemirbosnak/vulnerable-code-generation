//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Our treasure-hunting adventurer
typedef struct {
    int x, y;     // Current position
    int gold;    // Accumulated gold
} Adventurer;

// A dungeon filled with glittering treasures
typedef struct {
    int width, height;
    int **dungeon;    // Array of integer treasures
} Dungeon;

// Initialize our dungeon
Dungeon* init_dungeon(int width, int height) {
    Dungeon *dungeon = malloc(sizeof(Dungeon));
    dungeon->width = width;
    dungeon->height = height;

    // Allocate memory for dungeon cells
    dungeon->dungeon = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++)
        dungeon->dungeon[i] = malloc(width * sizeof(int));

    // Populate the dungeon with treasures
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            dungeon->dungeon[i][j] = rand() % 100;
    }

    return dungeon;
}

// Create a new adventurer
Adventurer* create_adventurer() {
    Adventurer *adventurer = malloc(sizeof(Adventurer));
    adventurer->x = 0;
    adventurer->y = 0;
    adventurer->gold = 0;

    return adventurer;
}

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Our greedy treasure-hunting algorithm
void adventure(Dungeon *dungeon, Adventurer *adventurer) {
    // While there are unexplored cells
    while (adventurer->x < dungeon->width && adventurer->y < dungeon->height) {
        // Get the treasure at the current cell
        int treasure = dungeon->dungeon[adventurer->y][adventurer->x];

        // If there's gold, add it to the adventurer's hoard
        if (treasure > 0) adventurer->gold += treasure;

        // Move to the adjacent cell with the most treasure
        int best_move = -1;
        int max_treasure = 0;
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            int next_x = adventurer->x + directions[i][0];
            int next_y = adventurer->y + directions[i][1];

            // Check if the cell is within bounds and has treasure
            if (next_x >= 0 && next_x < dungeon->width && next_y >= 0 && next_y < dungeon->height) {
                int cell_treasure = dungeon->dungeon[next_y][next_x];
                if (cell_treasure > max_treasure) {
                    max_treasure = cell_treasure;
                    best_move = i;
                }
            }
        }

        // Update adventurer's position
        adventurer->x += directions[best_move][0];
        adventurer->y += directions[best_move][1];
    }
}

// Free the memory allocated for the dungeon
void free_dungeon(Dungeon *dungeon) {
    for (int i = 0; i < dungeon->height; i++)
        free(dungeon->dungeon[i]);
    free(dungeon->dungeon);
    free(dungeon);
}

// Print the adventurer's final gold count
void print_result(Adventurer *adventurer) {
    printf("Treasure collected: %d gold pieces!\n", adventurer->gold);
}

int main() {
    // Create a dungeon
    Dungeon *dungeon = init_dungeon(20, 20);

    // Create an adventurer
    Adventurer *adventurer = create_adventurer();

    // Embark on the adventure
    adventure(dungeon, adventurer);

    // Print the adventurer's final gold count
    print_result(adventurer);

    // Free the memory
    free_dungeon(dungeon);
    free(adventurer);

    return 0;
}