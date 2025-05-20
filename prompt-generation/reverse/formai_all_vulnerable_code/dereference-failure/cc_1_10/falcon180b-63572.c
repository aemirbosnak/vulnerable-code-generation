//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char data[50];
    int id;
    struct node *next;
}node;

void push(node** start_ref, char data[], int id)
{
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->id = id;
    new_node->next = (*start_ref);
    (*start_ref) = new_node;
}

void display(node* start)
{
    while(start!= NULL)
    {
        printf("Data: %s\n", start->data);
        printf("ID: %d\n", start->id);
        start = start->next;
    }
}

int main()
{
    int num_players, i, id;
    char name[50];
    node* start = NULL;

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    for(i = 1; i <= num_players; i++)
    {
        printf("Enter the name of player %d: ", i);
        scanf("%s", name);

        push(&start, name, i);
    }

    printf("Player data:\n");
    display(start);

    return 0;
}