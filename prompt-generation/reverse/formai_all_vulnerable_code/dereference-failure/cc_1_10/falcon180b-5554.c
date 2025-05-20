//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node
{
    char ch;
    int code;
    struct node *next;
};

void insert(struct node **start, char ch, int code)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->ch = ch;
    newnode->code = code;
    newnode->next = (*start);
    (*start) = newnode;
}

void printtable(struct node *start)
{
    printf("\nColor Name\tCode\n");
    while(start!= NULL)
    {
        printf("%c\t%d\n", start->ch, start->code);
        start = start->next;
    }
}

void search(struct node *start, char ch)
{
    if(start == NULL)
    {
        printf("\nColor not found");
    }
    else if(start->ch == ch)
    {
        printf("\n%c\t%d", start->ch, start->code);
    }
    else
    {
        search(start->next, ch);
    }
}

int main()
{
    struct node *start = NULL;
    char ch;
    int code, i = 0;

    printf("\nEnter the color names and their corresponding codes:\n");

    while(i < MAX)
    {
        printf("\nEnter color name: ");
        scanf("%s", &ch);
        printf("\nEnter color code: ");
        scanf("%d", &code);

        insert(&start, ch, code);
        i++;
    }

    printf("\nColor Name\tCode\n");
    printtable(start);

    char searchch;
    printf("\nEnter the color to search: ");
    scanf("%c", &searchch);

    search(start, searchch);

    return 0;
}