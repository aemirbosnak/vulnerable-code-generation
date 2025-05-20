//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Knight {
    int data;
    struct Knight* next;
} Knight;

Knight* insert_at_tail(Knight* head, int data)
{
    Knight* new_knight = (Knight*)malloc(sizeof(Knight));
    new_knight->data = data;
    new_knight->next = NULL;

    if (head == NULL)
    {
        head = new_knight;
    }
    else
    {
        head->next = new_knight;
    }

    return head;
}

Knight* delete_from_head(Knight* head)
{
    Knight* temp = head;
    head = head->next;
    free(temp);

    return head;
}

void traverse(Knight* head)
{
    Knight* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Knight* head = NULL;

    insert_at_tail(head, 10);
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);
    insert_at_tail(head, 40);
    insert_at_tail(head, 50);

    traverse(head);

    delete_from_head(head);

    traverse(head);

    return 0;
}