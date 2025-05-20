//FormAI DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node
{
    char email[MAX_SIZE];
    struct node *next;
};

void add_email(struct node **headRef, char *new_email)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->email, new_email);
    new_node->next = (*headRef);
    (*headRef) = new_node;
}

void delete_email(struct node **headRef, char *email_to_delete)
{
    struct node *temp = *headRef, *prev;

    if (temp != NULL && strcmp(temp->email, email_to_delete) == 0)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->email, email_to_delete) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;

    free(temp);
}

void print_list(struct node *node)
{
    while (node != NULL)
    {
        printf("%s\n", node->email);
        node = node->next;
    }
}

int main()
{
    struct node *head = NULL;

    add_email(&head, "example1@gmail.com");
    add_email(&head, "example2@gmail.com");
    add_email(&head, "example3@gmail.com");
    add_email(&head, "example4@gmail.com");
    add_email(&head, "example5@gmail.com");

    printf("Initial list:\n");
    print_list(head);

    delete_email(&head, "example2@gmail.com");
    delete_email(&head, "example4@gmail.com");

    printf("\nList after deleting example2@gmail.com and example4@gmail.com:\n");
    print_list(head);

    return 0;
}