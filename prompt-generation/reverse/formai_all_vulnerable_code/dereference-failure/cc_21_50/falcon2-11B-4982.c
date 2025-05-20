//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int num;
    int line[5];
} BingoCard;

typedef struct {
    int num;
    int line[5];
    int count;
} Bingo;

int main() {
    srand(time(NULL));

    BingoCard* card1 = (BingoCard*)malloc(sizeof(BingoCard));
    card1->num = rand() % 75 + 1;
    card1->line[0] = rand() % 5 + 1;
    card1->line[1] = rand() % 5 + 1;
    card1->line[2] = rand() % 5 + 1;
    card1->line[3] = rand() % 5 + 1;
    card1->line[4] = rand() % 5 + 1;

    BingoCard* card2 = (BingoCard*)malloc(sizeof(BingoCard));
    card2->num = rand() % 75 + 1;
    card2->line[0] = rand() % 5 + 1;
    card2->line[1] = rand() % 5 + 1;
    card2->line[2] = rand() % 5 + 1;
    card2->line[3] = rand() % 5 + 1;
    card2->line[4] = rand() % 5 + 1;

    BingoCard* card3 = (BingoCard*)malloc(sizeof(BingoCard));
    card3->num = rand() % 75 + 1;
    card3->line[0] = rand() % 5 + 1;
    card3->line[1] = rand() % 5 + 1;
    card3->line[2] = rand() % 5 + 1;
    card3->line[3] = rand() % 5 + 1;
    card3->line[4] = rand() % 5 + 1;

    BingoCard* card4 = (BingoCard*)malloc(sizeof(BingoCard));
    card4->num = rand() % 75 + 1;
    card4->line[0] = rand() % 5 + 1;
    card4->line[1] = rand() % 5 + 1;
    card4->line[2] = rand() % 5 + 1;
    card4->line[3] = rand() % 5 + 1;
    card4->line[4] = rand() % 5 + 1;

    BingoCard* card5 = (BingoCard*)malloc(sizeof(BingoCard));
    card5->num = rand() % 75 + 1;
    card5->line[0] = rand() % 5 + 1;
    card5->line[1] = rand() % 5 + 1;
    card5->line[2] = rand() % 5 + 1;
    card5->line[3] = rand() % 5 + 1;
    card5->line[4] = rand() % 5 + 1;

    BingoCard* card6 = (BingoCard*)malloc(sizeof(BingoCard));
    card6->num = rand() % 75 + 1;
    card6->line[0] = rand() % 5 + 1;
    card6->line[1] = rand() % 5 + 1;
    card6->line[2] = rand() % 5 + 1;
    card6->line[3] = rand() % 5 + 1;
    card6->line[4] = rand() % 5 + 1;

    int player1_score = 0;
    int player2_score = 0;
    int player3_score = 0;
    int player4_score = 0;
    int player5_score = 0;
    int player6_score = 0;

    while (1) {
        printf("Player 1: %d\n", player1_score);
        printf("Player 2: %d\n", player2_score);
        printf("Player 3: %d\n", player3_score);
        printf("Player 4: %d\n", player4_score);
        printf("Player 5: %d\n", player5_score);
        printf("Player 6: %d\n", player6_score);

        if (player1_score == 5) {
            printf("Player 1 wins!\n");
            break;
        }
        if (player2_score == 5) {
            printf("Player 2 wins!\n");
            break;
        }
        if (player3_score == 5) {
            printf("Player 3 wins!\n");
            break;
        }
        if (player4_score == 5) {
            printf("Player 4 wins!\n");
            break;
        }
        if (player5_score == 5) {
            printf("Player 5 wins!\n");
            break;
        }
        if (player6_score == 5) {
            printf("Player 6 wins!\n");
            break;
        }

        int num_read = rand() % 75 + 1;
        int line[5];
        line[0] = rand() % 5 + 1;
        line[1] = rand() % 5 + 1;
        line[2] = rand() % 5 + 1;
        line[3] = rand() % 5 + 1;
        line[4] = rand() % 5 + 1;

        for (int i = 0; i < 5; i++) {
            if (line[i] == card1->line[i]) {
                printf("Player 1: %d\n", num_read);
                printf("Player 1 wins!\n");
                player1_score++;
                break;
            }
            if (line[i] == card2->line[i]) {
                printf("Player 2: %d\n", num_read);
                printf("Player 2 wins!\n");
                player2_score++;
                break;
            }
            if (line[i] == card3->line[i]) {
                printf("Player 3: %d\n", num_read);
                printf("Player 3 wins!\n");
                player3_score++;
                break;
            }
            if (line[i] == card4->line[i]) {
                printf("Player 4: %d\n", num_read);
                printf("Player 4 wins!\n");
                player4_score++;
                break;
            }
            if (line[i] == card5->line[i]) {
                printf("Player 5: %d\n", num_read);
                printf("Player 5 wins!\n");
                player5_score++;
                break;
            }
            if (line[i] == card6->line[i]) {
                printf("Player 6: %d\n", num_read);
                printf("Player 6 wins!\n");
                player6_score++;
                break;
            }
        }

        if (player1_score == 5) {
            printf("Player 1 wins!\n");
            break;
        }
        if (player2_score == 5) {
            printf("Player 2 wins!\n");
            break;
        }
        if (player3_score == 5) {
            printf("Player 3 wins!\n");
            break;
        }
        if (player4_score == 5) {
            printf("Player 4 wins!\n");
            break;
        }
        if (player5_score == 5) {
            printf("Player 5 wins!\n");
            break;
        }
        if (player6_score == 5) {
            printf("Player 6 wins!\n");
            break;
        }
    }

    free(card1);
    free(card2);
    free(card3);
    free(card4);
    free(card5);
    free(card6);

    return 0;
}