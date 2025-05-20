//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    int id;
    int num;
    int state;
} Player;

typedef struct {
    int num;
    int state;
} Ball;

void *player_thread(void *arg) {
    Player *player = (Player *) arg;
    int id = player->id;
    int num = player->num;
    int state = player->state;

    printf("Player %d is playing with %d balls.\n", id, num);
    while (state == 0) {
        sleep(1);
    }
    printf("Player %d wins!\n", id);
    pthread_exit(NULL);
}

void *ball_thread(void *arg) {
    Ball *ball = (Ball *) arg;
    int num = ball->num;
    int state = ball->state;

    printf("Ball %d is rolling...\n", num);
    while (state == 0) {
        sleep(1);
    }
    printf("Ball %d stops.\n", num);
    pthread_exit(NULL);
}

int main() {
    int num_players, num_balls, i, j;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the number of balls: ");
    scanf("%d", &num_balls);

    pthread_t players[num_players];
    Player players_data[num_players];
    Ball balls_data[num_balls];

    for (i = 0; i < num_players; i++) {
        players_data[i].id = i + 1;
        players_data[i].num = 5;
        players_data[i].state = 0;
        pthread_create(&players[i], NULL, player_thread, &players_data[i]);
    }

    for (i = 0; i < num_balls; i++) {
        balls_data[i].num = i + 1;
        balls_data[i].state = 0;
        pthread_create(&players[num_players - num_balls + i], NULL, ball_thread, &balls_data[i]);
    }

    for (i = 0; i < num_players; i++) {
        pthread_join(players[i], NULL);
    }

    for (j = 0; j < num_balls; j++) {
        pthread_join(players[num_players - num_balls + j], NULL);
    }

    printf("All players and balls have finished.\n");
    return 0;
}