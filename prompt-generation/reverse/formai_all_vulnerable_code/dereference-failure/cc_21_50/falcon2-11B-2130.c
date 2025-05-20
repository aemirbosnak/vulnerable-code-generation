//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int board[5][5] = {0};
    int current_bingo = 0;
    int last_bingo = 0;
    int num_draws = 20;
    int num_balls = 75;
    int ball_drawn = 0;
    int *balls = malloc(num_balls * sizeof(int));
    for (int i = 0; i < num_balls; i++) {
        balls[i] = i + 1;
    }
    printf("Welcome to the C Bingo Simulator!\n");
    for (int i = 0; i < num_draws; i++) {
        int random_ball = rand() % num_balls;
        ball_drawn = balls[random_ball];
        if (board[0][0] == 0) {
            board[0][0] = ball_drawn;
        } else if (board[0][1] == 0) {
            board[0][1] = ball_drawn;
        } else if (board[0][2] == 0) {
            board[0][2] = ball_drawn;
        } else if (board[1][0] == 0) {
            board[1][0] = ball_drawn;
        } else if (board[1][1] == 0) {
            board[1][1] = ball_drawn;
        } else if (board[1][2] == 0) {
            board[1][2] = ball_drawn;
        } else if (board[2][0] == 0) {
            board[2][0] = ball_drawn;
        } else if (board[2][1] == 0) {
            board[2][1] = ball_drawn;
        } else if (board[2][2] == 0) {
            board[2][2] = ball_drawn;
        } else if (board[3][0] == 0) {
            board[3][0] = ball_drawn;
        } else if (board[3][1] == 0) {
            board[3][1] = ball_drawn;
        } else if (board[3][2] == 0) {
            board[3][2] = ball_drawn;
        } else if (board[4][0] == 0) {
            board[4][0] = ball_drawn;
        } else if (board[4][1] == 0) {
            board[4][1] = ball_drawn;
        } else if (board[4][2] == 0) {
            board[4][2] = ball_drawn;
        }
        if (current_bingo == 5) {
            printf("Bingo!\n");
            current_bingo = 0;
        } else if (last_bingo == 5) {
            printf("No bingo this time.\n");
        } else {
            printf("%d is not a Bingo!\n", ball_drawn);
        }
        if (ball_drawn == num_balls) {
            break;
        }
        last_bingo = current_bingo;
        current_bingo = 0;
        printf("Ball %d has been drawn. %d balls left.\n", ball_drawn, num_balls - ball_drawn);
    }
    free(balls);
    return 0;
}