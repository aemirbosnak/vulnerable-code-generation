//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_PLAYERS 4

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    int player_id;
} Vehicle;

typedef struct {
    Vehicle* vehicles[MAX_PLAYERS];
    int num_players;
    int current_player;
} GameState;

void init_game(GameState* state) {
    state->num_players = 0;
    state->current_player = 0;
}

bool is_valid_position(Position p) {
    return p.x >= 0 && p.x < BOARD_SIZE && p.y >= 0 && p.y < BOARD_SIZE;
}

bool is_vehicle_at(GameState* state, Position p) {
    for (int i = 0; i < state->num_players; i++) {
        Vehicle* v = state->vehicles[i];
        if (v->pos.x == p.x && v->pos.y == p.y) {
            return true;
        }
    }
    return false;
}

bool is_collision(GameState* state, Position p) {
    for (int i = 0; i < state->num_players; i++) {
        Vehicle* v = state->vehicles[i];
        if (v->player_id != state->current_player && v->pos.x == p.x && v->pos.y == p.y) {
            return true;
        }
    }
    return false;
}

void display_board(GameState* state) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Position p = {j, i};
            if (is_vehicle_at(state, p)) {
                printf("[*]");
            } else {
                printf("[ ]");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void move_vehicle(GameState* state, int dx, int dy) {
    Vehicle* v = state->vehicles[state->current_player];
    Position new_pos = {v->pos.x + dx, v->pos.y + dy};
    if (is_valid_position(new_pos) && !is_vehicle_at(state, new_pos) && !is_collision(state, new_pos)) {
        v->pos = new_pos;
    }
}

void next_turn(GameState* state) {
    state->current_player = (state->current_player + 1) % state->num_players;
}

int main() {
    GameState state;
    init_game(&state);

    srand(time(NULL));

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (rand() % 2 == 0) {
            Vehicle* v = malloc(sizeof(Vehicle));
            v->pos.x = rand() % BOARD_SIZE;
            v->pos.y = rand() % BOARD_SIZE;
            v->player_id = state.num_players;
            state.vehicles[state.num_players] = v;
            state.num_players++;
        }
    }

    printf("Welcome to remote control vehicle simulation!\n");
    printf("You are player %d\n", state.current_player + 1);

    display_board(&state);

    bool game_over = false;
    while (!game_over) {
        int dx, dy;
        printf("Enter movement: ");
        scanf("%d %d", &dx, &dy);
        move_vehicle(&state, dx, dy);
        display_board(&state);
        next_turn(&state);

        if (state.num_players == 1) {
            printf("Player %d wins!\n", state.vehicles[0]->player_id + 1);
            game_over = true;
        }
    }

    return 0;
}