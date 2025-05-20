//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BASE_PAIRS 4

typedef enum {A, C, G, T} BasePair;

// Definition of the linked list node
typedef struct node {
    BasePair base_pair;
    struct node* next;
} Node;

// Function to generate a random base pair
BasePair get_random_base_pair() {
    // Generate a random number between 0 and 3 inclusive
    int random_num = rand() % NUM_BASE_PAIRS;
    
    // Return the corresponding base pair
    switch(random_num) {
        case 0: return A;
        case 1: return C;
        case 2: return G;
        case 3: return T;
    }
}

// Function to generate a random genome sequence of a given length
Node* generate_random_genome_sequence(int length) {
    Node* head = NULL;
    Node* current_node = NULL;
    
    // Initialize the random number generator with the current time as the seed
    srand(time(NULL));
    
    // Generate the requested number of base pairs and add them to the linked list
    for(int i=0; i<length; i++) {
        // Create a new node
        Node* new_node = (Node*) malloc(sizeof(Node));
        
        // Assign a random base pair to the node
        new_node->base_pair = get_random_base_pair();
        
        // Add the new node to the end of the linked list
        if(head == NULL) {
            // Case 1: the list is empty, so make this node the head node
            head = new_node;
            current_node = new_node;
        } else {
            // Case 2: the list is not empty, so add the new node to the end
            current_node->next = new_node;
            current_node = new_node;
        }
    }
    
    // Add a sentinel node to mark the end of the list
    Node* sentinel_node = (Node*) malloc(sizeof(Node));
    sentinel_node->base_pair = -1;
    sentinel_node->next = NULL;
    if(head == NULL) {
        // Case 1: the list is empty, so make the sentinel node the head node
        head = sentinel_node;
    } else {
        // Case 2: the list is not empty, so add the sentinel node to the end
        current_node->next = sentinel_node;
    }
    
    // Return the head node of the linked list
    return head;
}

// Function to print the genome sequence stored in a linked list
void print_genome_sequence(Node* head) {
    Node* current_node = head;
    while(current_node->next != NULL) {
        switch(current_node->base_pair) {
            case A: printf("A"); break;
            case C: printf("C"); break;
            case G: printf("G"); break;
            case T: printf("T"); break;
        }
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    int genome_length = 100;
    
    Node* genome_sequence = generate_random_genome_sequence(genome_length);
    
    printf("Generated genome sequence:\n");
    print_genome_sequence(genome_sequence);
    
    return 0;
}