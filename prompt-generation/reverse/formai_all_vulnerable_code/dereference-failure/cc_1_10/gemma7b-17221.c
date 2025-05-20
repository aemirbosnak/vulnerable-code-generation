//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Players 4

typedef struct Player
{
    char name[20];
    int score;
    struct Player* next;
} Player;

void initializePlayers(Player** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_Players; i++)
    {
        Player* newPlayer = malloc(sizeof(Player));
        newPlayer->name[0] = '\0';
        newPlayer->score = 0;
        newPlayer->next = NULL;

        if (*head == NULL)
        {
            *head = newPlayer;
        }
        else
        {
            ((*head)->next = newPlayer);
            head = &((*head)->next);
        }
    }
}

void playGame(Player** head)
{
    Player* currentPlayer = *head;
    while (currentPlayer)
    {
        printf("%s, it is your turn to enter your move:\n", currentPlayer->name);
        int move = scanf("enter your move: ");
        currentPlayer->score += move;
        printf("Your score is: %d\n", currentPlayer->score);
        currentPlayer = currentPlayer->next;
    }
}

int main()
{
    Player** head = NULL;
    initializePlayers(head);
    playGame(head);

    return 0;
}