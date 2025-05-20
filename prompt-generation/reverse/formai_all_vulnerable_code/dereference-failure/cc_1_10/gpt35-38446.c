//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
/*
 * C Database Indexing System 
 *
 * This program creates an indexing system that allows users 
 * to search and retrieve data from a database using an index. 
 * The indexing system uses a hash table to store the index 
 * and a binary search tree to store the actual data.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of each data field
#define MAX_FIELD_LENGTH 50

// Define the hash table size
#define HASH_TABLE_SIZE 1000

// Define the structure for data records
typedef struct _data_record {
    char name[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    int age;
    float salary;
} data_record;

// Define the structure for hash table entries
typedef struct _hash_entry {
    int key;
    int index;
    struct _hash_entry* next;
} hash_entry;

// Define the structure for binary search tree nodes
typedef struct _tree_node {
    data_record* data;
    struct _tree_node* left;
    struct _tree_node* right;
} tree_node;

// Define the hash function
int hash_function(char* str) {
    int hash = 0;
    for (int i = 0; i < strlen(str); i++) {
        hash = hash * 31 + str[i];
    }
    return hash;
}

// Define the function to create a new hash entry
hash_entry* create_hash_entry(int key, int index) {
    hash_entry* entry = (hash_entry*) malloc(sizeof(hash_entry));
    entry->key = key;
    entry->index = index;
    entry->next = NULL;
    return entry;
}

// Define the function to insert a hash entry into the hash table
void insert_hash_entry(hash_entry** table, int key, int index) {
    // Calculate the hash value
    int hash = key % HASH_TABLE_SIZE;
    // Check if the hash table entry is empty
    if (table[hash] == NULL) {
        table[hash] = create_hash_entry(key, index);
    } else {
        // Traverse the linked list and find the last entry
        hash_entry* entry = table[hash];
        while (entry->next != NULL) {
            entry = entry->next;
        }
        // Create a new entry and link it to the last entry
        entry->next = create_hash_entry(key, index);
    }
}

// Define the function to find a hash entry in the hash table
hash_entry* find_hash_entry(hash_entry** table, int key) {
    // Calculate the hash value
    int hash = key % HASH_TABLE_SIZE;
    // Traverse the linked list and find the entry with the given key
    hash_entry* entry = table[hash];
    while (entry != NULL && entry->key != key) {
        entry = entry->next;
    }
    return entry;
}

// Define the function to create a new tree node
tree_node* create_tree_node(data_record* data) {
    tree_node* node = (tree_node*) malloc(sizeof(tree_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define the function to insert a data record into the binary search tree
void insert_data_record(tree_node** root, data_record* data) {
    if (*root == NULL) {
        *root = create_tree_node(data);
    } else if (strcmp(data->name, (*root)->data->name) < 0) {
        insert_data_record(&(*root)->left, data);
    } else {
        insert_data_record(&(*root)->right, data);
    }
}

// Define the function to search for a data record in the binary search tree
data_record* find_data_record(tree_node* root, char* name) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(name, root->data->name) == 0) {
        return root->data;
    } else if (strcmp(name, root->data->name) < 0) {
        return find_data_record(root->left, name);
    } else {
        return find_data_record(root->right, name);
    }
}

int main() {
    // Initialize the hash table and the binary search tree
    hash_entry** table = (hash_entry**) malloc(HASH_TABLE_SIZE * sizeof(hash_entry*));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table[i] = NULL;
    }
    tree_node* root = NULL;
    // Create some sample data records
    data_record records[] = {
        {"Alice", "123 Main St.", 30, 50000.0},
        {"Bob", "456 Broadway", 40, 60000.0},
        {"Charlie", "789 Park Ave.", 50, 70000.0},
        {"David", "1010 Park Pl.", 60, 80000.0},
        {"Emma", "1111 Elm St.", 70, 90000.0}
    };
    int num_records = sizeof(records) / sizeof(records[0]);
    // Insert the data records into the hash table and the binary search tree
    for (int i = 0; i < num_records; i++) {
        int key = hash_function(records[i].name);
        insert_hash_entry(table, key, i);
        insert_data_record(&root, &records[i]);
    }
    // Search for a data record by name
    char name[MAX_FIELD_LENGTH];
    printf("Enter a name: ");
    scanf("%s", name);
    int key = hash_function(name);
    hash_entry* entry = find_hash_entry(table, key);
    if (entry == NULL) {
        printf("Record not found.\n");
    } else {
        data_record* record = find_data_record(root, name);
        printf("Name: %s\nAddress: %s\nAge: %d\nSalary: %f\n",
               record->name, record->address, record->age, record->salary);
    }
    // Free the memory
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_entry* entry = table[i];
        while (entry != NULL) {
            hash_entry* next = entry->next;
            free(entry);
            entry = next;
        }
    }
    free(table);
    free(root);
    return 0;
}