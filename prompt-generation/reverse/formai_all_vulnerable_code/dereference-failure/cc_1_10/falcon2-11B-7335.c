//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

struct music
{
    char title[50];
    char artist[50];
    char album[50];
    char genre[50];
    int year;
    int rating;
};

struct music_list
{
    struct music m;
    struct music_list *next;
};

struct music_list *create_music_list(struct music m)
{
    struct music_list *new_list = (struct music_list*)malloc(sizeof(struct music_list));
    new_list->m = m;
    new_list->next = NULL;
    return new_list;
}

void display_music_list(struct music_list *head)
{
    struct music_list *temp = head;
    while(temp!= NULL)
    {
        printf("%s - %s - %s - %s - %d - %d\n", temp->m.title, temp->m.artist, temp->m.album, temp->m.genre, temp->m.year, temp->m.rating);
        temp = temp->next;
    }
}

void add_to_music_list(struct music_list **head, struct music m)
{
    struct music_list *new_list = create_music_list(m);
    if(*head == NULL)
    {
        *head = new_list;
    }
    else
    {
        struct music_list *temp = *head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = new_list;
    }
}

void delete_from_music_list(struct music_list **head, struct music m)
{
    struct music_list *temp = *head;
    struct music_list *prev = NULL;

    if(*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    while(temp!= NULL && temp->m.title!= m.title)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("No such music in the list.\n");
        return;
    }

    if(prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
}

int main()
{
    struct music_list *head = NULL;
    struct music m1 = {"Boomerang", "Bobby Womack", "Boomerang", "Soul", 1987, 4};
    struct music m2 = {"The Dark Side of the Moon", "Pink Floyd", "The Dark Side of the Moon", "Rock", 1973, 5};

    add_to_music_list(&head, m1);
    add_to_music_list(&head, m2);

    display_music_list(head);

    delete_from_music_list(&head, m1);

    display_music_list(head);

    return 0;
}