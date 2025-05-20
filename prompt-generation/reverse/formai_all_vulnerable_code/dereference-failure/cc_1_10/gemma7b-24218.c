//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 12

typedef struct Node
{
    char character;
    struct Node* next;
} Node;

void generate_password(Node** head)
{
    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++)
    {
        int r = rand() % 3;
        switch (r)
        {
            case 0:
                (*head)->character = 'a' + rand() % 26;
                break;
            case 1:
                (*head)->character = 'A' + rand() % 26;
                break;
            case 2:
                (*head)->character = '0' + rand() % 10;
                break;
        }

        (*head)->next = malloc(sizeof(Node));
        *head = (*head)->next;
    }

    (*head)->next = NULL;
}

int main()
{
    Node* head = malloc(sizeof(Node));
    generate_password(&head);

    printf("Your password is: ");
    for (Node* current = head; current; current = current->next)
    {
        printf("%c", current->character);
    }

    printf("\n");

    return 0;
}