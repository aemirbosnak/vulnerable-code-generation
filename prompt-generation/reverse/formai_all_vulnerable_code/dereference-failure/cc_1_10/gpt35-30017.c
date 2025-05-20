//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100   // maximum number of nodes in the circuit

// Define the node structure for the circuit.
typedef struct node_tag {

    char name[10];        // name of the node
    double value;         // current value at the node
    struct node_tag *next; // pointer to the next node in the circuit
} NODE;

// Define the element structure for the circuit.
typedef struct element_tag {

    char type;           // type of element R/L/C/V/I
    char node1[10];      // name of node1
    char node2[10];      // name of node2
    double value;        // magnitude of the element value
} ELEMENT;

// Function to create a new node
NODE *create_node(char *name){

    NODE *new_node;
    new_node = (NODE *)malloc(sizeof(NODE));
    if(new_node){
        strcpy(new_node->name, name);
        new_node->value = 0;
        new_node->next = NULL;
    }
    return new_node;
}

// Function to search a node in the circuit
NODE *search_node(NODE *start, char *name){

    NODE *current = start;
    while(current){
        if(strcmp(current->name, name) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to add a new node to the end of the circuit
NODE *add_node(NODE *start, NODE *new_node){

    NODE *current = start;
    while(current->next){
        current = current->next;
    }
    current->next = new_node;
    return start;
}

// Function to create a new element
ELEMENT *create_element(char type, char *node1, char *node2, double value){

    ELEMENT *new_element;
    new_element = (ELEMENT *)malloc(sizeof(ELEMENT));
    if(new_element){
        new_element->type = type;
        strcpy(new_element->node1, node1);
        strcpy(new_element->node2, node2);
        new_element->value = value;
    }
    return new_element;
}

// Function to add a new element to the circuit
void add_element(NODE *start, ELEMENT *new_element){

    NODE *node1, *node2;
    node1 = search_node(start, new_element->node1);
    node2 = search_node(start, new_element->node2);
    if(node1 && node2){
        // Add the element to the circuit
        if(new_element->type == 'R'){
            node1->value += new_element->value;
            node2->value += new_element->value;
        }
        else if(new_element->type == 'L'){
            node1->value += new_element->value;
            node2->value += new_element->value;
        }
        else if(new_element->type == 'C'){
            node1->value += new_element->value;
            node2->value += new_element->value;
        }
        else if(new_element->type == 'V'){
            node1->value += new_element->value;
            node2->value -= new_element->value;
        }
        else if(new_element->type == 'I'){
            node1->value -= new_element->value;
            node2->value += new_element->value;
        }
    }
    else{
        printf("Node not found in the circuit.\n");
    }
}

// Function to print the circuit
void print_circuit(NODE *start){

    NODE *current = start;
    while(current){
        printf("%s : %lf\n", current->name, current->value);
        current = current->next;
    }
}

int main(){

    NODE *start = NULL;
    ELEMENT *element1, *element2, *element3;

    // Create nodes
    NODE *node1 = create_node("A");
    NODE *node2 = create_node("B");
    NODE *node3 = create_node("C");

    // Add nodes to the circuit
    start = add_node(start, node1);
    start = add_node(start, node2);
    start = add_node(start, node3);

    // Create elements
    element1 = create_element('R', "A", "B", 10);
    element2 = create_element('L', "B", "C", 5);
    element3 = create_element('V', "C", "A", 20);

    // Add elements to the circuit
    add_element(start, element1);
    add_element(start, element2);
    add_element(start, element3);

    // Print the circuit
    printf("Circuit:\n");
    print_circuit(start);

    return 0;
}