//LLAMA2-13B DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 16

void init_board(char** board);
void print_board(char** board);
void generate_word(char** board);
void check_word(char** board, char* word);
void move_up(char** board);
void move_down(char** board);
void move_left(char** board);
void move_right(char** board);

int main() {
    srand(time(NULL));

    char** board = (char**) malloc(MAX_LENGTH * sizeof(char*));
    for (int i = 0; i < MAX_LENGTH; i++) {
        board[i] = (char*) malloc(MIN_LENGTH + 1);
        for (int j = 0; j < MIN_LENGTH + 1; j++) {
            board[i][j] = ' ';
        }
    }

    init_board(board);

    while (1) {
        print_board(board);

        char command = getchar();

        if (command == 'q') {
            break;
        }

        switch (command) {
            case 'u':
                move_up(board);
                break;
            case 'd':
                move_down(board);
                break;
            case 'l':
                move_left(board);
                break;
            case 'r':
                move_right(board);
                break;
            case 'g':
                generate_word(board);
                break;
        }
    }

    free(board);

    return 0;
}

void init_board(char** board) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        board[i][0] = 'A';
        board[i][MIN_LENGTH] = 'Z';
    }
}

void print_board(char** board) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("%c", board[i][0]);
        for (int j = 1; j < MIN_LENGTH; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

void generate_word(char** board) {
    char word[MIN_LENGTH + 1];
    for (int i = 0; i < MIN_LENGTH; i++) {
        word[i] = 'A' + (rand() % 26);
    }
    word[MIN_LENGTH] = '\0';
    board[rand() % MAX_LENGTH][0] = word[0];
}

void check_word(char** board, char* word) {
    for (int i = 0; i < MIN_LENGTH; i++) {
        if (board[rand() % MAX_LENGTH][i] != word[i]) {
            return;
        }
    }
    printf("Word found! %s\n", word);
}

void move_up(char** board) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        char temp = board[i][0];
        board[i][0] = board[i][MIN_LENGTH];
        board[i][MIN_LENGTH] = temp;
    }
}

void move_down(char** board) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        char temp = board[i][MIN_LENGTH];
        board[i][MIN_LENGTH] = board[i][0];
        board[i][0] = temp;
    }
}

void move_left(char** board) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        char temp = board[i][0];
        board[i][0] = board[i][MIN_LENGTH - 1];
        board[i][MIN_LENGTH - 1] = temp;
    }
}

void move_right(char** board) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        char temp = board[i][MIN_LENGTH - 1];
        board[i][MIN_LENGTH - 1] = board[i][0];
        board[i][0] = temp;
    }
}