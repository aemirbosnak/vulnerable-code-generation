//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 100
#define MAX_NAME_LENGTH 30

typedef struct Station {
    char name[MAX_NAME_LENGTH];
    struct Station* next;
} Station;

typedef struct Graph {
    int numStations;
    Station* adjList[MAX_STATIONS];
} Graph;

Graph* createGraph(int stations);
void addStation(Graph* graph, const char* stationName);
void addRoute(Graph* graph, const char* stationFrom, const char* stationTo);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
int findStationIndex(Graph* graph, const char* stationName);

int main() {
    Graph* cityGraph = createGraph(MAX_STATIONS);
    int choice;
    char stationFrom[MAX_NAME_LENGTH], stationTo[MAX_NAME_LENGTH];

    while (1) {
        printf("\n--- Public Transportation System ---\n");
        printf("1. Add Station\n");
        printf("2. Add Route\n");
        printf("3. Display Network\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter station name: ");
                scanf("%s", stationFrom);
                addStation(cityGraph, stationFrom);
                break;

            case 2:
                printf("Enter starting station: ");
                scanf("%s", stationFrom);
                printf("Enter destination station: ");
                scanf("%s", stationTo);
                addRoute(cityGraph, stationFrom, stationTo);
                break;

            case 3:
                printGraph(cityGraph);
                break;

            case 4:
                freeGraph(cityGraph);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

Graph* createGraph(int stations) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numStations = 0;
    for (int i = 0; i < stations; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addStation(Graph* graph, const char* stationName) {
    if (graph->numStations >= MAX_STATIONS) {
        printf("Cannot add more stations, max limit reached.\n");
        return;
    }
    strcpy(graph->adjList[graph->numStations]->name, stationName);
    graph->adjList[graph->numStations] = (Station*)malloc(sizeof(Station));
    graph->numStations++;
    printf("Station %s added.\n", stationName);
}

void addRoute(Graph* graph, const char* stationFrom, const char* stationTo) {
    int fromIndex = findStationIndex(graph, stationFrom);
    int toIndex = findStationIndex(graph, stationTo);

    if (fromIndex == -1 || toIndex == -1) {
        printf("One or both stations not found.\n");
        return;
    }

    Station* newStation = (Station*)malloc(sizeof(Station));
    strcpy(newStation->name, stationTo);
    newStation->next = graph->adjList[fromIndex]->next;
    graph->adjList[fromIndex]->next = newStation;

    printf("Route from %s to %s added.\n", stationFrom, stationTo);
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numStations; i++) {
        Station* temp = graph->adjList[i];
        printf("Station %s is connected to: ", temp->name);
        temp = temp->next;
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numStations; i++) {
        Station* temp = graph->adjList[i];
        while (temp != NULL) {
            Station* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

int findStationIndex(Graph* graph, const char* stationName) {
    for (int i = 0; i < graph->numStations; i++) {
        if (strcmp(graph->adjList[i]->name, stationName) == 0) {
            return i;
        }
    }
    return -1;
}