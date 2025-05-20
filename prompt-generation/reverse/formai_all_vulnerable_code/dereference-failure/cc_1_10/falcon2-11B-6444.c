//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5

typedef struct {
    int size;
    int* numbers;
} BingoCard;

typedef struct {
    int size;
    BingoCard* cards;
} BingoTable;

void generate_bingo_card(BingoCard* card, int size) {
    card->size = size;
    card->numbers = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        card->numbers[i] = rand() % 75 + 1;
    }
}

BingoTable* initialize_bingo_table(int size) {
    BingoTable* table = (BingoTable*) malloc(sizeof(BingoTable));
    table->size = size;
    table->cards = (BingoCard*) malloc(size * sizeof(BingoCard));
    for (int i = 0; i < size; i++) {
        table->cards[i].size = MAX_BINGO_CARD_SIZE;
        table->cards[i].numbers = (int*) malloc(MAX_BINGO_CARD_SIZE * sizeof(int));
        generate_bingo_card(&table->cards[i], MAX_BINGO_CARD_SIZE);
    }
    return table;
}

void read_bingo_numbers(BingoTable* table, FILE* file) {
    char line[80];
    while (fgets(line, sizeof(line), file)) {
        int number = atoi(line);
        for (int i = 0; i < table->size; i++) {
            if (table->cards[i].numbers[0] == number) {
                table->cards[i].numbers[1]++;
                break;
            }
        }
    }
}

void print_bingo_table(BingoTable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("Bingo Card %d:\n", i + 1);
        for (int j = 0; j < table->cards[i].size; j++) {
            printf("%d ", table->cards[i].numbers[j]);
        }
        printf("\n");
    }
}

void play_bingo(BingoTable* table, FILE* file) {
    srand(time(NULL));
    while (true) {
        int number = rand() % 75 + 1;
        for (int i = 0; i < table->size; i++) {
            if (table->cards[i].numbers[0] == number) {
                table->cards[i].numbers[1]++;
                if (table->cards[i].numbers[1] == table->cards[i].size) {
                    printf("Player %d has a bingo!\n", i + 1);
                    return;
                }
                break;
            }
        }
    }
}

int main() {
    FILE* file = fopen("bingo_numbers.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    BingoTable* table = initialize_bingo_table(5);
    read_bingo_numbers(table, file);
    print_bingo_table(table);

    play_bingo(table, file);

    return 0;
}