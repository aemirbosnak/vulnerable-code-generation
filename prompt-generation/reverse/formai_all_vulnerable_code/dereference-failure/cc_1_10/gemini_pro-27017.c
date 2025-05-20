//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: optimized
#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <getopt.h>
#include <pthread.h>

#ifdef WIN32
#include <windows.h>
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

typedef struct {
    int x, y;
} point_t;

typedef struct {
    point_t *points;
    size_t count;
} point_list_t;

typedef struct {
    size_t rows, cols;
    bool *world;
} world_t;

static point_list_t point_list_new(void) {
    point_list_t list = { 0 };
    return list;
}

static void point_list_free(point_list_t *list) {
    free(list->points);
    *list = point_list_new();
}

static void point_list_add(point_list_t *list, int x, int y) {
    list->points = realloc(list->points, sizeof(*list->points) * (list->count + 1));
    list->points[list->count++] = (point_t) { .x = x, .y = y };
}

static world_t world_new(size_t rows, size_t cols) {
    world_t world = { .rows = rows, .cols = cols };
    world.world = calloc(rows * cols, sizeof(*world.world));
    return world;
}

static void world_free(world_t *world) {
    free(world->world);
    *world = world_new(0, 0);
}

static void world_set(world_t *world, int x, int y, bool state) {
    if (x < 0 || x >= (int)world->rows || y < 0 || y >= (int)world->cols) {
        return;
    }
    world->world[x * world->cols + y] = state;
}

static bool world_get(world_t *world, int x, int y) {
    if (x < 0 || x >= (int)world->rows || y < 0 || y >= (int)world->cols) {
        return false;
    }
    return world->world[x * world->cols + y];
}

static int world_count_neighbors(world_t *world, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            count += world_get(world, x + i, y + j);
        }
    }
    return count;
}

static bool world_step(world_t *world, point_list_t *to_die, point_list_t *to_be_born) {
    for (size_t i = 0; i < world->rows; i++) {
        for (size_t j = 0; j < world->cols; j++) {
            int count = world_count_neighbors(world, i, j);
            if (world_get(world, i, j)) {
                if (count < 2 || count > 3) {
                    point_list_add(to_die, i, j);
                }
            } else {
                if (count == 3) {
                    point_list_add(to_be_born, i, j);
                }
            }
        }
    }
    for (size_t i = 0; i < to_die->count; i++) {
        world_set(world, to_die->points[i].x, to_die->points[i].y, false);
    }
    for (size_t i = 0; i < to_be_born->count; i++) {
        world_set(world, to_be_born->points[i].x, to_be_born->points[i].y, true);
    }
    return to_die->count || to_be_born->count;
}

static void world_print(world_t *world) {
    for (size_t i = 0; i < world->rows; i++) {
        for (size_t j = 0; j < world->cols; j++) {
            putchar(world_get(world, i, j) ? '#' : '.');
        }
        putchar('\n');
    }
}

static void *pthread_wrapper(void *arg) {
    world_t *world = arg;
    while (true) {
        point_list_t to_die = point_list_new();
        point_list_t to_be_born = point_list_new();
        if (!world_step(world, &to_die, &to_be_born)) {
            break;
        }
        point_list_free(&to_die);
        point_list_free(&to_be_born);
        clear();
        world_print(world);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char **argv) {
    world_t world = world_new(24, 80);
    world_set(&world, 10, 10, true);
    world_set(&world, 11, 11, true);
    world_set(&world, 11, 12, true);
    world_set(&world, 12, 11, true);
    world_set(&world, 12, 12, true);

    clear();
    world_print(&world);

    pthread_t thread;
    if (pthread_create(&thread, NULL, pthread_wrapper, &world)) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    if (pthread_join(thread, NULL)) {
        perror("pthread_join");
        return EXIT_FAILURE;
    }

    world_free(&world);

    return EXIT_SUCCESS;
}