//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define struct for node in linked list
typedef struct node {
    int value;
    struct node* next;
} node;

// Define struct for hash table bucket
typedef struct bucket {
    int* values;
    int size;
    int count;
} bucket;

// Define function to initialize a linked list node
node* init_node(int val) {
    node* n = malloc(sizeof(node));
    n->value = val;
    n->next = NULL;
    return n;
}

// Define function to insert a value at the head of a linked list
node* insert_linked_list(node* head, int val) {
    node* new_node = init_node(val);
    new_node->next = head;
    return new_node;
}

// Define function to insert a value into a hash table
void insert_hash_table(bucket* table, int val) {
    int index = val % table->size;
    if (table->count == table->size) {
        printf("Hash table is full!\n");
        exit(1);
    }
    while (table->values[index] != -1) {
        index = (index + 1) % table->size;
    }
    table->values[index] = val;
    table->count++;
}

// Define function to search for a value in a hash table
int search_hash_table(bucket* table, int val) {
    int index = val % table->size;
    while (table->values[index] != val) {
        if (table->values[index] == -1) {
            return -1;
        }
        index = (index + 1) % table->size;
    }
    return index;
}

int main() {
    const int NUM_VALUES = 1000000;
    const int MAX_VALUE = 1000000;
    int* values = malloc(sizeof(int) * NUM_VALUES);
    srand(time(NULL));
    for (int i = 0; i < NUM_VALUES; i++) {
        values[i] = rand() % MAX_VALUE;
    }

    // Test linked list implementation
    clock_t start = clock();
    node* head = NULL;
    for (int i = 0; i < NUM_VALUES; i++) {
        head = insert_linked_list(head, values[i]);
    }
    double linked_list_time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Linked list insertion time: %.2f seconds\n", linked_list_time);

    // Test hash table implementation
    bucket* table = malloc(sizeof(bucket));
    table->size = NUM_VALUES / 2;
    table->count = 0;
    table->values = malloc(sizeof(int) * table->size);
    for (int i = 0; i < table->size; i++) {
        table->values[i] = -1;
    }
    start = clock();
    for (int i = 0; i < NUM_VALUES; i++) {
        insert_hash_table(table, values[i]);
    }
    double hash_table_time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Hash table insertion time: %.2f seconds\n", hash_table_time);

    // Test hash table search function
    start = clock();
    for (int i = 0; i < NUM_VALUES; i++) {
        int index = search_hash_table(table, values[i]);
    }
    double search_time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Hash table search time: %.2f seconds\n", search_time);

    free(table->values);
    free(table);
    free(values);
    return 0;
}