//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void enqueue(Queue* q, int val) {
    if (q->tail == NULL) {
        q->tail = malloc(sizeof(Node));
        q->tail->val = val;
        q->tail->next = NULL;
        q->head = q->tail;
    } else {
        q->tail->next = malloc(sizeof(Node));
        q->tail->next->val = val;
        q->tail->next->next = NULL;
        q->tail = q->tail->next;
    }
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        return -1;
    } else {
        int val = q->head->val;
        Node* temp = q->head;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(temp);
        return val;
    }
}

bool bfs(int** graph, int start, int end, int n) {
    bool* visited = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    Queue q = { NULL, NULL };
    enqueue(&q, start);
    visited[start] = true;
    while (q.head != NULL) {
        int curr = dequeue(&q);
        for (int i = 0; i < n; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                if (i == end) {
                    free(visited);
                    return true;
                }
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    free(visited);
    return false;
}

int main() {
    int n = 5;
    int** graph = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[4][2] = 1;
    if (bfs(graph, 0, 4, n)) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}