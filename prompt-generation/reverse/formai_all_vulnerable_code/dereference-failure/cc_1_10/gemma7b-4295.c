//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void graphColoring(Node* graph)
{
    int* colors = (int*)malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        colors[i] = -1;
    }

    for (Node* node = graph; node; node = node->next)
    {
        int color = colors[node->data];
        if (color == -1)
        {
            color = 0;
            while (colors[color] == 0)
            {
                color++;
            }
            colors[node->data] = color;
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("Node %d has color %d\n", i, colors[i]);
    }

    free(colors);
}

int main()
{
    Node* graph = (Node*)malloc(sizeof(Node));
    graph->data = 0;
    graph->next = (Node*)malloc(sizeof(Node));
    graph->next->data = 1;
    graph->next->next = (Node*)malloc(sizeof(Node));
    graph->next->next->data = 2;

    graphColoring(graph);

    return 0;
}