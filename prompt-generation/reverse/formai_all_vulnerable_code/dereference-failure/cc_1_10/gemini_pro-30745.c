//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A node represents a street intersection
typedef struct node {
    int id;
    int num_incoming_streets;
    int* incoming_streets;
    int num_outgoing_streets;
    int* outgoing_streets;
    int traffic_density;
} node_t;

// A road segment representing a road between two intersections
typedef struct road {
  int id;
  int origin;
  int destination;
  int capacity;
  int speed_limit;
} road_t;
int road_count = 0;

typedef struct car {
  int id;
  int start_time;
  int end_time;
} car_t;

// Create a new node with the given id
node_t* create_node(int id) {
    node_t* node = malloc(sizeof(node_t));
    node->id = id;
    node->num_incoming_streets = 0;
    node->incoming_streets = NULL;
    node->num_outgoing_streets = 0;
    node->outgoing_streets = NULL;
    node->traffic_density = 0;
    return node;
}

// Create a new road segment with the given origin, destination, capacity, and speed limit
road_t* create_road(int origin, int destination, int capacity, int speed_limit) {
    road_t* road = malloc(sizeof(road_t));
    road->id = road_count;
    road_count++;
    road->origin = origin;
    road->destination = destination;
    road->capacity = capacity;
    road->speed_limit = speed_limit;
    return road;
}

// Add a new incoming street to the given node
void add_incoming_street(node_t* node, int street_id) {
    node->num_incoming_streets++;
    node->incoming_streets = realloc(node->incoming_streets, node->num_incoming_streets * sizeof(int));
    node->incoming_streets[node->num_incoming_streets - 1] = street_id;
}

// Add a new outgoing street to the given node
void add_outgoing_street(node_t* node, int street_id) {
    node->num_outgoing_streets++;
    node->outgoing_streets = realloc(node->outgoing_streets, node->num_outgoing_streets * sizeof(int));
    node->outgoing_streets[node->num_outgoing_streets - 1] = street_id;
}

// Print the details of the given node
void print_node(node_t* node) {
    printf("Node %d:\n", node->id);
    printf("  Incoming streets: ");
    for (int i = 0; i < node->num_incoming_streets; i++) {
        printf("%d ", node->incoming_streets[i]);
    }
    printf("\n");
    printf("  Outgoing streets: ");
    for (int i = 0; i < node->num_outgoing_streets; i++) {
        printf("%d ", node->outgoing_streets[i]);
    }
    printf("\n");
    printf("  Traffic density: %d\n", node->traffic_density);
}

// Print the details of the given road segment
void print_road(road_t* road) {
    printf("Road %d:\n", road->id);
    printf("  Origin: %d\n", road->origin);
    printf("  Destination: %d\n", road->destination);
    printf("  Capacity: %d\n", road->capacity);
    printf("  Speed limit: %d\n", road->speed_limit);
}

// Main function
int main() {
    // Create a few nodes
    node_t* node1 = create_node(1);
    node_t* node2 = create_node(2);
    node_t* node3 = create_node(3);
    node_t* node4 = create_node(4);

    // Create a few road segments
    road_t* road1 = create_road(1, 2, 100, 50);
    road_t* road2 = create_road(2, 3, 100, 50);
    road_t* road3 = create_road(3, 4, 100, 50);
    road_t* road4 = create_road(4, 1, 100, 50);

    // Add the road segments to the nodes
    add_incoming_street(node1, road1->id);
    add_outgoing_street(node1, road4->id);
    add_incoming_street(node2, road1->id);
    add_outgoing_street(node2, road2->id);
    add_incoming_street(node3, road2->id);
    add_outgoing_street(node3, road3->id);
    add_incoming_street(node4, road3->id);
    add_outgoing_street(node4, road4->id);

    // Print the details of the nodes and road segments
    print_node(node1);
    print_node(node2);
    print_node(node3);
    print_node(node4);
    print_road(road1);
    print_road(road2);
    print_road(road3);
    print_road(road4);

    return 0;
}