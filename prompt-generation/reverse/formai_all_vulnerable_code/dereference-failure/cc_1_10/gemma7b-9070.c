//Gemma-7B DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player
{
    char name[20];
    int score;
    struct Player* next;
} Player;

void initializePlayers(Player** head, int numPlayers)
{
    *head = NULL;
    for(int i = 0; i < numPlayers; i++)
    {
        Player* newPlayer = malloc(sizeof(Player));
        strcpy(newPlayer->name, "Player");
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
    // Logic to play the game, such as rolling the dice, making moves, and updating scores.
    // For this example, simply increment the score of the first player.
    (*head)->score++;
}

int main()
{
    Player** head = NULL;
    initializePlayers(head, MAX_Players);
    playGame(head);
    // Print the scores of each player.
    for(Player* player = head; player; player = player->next)
    {
        printf("%s's score is %d\n", player->name, player->score);
    }

    return 0;
}