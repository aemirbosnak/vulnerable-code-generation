//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 10
#define MAX_ROUTES 20

typedef struct Route {
    char from[20];
    char to[20];
} Route;

typedef struct CityGraph {
    char cities[MAX_CITIES][20];
    int adjMatrix[MAX_CITIES][MAX_CITIES];
    int cityCount;
} CityGraph;

CityGraph* createGraph();
void addCity(CityGraph *graph, const char *city);
void addRoute(CityGraph *graph, const char *from, const char *to);
void printRoutes(CityGraph *graph, const char *currentCity, const char *destination, int *visited, int pathCount);
void findRoutes(CityGraph *graph, const char *start, const char *destination);
int getCityIndex(CityGraph *graph, const char *city);

int main() {
    CityGraph *graph = createGraph();
    
    // Define cities
    addCity(graph, "A");
    addCity(graph, "B");
    addCity(graph, "C");
    addCity(graph, "D");
    addCity(graph, "E");
    
    // Define routes
    addRoute(graph, "A", "B");
    addRoute(graph, "A", "C");
    addRoute(graph, "B", "D");
    addRoute(graph, "C", "D");
    addRoute(graph, "D", "E");
    addRoute(graph, "B", "E");
    
    // Find routes from A to E
    printf("Finding routes from A to E:\n");
    findRoutes(graph, "A", "E");
    
    // Cleanup
    free(graph);
    return 0;
}

CityGraph* createGraph() {
    CityGraph *graph = (CityGraph*)malloc(sizeof(CityGraph));
    graph->cityCount = 0;
    memset(graph->adjMatrix, 0, sizeof(graph->adjMatrix));
    return graph;
}

void addCity(CityGraph *graph, const char *city) {
    if (graph->cityCount < MAX_CITIES) {
        strcpy(graph->cities[graph->cityCount], city);
        graph->cityCount++;
    }
}

void addRoute(CityGraph *graph, const char *from, const char *to) {
    int fromIndex = getCityIndex(graph, from);
    int toIndex = getCityIndex(graph, to);

    if (fromIndex != -1 && toIndex != -1) {
        graph->adjMatrix[fromIndex][toIndex] = 1;
        graph->adjMatrix[toIndex][fromIndex] = 1; // Undirected graph
    }
}

void findRoutes(CityGraph *graph, const char *start, const char *destination) {
    int visited[MAX_CITIES] = {0};
    int pathCount = 0;
    printRoutes(graph, start, destination, visited, pathCount);
}

void printRoutes(CityGraph *graph, const char *currentCity, const char *destination, int *visited, int pathCount) {
    int index = getCityIndex(graph, currentCity);
    int destIndex = getCityIndex(graph, destination);

    if (index == -1) return; // Current city not found
    visited[index] = 1; // Mark current city as visited
    pathCount++; // Increase path count

    // If current city is the destination, print Path
    if (index == destIndex) {
        printf("Path found with length %d!\n", pathCount);
    } else {
        // Explore adjacent cities
        for (int i = 0; i < graph->cityCount; i++) {
            if (graph->adjMatrix[index][i] == 1 && !visited[i]) {
                printRoutes(graph, graph->cities[i], destination, visited, pathCount);
            }
        }
    }

    // Backtrack
    visited[index] = 0; // Unmark current city
    pathCount--; // Decrease path count
}

int getCityIndex(CityGraph *graph, const char *city) {
    for (int i = 0; i < graph->cityCount; i++) {
        if (strcmp(graph->cities[i], city) == 0) {
            return i;
        }
    }
    return -1; // City not found
}