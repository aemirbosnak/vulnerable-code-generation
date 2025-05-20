//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} coordinate;

typedef struct {
    char name[20];
    int age;
    coordinate position;
} player;

typedef struct {
    int width;
    int height;
    char **grid;
} table;

void print_table(table *table) {
    for (int i = 0; i < table->height; i++) {
        for (int j = 0; j < table->width; j++) {
            printf("%c", table->grid[i][j]);
        }
        printf("\n");
    }
}

void move_player(player *player, int dx, int dy) {
    player->position.x += dx;
    player->position.y += dy;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the table
    table table = {
        .width = 10,
        .height = 10,
        .grid = (char **)malloc(sizeof(char *) * table.height)
    };

    for (int i = 0; i < table.height; i++) {
        table.grid[i] = (char *)malloc(sizeof(char) * table.width);
    }

    // Initialize the table with spaces
    for (int i = 0; i < table.height; i++) {
        for (int j = 0; j < table.width; j++) {
            table.grid[i][j] = ' ';
        }
    }

    // Create the players
    player player1 = {
        .name = "Player 1",
        .age = 20,
        .position = {
            .x = 0,
            .y = 0
        }
    };

    player player2 = {
        .name = "Player 2",
        .age = 21,
        .position = {
            .x = table.width - 1,
            .y = table.height - 1
        }
    };

    // Place the players on the table
    table.grid[player1.position.y][player1.position.x] = '1';
    table.grid[player2.position.y][player2.position.x] = '2';

    // Print the table
    print_table(&table);

    // Main game loop
    while (1) {
        // Get the input from the players
        char input1[20];
        char input2[20];

        printf("Player 1: ");
        scanf("%s", input1);

        printf("Player 2: ");
        scanf("%s", input2);

        // Move the players
        if (strcmp(input1, "w") == 0) {
            move_player(&player1, 0, -1);
        } else if (strcmp(input1, "s") == 0) {
            move_player(&player1, 0, 1);
        } else if (strcmp(input1, "a") == 0) {
            move_player(&player1, -1, 0);
        } else if (strcmp(input1, "d") == 0) {
            move_player(&player1, 1, 0);
        }

        if (strcmp(input2, "w") == 0) {
            move_player(&player2, 0, -1);
        } else if (strcmp(input2, "s") == 0) {
            move_player(&player2, 0, 1);
        } else if (strcmp(input2, "a") == 0) {
            move_player(&player2, -1, 0);
        } else if (strcmp(input2, "d") == 0) {
            move_player(&player2, 1, 0);
        }

        // Check for collisions
        if (player1.position.x == player2.position.x && player1.position.y == player2.position.y) {
            printf("Collision!\n");
            break;
        }

        // Update the table
        table.grid[player1.position.y][player1.position.x] = '1';
        table.grid[player2.position.y][player2.position.x] = '2';

        // Print the table
        print_table(&table);
    }

    // Free the memory allocated for the table
    for (int i = 0; i < table.height; i++) {
        free(table.grid[i]);
    }
    free(table.grid);

    return 0;
}