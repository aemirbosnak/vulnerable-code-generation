//FormAI DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// define MAX_SIZE for simplicity
#define MAX_SIZE 10

// define struct for data 
typedef struct {
    int id;
    float value1;
    float value2;
} data_t;

// define struct for node
typedef struct node {
    data_t data;
    struct node *next;
} node_t;

// define struct for blockchain
typedef struct {
    node_t *head;
    int size;
} blockchain_t;

// create blank linked list for node
node_t *create_node() {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->next = NULL;
    return new_node;
}

// add data to linked list
void add_data(blockchain_t *blockchain, data_t data) {
    node_t *new_node = create_node();
    new_node->data = data;
    
    // set new node as head if list is empty
    if (blockchain->head == NULL) {
        blockchain->head = new_node;
    }
    // otherwise, set new node next to current head
    else {
        new_node->next = blockchain->head;
        blockchain->head = new_node;
    }
    
    // increase size of linked list
    blockchain->size++;
}

// print data in linked list
void print_data(blockchain_t *blockchain) {
    node_t *current = blockchain->head;
    while (current != NULL) {
        printf("ID: %d Value1: %f Value2: %f \n", current->data.id, current->data.value1, current->data.value2);
        current = current->next;
    }
}

// create new blockchain
blockchain_t *create_blockchain() {
    blockchain_t *blockchain = (blockchain_t *) malloc(sizeof(blockchain_t));
    blockchain->head = NULL;
    blockchain->size = 0;
    return blockchain;
}

int main() {
    // create blockchain
    blockchain_t *blockchain = create_blockchain();
    
    // add data to blockchain
    data_t data1 = {1, 1.0, 2.0};
    data_t data2 = {2, 2.0, 3.0};
    data_t data3 = {3, 3.0, 4.0};
    add_data(blockchain, data1);
    add_data(blockchain, data2);
    add_data(blockchain, data3);
    
    // print data in blockchain
    print_data(blockchain);
    
    return 0;
}