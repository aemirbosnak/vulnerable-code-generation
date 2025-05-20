//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define NAME_LENGTH 50

typedef struct Device {
    int id;
    char name[NAME_LENGTH];
} Device;

typedef struct Node {
    int device_id;
    struct Node *next;
} Node;

typedef struct Graph {
    Device devices[MAX_DEVICES];
    Node *adjacency_list[MAX_DEVICES];
    int device_count;
} Graph;

// Function prototypes
Graph* create_graph();
void add_device(Graph *graph, const char *name);
void add_connection(Graph *graph, int device1, int device2);
void display_topology(Graph *graph);
void free_graph(Graph *graph);

int main() {
    Graph *network = create_graph();
    int choice, device1, device2;
    char device_name[NAME_LENGTH];

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Device\n");
        printf("2. Add Connection\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", device_name);
                add_device(network, device_name);
                break;
            case 2:
                printf("Enter two device IDs to connect (0-%d): ", network->device_count - 1);
                scanf("%d %d", &device1, &device2);
                add_connection(network, device1, device2);
                break;
            case 3:
                display_topology(network);
                break;
            case 4:
                free_graph(network);
                return 0;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }
}

Graph* create_graph() {
    Graph *graph = malloc(sizeof(Graph));
    graph->device_count = 0;
    for (int i = 0; i < MAX_DEVICES; i++) {
        graph->adjacency_list[i] = NULL;
    }
    return graph;
}

void add_device(Graph *graph, const char *name) {
    if (graph->device_count < MAX_DEVICES) {
        graph->devices[graph->device_count].id = graph->device_count;
        strncpy(graph->devices[graph->device_count].name, name, NAME_LENGTH);
        graph->device_count++;
        printf("Device \"%s\" added with ID %d.\n", name, graph->device_count - 1);
    } else {
        printf("Maximum device limit reached.\n");
    }
}

void add_connection(Graph *graph, int device1, int device2) {
    if (device1 < graph->device_count && device2 < graph->device_count) {
        // Add device2 to device1's adjacency list
        Node *new_node = malloc(sizeof(Node));
        new_node->device_id = device2;
        new_node->next = graph->adjacency_list[device1];
        graph->adjacency_list[device1] = new_node;

        // Add device1 to device2's adjacency list
        new_node = malloc(sizeof(Node));
        new_node->device_id = device1;
        new_node->next = graph->adjacency_list[device2];
        graph->adjacency_list[device2] = new_node;

        printf("Connection added between Device %d and Device %d.\n", device1, device2);
    } else {
        printf("Invalid device IDs.\n");
    }
}

void display_topology(Graph *graph) {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < graph->device_count; i++) {
        printf("Device %d (%s): ", i, graph->devices[i].name);
        Node *current = graph->adjacency_list[i];
        while (current) {
            printf("-> %d (%s) ", current->device_id, graph->devices[current->device_id].name);
            current = current->next;
        }
        printf("\n");
    }
}

void free_graph(Graph *graph) {
    for (int i = 0; i < graph->device_count; i++) {
        Node *current = graph->adjacency_list[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
}