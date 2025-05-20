//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node
{
    char password[30];
    int attempts;
    struct node *next;
};

typedef struct node NODE;

NODE* createList(int n)
{
    NODE *head=NULL, *temp=NULL, *p=NULL;

    for(int i=0; i<n; i++)
    {
        temp=(NODE*)malloc(sizeof(NODE));

        printf("\nEnter the password: ");
        scanf("%s", &temp->password);

        temp->attempts=0;

        temp->next=NULL;

        if(head==NULL)
        {
            head=temp;
            p=temp;
        }
        else
        {
            p->next=temp;
            p=temp;
        }
    }

    return head;
}

void monitorAttempts(NODE *head, char password[])
{
    NODE *p=head;

    while(p!=NULL)
    {
        if(strcmp(p->password, password)==0)
        {
            p->attempts++;

            if(p->attempts==3)
            {
                printf("\nIntrusion detected!");
                exit(0);
            }

            break;
        }

        p=p->next;
    }
}

int main()
{
    NODE *head=NULL;
    char password[30];

    srand(time(NULL)); 

    int n=rand()%6+5;

    printf("Creating a list of %d passwords....\n", n);

    head=createList(n);

    while(1)
    {
        printf("\nEnter password: ");
        scanf("%s", &password);

        monitorAttempts(head, password);
    }

    return 0;
}