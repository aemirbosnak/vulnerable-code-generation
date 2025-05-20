//GEMINI-pro DATASET v1.0 Category: Game ; Style: Claude Shannon
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 256
#define MAX_SIZE 256
#define MAX_TRIES 256

typedef struct {
    char *name;
    int score;
} player_t;

typedef struct {
    char *entropy;
    int frequency;
} entropy_t;

typedef struct {
    int row;
    int col;
} position_t;

int compare_players(const void *a, const void *b) {
    const player_t *pa = (const player_t *)a;
    const player_t *pb = (const player_t *)b;
    return pb->score - pa->score;
}

int compare_entropy(const void *a, const void *b) {
    const entropy_t *ea = (const entropy_t *)a;
    const entropy_t *eb = (const entropy_t *)b;
    return ea->frequency - eb->frequency;
}

int compare_positions(const void *a, const void *b) {
    const position_t *pa = (const position_t *)a;
    const position_t *pb = (const position_t *)b;
    return pa->row - pb->row || pa->col - pb->col;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc < 3) {
        printf("Usage: %s <num_players> <num_tries>\n", argv[0]);
        return 1;
    }
    int num_players = atoi(argv[1]);
    int num_tries = atoi(argv[2]);
    if (num_players < 1 || num_players > MAX_SIZE) {
        printf("Invalid number of players: %d\n", num_players);
        return 1;
    }
    if (num_tries < 1 || num_tries > MAX_TRIES) {
        printf("Invalid number of tries: %d\n", num_tries);
        return 1;
    }
    char *inputs[MAX_LEN];
    int lengths[MAX_LEN];
    for (int i = 0; i < num_tries; i++) {
        char *input = malloc(MAX_LEN);
        scanf("%s", input);
        inputs[i] = input;
        lengths[i] = strlen(input);
    }
    player_t players[MAX_SIZE];
    for (int i = 0; i < num_players; i++) {
        char *name = malloc(MAX_LEN);
        scanf("%s", name);
        players[i].name = name;
        players[i].score = 0;
    }
    entropy_t entropy[MAX_LEN];
    for (int i = 0; i < MAX_LEN; i++) {
        entropy[i].entropy = malloc(MAX_LEN);
        entropy[i].frequency = 0;
    }
    for (int i = 0; i < num_tries; i++) {
        char *input = inputs[i];
        int length = lengths[i];
        for (int j = 0; j < length; j++) {
            char c = input[j];
            entropy[c].frequency++;
        }
    }
    qsort(entropy, MAX_LEN, sizeof(entropy_t), compare_entropy);
    for (int i = 0; i < num_players; i++) {
        player_t *player = &players[i];
        int score = 0;
        for (int j = 0; j < num_tries; j++) {
            char *input = inputs[j];
            int length = lengths[j];
            int csum = 0;
            for (int k = 0; k < length; k++) {
                char c = input[k];
                csum += entropy[c].frequency;
            }
            score += csum;
        }
        player->score = score;
    }
    qsort(players, num_players, sizeof(player_t), compare_players);
    for (int i = 0; i < num_players; i++) {
        player_t *player = &players[i];
        printf("%s %d\n", player->name, player->score);
    }
    int best_score = players[0].score;
    int worst_score = players[num_players - 1].score;
    printf("Best score: %d\n", best_score);
    printf("Worst score: %d\n", worst_score);
    int best_player = 0;
    int worst_player = num_players - 1;
    printf("Best player: %s\n", players[best_player].name);
    printf("Worst player: %s\n", players[worst_player].name);
    return 0;
}