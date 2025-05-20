//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int x, y;
    char name[20];
} Ghost;

typedef struct {
    int len, cap;
    Ghost *data;
} GhostList;

GhostList *ghost_list = NULL;

void create_ghost(int x, int y, const char *name) {
    Ghost *new_ghost = (Ghost *) malloc(sizeof(Ghost));
    strcpy(new_ghost->name, name);
    new_ghost->x = x;
    new_ghost->y = y;

    if (ghost_list->cap == ghost_list->len) {
        ghost_list->cap += 10;
        ghost_list->data = (Ghost *) realloc(ghost_list->data, ghost_list->cap * sizeof(Ghost));
    }

    ghost_list->data[ghost_list->len++] = *new_ghost;
}

void print_ghosts() {
    printf("Ghosts in the house:\n");
    for (int i = 0; i < ghost_list->len; i++) {
        printf("Ghost %s at (%d, %d)\n", ghost_list->data[i].name, ghost_list->data[i].x, ghost_list->data[i].y);
    }
}

void move_ghost(int index, int dx, int dy) {
    if (index < 0 || index >= ghost_list->len) {
        printf("Error: invalid ghost index\n");
        return;
    }

    ghost_list->data[index].x += dx;
    ghost_list->data[index].y += dy;
}

int main() {
    srand(time(NULL));

    create_ghost(5, 5, "Casper");
    create_ghost(10, 10, "Slim");
    create_ghost(15, 15, "Sheeta");

    print_ghosts();

    for (int i = 0; i < 10; i++) {
        int idx = rand() % ghost_list->len;
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;

        move_ghost(idx, dx, dy);
    }

    print_ghosts();

    free(ghost_list->data);
    free(ghost_list);

    return 0;
}