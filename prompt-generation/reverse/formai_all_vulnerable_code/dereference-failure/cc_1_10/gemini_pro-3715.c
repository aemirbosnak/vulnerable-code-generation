//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Custom types and data structures
typedef struct {
    int id;
    char *name;
    double speed;
} Connection;

// Function prototypes
Connection *createConnection(int id, char *name, double speed);
void destroyConnection(Connection *connection);
Connection *findFastestConnection(Connection *connections[], int numConnections);
void printConnection(Connection *connection);

int main() {
    // Create an array of connections
    Connection *connections[] = {
        createConnection(1, "Wired Ethernet", 100.0),
        createConnection(2, "Wi-Fi 5GHz", 60.0),
        createConnection(3, "Wi-Fi 2.4GHz", 20.0),
        createConnection(4, "Cellular LTE", 15.0),
    };
    int numConnections = sizeof(connections) / sizeof(Connection *);

    // Find the fastest connection
    Connection *fastestConnection = findFastestConnection(connections, numConnections);

    // Print the fastest connection
    printf("The fastest connection is:\n");
    printConnection(fastestConnection);

    // Clean up
    for (int i = 0; i < numConnections; i++) {
        destroyConnection(connections[i]);
    }

    return 0;
}

// Function definitions
Connection *createConnection(int id, char *name, double speed) {
    Connection *connection = malloc(sizeof(Connection));
    connection->id = id;
    connection->name = strdup(name);
    connection->speed = speed;
    return connection;
}

void destroyConnection(Connection *connection) {
    free(connection->name);
    free(connection);
}

Connection *findFastestConnection(Connection *connections[], int numConnections) {
    Connection *fastestConnection = NULL;
    for (int i = 0; i < numConnections; i++) {
        if (fastestConnection == NULL || connections[i]->speed > fastestConnection->speed) {
            fastestConnection = connections[i];
        }
    }
    return fastestConnection;
}

void printConnection(Connection *connection) {
    printf("ID: %d\n", connection->id);
    printf("Name: %s\n", connection->name);
    printf("Speed: %.2f Mbps\n", connection->speed);
}