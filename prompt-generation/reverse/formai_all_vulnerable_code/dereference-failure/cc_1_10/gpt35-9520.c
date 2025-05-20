//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int id;
    int score;
    int position;
    pthread_mutex_t* mutex_lock;
} Player;

pthread_barrier_t barrier;
pthread_mutex_t* table_mutex;
Player* players;
int num_players;
const int score_to_win = 50;
int winner_flag = 0;

void* player_function(void* arg) {
    Player* p = (Player*)arg;
    int dice, total_score = 0;
    srand(time(NULL) * p->id);
    pthread_barrier_wait(&barrier);
    while (!winner_flag) {
        if (pthread_mutex_trylock(p->mutex_lock) == 0) {
            dice = (rand() % 6) + 1;
            printf("Player %d rolls a %d\n", p->id, dice);
            if (dice == 1) {
                total_score = 0;
                printf("Player %d got a 1, turn score reset!\n", p->id);
                pthread_mutex_unlock(p->mutex_lock);
                sleep(1);
                continue;
            } else {
                total_score += dice;
                printf("Player %d's turn score is now %d\n", p->id, total_score);
                if (total_score + p->score >= score_to_win) {
                    printf("Player %d WINS!\n", p->id);
                    winner_flag = 1;
                } else {
                    pthread_mutex_unlock(p->mutex_lock);
                    sleep(1);
                    continue;
                }
            }
        } else {
            sleep(1);
        }
    }
    return NULL;
}

void game_init() {
    pthread_t p;
    pthread_mutex_init(table_mutex, NULL);
    pthread_barrier_init(&barrier, NULL, num_players + 1);
    players = (Player*)malloc(num_players * sizeof(Player));
    for (int i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        players[i].score = 0;
        players[i].position = 0;
        players[i].mutex_lock = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(players[i].mutex_lock, NULL);
        pthread_create(&p, NULL, player_function, (void*)&players[i]);
        pthread_detach(p);
    }
    pthread_barrier_wait(&barrier);
    printf("\nGame started with %d players,\nand the winning score is %d.\n", num_players, score_to_win);
    printf("-----------------------------------------------------------------\n");
}

void game_end() {
    for (int i = 0; i < num_players; i++) {
        pthread_mutex_destroy(players[i].mutex_lock);
    }
    pthread_barrier_destroy(&barrier);
    free(players);
    pthread_mutex_destroy(table_mutex);
}

void wait_for_players() {
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    while(num_players < 2) {
        printf("At least 2 players should play. Try again: ");
        scanf("%d", &num_players);
    }
}

int main() {
    wait_for_players();
    table_mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    game_init();
    game_end();
    return 0;
}