//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h> 

struct Node { 
    int key; 
    float value; 
}; 

struct Database { 
    int size; 
    int capacity; 
    struct Node* nodes; 
}; 

struct Database* createDatabase(int capacity) { 
    struct Database* db = (struct Database*) malloc(sizeof(struct Database)); 
    db->size = 0; 
    db->capacity = capacity; 
    db->nodes = (struct Node*) malloc(capacity * sizeof(struct Node)); 
    return db; 
} 

void insert(struct Database* db, int key, float value) { 
    if (db->size >= db->capacity) { 
        printf("Error: Database is full\n"); 
        return; 
    } 
    int i = db->size - 1; 
    while (i >= 0 && db->nodes[i].key > key) { 
        db->nodes[i + 1].key = db->nodes[i].key; 
        db->nodes[i + 1].value = db->nodes[i].value; 
        i--; 
    } 
    db->nodes[i + 1].key = key; 
    db->nodes[i + 1].value = value; 
    db->size++; 
} 

void delete(struct Database* db, int key) { 
    int i = 0; 
    while (i < db->size && db->nodes[i].key != key) { 
        i++; 
    } 
    if (i >= db->size) { 
        printf("Error: Key does not exist in database\n"); 
        return; 
    } 
    while (i < db->size - 1) { 
        db->nodes[i].key = db->nodes[i + 1].key; 
        db->nodes[i].value = db->nodes[i + 1].value; 
        i++; 
    } 
    db->size--; 
} 

float search(struct Database* db, int key) { 
    int i = 0; 
    while (i < db->size && db->nodes[i].key != key) { 
        i++; 
    } 
    if (i >= db->size) { 
        printf("Error: Key does not exist in database\n"); 
        return -1.0; 
    } 
    return db->nodes[i].value; 
} 

int main() { 
    struct Database* db = createDatabase(5); 
    insert(db, 3, 2.5); 
    insert(db, 1, 1.2); 
    insert(db, 4, 3.7); 
    insert(db, 2, 0.9); 
    insert(db, 5, 4.2); 
    delete(db, 3); 
    insert(db, 6, 5.1); 
    printf("Value of key 2: %f\n", search(db, 2)); 
    return 0; 
}