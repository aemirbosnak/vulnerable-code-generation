//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10
#define NUM_MONSTERS 5
#define NUM_ITEMS 2
#define START_HEALTH 100

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char symbol;
    int health;
    Position pos;
} Entity;

typedef struct {
    Entity player;
    Entity monsters[NUM_MONSTERS];
    Position items[NUM_ITEMS];
    int width;
    int height;
} Game;

void initialize_game(Game *game);
void draw_game(Game *game);
void move_player(Game *game, char direction);
void update_monsters(Game *game);
void process_turn(Game *game);
void generate_items(Game *game);
void generate_monsters(Game *game);
void clear_screen();
void print_welcome();

int main() {
    Game game;
    char command;

    print_welcome();
    initialize_game(&game);
    
    while (1) {
        clear_screen();
        draw_game(&game);
        printf("Enter your command (WASD to move, Q to quit): ");
        scanf(" %c", &command);
        command = toupper(command);

        if (command == 'Q') break;

        move_player(&game, command);
        update_monsters(&game);
        process_turn(&game);
    }

    printf("Game over! Thank you for playing.\n");
    return 0;
}

void print_welcome() {
    printf("Welcome to the Rogue-like Game!\n");
    printf("Explore the dungeon and try to survive!\n");
}

void clear_screen() {
    system("clear"); // For Linux
}

void initialize_game(Game *game) {
    game->player.symbol = '@';
    game->player.health = START_HEALTH;
    game->player.pos.x = MAX_WIDTH / 2;
    game->player.pos.y = MAX_HEIGHT / 2;
    
    game->width = MAX_WIDTH;
    game->height = MAX_HEIGHT;
    
    generate_items(game);
    generate_monsters(game);
}

void generate_items(Game *game) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        game->items[i].x = rand() % game->width;
        game->items[i].y = rand() % game->height;
    }
}

void generate_monsters(Game *game) {
    for (int i = 0; i < NUM_MONSTERS; i++) {
        game->monsters[i].symbol = 'M';
        game->monsters[i].health = 20;
        game->monsters[i].pos.x = rand() % game->width;
        game->monsters[i].pos.y = rand() % game->height;
    }
}

void draw_game(Game *game) {
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; x < game->width; x++) {
            int drawn = 0;
            if (game->player.pos.x == x && game->player.pos.y == y) {
                printf("%c ", game->player.symbol);
                drawn = 1;
            } else {
                for (int i = 0; i < NUM_MONSTERS; i++) {
                    if (game->monsters[i].pos.x == x && game->monsters[i].pos.y == y) {
                        printf("%c ", game->monsters[i].symbol);
                        drawn = 1;
                    }
                }
                for (int i = 0; i < NUM_ITEMS; i++) {
                    if (game->items[i].x == x && game->items[i].y == y) {
                        printf("* ");
                        drawn = 1;
                    }
                }
            }
            if (!drawn) printf(". "); // Empty space
        }
        printf("\n");
    }
    printf("Player health: %d\n", game->player.health);
}

void move_player(Game *game, char direction) {
    int new_x = game->player.pos.x;
    int new_y = game->player.pos.y;

    switch (direction) {
        case 'W': new_y--; break;
        case 'S': new_y++; break;
        case 'A': new_x--; break;
        case 'D': new_x++; break;
    }

    if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height) {
        game->player.pos.x = new_x;
        game->player.pos.y = new_y;
    }
}

void update_monsters(Game *game) {
    for (int i = 0; i < NUM_MONSTERS; i++) {
        if (game->monsters[i].health > 0) {
            // Simple AI for monster movement, just move randomly.
            int direction = rand() % 4;
            int new_x = game->monsters[i].pos.x;
            int new_y = game->monsters[i].pos.y;

            switch (direction) {
                case 0: new_y--; break; // Up
                case 1: new_y++; break; // Down
                case 2: new_x--; break; // Left
                case 3: new_x++; break; // Right
            }

            if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height) {
                game->monsters[i].pos.x = new_x;
                game->monsters[i].pos.y = new_y;
            }
        }
    }
}

void process_turn(Game *game) {
    // Simple interaction: if the player and a monster occupy the same position
    for (int i = 0; i < NUM_MONSTERS; i++) {
        if (game->monsters[i].health > 0 && 
            game->monsters[i].pos.x == game->player.pos.x && 
            game->monsters[i].pos.y == game->player.pos.y) {
            game->player.health -= 10;
            printf("Ouch! A monster attacked you! Your health is now %d\n", game->player.health);
            if (game->player.health <= 0) {
                printf("You were slain by the monsters...\n");
                exit(0);
            }
        }
    }

    // Check for item collection
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (game->items[i].x == game->player.pos.x && game->items[i].y == game->player.pos.y) {
            printf("You found an item!\n");
            game->items[i].x = -1; // Mark item as collected
            game->items[i].y = -1;
        }
    }
}