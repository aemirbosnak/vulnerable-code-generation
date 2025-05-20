//FormAI DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for storing music library information
struct node {
    int id;
    char title[50];
    char artist[50];
    float rating;
    struct node *next;
};

typedef struct node NODE;

NODE *head=NULL;
int count=0;

//Function prototypes
void insert();
void display();
void search(char[]);
void delete(int);
void update(int);

//Main function
int main()
{
    int choice, id;

    while(1)
    {
        printf("\n--------MENU--------\n");
        printf("1. Insert\n2. Display\n3. Search\n4. Delete\n5. Update\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nEnter the title to search: ");
                char title[50];
                scanf("%s", title);
                search(title); 
                break;
            case 4:
                printf("\nEnter the ID to delete: ");
                scanf("%d", &id);
                delete(id);
                break;
            case 5:
                printf("\nEnter the ID to update: ");
                scanf("%d", &id);
                update(id);
                break;
            case 6:
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}

//Function to insert a new record to the music library
void insert()
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));

    printf("\nEnter the ID: ");
    scanf("%d",&temp->id);
    printf("\nEnter the Title: ");
    scanf("%s",temp->title);
    printf("\nEnter the Artist: ");
    scanf("%s",temp->artist);
    printf("\nEnter the Rating: ");
    scanf("%f",&temp->rating);

    if(count == 0)
    {
        head = temp;
        temp->next = NULL;
        count++;
        printf("\nRecord inserted successfully!\n");
        return;
    }

    NODE *ptr, *prev;
    ptr = head;
    prev = NULL;

    while(ptr != NULL && ptr->id < temp->id)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        prev->next = temp;
        temp->next = NULL;
    }
    else if(prev == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        prev->next = temp;
        temp->next = ptr;
    }

    count++;
    printf("\nRecord inserted successfully!\n");
}

//Function to display all the records in the music library
void display()
{
    NODE *temp;
    temp=head;

    if(head == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nID\tTitle\tArtist\tRating\n");
    while(temp!=NULL)
    {
        printf("%d\t%s\t%s\t%f\n",temp->id,temp->title,temp->artist,temp->rating);
        temp=temp->next;
    }
}

//Function to search the record by Title
void search(char title[])
{
    NODE *temp;
    temp=head;

    while(temp!=NULL)
    {
        if(strcmp(temp->title, title)==0)
        {
            printf("\nRecord found!\n");
            printf("\nID\tTitle\tArtist\tRating\n");
            printf("%d\t%s\t%s\t%f\n",temp->id,temp->title,temp->artist,temp->rating);
            return;
        }
        temp=temp->next;
    }

    printf("\nRecord not found!\n");
}

//Function to delete the record by ID
void delete(int id)
{
    NODE *temp, *prev;
    temp=head;
    prev=NULL;

    while(temp!=NULL)
    {
        if(temp->id == id)
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            count--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\nRecord not found!\n");
}

//Function to update the record by ID
void update(int id)
{
    NODE *temp;
    temp=head;

    while(temp!=NULL)
    {
        if(temp->id == id)
        {
            printf("\nRecord found!\n");
            printf("\nEnter the new title: ");
            scanf("%s",temp->title);
            printf("\nEnter the new artist: ");
            scanf("%s",temp->artist);
            printf("\nEnter the new rating: ");
            scanf("%f",&temp->rating);
            printf("\nRecord updated successfully!\n");
            return;
        }
        temp=temp->next;
    }

    printf("\nRecord not found!\n");
}