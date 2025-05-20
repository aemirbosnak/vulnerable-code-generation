//MISTRAL-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 25
#define HEIGHT 15

typedef struct {
    int x, y;
} position;

typedef struct {
    char symbol;
    int health, damage;
} monster;

typedef struct {
    char symbol;
    int value;
} item;

typedef struct {
    int width, height;
    char **map;
} level;

position player = {13, 12};
position current_monster;
monster monsters[10];
item items[5];
level current_level;

void generate_monster() {
    current_monster.x = rand() % WIDTH;
    current_monster.y = rand() % HEIGHT;

    monsters[rand() % 10].symbol = 'G';
    monsters[rand() % 10].health = rand() % 10 + 5;
    monsters[rand() % 10].damage = rand() % 3 + 1;
}

void generate_item() {
    items[rand() % 5].symbol = '+';
    items[rand() % 5].value = rand() % 5 + 1;
}

void generate_level() {
    int i, j;

    current_level.width = WIDTH;
    current_level.height = HEIGHT;

    current_level.map = malloc(sizeof(char *) * HEIGHT);
    for (i = 0; i < HEIGHT; i++) {
        current_level.map[i] = calloc(WIDTH, sizeof(char));

        for (j = 0; j < WIDTH; j++) {
            current_level.map[i][j] = '.' ;
            if ((i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1))
                current_level.map[i][j] = '#';
        }
    }

    current_level.map[player.y][player.x] = '@';

    for (i = 0; i < 10; i++)
        generate_monster();

    for (i = 0; i < 5; i++)
        generate_item();
}

void print_level() {
    int i, j;

    for (i = 0; i < current_level.height; i++) {
        for (j = 0; j < current_level.width; j++) {
            printf("%c", current_level.map[i][j]);
        }
        printf("\n");
    }
}

void main() {
    srand(time(NULL));
    generate_level();
    print_level();

    while (1) {
        // Game logic goes here
    }
}