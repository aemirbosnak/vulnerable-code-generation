//FormAI DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4

void fill_board(int board[][COL], int size);
void shuffle_board(int board[][COL], int size);
void print_board(int board[][COL], int size);
void play_game(int board[][COL], int size);

int main()
{
    int board[ROW][COL];
    fill_board(board, ROW * COL);
    shuffle_board(board, ROW * COL);
    print_board(board, ROW * COL);
    play_game(board, ROW * COL);

    return 0;
}

void fill_board(int board[][COL], int size)
{
    srand(time(NULL));
    int num = 0;
    for (int i = 0; i < size/2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            board[i][j] = num;
            board[i][j + 2] = num;
            num++;
        }
    }
}

void shuffle_board(int board[][COL], int size)
{
    int temp, r1, c1, r2, c2;
    for (int i = 0; i < size; i++)
    {
        r1 = rand() % ROW;
        c1 = rand() % COL;
        r2 = rand() % ROW;
        c2 = rand() % COL;
        temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
}

void print_board(int board[][COL], int size)
{
    printf("Memory Game\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", board[i/ROW][i%COL]);
        if ((i+1) % COL == 0)
        {
            printf("\n");
        }
    }
}

void play_game(int board[][COL], int size)
{
    int first_choice, second_choice, matches = 0;
    int choices[size];
    for (int i = 0; i < size; i++)
    {
        choices[i] = -1;
    }
    
    while (matches < size/2)
    {
        printf("Choose two cards to flip (0-%d): ", size-1);
        scanf("%d %d", &first_choice, &second_choice);
        if (first_choice == second_choice || choices[first_choice] != -1 || choices[second_choice] != -1)
        {
            printf("Invalid choices, try again.\n");
            continue;
        }
        printf("Card 1: %d\tCard 2: %d\n", board[first_choice/ROW][first_choice%COL], board[second_choice/ROW][second_choice%COL]);
        if (board[first_choice/ROW][first_choice%COL] == board[second_choice/ROW][second_choice%COL])
        {
            printf("Match!\n");
            matches++;
            choices[first_choice] = 1;
            choices[second_choice] = 1;
        }
        else
        {
            printf("No match.\n");
        }
    }
    printf("Congratulations, you won!\n");
}