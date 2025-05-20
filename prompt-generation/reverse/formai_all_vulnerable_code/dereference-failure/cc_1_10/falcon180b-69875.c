//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_NODES 100

//Node structure
typedef struct node
{
    int data;
    int key;
    int ip;
    int port;
    struct node* next;
}Node;

//Hash function
int hash_func(int key, int num_nodes)
{
    return key % num_nodes;
}

//Function to add a node to the linked list
void add_node(Node** head, int data, int key, int ip, int port)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->key = key;
    new_node->ip = ip;
    new_node->port = port;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node* temp = *head;

    while(temp->next!= NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

//Function to search for a node in the linked list
Node* search_node(Node* head, int key)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        if(temp->key == key)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

//Function to print the linked list
void print_list(Node* head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        printf("Data: %d, Key: %d, IP: %d, Port: %d\n", temp->data, temp->key, temp->ip, temp->port);
        temp = temp->next;
    }
}

//Main function
int main()
{
    int num_nodes = 5;
    Node* head = NULL;

    //Add nodes to the linked list
    for(int i=0; i<num_nodes; i++)
    {
        add_node(&head, i+1, i+1, i+100, i+200);
    }

    //Print the linked list
    printf("Linked List:\n");
    print_list(head);

    //Search for a node in the linked list
    Node* search_result = search_node(head, 2);

    if(search_result!= NULL)
    {
        printf("Node found!\n");
    }
    else
    {
        printf("Node not found.\n");
    }

    return 0;
}