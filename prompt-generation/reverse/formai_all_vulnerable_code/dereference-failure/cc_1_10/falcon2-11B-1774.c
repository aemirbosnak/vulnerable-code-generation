//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x, y;
} board;

int check(int x1, int y1, int x2, int y2){
    return (x1 == x2 && y1 == y2) || (x1 == y2 && y1 == x2);
}

void place_piece(board *board, int x, int y, int player){
    board->x = x;
    board->y = y;
    if(player == 1){
        printf("Player 1 places a piece at (%d,%d)\n", board->x, board->y);
    } else {
        printf("Player 2 places a piece at (%d,%d)\n", board->x, board->y);
    }
}

void move_piece(board *board, int x1, int y1, int x2, int y2){
    if(check(x1, y1, x2, y2)){
        board->x = x2;
        board->y = y2;
        printf("Player %d moved piece from (%d,%d) to (%d,%d)\n", (board->x == x1 && board->y == y1)? 1 : 2, x1, y1, board->x, board->y);
    } else {
        printf("Invalid move\n");
    }
}

int main(){
    int board_size = 8;
    board board_array[board_size][board_size];

    int x1, y1, x2, y2;

    int player_turn = 1;

    printf("Welcome to the Checkers Game!\n");
    printf("Player %d starts first\n", player_turn == 1? 1 : 2);

    while(1){
        printf("Player %d, enter the coordinates of the piece you want to move (0 to quit): ", player_turn == 1? 1 : 2);
        scanf("%d %d", &x1, &y1);
        if(x1 == 0 || y1 == 0){
            break;
        }

        printf("Player %d, enter the coordinates of the piece you want to move to: ", player_turn == 1? 1 : 2);
        scanf("%d %d", &x2, &y2);
        if(x2 == 0 || y2 == 0){
            printf("Invalid move\n");
            continue;
        }

        move_piece(&board_array[x1][y1], x1, y1, x2, y2);
        place_piece(&board_array[x2][y2], x2, y2, player_turn);
        player_turn = 1 - player_turn;
    }

    printf("Game Over!\n");

    return 0;
}