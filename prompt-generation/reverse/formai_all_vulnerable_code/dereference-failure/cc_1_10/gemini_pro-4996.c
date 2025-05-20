//GEMINI-pro DATASET v1.0 Category: Space Invaders Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define ENEMIES 50
#define MAX_BULLETS 100

#define ENEMY_WIDTH 5
#define ENEMY_HEIGHT 3
#define BULLET_WIDTH 2
#define BULLET_HEIGHT 1

typedef struct {
	int x;
	int y;
	int width;
	int height;
	char *bitmap;
} sprite;

typedef struct {
	sprite *sprite;
	int x;
	int y;
	int dx;
	int dy;
} entity;

typedef struct {
	entity *entities;
	int num_entities;
} level;

void init_game(level *level) {
	int i;

	level->entities = malloc(sizeof(entity) * ENEMIES);
	level->num_entities = ENEMIES;

	for (i = 0; i < ENEMIES; i++) {
		level->entities[i].sprite = malloc(sizeof(sprite));
		level->entities[i].sprite->bitmap = malloc(sizeof(char) * ENEMY_WIDTH * ENEMY_HEIGHT);
		level->entities[i].sprite->width = ENEMY_WIDTH;
		level->entities[i].sprite->height = ENEMY_HEIGHT;

		level->entities[i].x = rand() % (WIDTH - ENEMY_WIDTH);
		level->entities[i].y = rand() % (HEIGHT - ENEMY_HEIGHT);
		level->entities[i].dx = 1;
		level->entities[i].dy = 1;

		strcpy(level->entities[i].sprite->bitmap, "|||||");
	}
}

void free_game(level *level) {
	int i;

	for (i = 0; i < level->num_entities; i++) {
		free(level->entities[i].sprite->bitmap);
		free(level->entities[i].sprite);
	}

	free(level->entities);
}

void update_game(level *level) {
	int i;

	for (i = 0; i < level->num_entities; i++) {
		level->entities[i].x += level->entities[i].dx;
		level->entities[i].y += level->entities[i].dy;

		if (level->entities[i].x < 0 || level->entities[i].x >= WIDTH - ENEMY_WIDTH) {
			level->entities[i].dx = -level->entities[i].dx;
		}

		if (level->entities[i].y < 0 || level->entities[i].y >= HEIGHT - ENEMY_HEIGHT) {
			level->entities[i].dy = -level->entities[i].dy;
		}
	}
}

void draw_game(level *level) {
	int i, j;

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			printf(" ");
		}
		printf("\n");
	}

	for (i = 0; i < level->num_entities; i++) {
		for (j = 0; j < level->entities[i].sprite->height; j++) {
			printf("%.*s", level->entities[i].sprite->width, level->entities[i].sprite->bitmap + j * level->entities[i].sprite->width);
		}
		printf("\n");
	}
}

int main() {
	level level;
	int running;

	srand(time(NULL));

	init_game(&level);

	running = 1;

	while (running) {
		update_game(&level);
		draw_game(&level);
	}

	free_game(&level);

	return 0;
}