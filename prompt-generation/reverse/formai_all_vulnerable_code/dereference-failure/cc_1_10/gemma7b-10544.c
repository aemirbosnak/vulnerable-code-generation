//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Knight
{
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

int main()
{
    Knight* head = NULL;

    insert_at_tail(head, 10);
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);

    delete_from_head(head);

    printf("The data in the queue is: ");
    Knight* current_knight = head;
    while (current_knight)
    {
        printf("%d ", current_knight->data);
        current_knight = current_knight->next;
    }

    return 0;
}