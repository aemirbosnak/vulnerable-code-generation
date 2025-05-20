//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Define screen size */
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

/* Define player position */
#define PLAYER_POS_X 40
#define PLAYER_POS_Y 20

/* Define map size */
#define MAP_WIDTH 40
#define MAP_HEIGHT 20

/* Define object types */
#define OBJECT_NONE 0
#define OBJECT_WALL 1
#define OBJECT_DOOR 2
#define OBJECT_GHOST 3
#define OBJECT_PLAYER 4

/* Define colors */
#define COLOR_DEFAULT "\033[0m"
#define COLOR_RED "\033[1;31m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_CYAN "\033[1;36m"

/* Define player color */
#define COLOR_PLAYER COLOR_CYAN

/* Define ghost color */
#define COLOR_GHOST COLOR_RED

/* Define wall color */
#define COLOR_WALL COLOR_BLUE

/* Define door color */
#define COLOR_DOOR COLOR_GREEN

/* Map structure */
struct Map {
    int width;
    int height;
    int *data;
};

/* Initialize map */
void init_map(struct Map *map) {
    int i, j;
    for (i = 0; i < map->height; i++) {
        for (j = 0; j < map->width; j++) {
            if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1) {
                map->data[i * map->width + j] = OBJECT_WALL;
            } else {
                map->data[i * map->width + j] = OBJECT_NONE;
            }
        }
    }
}

/* Draw map */
void draw_map(struct Map *map) {
    int i, j;
    for (i = 0; i < map->height; i++) {
        for (j = 0; j < map->width; j++) {
            int object = map->data[i * map->width + j];
            switch (object) {
                case OBJECT_NONE:
                    printf(" ");
                    break;
                case OBJECT_WALL:
                    printf(COLOR_WALL "#");
                    break;
                case OBJECT_DOOR:
                    printf(COLOR_DOOR "+");
                    break;
                case OBJECT_GHOST:
                    printf(COLOR_GHOST "G");
                    break;
            }
        }
        printf(COLOR_DEFAULT "\n");
    }
}

/* Place object */
void place_object(struct Map *map, int object) {
    int x, y;
    do {
        x = rand() % (map->width - 2) + 1;
        y = rand() % (map->height - 2) + 1;
    } while (map->data[y * map->width + x] != OBJECT_NONE);
    map->data[y * map->width + x] = object;
}

/* Initialize game */
void init_game(struct Map *map) {
    srand(time(NULL));
    init_map(map);
    int i;
    for (i = 0; i < 5; i++) {
        place_object(map, OBJECT_GHOST);
    }
    place_object(map, OBJECT_DOOR);
}

/* Update player position */
void update_player(int *player_pos_x, int *player_pos_y, char direction) {
    switch (direction) {
        case 'a':
            (*player_pos_x)--;
            break;
        case 'd':
            (*player_pos_x)++;
            break;
        case 'w':
            (*player_pos_y)--;
            break;
        case 's':
            (*player_pos_y)++;
            break;
    }
}

/* Check collision with objects */
int check_collision(struct Map *map, int x, int y) {
    return map->data[y * map->width + x];
}

/* Main function */
int main(void) {
    /* Initialize map */
    struct Map map;
    map.width = MAP_WIDTH;
    map.height = MAP_HEIGHT;
    map.data = malloc(map.width * map.height * sizeof(int));
    init_game(&map);

    /* Initialize player */
    int player_pos_x = PLAYER_POS_X;
    int player_pos_y = PLAYER_POS_Y;

    /* Draw game */
    printf(COLOR_DEFAULT "\033[2J");
    draw_map(&map);
    printf("\nWelcome to the haunted house simulator!\n");
    
    /* Game loop */
    while (true) {
        printf("Enter a direction (w,a,s,d): ");
        char direction;
        scanf(" %c", &direction);
        printf("\033[1A"); /* Move cursor up one line */
        printf("\033[2K"); /* Clear line */
        update_player(&player_pos_x, &player_pos_y, direction);
        int collision = check_collision(&map, player_pos_x, player_pos_y);
        if (collision == OBJECT_WALL) {
            printf("You hit a wall.\n");
            update_player(&player_pos_x, &player_pos_y, 0); /* Move player back */
        } else if (collision == OBJECT_DOOR) {
            printf("You found the door!\n");
            break; /* Exit game */
        } else if (collision == OBJECT_GHOST) {
            printf("You got scared by a ghost!\n");
        }
        printf(COLOR_DEFAULT "\033[%d;%dH" COLOR_PLAYER "@" COLOR_DEFAULT, player_pos_y + 1, player_pos_x + 1); /* Move cursor to player position */
    }

    /* Clean up */
    free(map.data);

    return 0;
}