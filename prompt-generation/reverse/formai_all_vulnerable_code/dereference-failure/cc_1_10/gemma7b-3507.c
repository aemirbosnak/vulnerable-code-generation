//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define MAX_BINGO_CARDS 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

typedef struct BingoCard {
    int numbers[MAX_BALLS];
    struct BingoCard* next;
} BingoCard;

void generate_balls(Ball** head) {
    time_t t = time(NULL);
    srand(t);
    for (int i = 0; i < MAX_BALLS; i++) {
        Ball* new_ball = malloc(sizeof(Ball));
        new_ball->number = rand() % MAX_BALLS + 1;
        new_ball->next = *head;
        *head = new_ball;
    }
}

void print_balls(Ball* head) {
    while (head) {
        printf("%d ", head->number);
        head = head->next;
    }
    printf("\n");
}

void create_bingo_card(BingoCard** head) {
    *head = malloc(sizeof(BingoCard));
    for (int i = 0; i < MAX_BALLS; i++) {
        (*head)->numbers[i] = -1;
    }
    (*head)->next = NULL;
}

void mark_bingo_card(BingoCard* card, int number) {
    for (int i = 0; i < MAX_BALLS; i++) {
        if (card->numbers[i] == number) {
            card->numbers[i] = 0;
        }
    }
}

void check_bingo(BingoCard* card) {
    for (int i = 0; i < MAX_BALLS; i++) {
        if (card->numbers[i] == 0) {
            printf("Bingo!\n");
            return;
        }
    }
    printf("No bingo.\n");
}

int main() {
    Ball* balls = NULL;
    generate_balls(&balls);
    print_balls(balls);

    BingoCard* cards[MAX_BINGO_CARDS] = {NULL};
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        create_bingo_card(&cards[i]);
    }

    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        mark_bingo_card(cards[i], balls->number);
        check_bingo(cards[i]);
    }

    return 0;
}