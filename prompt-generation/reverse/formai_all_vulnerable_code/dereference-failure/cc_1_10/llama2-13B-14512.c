//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SHIPS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
} ship_t;

typedef struct {
    ship_t ships[MAX_SHIPS];
    int current_ship;
} game_state_t;

void init_game_state(game_state_t *state) {
    for (int i = 0; i < MAX_SHIPS; i++) {
        state->ships[i].name[0] = '\0';
        state->ships[i].health = 100;
        state->ships[i].damage = 10;
    }
    state->current_ship = 0;
}

void add_ship(game_state_t *state, char *name) {
    ship_t *new_ship = malloc(sizeof(ship_t));
    strcpy(new_ship->name, name);
    new_ship->health = 100;
    new_ship->damage = 10;
    state->ships[state->current_ship] = *new_ship;
    state->current_ship++;
}

void update_ship(game_state_t *state, int ship_index) {
    ship_t *ship = &state->ships[ship_index];
    ship->health -= 10;
    if (ship->health <= 0) {
        ship->health = 0;
        state->current_ship--;
    }
}

void draw_ships(game_state_t *state) {
    for (int i = 0; i < state->current_ship; i++) {
        printf("Ship %d: %s (%d/%d)\n", i, state->ships[i].name, state->ships[i].health, state->ships[i].damage);
    }
}

int main() {
    game_state_t state;
    init_game_state(&state);

    char name[MAX_NAME_LENGTH];
    while (1) {
        printf("Add ship: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        add_ship(&state, name);

        update_ship(&state, state.current_ship - 1);

        draw_ships(&state);

        printf("Next ship? (y/n): ");
        char choice = getchar();
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}