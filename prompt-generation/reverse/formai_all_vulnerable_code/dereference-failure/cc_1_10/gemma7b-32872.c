//Gemma-7B DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to store game data
    typedef struct GameData
    {
        char name[20];
        int score;
        struct GameData* next;
    } GameData;

    // Create a linked list of game data
    GameData* head = NULL;

    // Get the player's name and score
    printf("Enter your name: ");
    scanf("%s", head->name);

    printf("Enter your score: ");
    scanf("%d", &head->score);

    // Create a new game data node
    GameData* new_node = malloc(sizeof(struct GameData));

    // Initialize the new node
    new_node->name[0] = '\0';
    new_node->score = 0;
    new_node->next = NULL;

    // Add the new node to the linked list
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->next = new_node;
        head = new_node;
    }

    // Print the game data
    printf("Name: %s\n", head->name);
    printf("Score: %d\n", head->score);

    // Free the memory allocated for the new node
    free(new_node);

    return 0;
}