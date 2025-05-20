//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>

#define ROWS 3
#define COLS 3

enum Player {
    PLAYER_X,
    PLAYER_O
};

struct Game {
    enum Player current_player;
    char board[ROWS][COLS];
};

void init_game(struct Game* game) {
    game->current_player = PLAYER_X;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            game->board[r][c] = ' ';
        }
    }
}

int check_for_winner(const struct Game* game) {
    const char* winning_combinations[] = {
        "123", "456", "789", // horizontal
        "147", "258", "369", // vertical
        "159", "357" // diagonal
    };

    char current_player_symbol = game->current_player == PLAYER_X ? 'X' : 'O';
    for (int i = 0; i < sizeof(winning_combinations) / sizeof(*winning_combinations); i++) {
        const char* combination = winning_combinations[i];
        char a = game->board[combination[0] - '1' / 3][combination[0] - '1' % 3];
        char b = game->board[combination[1] - '1' / 3][combination[1] - '1' % 3];
        char c = game->board[combination[2] - '1' / 3][combination[2] - '1' % 3];

        if (a == b && b == c && c == current_player_symbol) {
            return game->current_player;
        }
    }

    return -1;
}

void play_turn(struct Game* game) {
    int row, col;
    printf("Player %c's turn. Enter row and column number separated by a space: ", game->current_player == PLAYER_X ? 'X' : 'O');
    scanf("%d %d", &row, &col);

    if (game->board[row - 1][col - 1] != ' ') {
        printf("Spot is already taken!\n");
    }
    else {
        char player_symbol = game->current_player == PLAYER_X ? 'X' : 'O';
        game->board[row - 1][col - 1] = player_symbol;
        game->current_player = game->current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
    }
}

void print_board(const struct Game* game) {
    printf("    1 | 2 | 3 \n");
    printf("   -----------\n");
    for (int r = 0; r < ROWS; r++) {
        printf("%d ", r + 1);
        printf("| %c | %c | %c |\n", game->board[r][0], game->board[r][1], game->board[r][2]);
        printf("   -----------\n");
    }
}

int main() {
    struct Game game;
    init_game(&game);

    while (check_for_winner(&game) == -1) {
        print_board(&game);
        play_turn(&game);
    }

    int winner = check_for_winner(&game);
    printf("Player %c wins!\n", winner == PLAYER_X ? 'X' : 'O');
    print_board(&game);

    return 0;
}