//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Router {
    char name[10];
    struct Router* connected[10];
    int numConnections;
} Router;

int main() {
    Router* network[6];
    char names[6][10] = {"Router1", "Router2", "Router3", "Router4", "Router5", "Router6"};

    //initialize routers
    for(int i = 0; i < 6; i++) {
        network[i] = (Router*) malloc(sizeof(Router));
        strcpy(network[i]->name, names[i]);
        network[i]->numConnections = 0;
    }

    //connect routers together
    network[0]->connected[network[0]->numConnections++] = network[1];
    network[0]->connected[network[0]->numConnections++] = network[2];
    network[1]->connected[network[1]->numConnections++] = network[2];
    network[1]->connected[network[1]->numConnections++] = network[3];
    network[2]->connected[network[2]->numConnections++] = network[3];
    network[2]->connected[network[2]->numConnections++] = network[4];
    network[3]->connected[network[3]->numConnections++] = network[4];
    network[3]->connected[network[3]->numConnections++] = network[5];
    network[4]->connected[network[4]->numConnections++] = network[5];

    //print network topology
    for(int i = 0; i < 6; i++) {
        Router* router = network[i];
        printf("Router %s is connected to:", router->name);

        for(int j = 0; j < router->numConnections; j++) {
            Router* connectedRouter = router->connected[j];
            printf(" %s", connectedRouter->name);
        }
        printf("\n");
    }

    //free memory
    for(int i = 0; i < 6; i++) {
        free(network[i]);
    }

    return 0;
}