//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 2

typedef struct Player
{
    char name[20];
    int score;
    struct Player* next;
} Player;

Player* CreatePlayer(char* name)
{
    Player* player = malloc(sizeof(Player));
    strcpy(player->name, name);
    player->score = 0;
    player->next = NULL;

    return player;
}

void AddPlayer(Player* head, char* name)
{
    Player* newPlayer = CreatePlayer(name);

    if (head == NULL)
    {
        head = newPlayer;
    }
    else
    {
        head->next = newPlayer;
    }

    head = newPlayer;
}

void AnalyzeDiskSpace(Player* head)
{
    printf("Players:");
    for (Player* player = head; player; player = player->next)
    {
        printf(" %s", player->name);
    }

    printf("\nTotal Disk Space Usage:");
    int totalSpace = 0;
    for (Player* player = head; player; player = player->next)
    {
        totalSpace += player->score;
    }

    printf(" %d KB\n", totalSpace);
}

int main()
{
    Player* head = NULL;

    // Add players
    AddPlayer(head, "John Doe");
    AddPlayer(head, "Jane Doe");
    AddPlayer(head, "Bob Smith");

    // Analyze disk space
    AnalyzeDiskSpace(head);

    return 0;
}