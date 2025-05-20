//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Asset
{
    char name[MAX];
    double value;
    struct Asset* next;
} Asset;

typedef struct Portfolio
{
    Asset* head;
    double total_value;
    struct Portfolio* next;
} Portfolio;

void createAsset(Portfolio* p, char* name, double value)
{
    Asset* newAsset = malloc(sizeof(Asset));
    strcpy(newAsset->name, name);
    newAsset->value = value;
    newAsset->next = NULL;

    if (p->head == NULL)
    {
        p->head = newAsset;
    }
    else
    {
        p->head->next = newAsset;
    }

    p->total_value += value;
}

void printPortfolio(Portfolio* p)
{
    Asset* currentAsset = p->head;

    printf("Assets:\n");
    while (currentAsset)
    {
        printf("%s - $%.2lf\n", currentAsset->name, currentAsset->value);
        currentAsset = currentAsset->next;
    }

    printf("Total Value: $%.2lf\n", p->total_value);
}

int main()
{
    Portfolio* p = malloc(sizeof(Portfolio));
    p->head = NULL;
    p->total_value = 0.0;
    p->next = NULL;

    createAsset(p, "Apple", 100.0);
    createAsset(p, "Banana", 200.0);
    createAsset(p, "Orange", 300.0);

    printPortfolio(p);

    return 0;
}