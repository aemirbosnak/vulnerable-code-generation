//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 10
#define NUM_ROOMS 5
#define ROOM_MAX_SIZE 6
#define ROOM_MIN_SIZE 3
#define EMPTY '.'
#define PLAYER '@'
#define WALL '#'

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position position;
    char **map;
    int width;
    int height;
} Game;

void initialize_game(Game *game) {
    game->width = MAX_WIDTH;
    game->height = MAX_HEIGHT;
    game->map = malloc(game->height * sizeof(char *));
    for (int i = 0; i < game->height; i++) {
        game->map[i] = malloc(game->width * sizeof(char));
    }
    
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; x < game->width; x++) {
            game->map[y][x] = WALL;
        }
    }
    game->position.x = game->width / 2;
    game->position.y = game->height / 2;
    game->map[game->position.y][game->position.x] = PLAYER;
}

void generate_room(Game *game, int room_x, int room_y, int room_width, int room_height) {
    for (int y = room_y; y < room_y + room_height; y++) {
        for (int x = room_x; x < room_x + room_width; x++) {
            game->map[y][x] = EMPTY;
        }
    }
}

void generate_dungeon(Game *game) {
    srand(time(NULL));
    for (int i = 0; i < NUM_ROOMS; i++) {
        int room_width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int room_height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int room_x = rand() % (game->width - room_width - 1) + 1;
        int room_y = rand() % (game->height - room_height - 1) + 1;
        
        generate_room(game, room_x, room_y, room_width, room_height);
    }
}

void print_map(Game *game) {
    system("clear");
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; x < game->width; x++) {
            putchar(game->map[y][x]);
        }
        putchar('\n');
    }
}

void move_player(Game *game, int dx, int dy) {
    int new_x = game->position.x + dx;
    int new_y = game->position.y + dy;
    
    if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height && 
        game->map[new_y][new_x] != WALL) {
        game->map[game->position.y][game->position.x] = EMPTY;  // Clear old position
        game->position.x = new_x;
        game->position.y = new_y;
        game->map[game->position.y][game->position.x] = PLAYER;  // Set new position
    }
}

int main() {
    Game game;
    initialize_game(&game);
    generate_dungeon(&game);

    char command;
    while (1) {
        print_map(&game);
        printf("Use WASD to move (q to quit): ");
        command = getchar();
        getchar();  // Consume newline character

        if (command == 'q') {
            break;
        } else if (command == 'w') {
            move_player(&game, 0, -1);
        } else if (command == 's') {
            move_player(&game, 0, 1);
        } else if (command == 'a') {
            move_player(&game, -1, 0);
        } else if (command == 'd') {
            move_player(&game, 1, 0);
        } else {
            printf("Invalid command!\n");
        }
    }

    // Freeing the allocated memory
    for (int i = 0; i < game.height; i++) {
        free(game.map[i]);
    }
    free(game.map);
    
    return 0;
}