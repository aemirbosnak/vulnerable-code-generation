//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100   // Maximum number of nodes in the circuit
#define MAX_SIM_TIME 10 // Maximum simulation time

// Structure for each node
typedef struct node {
    int id;               // Node number
    float voltage;        // Node voltage
    bool is_ground;       // Is this node ground node?
    struct node* next;    // Next node in the list
} Node;

// Structure for each component in the circuit
typedef struct component {
    int id;                 // Component number
    float value;            // Component value (Resistance/Capacitance/Inductance)
    enum {RESISTOR = 1, CAPACITOR, INDUCTOR} type;  // Component type
    Node* node1;            // First node connected to the component
    Node* node2;            // Second node connected to the component
    struct component* next; // Next component in the list
} Component;

// Global variables
int num_nodes = 0;              // Number of nodes in the circuit
Node* nodes_list[MAX_NODES];    // Array of node pointers
Component* components_list = NULL;  // List of components in the circuit
float delta_t = 0.001;          // Time step for simulation

// Function prototypes
Node* create_node(int id, bool is_ground);
Component* create_component(int id, float value, int type, Node* node1, Node* node2);
void add_component(Component* new_component);
void print_circuit();
void simulate_circuit();

int main() {
    // Create the circuit
    Node* node0 = create_node(0, true);
    Node* node1 = create_node(1, false);
    Node* node2 = create_node(2, false);
    Node* node3 = create_node(3, false);
    Node* node4 = create_node(4, false);
    
    Component* r1 = create_component(1, 100.0, RESISTOR, node0, node1);
    Component* c1 = create_component(2, 1e-6, CAPACITOR, node1, node2);
    Component* r2 = create_component(3, 50.0, RESISTOR, node2, node3);
    Component* l1 = create_component(4, 100e-3, INDUCTOR, node3, node4);
    Component* c2 = create_component(5, 1e-6, CAPACITOR, node4, node0);
    
    // Add components to the list
    add_component(r1);
    add_component(c1);
    add_component(r2);
    add_component(l1);
    add_component(c2);
    
    // Print the circuit
    print_circuit();
    
    // Simulate the circuit
    simulate_circuit();
    
    return 0;
}

/**
 * Create a new node with the given id and is_ground flag.
 */
Node* create_node(int id, bool is_ground) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->id = id;
    new_node->is_ground = is_ground;
    new_node->next = NULL;
    nodes_list[num_nodes++] = new_node;
    return new_node;
}

/**
 * Create a new component with the given id, value, type, and nodes.
 */
Component* create_component(int id, float value, int type, Node* node1, Node* node2) {
    Component* new_component = (Component*) malloc(sizeof(Component));
    new_component->id = id;
    new_component->value = value;
    new_component->type = type;
    new_component->node1 = node1;
    new_component->node2 = node2;
    new_component->next = NULL;
    return new_component;
}

/**
 * Add a new component to the list of components.
 */
void add_component(Component* new_component) {
    if (components_list == NULL) {
        components_list = new_component;
    } else {
        Component* current_component = components_list;
        while (current_component->next != NULL) {
            current_component = current_component->next;
        }
        current_component->next = new_component;
    }
}

/**
 * Print the details of the circuit.
 */
void print_circuit() {
    printf("Circuit Details\n");
    printf("---------------\n");
    printf("Number of nodes: %d\n", num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes_list[i]->id, nodes_list[i]->is_ground ? "GROUND" : "");
    }
    printf("List of components:\n");
    printf("ID\tType\tValue\tNode 1\tNode 2\n");
    Component* current_component = components_list;
    while (current_component != NULL) {
        printf("%d\t", current_component->id);
        switch(current_component->type) {
            case RESISTOR:
                printf("RESISTOR\t");
                break;
            case CAPACITOR:
                printf("CAPACITOR\t");
                break;
            case INDUCTOR:
                printf("INDUCTOR\t");
                break;
        }
        printf("%.3e\t", current_component->value);
        printf("%d\t%d\n", current_component->node1->id, current_component->node2->id);
        current_component = current_component->next;
    }
}

/**
 * Simulate the circuit for a maximum of MAX_SIM_TIME seconds.
 */
void simulate_circuit() {
    float time = 0.0;
    while (time < MAX_SIM_TIME) {
        // TODO: Implement circuit simulation code here
        time += delta_t;
    }
}