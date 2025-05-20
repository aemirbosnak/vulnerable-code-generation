//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid, bt, at, wt, tat, ct;
};

struct node{
    struct process p;
    struct node *next, *prev;
};

void insert(struct node **head_ref, struct process p)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->p = p;
    new_node->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        (*head_ref)->prev = NULL;
        return;
    }


    struct node *last_node = *head_ref;

    while(last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = new_node;
    new_node->prev = last_node;


}

void delete_node(struct node **head_ref, struct node *del_node)
{
    if(*head_ref == NULL || del_node == NULL)
        return;

    if(*head_ref == del_node)
        *head_ref = (*head_ref)->next;

    if(del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    if(del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    free(del_node);
}

void SJF(struct node **head_ref)
{
    int time = 0;
    while(*head_ref != NULL)
    {
        struct node *smallest = *head_ref;
        struct node *current_node = *head_ref;
        while(current_node != NULL)
        {
            if(current_node->p.bt < smallest->p.bt)
                smallest = current_node;
            current_node = current_node->next;
        }

        smallest->p.wt = time - smallest->p.at;
        time += smallest->p.bt;
        smallest->p.tat = smallest->p.wt + smallest->p.bt;
        smallest->p.ct = time;
        delete_node(head_ref, smallest);
    }
}

void print_queue(struct node *head)
{
    struct node *current_node = head;
    while(current_node != NULL)
    {
        printf("PID: %d BT: %d AT: %d WT: %d TAT: %d CT: %d\n",
                current_node->p.pid, current_node->p.bt, current_node->p.at, current_node->p.wt,
                current_node->p.tat, current_node->p.ct);

        current_node = current_node->next;
    }
}

int main()
{
    struct node *head = NULL;

    struct process p1 = {1, 10, 0, 0, 0, 0};
    struct process p2 = {2, 20, 5, 0, 0, 0};
    struct process p3 = {3, 30, 10, 0, 0, 0};
    struct process p4 = {4, 25, 15, 0, 0, 0};

    insert(&head, p1);
    insert(&head, p2);
    insert(&head, p3);
    insert(&head, p4);

    SJF(&head);

    printf("SJF schedule:\n");
    print_queue(head);

    return 0;
}