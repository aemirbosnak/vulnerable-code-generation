//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char* data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void addToList(char* data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void displayList()
{
    struct node* temp = head;
    while(temp!= NULL)
    {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    char str[100];
    printf("Enter the string to be added to the list: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0'; // remove newline character from the input string

    addToList(str);
    displayList();

    return 0;
}