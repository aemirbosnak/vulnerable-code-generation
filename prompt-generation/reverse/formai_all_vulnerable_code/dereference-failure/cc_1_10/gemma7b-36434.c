//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 2

typedef struct Player
{
    char name[20];
    int baggage_weight;
    int baggage_count;
    struct Player* next;
} Player;

Player* head = NULL;

void addPlayer(char* name, int baggage_weight, int baggage_count)
{
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->baggage_weight = baggage_weight;
    newPlayer->baggage_count = baggage_count;
    newPlayer->next = NULL;

    if (head == NULL)
    {
        head = newPlayer;
    }
    else
    {
        head->next = newPlayer;
        head = newPlayer;
    }
}

void handleBaggage(Player* player)
{
    int total_weight = 0;
    for (int i = 0; i < player->baggage_count; i++)
    {
        total_weight += player->baggage_weight;
    }

    if (total_weight <= player->baggage_weight)
    {
        printf("%s, your total baggage weight is %d, which is within your limit of %d.\n", player->name, total_weight, player->baggage_weight);
    }
    else
    {
        printf("%s, your total baggage weight is %d, which exceeds your limit of %d. You will need to remove items from your baggage.\n", player->name, total_weight, player->baggage_weight);
    }
}

int main()
{
    addPlayer("John Doe", 20, 3);
    addPlayer("Jane Doe", 15, 2);

    handleBaggage(head);

    return 0;
}