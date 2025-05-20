//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to represent a record
typedef struct record {
    int id;
    char name[50];
    int age;
} Record;

// struct to represent a node in the index tree
typedef struct node {
    int key;
    int offset;
    struct node *left;
    struct node *right;
} Node;

// function to insert a record into the database
void insert_record(FILE *fp, Record r) {
    fseek(fp, 0, SEEK_END); // position file pointer to end of file
    fwrite(&r, sizeof(Record), 1, fp); // write record to file
}

// function to search for a record by ID
Record search_record(FILE *fp, int id) {
    Record r;
    fseek(fp, 0, SEEK_SET); // position file pointer to beginning of file
    while (fread(&r, sizeof(Record), 1, fp) == 1) { // read records from file
        if (r.id == id) { // compare ID with target ID
            return r;
        }
    }
    // if record not found, return empty record with ID -1
    Record empty = {-1, "", -1};
    return empty;
}

// function to create a new node in the index tree
Node *new_node(int key, int offset) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->offset = offset;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// function to insert a node into the index tree
Node *insert_node(Node *root, int key, int offset) {
    if (root == NULL) { // empty tree
        return new_node(key, offset);
    }
    if (key < root->key) { // key is less than root's key, insert to left subtree
        root->left = insert_node(root->left, key, offset);
    } else if (key > root->key) { // key is greater than root's key, insert to right subtree
        root->right = insert_node(root->right, key, offset);
    }
    return root;
}

// function to search for a node in the index tree
Node *search_node(Node *root, int key) {
    if (root == NULL || root->key == key) { // empty tree or key found
        return root;
    }
    if (key < root->key) { // key is less than root's key, search left subtree
        return search_node(root->left, key);
    }
    if (key > root->key) { // key is greater than root's key, search right subtree
        return search_node(root->right, key);
    }
}

// function to print all nodes in the index tree (inorder traversal)
void print_nodes(Node *root) {
    if (root == NULL) {
        return;
    }
    print_nodes(root->left);
    printf("%d %d\n", root->key, root->offset);
    print_nodes(root->right);
}

int main() {
    FILE *data = fopen("data.bin", "ab+"); // open data file
    Node *root = NULL; // initialize empty index tree
    int n;
    printf("Enter number of records to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Record r;
        printf("Enter ID, name, and age separated by spaces for record %d: ", i+1);
        scanf("%d %s %d", &r.id, r.name, &r.age);
        insert_record(data, r); // insert record into data file
        root = insert_node(root, r.id, ftell(data)-sizeof(Record)); // insert node into index tree with offset of inserted record
    }
    printf("Index tree:\n");
    print_nodes(root); // print index tree
    int id;
    printf("Enter ID to search for: ");
    scanf("%d", &id);
    Record result = search_record(data, id); // search for record by ID
    if (result.id != -1) { // record found
        printf("Record found:\n");
        printf("ID: %d\nName: %s\nAge: %d\n", result.id, result.name, result.age);
    } else { // record not found
        printf("Record not found.\n");
    }
    fclose(data); // close data file
    return 0;
}