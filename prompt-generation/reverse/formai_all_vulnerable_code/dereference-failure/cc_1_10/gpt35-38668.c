//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_SHIPS 5
#define SHIP_SIZES {5, 4, 3, 3, 2}
#define NUM_PLAYERS 2
#define MAX_GUESS 100

int player_scores[NUM_PLAYERS] = {0};
int guess_count = 0;

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate position;
    int size;
    bool is_destroyed;
} Ship;

typedef struct {
    Ship ships[NUM_SHIPS];
    bool is_player_turn;
    char guess_board[BOARD_SIZE][BOARD_SIZE];
    char ships_board[BOARD_SIZE][BOARD_SIZE];
} Player;

void initialize_game(Player players[NUM_PLAYERS]) {
    srand(time(NULL));
    
    // initialize ships for each player
    for (int p = 0; p < NUM_PLAYERS; p++) {
        int* ship_sizes = SHIP_SIZES;
        for (int i = 0; i < NUM_SHIPS; i++) {
            players[p].ships[i].size = ship_sizes[i];
            players[p].ships[i].is_destroyed = false;
            
            // randomly place the ship on the board
            bool placed = false;
            while (!placed) {
                bool is_horizontal = rand() % 2 == 0;
                int max_x = is_horizontal ? BOARD_SIZE - ship_sizes[i] : BOARD_SIZE;
                int max_y = is_horizontal ? BOARD_SIZE : BOARD_SIZE - ship_sizes[i];
                
                Coordinate start_pos = {
                    .x = rand() % max_x,
                    .y = rand() % max_y
                };
                
                // check if the positions are unoccupied
                bool unoccupied = true;
                for (int s = 0; s < i; s++) {
                    for (int j = 0; j < ship_sizes[i]; j++) {
                        Coordinate c = {
                            .x = start_pos.x + (is_horizontal ? j : 0),
                            .y = start_pos.y + (is_horizontal ? 0 : j)
                        };
                        if (c.x == players[p].ships[s].position.x && c.y == players[p].ships[s].position.y) {
                            unoccupied = false;
                            break;
                        }
                    }
                    if (!unoccupied) {
                        break;
                    }
                }
                if (unoccupied) {
                    // place the ship
                    for (int j = 0; j < ship_sizes[i]; j++) {
                        Coordinate c = {
                            .x = start_pos.x + (is_horizontal ? j : 0),
                            .y = start_pos.y + (is_horizontal ? 0 : j)
                        };
                        players[p].ships_board[c.x][c.y] = 'S';
                        players[p].ships[i].position = c;
                    }
                    placed = true;
                }
            }
        }
        
        // initialize the guess board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                players[p].guess_board[i][j] = '-';
            }
        }
        
        // randomly choose which player goes first
        players[p].is_player_turn = rand() % 2 == 0;
    }
}

void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    // print the horizontal labels
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    
    // print the vertical labels and board contents
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_ship_index(Player player, Coordinate c) {
    for (int i = 0; i < NUM_SHIPS; i++) {
        if (player.ships[i].is_destroyed) {
            continue;
        }
        if (player.ships[i].position.x == c.x && player.ships[i].position.y == c.y) {
            return i;
        }
    }
    return -1;
}

bool guess(Player players[NUM_PLAYERS], int x, int y) {
    Player* current_player = &players[0];
    Player* other_player = &players[1];
    if (!current_player->is_player_turn) {
        current_player = &players[1];
        other_player = &players[0];
    }
    
    // make the guess
    guess_count++;
    if (other_player->ships_board[x][y] == 'S') {
        printf("Hit!\n");
        int hit_ship_index = get_ship_index(*other_player, (Coordinate) {.x = x, .y = y});
        Ship* hit_ship = &other_player->ships[hit_ship_index];
        hit_ship->is_destroyed = true;
        current_player->guess_board[x][y] = 'X';
        // check for end of game
        bool game_over = true;
        for (int i = 0; i < NUM_SHIPS; i++) {
            if (!hit_ship->is_destroyed) {
                game_over = false;
            }
        }
        if (game_over) {
            player_scores[0] = current_player == &players[0] ? guess_count : -1;
            player_scores[1] = current_player == &players[1] ? guess_count : -1;
            return true;
        }
    } else {
        printf("Miss!\n");
        current_player->guess_board[x][y] = 'O';
    }
    
    // switch player turn
    current_player->is_player_turn = !current_player->is_player_turn;
    other_player->is_player_turn = !other_player->is_player_turn;
    
    return false;
}

void play_game(Player players[NUM_PLAYERS]) {
    do {
        // display player board to guess on
        Player* current_player = &players[0];
        Player* other_player = &players[1];
        if (!current_player->is_player_turn) {
            current_player = &players[1];
            other_player = &players[0];
        }
        printf("Player %d, it is your turn.\n", current_player == &players[0] ? 1 : 2);
        printf("Your board:\n");
        display_board(current_player->guess_board);
        
        // get guess coordinates from player
        int x = -1;
        int y = -1;
        while (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Enter guess coordinates (e.g. A5): ");
            char input[10];
            scanf("%s", input);
            x = (int)(input[1] - '1');
            y = (int)(input[0] - 'A');
            if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
                printf("Invalid coordinates, please try again.\n");
            }
            if (current_player->guess_board[x][y] != '-') {
                printf("Location already guessed, please try again.\n");
                x = -1;
                y = -1;
            }
        }
        // make the guess and check if the game is over
        if (guess(players, x, y)) {
            break;
        }
        
        // display other player's board
        printf("\nOther player's board:\n");
        display_board(current_player == &players[0] ? other_player->ships_board : other_player->guess_board);
    } while (true);
}

void print_winner() {
    printf("Game over!\n");
    if (player_scores[0] == -1) {
        printf("Player 2 wins!\n");
    } else if (player_scores[1] == -1) {
        printf("Player 1 wins!\n");
    } else if (player_scores[0] < player_scores[1]) {
        printf("Player 1 wins in %d guesses!\n", player_scores[0]);
    } else if (player_scores[1] < player_scores[0]) {
        printf("Player 2 wins in %d guesses!\n", player_scores[1]);
    } else {
        printf("Tie game!\n");
    }
}

int main() {
    Player players[NUM_PLAYERS];
    initialize_game(players);
    play_game(players);
    print_winner();
    return 0;
}