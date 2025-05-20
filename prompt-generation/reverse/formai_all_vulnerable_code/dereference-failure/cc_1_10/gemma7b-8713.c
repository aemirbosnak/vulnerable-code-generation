//Gemma-7B DATASET v1.0 Category: Game ; Style: futuristic
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

void InitializeGame(Player** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_Players; i++)
    {
        *head = malloc(sizeof(Player));
        (*head)->name[0] = 'A' + i;
        (*head)->score = 0;
        (*head)->next = NULL;

        head = &((*head)->next);
    }
}

void PlayGame(Player* head)
{
    // Simulate some random events
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int event = rand() % 3;
        switch (event)
        {
            case 0:
                head->score++;
                printf("Congratulations, %s, you won a point!\n", head->name);
                break;
            case 1:
                head->score--;
                printf("Oops, %s, you lost a point!\n", head->name);
                break;
            case 2:
                printf("Oh no, %s, you have been struck by lightning!\n", head->name);
                head->score = 0;
                break;
        }
    }

    // Print final scores
    printf("Final scores:\n");
    for (Player* player = head; player; player = player->next)
    {
        printf("%s: %d points\n", player->name, player->score);
    }
}

int main()
{
    Player* head = NULL;
    InitializeGame(&head);
    PlayGame(head);

    return 0;
}