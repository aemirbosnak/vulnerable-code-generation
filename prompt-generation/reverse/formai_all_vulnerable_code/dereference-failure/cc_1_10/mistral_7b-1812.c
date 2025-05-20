//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PAIRS 2
#define MAX_PAIRS 10
#define MIN_CARD_SIZE 2
#define MAX_CARD_SIZE 10

typedef struct Card {
    int value;
    char symbol;
} Card;

void print_board(Card **board, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", board[i][j].symbol);
        }
        printf("\n");
    }
}

void deal_cards(Card **board, int pairs, int card_size) {
    int i, j, index1, index2;
    Card temp;

    srand(time(NULL));

    for (i = 0; i < pairs; i++) {
        index1 = rand() % (pairs * 2);
        index2 = rand() % (pairs * 2);

        while (index1 == index2) {
            index2 = rand() % (pairs * 2);
        }

        board[index1 / 2][index1 % 2] = (Card) { .value = i + 1, .symbol = 'A' + card_size * (i + 1) };
        board[index2 / 2][index2 % 2] = board[index1 / 2][index1 % 2];
        board[index1 / 2][index1 % 2] = (Card) { .value = i + 1 + pairs, .symbol = 'A' + card_size * (i + 1 + pairs) };
    }
}

int check_match(Card **board, int rows, int cols, int *clicked, int x, int y) {
    if (clicked[x * cols + y] != 0) {
        return -1;
    }

    clicked[x * cols + y] = 1;

    if (board[x][y].value == board[x + rows / 2][y + cols / 2].value) {
        return 1;
    }

    return 0;
}

int main() {
    int pairs, card_size;
    int rows, cols;
    Card **board;
    int clicked[100];
    int i, x, y;

    printf("Enter the number of pairs: ");
    scanf("%d", &pairs);

    if (pairs < MIN_PAIRS || pairs > MAX_PAIRS) {
        printf("Invalid number of pairs. Exiting...\n");
        return 1;
    }

    printf("Enter the size of the cards: ");
    scanf("%d", &card_size);

    if (card_size < MIN_CARD_SIZE || card_size > MAX_CARD_SIZE) {
        printf("Invalid card size. Exiting...\n");
        return 1;
    }

    rows = pairs * 2;
    cols = (pairs * 2 + 1) / 2;

    board = malloc(rows * sizeof(Card *));
    for (i = 0; i < rows; i++) {
        board[i] = calloc(cols, sizeof(Card));
    }

    deal_cards(board, pairs, card_size);

    print_board(board, rows, cols);

    while (1) {
        printf("Enter the position (x, y) to click: ");
        scanf("%d%d", &x, &y);

        if (check_match(board, rows, cols, clicked, x, y) == 1) {
            printf("Match found! Keep going...\n");
            if (--pairs == 0) {
                printf("Congratulations! You've found all the pairs.\n");
                break;
            }
            print_board(board, rows, cols);
        } else if (check_match(board, rows, cols, clicked, x, y) == -1) {
            printf("You already clicked on this card. Try again.\n");
        } else {
            printf("No match found. Keep trying...\n");
        }
    }

    for (i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}