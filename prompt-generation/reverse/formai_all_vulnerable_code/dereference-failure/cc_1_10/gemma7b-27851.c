//Gemma-7B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_NUM 2

typedef struct Player
{
    char name[20];
    int score;
    struct Player* next;
} Player;

void initializeGame(Player** head)
{
    *head = NULL;
}

void addPlayer(Player** head, char* name)
{
    Player* newNode = malloc(sizeof(Player));
    strcpy(newNode->name, name);
    newNode->score = 0;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void playGame(Player* head)
{
    // Game Logic Here
    for (Player* currentPlayer = head; currentPlayer; currentPlayer = currentPlayer->next)
    {
        // Get the player's turn
        // Roll the dice
        // Calculate the player's score
        currentPlayer->score += rollDice();
        // Print the player's score
    }

    // Game End
}

int rollDice()
{
    // Pseudo-random number generator
    return rand() % 6 + 1;
}

int main()
{
    Player* head = NULL;
    initializeGame(&head);

    // Add players to the game
    addPlayer(&head, "John");
    addPlayer(&head, "Mary");

    // Play the game
    playGame(head);

    // Print the final scores
    for (Player* currentPlayer = head; currentPlayer; currentPlayer = currentPlayer->next)
    {
        printf("%s's score: %d\n", currentPlayer->name, currentPlayer->score);
    }

    return 0;
}