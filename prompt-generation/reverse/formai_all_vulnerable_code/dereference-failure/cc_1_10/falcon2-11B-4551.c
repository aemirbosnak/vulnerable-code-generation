//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Linked List Node
typedef struct node
{
    char name[50];
    struct node* next;
} Node;

// Linked List Head
Node* head = NULL;

// Function to add a name to the mailing list
void add_name(char* name)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

// Function to delete a name from the mailing list
void delete_name(char* name)
{
    Node* temp = head;
    Node* prev = NULL;

    while(temp!= NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            if(prev!= NULL)
                prev->next = temp->next;
            else
                head = temp->next;

            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to search for a name in the mailing list
int search_name(char* name)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        if(strcmp(temp->name, name) == 0)
            return 1;
        temp = temp->next;
    }

    return 0;
}

// Function to print the entire mailing list
void print_list()
{
    Node* temp = head;

    while(temp!= NULL)
    {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main()
{
    char name1[50] = "John";
    char name2[50] = "Jane";

    add_name(name1);
    add_name(name2);

    printf("Name 1: %s\n", name1);
    printf("Name 2: %s\n", name2);

    delete_name(name1);

    printf("Name 1: %s\n", name1);
    printf("Name 2: %s\n", name2);

    if(search_name(name1))
        printf("Name 1 found\n");
    else
        printf("Name 1 not found\n");

    print_list();

    return 0;
}