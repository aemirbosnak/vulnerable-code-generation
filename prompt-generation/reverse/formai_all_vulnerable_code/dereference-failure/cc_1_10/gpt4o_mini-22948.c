//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_NODES 10

typedef struct Node {
    char name[30];
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_NODES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

Node* createNode(const char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, const char* destName) {
    Node* newNode = createNode(destName);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void visualizeGraph(Graph* graph) {
    system("clear");
    printf("Graph Visualization:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        printf("Vertex %d:\n", v);
        Node* temp = graph->adjLists[v];
        while (temp) {
            printf("   |---> %s\n", temp->name);
            temp = temp->next;
        }
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    int vertices;

    printf("Welcome to the Graph Visualization Program!\n");
    printf("Enter the number of vertices (1 to %d): ", MAX_NODES);
    scanf("%d", &vertices);
    clearInputBuffer();

    if (vertices < 1 || vertices > MAX_NODES) {
        printf("Invalid number of vertices! Exiting...\n");
        return 1;
    }

    Graph* graph = createGraph(vertices);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Visualize Graph\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int option;
        scanf("%d", &option);
        clearInputBuffer();

        if (option == 1) {
            int src;
            char dest[30];

            printf("Enter source vertex (0 to %d): ", vertices - 1);
            scanf("%d", &src);
            clearInputBuffer();

            if (src < 0 || src >= vertices) {
                printf("Invalid source vertex! Please try again.\n");
                continue;
            }

            printf("Enter destination node name: ");
            fgets(dest, 30, stdin);
            dest[strcspn(dest, "\n")] = 0; // Remove newline character

            addEdge(graph, src, dest);
            printf("Edge added from Vertex %d to %s\n", src, dest);
        } else if (option == 2) {
            printGraph(graph);
        } else if (option == 3) {
            visualizeGraph(graph);
            printf("\nPress any key to continue...\n");
            getch();
        } else if (option == 4) {
            printf("Exiting the program. Bye!\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
    return 0;
}