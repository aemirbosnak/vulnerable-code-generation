//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>

struct indexNode
{
    int key;
    int pos;
};

struct indexTable
{
    int size;
    struct indexNode *nodeList;
};

void createIndex(struct indexTable **table, int size)
{
    (*table) = (struct indexTable *)malloc(sizeof(struct indexTable));
    (*table)->size = size;
    (*table)->nodeList = (struct indexNode *)malloc(sizeof(struct indexNode) * size);

    for (int i = 0; i < size; i++)
    {
        (*table)->nodeList[i].key = -1;
        (*table)->nodeList[i].pos = -1;
    }
}

void insertIndex(struct indexTable *table, int key, int pos)
{
    int hash = key % table->size;

    while (table->nodeList[hash].pos != -1)
    {
        hash = (hash + 1) % table->size;
    }

    table->nodeList[hash].key = key;
    table->nodeList[hash].pos = pos;
}

int searchIndex(struct indexTable *table, int key)
{
    int hash = key % table->size;

    while (table->nodeList[hash].pos != -1)
    {
        if (table->nodeList[hash].key == key)
        {
            return table->nodeList[hash].pos;
        }

        hash = (hash + 1) % table->size;
    }

    return -1;
}

int main()
{
    struct indexTable *table;
    int size = 10;

    createIndex(&table, size);

    // insert data in index
    insertIndex(table, 1, 10);
    insertIndex(table, 2, 20);
    insertIndex(table, 12, 30);
    insertIndex(table, 22, 40);

    // search data in index
    int pos = searchIndex(table, 2);
    if (pos == -1)
    {
        printf("Data is not found in index\n");
    }
    else
    {
        printf("Data is found at position %d\n", pos);
    }

    return 0;
}