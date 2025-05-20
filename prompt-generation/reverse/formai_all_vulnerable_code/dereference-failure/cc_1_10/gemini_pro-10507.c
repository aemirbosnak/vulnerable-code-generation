//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sensor node struct
typedef struct {
    int id;
    float temperature;
    struct sensor_node *next;
} sensor_node;

// Network node struct
typedef struct {
    int id;
    struct sensor_node *sensors;
    struct network_node *next;
} network_node;

// Create a new sensor node
sensor_node* create_sensor_node(int id, float temperature) {
    sensor_node *new_node = (sensor_node*)malloc(sizeof(sensor_node));
    new_node->id = id;
    new_node->temperature = temperature;
    new_node->next = NULL;
    return new_node;
}

// Create a new network node
network_node* create_network_node(int id) {
    network_node *new_node = (network_node*)malloc(sizeof(network_node));
    new_node->id = id;
    new_node->sensors = NULL;
    new_node->next = NULL;
    return new_node;
}

// Add a sensor node to a network node
void add_sensor_node(network_node *network_node, sensor_node *sensor_node) {
    if (network_node->sensors == NULL) {
        network_node->sensors = sensor_node;
    } else {
        sensor_node->next = network_node->sensors;
        network_node->sensors = sensor_node;
    }
}

// Print the sensor data for a network node
void print_sensor_data(network_node *network_node) {
    sensor_node *current_node = network_node->sensors;
    while (current_node != NULL) {
        printf("Sensor %d: %.2f degrees Celsius\n", current_node->id, current_node->temperature);
        current_node = current_node->next;
    }
}

// Main function
int main() {
    // Create three sensor nodes
    sensor_node *sensor_node1 = create_sensor_node(1, 20.0);
    sensor_node *sensor_node2 = create_sensor_node(2, 22.5);
    sensor_node *sensor_node3 = create_sensor_node(3, 25.0);

    // Create two network nodes
    network_node *network_node1 = create_network_node(1);
    network_node *network_node2 = create_network_node(2);

    // Add the sensor nodes to the network nodes
    add_sensor_node(network_node1, sensor_node1);
    add_sensor_node(network_node1, sensor_node2);
    add_sensor_node(network_node2, sensor_node3);

    // Print the sensor data for each network node
    printf("Sensor data for network node 1:\n");
    print_sensor_data(network_node1);

    printf("Sensor data for network node 2:\n");
    print_sensor_data(network_node2);

    return 0;
}