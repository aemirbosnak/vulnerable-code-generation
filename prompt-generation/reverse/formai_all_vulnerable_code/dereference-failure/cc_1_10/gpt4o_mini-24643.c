//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT_SIZE 20
#define DEFAULT_GENERATIONS 100
#define ALIVE 'O'
#define DEAD '.'

typedef struct {
    char **grid;
    int size;
} GameOfLife;

void init_game(GameOfLife *game, int size);
void free_game(GameOfLife *game);
void print_grid(GameOfLife *game);
void randomize_grid(GameOfLife *game);
void update_grid(GameOfLife *game);
int count_neighbors(GameOfLife *game, int x, int y);
void configure_game(GameOfLife *game, int generations, int size);

int main(int argc, char *argv[]) {
    int size = DEFAULT_SIZE;
    int generations = DEFAULT_GENERATIONS;

    if (argc > 1) {
        size = atoi(argv[1]);
    }
    if (argc > 2) {
        generations = atoi(argv[2]);
    }

    GameOfLife game;
    configure_game(&game, generations, size);
    free_game(&game);

    return 0;
}

void configure_game(GameOfLife *game, int generations, int size) {
    init_game(game, size);
    randomize_grid(game);
    
    printf("Initial Configuration:\n");
    print_grid(game);

    for (int i = 0; i < generations; i++) {
        usleep(200000); // Sleep for 200 milliseconds for visualization
        update_grid(game);
        printf("\nGeneration %d:\n", i + 1);
        print_grid(game);
    }
}

void init_game(GameOfLife *game, int size) {
    game->size = size;
    game->grid = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        game->grid[i] = (char *)malloc(size * sizeof(char));
    }
}

void free_game(GameOfLife *game) {
    for (int i = 0; i < game->size; i++) {
        free(game->grid[i]);
    }
    free(game->grid);
}

void print_grid(GameOfLife *game) {
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            printf("%c ", game->grid[i][j]);
        }
        printf("\n");
    }
}

void randomize_grid(GameOfLife *game) {
    srand(time(NULL));
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            game->grid[i][j] = (rand() % 2 == 0) ? ALIVE : DEAD;
        }
    }
}

void update_grid(GameOfLife *game) {
    char **new_grid = (char **)malloc(game->size * sizeof(char *));
    for (int i = 0; i < game->size; i++) {
        new_grid[i] = (char *)malloc(game->size * sizeof(char));
    }

    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            int neighbors = count_neighbors(game, i, j);
            if (game->grid[i][j] == ALIVE) {
                new_grid[i][j] = (neighbors < 2 || neighbors > 3) ? DEAD : ALIVE;
            } else {
                new_grid[i][j] = (neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }

    for (int i = 0; i < game->size; i++) {
        free(game->grid[i]);
        game->grid[i] = new_grid[i];
    }
    free(new_grid);
}

int count_neighbors(GameOfLife *game, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; 
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < game->size && ny >= 0 && ny < game->size) {
                count += (game->grid[nx][ny] == ALIVE) ? 1 : 0;
            }
        }
    }
    return count;
}