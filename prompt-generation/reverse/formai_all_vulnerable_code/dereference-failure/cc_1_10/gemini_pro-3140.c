//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_IMAGE_SIZE 1024

typedef struct {
    char *name;
    int score;
    unsigned char *image;
} player_t;

player_t *players[MAX_PLAYERS];
unsigned char *image;

void init_game() {
    int i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i] = malloc(sizeof(player_t));
        players[i]->name = malloc(MAX_IMAGE_SIZE);
        players[i]->image = malloc(MAX_IMAGE_SIZE);
        players[i]->score = 0;
    }

    image = malloc(MAX_IMAGE_SIZE);
}

void load_image(char *filename) {
    FILE *fp;
    int size;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file %s\n", filename);
        exit(1);
    }

    size = fread(image, 1, MAX_IMAGE_SIZE, fp);
    if (size <= 0) {
        fprintf(stderr, "Error reading image file %s\n", filename);
        exit(1);
    }

    fclose(fp);
}

void watermark_image(char *player_name, unsigned char *image) {
    int i, j;
    int len = strlen(player_name);

    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            image[i * 8 + j] |= (player_name[i] >> j) & 1;
        }
    }
}

void check_watermark(char *player_name, unsigned char *image, int *score) {
    int i, j;
    int len = strlen(player_name);
    int matches = 0;

    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            matches += (image[i * 8 + j] & 1) == ((player_name[i] >> j) & 1);
        }
    }

    *score = matches * 100 / len;
}

void play_game() {
    int i, j;
    int round = 0;
    int winner = -1;
    int high_score = 0;

    while (winner == -1) {
        round++;

        printf("Round %d\n", round);

        for (i = 0; i < MAX_PLAYERS; i++) {
            printf("Player %s's turn\n", players[i]->name);

            // Get player's guess
            printf("Enter your guess: ");
            gets(players[i]->name);

            // Watermark the image
            watermark_image(players[i]->name, image);
        }

        // Check each player's guess
        for (i = 0; i < MAX_PLAYERS; i++) {
            check_watermark(players[i]->name, image, &players[i]->score);

            printf("Player %s's score: %d\n", players[i]->name, players[i]->score);

            if (players[i]->score > high_score) {
                high_score = players[i]->score;
                winner = i;
            }
        }
    }

    printf("Player %s wins!\n", players[winner]->name);
}

void cleanup() {
    int i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        free(players[i]->name);
        free(players[i]->image);
        free(players[i]);
    }

    free(image);
}

int main() {
    init_game();

    load_image("image.jpg");

    play_game();

    cleanup();

    return 0;
}