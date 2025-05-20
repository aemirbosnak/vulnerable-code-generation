//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of players
#define MAX_PLAYERS 10

// Define the structure of a player
typedef struct {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double debt;
} player;

// Define the structure of the game
typedef struct {
    int num_players;
    player players[MAX_PLAYERS];
    int current_player;
} game;

// Create a new game
game* new_game() {
    game* g = malloc(sizeof(game));
    g->num_players = 0;
    g->current_player = 0;
    return g;
}

// Add a player to the game
void add_player(game* g, player* p) {
    g->players[g->num_players] = *p;
    g->num_players++;
}

// Get the current player
player* get_current_player(game* g) {
    return &g->players[g->current_player];
}

// Move to the next player
void next_player(game* g) {
    g->current_player++;
    if (g->current_player >= g->num_players) {
        g->current_player = 0;
    }
}

// Print the game state
void print_game_state(game* g) {
    for (int i = 0; i < g->num_players; i++) {
        player* p = &g->players[i];
        printf("%s: $%.2f income, $%.2f expenses, $%.2f savings, $%.2f debt\n",
               p->name, p->income, p->expenses, p->savings, p->debt);
    }
}

// Play the game
void play_game(game* g) {
    while (1) {
        // Get the current player
        player* p = get_current_player(g);

        // Print the game state
        print_game_state(g);

        // Get the player's input
        printf("%s, what would you like to do?\n", p->name);
        printf("1. Earn income\n");
        printf("2. Pay expenses\n");
        printf("3. Save money\n");
        printf("4. Pay down debt\n");
        printf("5. Quit\n");
        int choice;
        scanf("%d", &choice);

        // Process the player's input
        switch (choice) {
            case 1:
                // Earn income
                printf("How much income did you earn?\n");
                double income;
                scanf("%lf", &income);
                p->income += income;
                break;
            case 2:
                // Pay expenses
                printf("How much did you spend on expenses?\n");
                double expenses;
                scanf("%lf", &expenses);
                p->expenses += expenses;
                break;
            case 3:
                // Save money
                printf("How much money did you save?\n");
                double savings;
                scanf("%lf", &savings);
                p->savings += savings;
                break;
            case 4:
                // Pay down debt
                printf("How much debt did you pay down?\n");
                double debt;
                scanf("%lf", &debt);
                p->debt -= debt;
                break;
            case 5:
                // Quit
                return;
        }

        // Move to the next player
        next_player(g);
    }
}

// Main function
int main() {
    // Create a new game
    game* g = new_game();

    // Add some players to the game
    player p1 = {"Alice", 25, 50000, 30000, 20000, 10000};
    add_player(g, &p1);
    player p2 = {"Bob", 30, 60000, 40000, 30000, 5000};
    add_player(g, &p2);
    player p3 = {"Carol", 35, 70000, 50000, 40000, 0};
    add_player(g, &p3);

    // Play the game
    play_game(g);

    return 0;
}