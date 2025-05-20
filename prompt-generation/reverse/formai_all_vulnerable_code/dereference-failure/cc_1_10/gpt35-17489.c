//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000000
#define MAX_QUERY_LENGTH 20

typedef struct Record {
    int id;
    char name[20];
    char address[50];
    int age;
} Record;

typedef struct IndexNode {
    int key;
    int record_index;
    struct IndexNode* left;
    struct IndexNode* right;
} IndexNode;

typedef struct Index {
    IndexNode* root;
} Index;

Record records[MAX_RECORDS];
int current_record_index = 0;

IndexNode* create_index_node(int key, int record_index) {
    IndexNode* node = (IndexNode*)malloc(sizeof(IndexNode));
    node->key = key;
    node->record_index = record_index;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Index* create_index() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->root = NULL;
    return index;
}

void insert_record(IndexNode** node, int key, int record_index) {
    if (*node == NULL) {
        *node = create_index_node(key, record_index);
        return;
    }
    if (key <= (*node)->key) {
        insert_record(&((*node)->left), key, record_index);
    } else {
        insert_record(&((*node)->right), key, record_index);
    }
}

void build_index(Index* index) {
    for (int i = 0; i < current_record_index; i++) {
        insert_record(&(index->root), records[i].id, i);
    }
}

void search_records_by_id(IndexNode* node, int id) {
    if (node == NULL) {
        printf("No records found with ID %d.\n", id);
        return;
    }
    if (id == node->key) {
        Record record = records[node->record_index];
        printf("ID: %d, Name: %s, Address: %s, Age: %d\n", 
               record.id, record.name, record.address, record.age);
    }
    if (id <= node->key) {
        search_records_by_id(node->left, id);
    } 
    if (id >= node->key) {
        search_records_by_id(node->right, id);
    }
}

void add_record(Index* index, Record record) {
    records[current_record_index] = record;
    insert_record(&(index->root), record.id, current_record_index);
    current_record_index++;
}

void print_records() {
    for (int i = 0; i < current_record_index; i++) {
        Record record = records[i];
        printf("ID: %d, Name: %s, Address: %s, Age: %d\n", 
               record.id, record.name, record.address, record.age);
    }
}

int main() {
    Index* index = create_index();
    build_index(index);

    // Sample records
    Record record1 = {10001, "John Doe", "123 Main St. Anytown USA", 25};
    add_record(index, record1);
    Record record2 = {10002, "Jane Smith", "456 Broadway Dr. Somewhere City", 30};
    add_record(index, record2);
    Record record3 = {10003, "Bob Johnson", "789 Elm St. Nowhere USA", 40};
    add_record(index, record3);

    printf("All records:\n");
    print_records();

    printf("\nSearch for record with ID 10002:\n");
    search_records_by_id(index->root, 10002);

    return 0;
}