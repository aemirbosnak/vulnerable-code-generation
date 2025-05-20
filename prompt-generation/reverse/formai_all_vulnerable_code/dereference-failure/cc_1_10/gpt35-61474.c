//FormAI DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int data;
    struct node *next;
} node;

node *push(node *, int);
node *pop(node *);
void display(node *);

int main()
{
    node *top = NULL;
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL)
    {
        printf("File does not exist or could not be opened\n");
        exit(0);
    }

    fseek(fp, 0L, SEEK_END);
    long int fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *content = (char *)malloc(sizeof(char) * (fileSize + 1));
    fread(content, sizeof(char), fileSize, fp);
    fclose(fp);

    int i;
    for (i = 0; i < fileSize; ++i)
    {
        top = push(top, *(content + i));
    }
    free(content);

    printf("Recovered data:\n");
    display(top);
    return 0;
}

node *push(node *top, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = top;
    top = temp;
    return top;
}

node *pop(node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display(node *top)
{
    while (top != NULL)
    {
        printf("%c", top->data);
        top = pop(top);
    }
    printf("\n");
}